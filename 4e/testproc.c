#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int p;
int main(int argc, char *argv[])
{
    p = fork();

    if (p > 0)
        printf("padre: %d, mio padre pid %d\n", getpid(), getppid());
    else
        printf("figlio %d, mio pid %d, mio padre pid %d\n", getpid(), p, getppid());
    return 0;
}