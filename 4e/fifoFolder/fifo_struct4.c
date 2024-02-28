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

    fd = open("prova", O_RDONLY);

    for (int i = 0; i < DIM_ARRAY; i++)
    {
        read(fd, &scuola[i], sizeof(studente));
    }

    close(fd);

    for (int i = 0; i < DIM_ARRAY; i++)
    {
        printf("nome: %s, cognome: %s, voto: %d\n", scuola[i].nome, scuola[i].cognome, scuola[i].voto);
    }

    return 0;
}
