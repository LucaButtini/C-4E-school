#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERRORE ARGOMENTI \n");
        exit(1);
    }
    int n;             // inserito dall'utente da riga di comando e deve essere ricercato nell'array
    int numeri[10000]; // array da 10k
    FILE *destinazione;
    int p;
    int status;
    for (int i = 0; i < 10000; i++)
    {
        numeri[i] = rand() % 501; // genera numero casuale
    }
    destinazione = fopen("numeri.txt", "w");
    for (int i = 0; i < 10000; i++)
    {
        fprintf(destinazione, "%d: %d \n", i, numeri[i]);
    }
    n = atoi(argv[1]); //converto stringa in intero
    p = fork();
    if (p == 0) // padre
    {
        int p1;
        p1 = fork();
        for (int i = 0; i < 2000; i++) // ricerca nei primi 2000
        {
            if (n == numeri[i])
            {
                printf("PID: %d indice: %d n: %d \n", getpid(), i, numeri[i]);
            }
        }
        if (p1 != 0) // figlio 2
        {
            for (int i = 1999; i < 5999; i++)
            {
                if (n == numeri[i])
                {
                    printf("PID: %d indice: %d n: %d \n", getpid(), i, numeri[i]);
                }
            }
        }
    }
    else // figlio 1
    {
        for (int i = 5999; i < 9999; i++)
        {
            if (n == numeri[i])
            {
                printf("PID: %d indice: %d n: %d \n", getpid(), i, numeri[i]);
            }
        }
    }
    return 0;
}
