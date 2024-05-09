#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define BUFFER_DIM 1024
#define BUFFER_SIZE 64
// VERSIONE COI MUTEX
typedef struct
{
    unsigned char buffer[BUFFER_DIM];
    int n;
} buffer_str;
// Dichiarazione del mutex per la protezione delle variabili condivise
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
buffer_str ring_buffer[BUFFER_SIZE];
bool eof = false;
int read_index = 0;
int write_index = 0;
int n_block = 0;

void leggi_file(FILE *file)
{
    while (!feof(file))
    {
        // Acquisizione del mutex prima di accedere alle variabili condivise
        pthread_mutex_lock(&mutex);
        if (n_block < BUFFER_SIZE)
        {
            int n = fread(ring_buffer[write_index].buffer, 1, BUFFER_DIM, file);
            if (n > 0)
            {
                ring_buffer[write_index].n = n;
                write_index = (write_index + 1) % BUFFER_SIZE;
                n_block++;
            }
        }
        // Rilascio del mutex dopo aver completato l'accesso alle variabili condivise
        pthread_mutex_unlock(&mutex);
    }
    eof = true;
}

void scrivi_file(FILE *file)
{
    while (!eof || n_block > 0)
    {
        // Acquisizione del mutex prima di accedere alle variabili condivise
        pthread_mutex_lock(&mutex);
        if (n_block > 0)
        {
            fwrite(ring_buffer[read_index].buffer, 1, ring_buffer[read_index].n, file);
            read_index = (read_index + 1) % BUFFER_SIZE;
            n_block--;
        }
        // Rilascio del mutex dopo aver completato l'accesso alle variabili condivise
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char *argv[])
{
    FILE *origine, *destinazione;
    pthread_t lettura, scrittura;

    if (argc != 3)
    {
        printf("errore argomenti\n");
        return -1;
    }
    origine = fopen(argv[1], "rb");
    if (origine == NULL)
    {
        printf("errore apertura file di origine\n");
        return -1;
    }
    destinazione = fopen(argv[2], "wb");
    if (destinazione == NULL)
    {
        printf("errore apertura file di destinazione\n");
        fclose(origine);
        return -1;
    }

    pthread_create(&lettura, NULL, (void *(*)(void *))leggi_file, origine);
    pthread_create(&scrittura, NULL, (void *(*)(void *))scrivi_file, destinazione);
    pthread_join(lettura, NULL);
    pthread_join(scrittura, NULL);

    fclose(origine);
    fclose(destinazione);

    return 0;
}
