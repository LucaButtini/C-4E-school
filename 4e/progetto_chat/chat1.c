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

int fd, p, n;
unsigned char buffer[DIM];
int main(int argc, char *argv[])
{
    do
    {

        p = fork();
        if (p < 0)
        {
            printf("errore generazione figlio\n");
            exit(-1);
        }
        if (p > 0) // padre
        {
            fd = open("fchat1", O_WRONLY);
            scanf("%s", buffer);
            n = write(fd, buffer, sizeof(buffer));
            if (n < 0)
            {
                printf("errore scrittura\n");
                exit(-1);
            }
            close(fd);
        }
        else // figlio
        {
            fd = open("fchat2", O_RDONLY);
            n = read(fd, buffer, sizeof(buffer));
            if (n < 0)
            {
                printf("errore lettura\n");
                exit(-1);
            }
            printf("%s", buffer);
            close(fd);
        }
    } while (1);
    return 0;
}