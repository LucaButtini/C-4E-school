#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#define DIM_ARRAY 5
// PRODUTTORE
int main(int argc, char *argv[])
{
    int fd; // file descriptor (handle) dell'array

    srand(time(NULL));
    int numeri[DIM_ARRAY];
    for (int i = 0; i < DIM_ARRAY; i++)
    {
        numeri[i] = rand() % 100;
        printf("Numero [%d] --> %d\n", i + 1, numeri[i]);
    }

    fd = open("sum", O_WRONLY);
    write(fd, numeri, sizeof(numeri));
    close(fd);
    return 0;
}