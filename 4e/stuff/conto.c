#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*Scrivi il codice
sorgente di un programma che permette al processo padre di generare un processo
figlio.

Sia il processo padre
e sia il processo figlio visualizzano ciascuno il proprio PID e il PID del
proprio parente.

Padre conta da 0 a
19.

Figlio conta da 0 a
9.

Manda in esecuzione
più volte e osserva il comportamento del programma in esecuzione.*/

int p;

int main(int argc, char *argv[])
{
    p = fork();
    if (p < 0)
    {
        printf("Il processo figlio non è stato generato\n");
        exit(1);
    }
    else if (p > 0)
    {
        // padre
        printf("Il mio pid è: %d\n", getpid());
        printf("Mio figlio ha pid : %d\n\n", p);
        // conto del padre
        for (int i = 0; i <= 50; i++)
        {
            printf("padre %d\n", i);
        }
    }
    else
    {
        // figlio
        printf("\nIl mio pid è: %d\n", getpid());
        printf("Mio padre ha pid : %d\n\n", getppid());
        // conto del figlio
        for (int i = 0; i <= 20; i++)
        {
            printf("figlio %d\n", i);
        }
    }

    return 0;
}