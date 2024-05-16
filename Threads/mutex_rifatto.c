#include <stdio.h>
#include <pthread.h>

#define SLICE_DIM 64
#define NUM_SLICES 16

int read_index, write_index;
int n_slices;
typedef struct // mi aiuto con una struct dato che devo mettere assieme più dati
{
    unsigned char buffer_in_str[SLICE_DIM];
    int n;
} buffer_struct;

buffer_struct buffer[NUM_SLICES];
pthread_mutex_t mutex;
pthread_cond_t not_full, not_empty;

void *write_file(void *arg)
{
    pthread_mutex_lock(&mutex);
    if (n_slices > 0)
    {
        fwrite(buffer[read_index].buffer_in_str, 1, buffer[read_index].n, (FILE *)arg);
        read_index = (read_index + 1) % NUM_SLICES;
        n_slices--;
    }
    else
    {
        pthread_cond_wait(&not_empty, &mutex);
    }

    pthread_mutex_unclock(&mutex);
    pthread_cond_signal(&not_full);
}
void *read_file(void *arg)
{
    int n; // registro numero dati effettivamente letti, questa "n" è nello stack del thread
    pthread_mutex_lock(&mutex);
    if (n_slices >= NUM_SLICES)
        pthread_cond_wait(&not_full, &mutex);

    n = fread(buffer[write_index].buffer_in_str, 1, SLICE_DIM, (FILE *)arg);
    if (n > 0)
    {
        buffer[write_index].n = n;
        write_index = (write_index + 1) % NUM_SLICES;
        n_slices++;
        pthread_cond_signal(&not_empty);
    }
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char *argv[])
{
    FILE *fr;
    fr = fopen("origine", "rb");
    pthread_t write_th, read_th;
    pthread_create(&write_th, NULL, &write_file, fr);
    pthread_create(&read_th, NULL, &read_file, NULL);

    return 0;
}