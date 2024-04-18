#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int spawn(char program[], char *argument[])
{
    int pid;
    pid = fork(); // creo nuovo processo
    if (pid < 0)  // controllo se la fork ha fallito
        return -1;
    if (pid > 0)  // padre
        return 0; // il compito del padre della spawn è semplicemente di terminare la funzione, il produttore è il padre che continua fuori dallo spawn
    // figlio
    execv(program, argument); // eseguo il nuovo processo, argomenti nome programma e la sua riga di comando
    abort();                  // se l'esecuzione del nuovo processo fallisce, termino il processo figlio
}
int main(int argc, char *argv[])
{
    FILE *file;
    int fifo;
    unsigned char buffer[BLOCK_DIM];
    int n, a;
    char *arg[3];
    if (argc != 3)
    {
        printf("errore argomenti\n");
        exit(-1);
    }
    /*
    esempio:
    1) execl("/home/itis/lab/finestra", "finestra", "ciao", "4", NULL);
    char *mioarray[];
    mioarray[0] = "finestra";
    mioarray[1] = "ciao";
    ecc...
    mioarray[3] = NULL;
    2) execv("home/itis/lab/finestra", mioarray)

    la execv e execl sono la stessa cosa ma si chiamano differentemente
    */
    // eccetera ....
    return 0;
}