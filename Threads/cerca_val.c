#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#define DIM_ARRAY 1000

int array[DIM_ARRAY];
int numero;
void *first(void *s)
{
    for (int i = 0; i < DIM_ARRAY / 4; i++)
    {
        if (array[i] == numero)
        {
           printf("Il numero [%d] in posizione --> %d\n", numero, i);
        }
    }
    pthread_exit(NULL);
}

void *second(void *s)
{
    for (int i = DIM_ARRAY / 4; i < DIM_ARRAY / 2; i++)
    {
        if (array[i] == numero)
        {
            printf("Il numero [%d] in posizione --> %d\n", numero, i);
        }
    }
    pthread_exit(NULL);
}
void *third(void *s)
{
    for (int i = DIM_ARRAY / 2; i < (DIM_ARRAY / 2 + DIM_ARRAY / 4); i++)
    {
        if (array[i] == numero)
        {
            printf("Il numero [%d] in posizione --> %d\n", numero, i);
        }
        
    }
   pthread_exit(NULL);
}

void *fourth(void *s)
{
    for (int i = (DIM_ARRAY / 2 + DIM_ARRAY / 4); i < DIM_ARRAY; i++)
    {
        if (array[i] == numero)
        {
            printf("Il numero [%d] in posizione --> %d\n", numero, i);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t thread_prima, thread_seconda, thread_terza, thread_quarta;
    for (int i = 0; i < DIM_ARRAY; i++)
    {
        array[i] = rand() % 500;
    }
    printf("Inserire numero da cercare: \n");
    scanf("%d", &numero);
    pthread_create(&thread_prima, NULL, &first, NULL);
    pthread_create(&thread_seconda, NULL, &second, NULL);
    pthread_create(&thread_terza, NULL, &third, NULL);
    pthread_create(&thread_quarta, NULL, &fourth, NULL);
    pthread_join(thread_prima, NULL);
    pthread_join(thread_seconda, NULL);
    pthread_join(thread_terza, NULL);
    pthread_join(thread_quarta, NULL);
    return 0;
}