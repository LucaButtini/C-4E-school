#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fileOrigine;  // Dichiarazione di un puntatore a un oggetto di tipo FILE

    fileOrigine = fopen("nomeFile.txt", "r");  // Apre il file in modalità lettura 

    if (fileOrigine == NULL)  // Verifica se l'apertura del file ha avuto successo
    {
        printf("Impossibile aprire il file");  // Stampa un messaggio di errore
        exit(1);  // Termina il programma con codice di uscita 1 indicando un errore
    }
    else
    {
        printf("File aperto");  // Stampa un messaggio che dice che il file è stato aperto con successo
    }

    fclose(fileOrigine);  // Chiude il file

    if (fclose(fileOrigine) == 0)  // Tentativo di chiusura del file e verifica se la chiusura ha avuto successo
        printf("\nChiusura del file avvenuta con successo");  // Stampa un messaggio di chiusura riuscita
    else
        printf("\nChiusura del file fallita");  // Stampa un messaggio di chiusura fallita

    return 0;  // Termina il programma restituendo 0 indicando una terminazione corretta
}
