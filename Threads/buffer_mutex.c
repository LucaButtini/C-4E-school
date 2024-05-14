#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define DIM 64
#define N 16

typedef struct
{
    unsigned char buffer[DIM];
    int n;
} buffer_str;

buffer_str ring_buffer[N];
int read_index = 0, write_index = 0, n_block = 0;
//int end = 0;
bool end = false;
pthread_mutex_t critical, mutex;
pthread_cond_t not_full, not_empty;
FILE *origine, *destinazione;

void *leggi(void *par)
{
    int n;
    while (!feof(origine))
    {
        pthread_mutex_lock(&critical);
        if (n_block > N)
            pthread_cond_wait(&not_full, &critical);

        n = fread(ring_buffer[write_index].buffer, 1, DIM, origine);
        if (n > 0)
        {
            ring_buffer[write_index].n = n;
            write_index = (write_index + 1) % N;
            pthread_mutex_lock(&mutex);
            n_block++;
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&not_empty);
        }
        pthread_mutex_unlock(&critical);
    }
    //end = 1;
    end = true;
    pthread_cond_signal(&not_empty);
    pthread_exit(NULL);
}

void *scrivi(void *par)
{
    while (1)
    {
        if (end && n_block == 0)
            break;
        pthread_mutex_lock(&critical);
        if (n_block > 0)
        {
            fwrite(ring_buffer[read_index].buffer, 1, ring_buffer[read_index].n, destinazione);
            read_index = (read_index + 1) % N;
            pthread_mutex_lock(&mutex);
            n_block--;
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&not_full);
        }
        else
        {
            pthread_cond_wait(&not_empty, &critical);
        }
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
    pthread_mutex_init(&critical, NULL);
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_cond_init(&not_empty, NULL);

    pthread_create(&lettura_thread, NULL, &leggi, NULL);
    pthread_create(&scrittura_thread, NULL, &scrivi, NULL);

    pthread_join(lettura_thread, NULL);
    pthread_join(scrittura_thread, NULL);

    pthread_mutex_destroy(&critical);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_full);
    pthread_cond_destroy(&not_empty);

    fclose(origine);
    fclose(destinazione);
    return 0;
}