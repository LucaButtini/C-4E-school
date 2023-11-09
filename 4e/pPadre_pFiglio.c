#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// restituisce un val intero.
// p nel padre = PID figlio
// p nel figlio=0
// è dichiarata a livello locale e permette di gestire il padre e figlio
// il codice del padre è condiviso con il figlio, tutto ciò che è presente nel padre sarà presente nel figlio. Sono indipendenti, zone di memoria differente
// anche i figli possono generare altri figli
// il p del padre è uguale a quello del figlio
// tutti i processi in Linux hanno un padre, tranne quello Init lanciato dal kernel e serve per inizializzare il sistema operativo
int p;

int main()
{
    // la fork crea una copia del codice, hanno i PID diversi
    p = fork(); // restituisce un intero
    if (p != 0) // siamo nel padre
    {
        printf("\nIo sono il padre, p=%d, PID=%d, mio padre ha PID uguale %d \n", p, getpid(), getppid()); // funzione getpid permette di ottenere la visualizzazione del PID. Il padre del padre è il terminale, la shell bash.
        }
    else // figlio
    {
        printf("\nIo sono il figlio, p=%d, PID=%d, mio padre ha PID uguale %d\n", p, getpid(), getppid()); // funzione getppid restituisce pid del padre
    }
    return 0;
}
