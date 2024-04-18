#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#define DIM_ARRAY 2
typedef struct
{
    char nome[100];
    char cognome[100];
    int voto;
} studente;
int fd;
int main(int argc, char *argv[])
{
    studente scuola[DIM_ARRAY];
    strcpy(scuola[0].nome, "nome1");
    strcpy(scuola[0].cognome, "cognome1");
    scuola[0].voto = 8;
    strcpy(scuola[1].nome, "nome2");
    strcpy(scuola[1].cognome, "cognome2");
    scuola[1].voto = 9;
    fd = open("prova", O_WRONLY);
    for (int i = 0; i < DIM_ARRAY; i++)
    {
        write(fd, &scuola[i], sizeof(studente));
    }
    printf("Scrittura avvenuta\n");
    close(fd);
    return 0;
}