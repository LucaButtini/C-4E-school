#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
typedef struct
{
    char nome[100];
    char cognome[100];
    int media;
} studente;
int fd;
int main(int argc, char *argv[])
{
    studente std;
    fd = open("perver", O_RDONLY);
    read(fd, &std, sizeof(std));
    printf("nome: %s, cognome: %s, media: %d\n", std.nome, std.cognome, std.media);
}