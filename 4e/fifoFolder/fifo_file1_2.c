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

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("errore apertura file\n");
        exit(-1);
    }

    fd = open("verginita", O_WRONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        fclose(file);
        exit(-1);
    }

    while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0)
    {
        write(fd, buffer, n);
    }

    fclose(file);
    close(fd);

    return 0;
}
