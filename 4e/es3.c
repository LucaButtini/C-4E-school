#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int qui, quo, qua;

int main()
{
    // Genera il primo figlio (Qui)
    qui = fork();

    if (qui < 0)
    {
        printf("Errore nella generazione di Qui\n");
        exit(1);
    }
    else if (qui > 0)
    {
        // Codice del padre
        printf("Sono il padre A, il mio PID = %d\n", getpid());
        printf("Sono il figlio QUI, il mio PID = %d\n", qui);

        // Genera il secondo figlio (Quo)
        quo = fork();

        if (quo < 0)
        {
            printf("Errore nella generazione di Quo\n");
            exit(1);
        }
        else if (quo > 0)
        {
            // Codice del padre
            printf("Sono il figlio QUO, il mio PID = %d\n", quo);

            // Genera il terzo figlio (Qua)
            qua = fork();

            if (qua < 0)
            {
                printf("Errore nella generazione di Qua\n");
                exit(1);
            }
            else if (qua > 0)
            {
                // Codice del padre
                printf("Sono il figlio QUA, il mio PID = %d\n", qua);
            }
            else
            {
                // Codice del figlio Qua
                printf("Sono il figlio QUA, il mio PID = %d\n", getpid());
            }
        }
        else
        {
            // Codice del figlio Quo
            printf("Sono il figlio QUO, il mio PID = %d\n", getpid());
        }
    }
    else
    {
        // Codice del figlio Qui
        printf("Sono il figlio QUI, il mio PID = %d\n", getpid());
    }

    return 0;
}


//si stampano più volte dato che si sovrappongono i processi