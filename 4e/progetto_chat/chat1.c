#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define DIM 1024

int fd, p, n;
char *message;

int main(int argc, char *argv[])
{
    message = (char *)malloc(DIM);

    do
    {
        p = fork();
        if (p < 0)
        {
            printf("errore generazione figlio\n");
            free(message);
            exit(-1);
        }

        if (p > 0)
        { // padre
            fd = open("fchat1", O_WRONLY);
            if (fd < 0)
            {
                printf("errore apertura file in scrittura\n");
                free(message);
                exit(-1);
            }
            printf("Inserisci un messaggio (o HALT per terminare): ");
            fgets(message, DIM, stdin);

            n = write(fd, message, strlen(message) + 1);
            if (n < 0)
            {
                printf("errore scrittura\n");
                free(message);
                exit(-1);
            }

            // Controllo per terminare il ciclo nel padre
            if (strcmp(message, "HALT\n") == 0)
            {
                printf("Chat terminata\n");
                free(message);
                close(fd);
                exit(0);
            }
        }
        else
        { // figlio
            fd = open("fchat2", O_RDONLY);
            if (fd < 0)
            {
                printf("errore apertura file in lettura\n");
                free(message);
                exit(-1);
            }

            n = read(fd, message, DIM);
            if (n < 0)
            {
                printf("errore lettura\n");
                free(message);
                exit(-1);
            }

            // Controllo per terminare il ciclo nel figlio
            if (strcmp(message, "HALT\n") == 0)
            {
                printf("Chat terminata\n");
                free(message);
                close(fd);
                exit(0);
            }
            printf("%s", message);
        }
    } while (1);

    return 0;
}
