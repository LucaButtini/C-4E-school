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

int p, n;
int fd[2];
FILE *origine, *destinazione;
unsigned char buffer[DIM];
int main(int argc, char *argv[])
{
    if (pipe(fd) < 0)
    {
        printf("errore creazione pipe\n");
        exit(-1);
    }
    p = fork();
    if (p < 0)
    {
        printf("errore creazione figlio\n");
        exit(-1);
    }
    if (p > 0) // processo padre
    {
        if (argc != 3)
        {
            printf("errore numero parametri\n");
            exit(-1);
        }
        close(fd[0]);
        origine = fopen(argv[1], "r");
        if (origine == NULL)
        {
            printf("errore apertura file\n");
            exit(-1);
        }
        while ((n = fread(buffer, 1, sizeof(buffer), origine)) > 0)
        {
            write(fd[1], buffer, n);
        }
        fclose(origine);
        close(fd[0]);
    }
    else // figlio
    {
        close(fd[1]);
        destinazione = fopen(argv[2], "w");
        if (destinazione == NULL)
        {
            printf("errore apertura file\n");
            close(fd[0]);
            exit(-1);
        }
        while ((n = read(fd[0], buffer, sizeof(buffer))) > 0)
        {
            fwrite(buffer, 1, n, destinazione);
        }
        fclose(destinazione);
        close(fd[0]);
        return 0;
    }
}