#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#define DIM_ARRAY 5
// CONSUMATORE
int main(int argc, char *argv[])
{
    int fd, somma = 0;
    int numeri[DIM_ARRAY];
    fd = open("sum", O_RDONLY);

    read(fd, numeri, sizeof(numeri));
    for (int i = 0; i < DIM_ARRAY; i++)
    {
        somma += numeri[i];
    }
    printf("Somma dei numeri --> %d\n", somma);
    close(fd);
    return 0;
}