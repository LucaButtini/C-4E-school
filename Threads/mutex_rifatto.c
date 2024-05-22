#include <pthread.h>
#include <stdio.h>
#include <time.h>

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
FILE *origine, *destinazione;

void *write_file(void *arg) {
  while (1) {

    pthread_mutex_lock(&mutex);
    if (n_slices > 0) {
      fwrite(buffer[read_index].buffer_in_str, 1, buffer[read_index].n,(FILE *)arg);
      read_index = (read_index + 1) % NUM_SLICES;
      n_slices--;
    } else {
      pthread_cond_wait(&not_empty, &mutex);
    }
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&not_full);
  }
  pthread_exit(NULL);
}

void *read_file(void *arg) {
  int n; // registro numero dati effettivamente letti, questa "n" è nello stack
  while (!feof(origine)) {

    pthread_mutex_lock(&mutex);

    if (n_slices >= NUM_SLICES)

      pthread_cond_wait(&not_full, &mutex);

    n = fread(buffer[write_index].buffer_in_str, 1, SLICE_DIM, (FILE *)arg);

    if (n > 0) {
      buffer[write_index].n = n;

      write_index = (write_index + 1) % NUM_SLICES;

      n_slices++;

      pthread_cond_signal(&not_empty);
    }
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Uso: %s file-origine file-destinazione\r\n", argv[0]);
    return 0;
  }
  origine = fopen(argv[1], "rb");
  if (origine == NULL) {
    printf("Errore apertura file %s\r\n", argv[1]);
    return 0;
  }
  destinazione = fopen(argv[2], "wb");
  if (destinazione == NULL) {
    printf("Errore apertura file %s\r\n", argv[2]);
    fclose(origine);
    return -1;
  }
  pthread_t write_th, read_th;
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&not_full, NULL);
  pthread_cond_init(&not_empty, NULL);
  pthread_create(&write_th, NULL, &write_file, NULL);
  pthread_create(&read_th, NULL, &read_file, NULL);
  pthread_join(read_th, NULL);
  pthread_join(write_th, NULL);
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&not_full);
  pthread_cond_destroy(&not_empty);
  fclose(origine);
  fclose(destinazione);

  return 0;
}