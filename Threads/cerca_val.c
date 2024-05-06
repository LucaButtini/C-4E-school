#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>
#define DIM_ARRAY 1000

int array[DIM_ARRAY];
int num;
void *first(void *s)
{
    int presente = 0;
    for (int i = 0; i < DIM_ARRAY / 4; i++)
    {
        if (array[i] == num)
        {
            printf("Il numero %d si trova in posizione: %d\n", num, i);
            presente++;
        }
    }
    if (presente == 0)
    {
        printf("Numero non presente nella prima metà\n");
    }
    return NULL;
}

void *second(void *s)
{
    int presente = 0;
    for (int i = DIM_ARRAY / 4; i < DIM_ARRAY / 2; i++)
    {
        if (array[i] == num)
        {
            presente++;
            printf("Il numero %d si trova in posizione: %d\n", num, i);
        }
    }
    if (presente == 0)
    {
        printf("Numero non presente nella seconda metà\n");
    }
    return NULL;
}

void *third(void *s)
{
    int presente = 0;
    for (int i = DIM_ARRAY / 2; i < (DIM_ARRAY / 2 + DIM_ARRAY / 4); i++)
    {
        if (array[i] == num)
        {
            printf("Il numero %d si trova in posizione: %d\n", num, i);
            presente++;
        }
        
    }
    if (presente == 0)
    {
        printf("Numero non presente nella terza metà\n");
    }
    return NULL;
}

void *fourth(void *s)
{
    int presente = 0;
    for (int i = (DIM_ARRAY / 2 + DIM_ARRAY / 4); i < DIM_ARRAY; i++)
    {
        if (array[i] == num)
        {
            printf("Il numero %d si trova in posizione: %d\n", num, i);
            presente ++;
        }
    }
    if (presente == 0)
    {
        printf("Numero non presente nella quarta metà\n");
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread_prima, thread_seconda, thread_terza, thread_quarta;
    printf("Inserire numero da ricercare: \n");
    scanf("%d", &num);
    for (int i = 0; i < DIM_ARRAY; i++)
    {
        int r = rand() % 500;
        array[i] = r;
    }
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