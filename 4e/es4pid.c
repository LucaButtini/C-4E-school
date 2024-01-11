#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//  ./a.out | grep -c ciao
// la stampa 2^n fork
int p;
int main()
{
    p = fork();
    p = fork();
    p = fork();
    p = fork();
    p = fork();
    p = fork();
    printf("ciao\n");
    return 0;
}