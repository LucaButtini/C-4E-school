#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int p1, p2, i;

int main(int argc, char *argv[])
{
    if (argc != 2) // controllo argomenti argc 2
    {
        printf("ERRORE ARGOMENTI \n");
        exit(1);
    }
    const int DIM = 10000;
    int inserito;    // inserito da utente
    int numeri[DIM]; // array numeri
    FILE *destinazione;
    for (i = 0; i < DIM; i++)
    {
        numeri[i] = rand() % 500 + 1; // Numero random nell'intervallo 1-500
    }
    destinazione = fopen("ripasso.txt", "w"); // apro il file
    for (i = 0; i < DIM; i++)
    {
        fprintf(destinazione, "[%d] --> %d\n", i, numeri[i]); // scrivo nel file i numeri
    }

    inserito = atoi(argv[1]); // converto in intero la stringa inserita da riga di comando

    p1 = fork(); // prima fork

    if (p1 != 0) // padre
    {
        // padre cerca nei primi 2000 numeri
        for (i = 0; i < 2000; i++)
        {
            if (numeri[i] == inserito)
            {
                printf("PID [%d], posizione [%d] --> %d\n", getpid(), i, numeri[i]);
            }
        }
        p2 = fork(); // seconda fork

        if (p2 == 0) // figlio 1
        {
            // figlio 1 cerca negli altri 4000
            for (i = 2000; i < 6000; i++)
            {
                if (numeri[i] == inserito)
                {
                    printf("PID [%d], posizione [%d] --> %d\n", getpid(), i, numeri[i]);
                }
            }
        }
        else // figlio 2
        {
            // figlio 2 cerca negli altri 4000
            for (i = 6000; i < DIM; i++)
            {
                if (numeri[i] == inserito)
                {
                    printf("PID [%d], posizione [%d] --> %d\n", getpid(), i, numeri[i]);
                }
            }
        }
    }
    return 0;
}
