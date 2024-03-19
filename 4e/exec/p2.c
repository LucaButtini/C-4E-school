#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

typedef struct
{
    char nome[100];
    char cognome[100];
    int eta;
} studente;

int main(int argc, char *argv[])
{
    printf("\nDATI:\n");
    printf("NOME: %s\n", argv[1]);
    printf("COGNOME: %s\n", argv[2]);
    printf("ETA': %s\n", argv[3]);
    return 0;
}
