#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>

#define DIM_SLICE 64
#define N_SLICES 16

// struttura buffer
typedef struct {
  unsigned char buffer[DIM_SLICE];
  // byte effettivamente scritti
  int n;
} buffer_str;

buffer_str buffer_ring[N_SLICES];
// indici lettura, scrittura, contatore di slice
int read_index, write_index, slice_count;
// flag per la fine della lettura
bool end_flag = false;
// variabile mutex
pthread_mutex_t mutex;
// variabili di condizione
pthread_cond_t not_empty, not_full;
// puntatori a file origine e destinazione
FILE *origine, *destinazione;

// funzione thread di lettura
void *read_file(void *arg) {
  int n;
  while (!feof(origine)) {
    // blocco la sezione critica
    pthread_mutex_lock(&mutex);
    // attendo se il ring è pieno segnalando all'altro thread la situazione del
    // buffer
    if (slice_count > N_SLICES)
      pthread_cond_wait(&not_full, &mutex);
    // leggo i dati dal file di origine
    n = fread(buffer_ring[write_index].buffer, 1, DIM_SLICE, origine);
    if (n > 0) {
      // aggiorno il numero di dati letti
      buffer_ring[write_index].n = n;
      // passa alla sezione successiva del ring buffer
      write_index = (write_index + 1) % N_SLICES;
      // incremento contatore numero di blocchi
      slice_count++;
      // ring buffer non e più vuoto
      pthread_cond_signal(&not_empty);
    }
    // sblocco la sezione critica
    pthread_mutex_unlock(&mutex);
  }
  // fine lettura
  end_flag = true;
  pthread_cond_signal(&not_empty);
  pthread_exit(NULL);
}

void *write_file(void *arg) {
  // controllo se lettura è terminata e non ci sono più blocchi nel ring buffer
  while (1) {
    if (end_flag && slice_count == 0)
      break;
    // blocco sezione critica
    pthread_mutex_lock(&mutex);
    // controllo se ci sono blocchi
    if (slice_count > 0) {
      // scrittura nel file di destinazione
      fwrite(buffer_ring[read_index].buffer, 1, buffer_ring[read_index].n, destinazione);
      // sezione succesiva del ring buffer
      read_index = (read_index + 1) % N_SLICES;
      // decremento numero di blocchi
      slice_count--;
      // ring buffer non è pieno
      pthread_cond_signal(&not_full);
    } else {
      // attendo che il ring buffer sia vuoto
      pthread_cond_wait(&not_empty, &mutex);
    }
    // sblocco la sezione critica
    pthread_mutex_unlock(&mutex);
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  // varibili di tipo thread
  pthread_t t_write, t_read;
  // controllo numero argomenti
  if (argc != 3) {
    printf("errore argomenti\n");
    return 0;
  }
  // controllo corretta apertura del file di origine e di destinazione
  origine = fopen(argv[1], "rb");
  if (origine == NULL) {
    printf("errore apertura file di origine\n");
    return -1;
  }
  destinazione = fopen(argv[2], "wb");
  if (destinazione == NULL) {
    printf("errore apertura file di destinazione\n");
    fclose(origine);
    return -1;
  }
  // creazione thread scrittura e lettura
  pthread_create(&t_read, NULL, &read_file, NULL);
  pthread_create(&t_write, NULL, &write_file, NULL);
  // creazione mutex e condizioni
  pthread_mutex_init(&mutex, NULL);
  pthread_cond_init(&not_empty, NULL);
  pthread_cond_init(&not_full, NULL);
  // join dei thread per aspettare che termino l'esecuzione
  pthread_join(t_read, NULL);
  pthread_join(t_write, NULL);
  // distruzione mutex e cond
  pthread_mutex_destroy(&mutex);
  pthread_cond_destroy(&not_empty);
  pthread_cond_destroy(&not_full);
  // chiusura file origine e destinazione
  fclose(origine);
  fclose(destinazione);
  return 0;
}