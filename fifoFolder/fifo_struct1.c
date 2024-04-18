#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
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
    strcpy(std.nome, "franco");
    strcpy(std.cognome, "capella");
    std.media = 9;
    fd = open("perver", O_WRONLY);
    write(fd, &std, sizeof(std));
    close(fd);
    return 0;
}