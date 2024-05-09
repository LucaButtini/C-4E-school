#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_DIM 1024
FILE *file_origine, *file_destinazione;
void *leggi_file(void *args)
{
    file_origine = fopen(argv[1], "r");
    if (file_origine == NULL)
    {
        printf("Errore nell'apertura del file di origine\n");
        pthread_exit(NULL); // Esce dal thread in caso di errore
    }
    file_destinazione = fopen(argv[2], "w");
    if (file_destinazione == NULL)
    {
        printf("Errore nell'apertura del file di destinazione\n");
        fclose(file_origine);
        pthread_exit(NULL); // Esce dal thread in caso di errore
    }
    char buffer[BUFFER_DIM];
    while (!feof(file_origine))
    {
        fread(buffer, 1, BUFFER_DIM, file_origine);
        // la fwrite come la faccio?
    }
    fclose(file_origine);
    fclose(file_destinazione);
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        return -1;
        
    // Crea un array di puntatori a char per passare i percorsi dei file alla funzione leggi_file()
    char *file_paths[2];
    file_paths[0] = argv[1]; // Percorso del file di origine
    file_paths[1] = argv[2]; // Percorso del file di destinazione
    pthread_t thread_lettura;
    pthread_create(&thread_lettura, NULL, leggi_file, (void *)file_paths);
    pthread_join(thread_lettura, NULL);
    return 0;
}
