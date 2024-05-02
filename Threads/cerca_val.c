#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#define DIM_ARRAY 1000

int array[DIM_ARRAY];
int main(int argc, char *argv[])
{
    
    for (int i = 0; i < DIM_ARRAY; i++)
    {
        array[i] = rand() % 501;
    }
    for (int i = 0; i < DIM_ARRAY; i++)
    {
        printf("[%d] --> %d\n", i, array[i]);
    }
    return 0;
}