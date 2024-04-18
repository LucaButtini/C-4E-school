#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define DIM 10

void *ricerca_seconda(void *s)
{
    int *array = (int *)s;
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
    int *array = (int *)s;
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
    int array[DIM] = {8, 5, 2, 5, 6, 4, 8, 7, 8, 0}; // Array predefinito
    pthread_t tPrima, tSeconda;

    pthread_create(&tPrima, NULL, &ricerca_prima, (void *)array);
    pthread_create(&tSeconda, NULL, &ricerca_seconda, (void *)array);

    pthread_join(tPrima, NULL);
    pthread_join(tSeconda, NULL);

    return 0;
}
