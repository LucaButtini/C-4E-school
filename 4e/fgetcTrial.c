#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fileOrigine;  // Dichiarazione di un puntatore a un oggetto di tipo FILE
    char c;  // Dichiarazione di una variabile di tipo char per memorizzare i caratteri letti

    fileOrigine = fopen("nomi.txt", "r");  // Apre il file in modalità lettura 

    if (fileOrigine == NULL)  // Verifica se l'apertura del file ha avuto successo
    {
        printf("Impossibile aprire il file");  // Stampa un messaggio di errore
        exit(1);  // Termina il programma con codice di uscita 1 indicando un errore
    }
    else
    {
        c = fgetc(fileOrigine);  // Legge il primo carattere dal file
        while (c != EOF)  // Ciclo che continua finché non si raggiunge la fine del file (EOF)
        {
            putchar(c);  // Stampa il carattere sul monitor
            c = fgetc(fileOrigine);  // Legge il carattere successivo dal file
        }

        if (fclose(fileOrigine) == 0)  // Chiude il file e verifica se la chiusura ha avuto successo
            printf("\n\nChiusura del file avvenuta con successo");  // Stampa un messaggio di chiusura riuscita
        else
            printf("\n\nChiusura del file fallita");  // Stampa un messaggio di chiusura fallita
    }

    return 0;  // Termina il programma restituendo 0 indicando una terminazione corretta
}
