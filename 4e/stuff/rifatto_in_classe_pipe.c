#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIM_ARRAY 5

int main(int argc, char *argv[])
{
    int p, fattore, status;
    int fd[2];
    if (pipe(fd) == -1)
    {
        printf("Errore creazione delle pipe\n");
        exit(-1);
    }
    p = fork();
    if (p < 0)
    {
        printf("Errore generazione del figlio\n");
        exit(-1);
    }
    else if (p > 0) // padre
    {

        printf("Sono il padre, mio pid: %d\n", getpid());
        close(fd[1]);
        wait(&status); // con la wait non si sincronizza la read e write essendo già esse sincrone, si usa per aspettare che il  figlio termini.
        // posso chiamarli con lo stesso nome essendo due processi differenti
        int insNumeri[DIM_ARRAY];
        printf("Inserisci un numero\n\n");
        scanf("%d", &fattore);
        read(fd[0], insNumeri, DIM_ARRAY * sizeof(int));
        close(fd[0]);
        printf("I risultati sono: \n");
        for (int i = 0; i < DIM_ARRAY; i++)
        {
            printf("%d\n", insNumeri[i] * fattore);
        }
        //wait(&status);
    }
    else // figlio
    {
        close(fd[0]);
        printf("Sono il figlio, mio pid: %d\n", getpid());
        int insNumeri[DIM_ARRAY]; // lo si fa qua dato che il figlio ha bisogno dell'array
        // se si genera in alto si crea una copia nel padre e figlio
        for (int i = 0; i < DIM_ARRAY; i++)
        {
            printf("Inserisci il numero %d\n", i + 1);
            scanf("%d", &insNumeri[i]);
        }

        write(fd[1], insNumeri, DIM_ARRAY * sizeof(int));
        close(fd[1]);
    }
    return 0;
}