#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int p, n;

int main(int argc, char *argv[])
{
    printf("Inserisci un numero: ");
    scanf("%d", &n);
    p = fork();
    if (p != 0)
    {
        n += 10;
        printf("\npadre PID %d, n: %d\n", getpid(), n);
    }
    else if (p == 0)
    {
        n += 5;
        printf("\nfiglio PID %d, n: %d\n\n", getpid(), n);
    }
    return 0;
}