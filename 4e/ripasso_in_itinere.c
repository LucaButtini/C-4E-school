#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>
#define DIM 10000
// int p1, p2, i;
int p;
int main(int argc, char *argv[])
{
    if (argc != 2) // controllo argomenti argc 2
    {
        printf("ERRORE ARGOMENTI \n");
        exit(1);
    }
    int inserito;    // inserito da utente
    int numeri[DIM]; // array numeri
    FILE *destinazione;
    srand(time(NULL));
    for (int i = 0; i < DIM; i++)
    {
        numeri[i] = rand() % 501; // Numero random nell'intervallo 1-500
    }
    destinazione = fopen("ripasso.txt", "w"); // apro il file
    for (int i = 0; i < DIM; i++)
    {
        fprintf(destinazione, "[%d] --> %d\n", i, numeri[i]); // scrivo nel file i numeri. Passo il file 
    }
    fclose(destinazione);
    inserito = atoi(argv[1]); // converto in intero la stringa inserita da riga di comando
    p = fork();               // prima fork

    if (p > 0) // padre
    {
        // padre cerca nei primi 2000 numeri
        for (int i = 0; i < 2000; i++)
        {
            if (numeri[i] == inserito)
            {
                printf("PID [%d], posizione [%d] --> %d\n", getpid(), i, numeri[i]); // stampo pid del processo
            }
        }

        p = fork(); // seconda fork

        if (p == 0) // figlio 1
        {
            // figlio 1 cerca negli altri 4000
            for (int i = 2000; i < 6000; i++)
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
            for (int i = 6000; i < DIM; i++)
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
