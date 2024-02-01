#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define DIM 5

int main(int argc, char *argv[])
{
    int p, n, j, status;
    int fd[2];
    int array[DIM];
    if (pipe(fd) == -1)
    {
        printf("errore creazione pipe\n");
        exit(-1);
    }
    p = fork();
    if (p < 0)
    {
        printf("errore generazione figlio\n");
    }
    if (p > 0) // padre
    {
        printf("\nsono il padre: il mio pid è %d, mio figlio ha pid %d\n\n", getpid(), p);
        wait(&status);

        close(fd[1]); // chiudo scrittura
        n = read(fd[0], array, DIM * sizeof(int));
        if (n == -1)
        {
            printf("erore di lettura nella pipe\n");
            close(fd[0]);
            exit(-1);
        }
        printf("Inserisci un numero\n");
        scanf("%d", &j);
        printf("====================\n");
        for (int i = 0; i < DIM; i++)
        {
            array[i] *= j;
            printf("\n%d\n", array[i]);
        }
        close(fd[0]); // chiudo in lettura. Uscita pipe
    }
    else
    {
        printf("sono il figlio: il mio pid è %d, mio padre ha pid %d\n\n", getpid(), getppid());
        for (int i = 0; i < DIM; i++)
        {
            printf("Inserisci il numero %d\n", i + 1);
            scanf("%d", &array[i]);
        }
        if (write(fd[1], array, DIM * sizeof(int)) == -1) 
        {
            printf("errore di scrittura nella pipe\n");
            close(fd[1]);
            exit(-1); 
        }

        close(fd[1]);
    }
    return 0;
}