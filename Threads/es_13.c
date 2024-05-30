#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

// array come ring buffer
int buffer_ring[BUFFER_SIZE];
// flag per la fine dell'inserimento
bool flag = false;
int write_index=0, read_index=0;
// var condivise
int n_block=0, n=0;
// variabili mutex e di condizione
pthread_mutex_t mutex;
pthread_cond_t not_empty, not_full;

// funzione di generazione dei numeri e inserimento nell'array
void *f_generate(void *arg)
{
    while (n > 0)
    {
        // blocco la sezione critica
        pthread_mutex_lock(&mutex);
        // aspetto se il buffer è pieno
        if (n_block >= BUFFER_SIZE)
            pthread_cond_wait(&not_full, &mutex);

        buffer_ring[write_index] = rand() % 100;
        // decremento n
        n--;
        // sezione successiva del buffer ring
        write_index = (write_index + 1) % BUFFER_SIZE;
        // aumento il numero di blocchi
        n_block++;
        // avviso che non il ring buffer non è vuoto
        pthread_cond_signal(&not_empty);
        // sblocco la sezione critica
        pthread_mutex_unlock(&mutex);
    }
    // flag di fine
    flag = true;
    // avviso se il consumatore è in attesa
    pthread_cond_signal(&not_empty);
    pthread_exit(NULL);
}
void *f_print(void *arg)
{
    while (!flag || n_block > 0)
    {
        // blocco sezione critica
        pthread_mutex_lock(&mutex);
        if (n_block > 0)
        {
            // visualizzazione numero casuale nel buffer
            printf("%d\n", buffer_ring[read_index]);
            // sezione successiva del buffer
            read_index = (read_index + 1) % BUFFER_SIZE;
            // decremeta il numero di blocchi
            n_block--;
            // avviso che il buffer non è pieno
            pthread_cond_signal(&not_full);
        }
        else
        {
            // aspetto che il buffer non sia vuoto
            pthread_cond_wait(&not_empty, &mutex);
        }
        // sblocco la sezione critica
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    if (argc != 2)
    {
        printf("errore argomenti\n");
        return -1;
    }
    n = atoi(argv[1]);
    pthread_create(&t1, NULL, &f_generate, NULL);
    pthread_create(&t2, NULL, &f_print, NULL);
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&not_empty, NULL);
    pthread_cond_init(&not_full, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&not_empty);
    pthread_cond_destroy(&not_full);
    return 0;
}
