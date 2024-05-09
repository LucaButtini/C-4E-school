#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define BUFFER_DIM 1024
#define BUFFER_SIZE 64

// MANCANO I MUTEX QUINDI NON VA
typedef struct
{
    unsigned char buffer[BUFFER_DIM] : int n;
} buffer_str;

buffer_str ring_buffer[BUFFER_SIZE];
bool eof = false;
int read_index = 0;
int write_index = 0;
int n_block = 0;

void leggi_file(FILE *file)
{
    while (!feof(file))
    {
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
    }
    eof = true;
}

void scrivi_file(FILE *file)
{
    while (!eof || n_block = 0)
    {
        if (n_block < 0)
        {
            fwrite(ring_buffer[read_index].buffer, 1, ring_buffer[read_index].n, file);
            read_index = (read_index + 1) % BUFFER_SIZE;
            n_block--;
        }
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
        fclose(origine);
        return -1;
    }
    destinazione = fopen(argv[1], "rb");
    if (destinazione == NULL)
    {
        printf("errore apertura file di destinazione\n");
        return -1;
    }
    pthread_create(&lettura, NULL, &leggi_file, origine);
    pthread_create(&scrittura, NULL, &scrivi_file, destinazione);
    pthread_join(lettura, NULL);
    pthread_join(scrittura, NULL);
    fclose(origine);
    fclose(destinazione);
    return 0;
}