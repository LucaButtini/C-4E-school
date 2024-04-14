#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int p1, p2;
int main()
{

    p1 = fork(); // Genera il primo figlio

    if (p1 < 0)
    {
        printf("Errore nella generazione del primo figlio\n");
        exit(1);
    }
    else if (p1 > 0)
    {
        // Codice del padre
        printf("Sono il padre, il mio PID è %d\n", getpid());
        printf("Il PID del primo figlio è %d\n", p1);

        // Genera il secondo figlio
        p2 = fork();

        if (p2 < 0)
        {
            printf("Errore nella generazione del secondo figlio\n");
            exit(1);
        }
        else if (p2 > 0)
        {
            // Codice del padre
            printf("Il PID del secondo figlio è %d\n", p2);
        }
        else
        {
            // Codice del secondo figlio
            printf("Sono il secondo figlio, il mio PID è %d\n", getpid());
            printf("Il PID del mio padre è %d\n", getppid());
        }
    }
    else
    {
        // Codice del primo figlio
        printf("Sono il primo figlio, il mio PID è %d\n", getpid());
        printf("Il PID del mio padre è %d\n", getppid());
    }

    return 0;
}

//non stampa sempre il pid del padre dal figlio