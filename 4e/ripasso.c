#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    const int DIM = 10000;
    int numeri[DIM];
    int i;

    // var per il random
    time_t t;
    srand((unsigned)time(&t));

    FILE *fileDestinazione; // Dichiarazione di un puntatore a un oggetto di tipo FILE

    for (i = 0; i < DIM; i++)
    {
        numeri[i] = rand() % 501; // generazione numeri random
    }

    fileDestinazione = fopen("numeri.txt", "w");

    if (fileDestinazione == NULL) // Verifica se l'apertura del file ha avuto successo
    {
        printf("Impossibile aprire il file"); // Stampa un messaggio di errore
        exit(1);                              // Termina il programma con codice di uscita 1, errore
    }

    for (int i = 0; i < DIM; i++)
    {
        fprintf(fileDestinazione, "%d\n", numeri[i]);
        // fwrite(numeri, sizeof(int), DIM, fileDestinazione);
    }

    fclose(fileDestinazione);
    return 0;
}
