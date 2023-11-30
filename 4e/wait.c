#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> //per la wait

int p, status; // status contiene un num intero
// sintassi della exit è "void exit(int status)"
int main(int argc, char *argv[])
{
    // il padre attende la terminazione del figlio, attende il primo che termina.
    p = fork();
    if (p == 0) // figlio
    {
        printf("1_ Sono il figlio, pid: %d\n", getpid());
        printf("2_ Sono il figlio e mio padre ha pid: %d\n", getppid());
        exit(25); // prima comunicazione fra figlio e padre
    }
    else // padre
    {
        printf("4_ Sono il padre, pid: %d\n", getpid());
    }
    return 0;
}