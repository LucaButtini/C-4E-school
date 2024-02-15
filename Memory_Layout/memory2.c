#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int global = 130;
int global2;
int main(int argc, char *argv[])
{
    // dentro l'SO per ogni processo c'è un file che descrive la sua memoria dinamica
    // possiamo vederlo come un file di log
    // cat /proc/pid
    //-----------------------------------------------------------------------
    // 7fffcacaa000-7fffcaccb000                       [stack]
    // indica fine e inizio dello stack
    /// usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 --> sono librerie dinamiche
    int a;
    while (1)
    {
        printf("%d\n", getpid());
        printf("%p\n", &a);
        sleep(1);
    }
    return 0;
}