#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("sono il processo in esecuzione: mio pid %d\n", getpid());
    // il risultato è il contenuto della cartella nella quale c'è il programma
    // lanciamo un processo di linux, LS.
    // path del comando, il comando e tutti i flag del comando
    execl("/bin/ls", "ls", "-l", "-a", "-t", NULL);
    return 0;
}