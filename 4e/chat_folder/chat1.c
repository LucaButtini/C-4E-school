#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define DIM_STR 50
#define RED "\e[0;31m"
#define BLUE "\x1b[34m"
int fd, p, n;
char *message;
int main(int argc, char *argv[])
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
        message = malloc(DIM_STR);
        while (1)
        {
            printf(BLUE "User 1: ");
            fgets(message, DIM_STR, stdin);
            n = write(fd, message, DIM_STR);
            if (n < 0)
            {
                printf("errore in scrittura\n");
                exit(-1);
                free(message);
                close(fd);
            }
            if (strcmp(message, "HALT\n") == 0)
            {
                close(fd);
                free(message);
                exit(1);
            }
        }
    }
    else // figlio
    {
        fd = open("fchat2", O_RDONLY);
        message = malloc(DIM_STR);
        n = read(fd, message, DIM_STR);
        if (n < 0)
        {
            printf("errore in lettura\n");
            exit(-1);
            free(message);
            close(fd);
        }
        printf(RED "User 2: %s", message);
        if (strcmp(message, "HALT\n") == 0)
        {
            close(fd);
            free(message);
            exit(1);
        }
    }
    return 0;
}