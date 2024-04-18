#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define DIM 10

int array[DIM] = {8, 5, 2, 5, 6, 4, 8, 7, 8, 0}; // Array predefinito in visualizzazione globale

void *ricerca_seconda(void *s)
{
    // Esegue la ricerca nella seconda metà dell'array
    for (int i = DIM / 2; i < DIM; i++)
    {
        if (array[i] == 8)
        {
            printf("Il numero 8 si trova nella seconda metà dell'array, in posizione: %d\n", i);
        }
    }
    pthread_exit NULL;
}

void *ricerca_prima(void *s)
{
    // Esegue la ricerca nella prima metà dell'array
    for (int i = 0; i < DIM / 2; i++)
    {
        if (array[i] == 8)
        {
            printf("Il numero 8 si trova nella prima metà dell'array, in posizione: %d\n", i);
        }
    }
    pthread_exit NULL;
}

int main()
{
    pthread_t tPrima, tSeconda;
    pthread_create(&tPrima, NULL, &ricerca_prima, array);
    pthread_create(&tSeconda, NULL, &ricerca_seconda, array);
    pthread_join(tPrima, NULL);
    pthread_join(tSeconda, NULL);

    return 0;
}
