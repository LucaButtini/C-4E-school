#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024

// Funzione eseguita dal thread per leggere il file di origine
void *leggi_file(void *args)
{
    // Casting degli argomenti come array di puntatori a char
    char **file_paths = (char **)args;
    char *file_origine = file_paths[0];      // Percorso del file di origine
    char *file_destinazione = file_paths[1]; // Percorso del file di destinazione

    // Apertura del file di origine in modalità di lettura ("r")
    FILE *file_origine_ptr = fopen(file_origine, "r");
    if (file_origine_ptr == NULL)
    {
        printf("Errore nell'apertura del file di origine\n");
        pthread_exit(NULL); // Esce dal thread in caso di errore
    }

    // Apertura del file di destinazione in modalità di scrittura ("w")
    FILE *file_destinazione_ptr = fopen(file_destinazione, "w");
    if (file_destinazione_ptr == NULL)
    {
        printf("Errore nell'apertura del file di destinazione\n");
        fclose(file_origine_ptr); // Chiude il file di origine prima di uscire
        pthread_exit(NULL);       // Esce dal thread in caso di errore
    }

    char buffer[MAX_BUFFER_SIZE];
    // Legge dal file di origine finché non raggiunge la fine
    while (!feof(file_origine_ptr))
    {
        // Legge fino a MAX_BUFFER_SIZE byte dal file di origine e memorizza il numero di byte letti in bytes_read
        size_t bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, file_origine_ptr);
        // Scrive i byte letti nel file di destinazione
        fwrite(buffer, 1, bytes_read, file_destinazione_ptr);
    }

    // Chiude entrambi i file
    fclose(file_origine_ptr);
    fclose(file_destinazione_ptr);

    // Termina il thread
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    // Verifica che ci siano esattamente due argomenti (oltre al nome del programma)
    if (argc != 3)
    {
        // Stampa il modo corretto di utilizzo del programma
        printf("Utilizzo: %s <file_origine> <file_destinazione>\n", argv[0]);
        return 1; // Termina il programma con un codice di errore
    }

    // Crea un array di puntatori a char per passare i percorsi dei file alla funzione leggi_file()
    char *file_paths[2];
    file_paths[0] = argv[1]; // Percorso del file di origine
    file_paths[1] = argv[2]; // Percorso del file di destinazione

    // Crea un thread per leggere il file di origine
    pthread_t thread_lettura;
    pthread_create(&thread_lettura, NULL, leggi_file, (void *)file_paths);

    // Attende che il thread di lettura termini prima di terminare il programma
    pthread_join(thread_lettura, NULL);

    // Termina il programma con successo
    return 0;
}
