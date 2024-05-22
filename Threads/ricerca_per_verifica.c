#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define DIM_ARRAY 100

typedef struct {
  int numeri[DIM_ARRAY];
  int n_ricercato;
} arr_str;

arr_str arr_numeri;

void *ricerca1(void *arg) {
  for (int i = 0; i < DIM_ARRAY / 2; i++) {
    if (arr_numeri.numeri[i] == arr_numeri.n_ricercato) {
      printf("Numero %d trovato in posizione %d\n", arr_numeri.n_ricercato, i);
      pthread_exit(NULL);
    } 
  }
  pthread_exit(NULL);
}

void *ricerca2(void *arg) {
  for (int i = DIM_ARRAY / 2; i < DIM_ARRAY; i++) {
    if (arr_numeri.numeri[i] == arr_numeri.n_ricercato) {
      printf("Numero %d trovato in posizione %d\n", arr_numeri.n_ricercato, i);
      pthread_exit(NULL);
    } 
  }
  pthread_exit(NULL); 
}

int main(int argc, char *argv[]) {
  FILE *f;
  pthread_t cerca1_t, cerca2_t;
  if (argc != 3) {
    printf("errore parametri\n");
    return -1;
  }
  f = fopen(argv[1], "a");
  if (f == NULL) {
    printf("errore apertura file\n");
    return -1;
  }
  arr_numeri.n_ricercato = atoi(argv[2]);

  for (int i = 0; i < DIM_ARRAY; i++) {
    arr_numeri.numeri[i] = rand() % 100;
    fprintf(f,"\nNumero %d in posizione %d\n", arr_numeri.n_ricercato, arr_numeri.numeri[i]);
  }

  pthread_create(&cerca1_t, NULL, &ricerca1, NULL);
  pthread_create(&cerca2_t, NULL, &ricerca2, NULL);
  pthread_join(cerca1_t, NULL);
  pthread_join(cerca2_t, NULL);

  fclose(f);
  return 0;
}
