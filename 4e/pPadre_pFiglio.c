#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// restituisce un val intero.
// p nel padre = PID figlio
// p nel figlio=0
// è dichiarata a livello locale e permette di gestire il padre e figlio
// il codice del padre è condiviso con il figlio, tutto ciò che è presente nel padre sarà presente nel figlio. Sono indipendenti, zone di memoria differente
int p;

int main()
{
    p = fork(); // restituisce un intero
    // padre genera un figlio, anche i figli possono generare altri figli
    return 0;
}
