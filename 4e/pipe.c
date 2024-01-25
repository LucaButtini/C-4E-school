#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
int main(int argc, char *argv[])
{
    // prima della fork creo la pipe
    int p, n;
    int fd[2]; // creo il file descriptor

    // passo alla pipe fd
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
        close(fd[0]); // chiudo in lettura. Uscita pipe

        const char *messaggio = "Buona fortuna\n"; // costante puntatore a caratteri, quindi messaggio è char buffer[BUFFER_SIZE]; un puntatore
        // 3 parametri: la scrittura, il messaggio e la lunghezza del messaggio

        if (write(fd[1], messaggio, strlen(messaggio)) == -1) // controllo che non ci siano errori in scrittura nella pipe
        {
            // se c'è errore nella pipe bisogna chiudere la pipe
            printf("erore di scrittura nella pipe\n");
            close(fd[1]);
            exit(-1);
        }
        close(fd[1]); // chiudo in scrittura

        wait(); // così il padre aspetta i figli
    }
    else // figlio
    {
        char buffer[BUFFER_SIZE]; // dichiaro buffer nel figlio dato che è usato solo qui
        printf("sono il figlio: il mio pid è %d, mio padre ha pid %d\n\n", getpid(), getppid());

        close(fd[1]);
        // passo 3 parametri: fd, buffer e la dim del buffer
        n = read(fd[0], buffer, BUFFER_SIZE);
        if (n == -1)
        {
            printf("erore di lettura nella pipe\n");
            close(fd[0]);
            exit(-1);
        }
        else
        {
            buffer[n] = '\0'; // assegno il carattere terminatore
            printf("messaggio letto: %s\n", buffer);
            close(fd[0]);
        }
    }

    return 0;
}