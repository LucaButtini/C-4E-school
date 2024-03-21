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

int main(int argc, char *argv[])
{
    // guarda libro per completare se non ho finito il codice
    FILE *file;
    int fifo, n;
    char *args[3];
    unsigned char buffer[BLOCK_DIM];
    return 0;
}