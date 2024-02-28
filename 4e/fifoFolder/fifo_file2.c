
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#define DIM 1024
int fd, n;
FILE *file;
unsigned char buffer[DIM];
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("errore args\n");
        exit(-1);
    }
    file = fopen(argv[1], "w");
    if (file == NULL)
    {
        printf("errore apertura file\n");
        exit(-1);
    }
    fd = open("verginita", O_WRONLY);
    while (n = read(fd, buffer, sizeof(buffer)) > 0)
    {
        fwrite(buffer, 1, n, file);
    }
    fclose(file);
    close(fd);
    return 0;
}