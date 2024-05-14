#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define DIM 64 // Dimensione del buffer
#define N 16   // Numero di buffer nel ring

// Struttura per rappresentare un buffer nel ring
typedef struct
{
    unsigned char buffer[DIM]; // Buffer di dati
    int n;                     // Numero di byte effettivamente presenti nel buffer
} buffer_str;

// Array di buffer nel ring
buffer_str ring_buffer[N];
// Indici di lettura e scrittura, e contatore di blocchi nel ring
int read_index = 0, write_index = 0, n_block = 0;
// Flag che indica se la lettura è terminata
bool end = false;
// Mutex per sincronizzazione critica e per il contatore di blocchi
pthread_mutex_t critical, mutex;
// Variabili di condizione per segnalare lo stato del ring
pthread_cond_t not_full, not_empty;
FILE *origine, *destinazione;

// Funzione eseguita dal thread di lettura
void *leggi(void *par)
{
    int n;
    while (!feof(origine))
    {
        // Blocca la sezione critica
        pthread_mutex_lock(&critical);

        // Attende se il ring è pieno
        if (n_block > N)
            pthread_cond_wait(&not_full, &critical);

        // Legge dal file di origine nel buffer corrente
        n = fread(ring_buffer[write_index].buffer, 1, DIM, origine);
        if (n > 0) // Se sono stati letti dei byte
        {
            // Imposta il numero di byte nel buffer corrente
            ring_buffer[write_index].n = n;
            // Passa al prossimo buffer nel ring
            write_index = (write_index + 1) % N;
            // Blocca il mutex per modificare n_block
            pthread_mutex_lock(&mutex);
            // Incrementa il contatore di blocchi nel ring
            n_block++;
            // Sblocca il mutex
            pthread_mutex_unlock(&mutex);
            // Segnala che il ring non è più vuoto
            pthread_cond_signal(&not_empty);
        }
        // Sblocca la sezione critica
        pthread_mutex_unlock(&critical);
    }
    // Imposta il flag di fine lettura
    end = true;
    // Segnala che il ring non è più vuoto
    pthread_cond_signal(&not_empty);
    pthread_exit(NULL);
}

// Funzione eseguita dal thread di scrittura
void *scrivi(void *par)
{
    while (1)
    {
        // Se la lettura è terminata e non ci sono più blocchi nel ring, esce dal ciclo
        if (end && n_block == 0)
            break;

        // Blocca la sezione critica
        pthread_mutex_lock(&critical);

        // Se ci sono blocchi nel ring, scrive nel file di destinazione
        if (n_block > 0)
        {
            // Scrive dal buffer corrente nel file di destinazione
            fwrite(ring_buffer[read_index].buffer, 1, ring_buffer[read_index].n, destinazione);
            // Passa al prossimo buffer nel ring
            read_index = (read_index + 1) % N;
            // Blocca il mutex per modificare n_block
            pthread_mutex_lock(&mutex);
            // Decrementa il contatore di blocchi nel ring
            n_block--;
            // Sblocca il mutex
            pthread_mutex_unlock(&mutex);
            // Segnala che il ring non è più pieno
            pthread_cond_signal(&not_full);
        }
        else
        {
            // Attende se il ring è vuoto
            pthread_cond_wait(&not_empty, &critical);
        }
        // Sblocca la sezione critica
        pthread_mutex_unlock(&critical);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t scrittura_thread, lettura_thread;

    if (argc != 3)
    {
        printf("Uso: %s file-origine file-destinazione\r\n", argv[0]);
        return 0;
    }
    origine = fopen(argv[1], "rb");
    if (origine == NULL)
    {
        printf("Errore apertura file %s\r\n", argv[1]);
        return 0;
    }
    destinazione = fopen(argv[2], "wb");
    if (destinazione == NULL)
    {
        printf("Errore apertura file %s\r\n", argv[2]);
        fclose(origine);
        return -1;
    }

    // Inizializza i mutex e le variabili di condizione
    pthread_mutex_init(&critical, NULL);
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    // Avvia i thread di lettura e scrittura
    pthread_create(&lettura_thread, NULL, &leggi, NULL);
    pthread_create(&scrittura_thread, NULL, &scrivi, NULL);

    // Attende che i thread terminino
    pthread_join(lettura_thread, NULL);
    pthread_join(scrittura_thread, NULL);

    // Distrugge i mutex e le variabili di condizione
    pthread_mutex_destroy(&critical);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    fclose(origine);
    fclose(destinazione);

    return 0;
    /
}
