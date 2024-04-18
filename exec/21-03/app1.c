#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

#define BLOCK_DIM 1024
// #define BLOCK_DIM 128 dimostro che funziona anche a blocchi più piccoli
#define PROGRAM "./app2"

// creo la funzione spawn
int spawn(char program[], char *args[])
{
    int p;
    printf("\nsono padre spawn, pid: %d\n", getpid());
    p = fork();
    if (p < 0)
    {
        return -1;
    }
    else if (p > 0)
    {
        printf("\nsono padre spawn, mio figlio ha pid: %d\n", p);
        return 0;
    }
    else
        printf("\nsono figlio, pid: %d\n", getpid());

    execv(program, args);
    printf("\nerrore esecuzione programma\n");
    abort();
}
int main(int argc, char *argv[])
{
    // pag 181 a 184 come riferimento dell'esercizio
    FILE *file;
    int fifo, n;
    char *args[3];
    unsigned char buffer[BLOCK_DIM];
    printf("\nsono padre, pid: %d\n", getpid());
    if (argc != 3)
    {
        printf("\nerrore argomenti\n");
        exit(-1);
    }
    // args contiene consumatore, destinazione.txt, NULL
    //-------------------------------
    // sto creando la riga di comando che passerò al figlio
    // ho costruito la linea di comando per mandare in esecuzione il consumatore
    args[0] = (char *)malloc(strlen(PROGRAM) + 1);
    strcpy(args[0], PROGRAM);
    args[1] = (char *)malloc(strlen(argv[2] + 1));
    strcpy(args[1], argv[2]);
    args[2] = NULL;
    if (spawn(PROGRAM, args) < 0)
    {
        free(args[0]);
        free(args[1]);
        exit(-1);
    }
    // guardo cosa contiene args[0]
    printf("\nargs[0] --> %S\n", args[0]);
    // creo la fifo e controllo la corretta creazione
    if (mkfifo("my_fifo", 0777) == -1)
    {
        if (errno != EEXIST)
            printf("\nerrore creazione fifo\n");
        exit(-1);
    }
    fifo = open("my_fifo", O_WRONLY);
    if (fifo < 0)
    {
        printf("\nerrore apertura fifo\n");
        free(args[0]);
        free(args[1]);
        exit(-1);
    }
    file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("\nerrore apertura file\n");
        close(fifo);
        free(args[0]);
        free(args[1]);
        exit(-1);
    }
    while (!feof(file))
    {
        n = fread(buffer, 1, sizeof(buffer), file);
        if (n > 0)
            write(fifo, buffer, n);
    }
    close(fifo);
    fclose(file);
    free(args[0]);
    free(args[1]);
    return 0;
}