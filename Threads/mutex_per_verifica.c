#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

#define DIM_SLICE 64
#define N_SLICES 16

typedef struct {
  unsigned char buffer[DIM_SLICE];
  int n;
} buffer_str;

buffer_str buffer_ring[N_SLICES];
int read_index, write_index;
int n_block;
FILE *origine, *destinazione;
pthread_mutex_t mutex;
pthread_cond_t not_empty, not_full;


int main(int argc, char *argv[]) {

  pthread_t t_write, t_read;

  if (argc != 3) {
    printf("errore argomenti\n");
    return 0;
  }

  return 0;
}