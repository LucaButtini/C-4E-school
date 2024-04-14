
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 20 // Definizione di una costante MAX_STR con valore 20
#define qtaNomi 4  // Definizione di una costante qtaNomi con valore 4
int i;             // Dichiarazione di una variabile intera i

int main()
{
    FILE *fileDestinazione; // Dichiarazione di un puntatore a un oggetto di tipo FILE
    char vett[MAX_STR];     // Dichiarazione di un array di caratteri chiamato vett con dimensione MAX_STR

    fileDestinazione = fopen("nomi.txt", "w"); // Apre il file in modalità scrittura
    if (fileDestinazione == NULL)              // Verifica se l'apertura del file ha avuto successo
    {
        printf("Impossibile aprire il file"); // Stampa un messaggio di errore
        exit(1);                              // Termina il programma con codice di uscita 1, errore
    }
    else
    {
        for (i = 0; i < qtaNomi; i++) //  for da 0 a qtaNomi
        {
            printf("Inserisci il %d^ nome   >>   ", i + 1); // messaggio
            scanf("%s", vett);                              // Legge una stringa

            fputs(vett, fileDestinazione); // Scrive la stringa vett nel fileDestinazione
            fputc('\n', fileDestinazione); // Scrive un carattere di nuova riga nel file
        }
    }
    fclose(fileDestinazione); // Chiude il file

    fileDestinazione = fopen("nomi.txt", "r");     // Apre il file  in modalità lettura
    while (fgets(vett, MAX_STR, fileDestinazione)) // Legge una riga alla volta dal file in vett
        printf("%s", vett);                        // Stampa la riga letta

    if (fclose(fileDestinazione) == 0)                           // Chiude il file e verifica se la chiusura ha avuto successo
        printf("\n\nChiusura del file avvenuta con successo\n"); // Stampa un messaggio di chiusura riuscita
    else
        printf("\n\nChiusura del file fallita"); // Stampa un messaggio di chiusura fallita

    return 0; // Termina il programma restituendo 0 indicando una terminazione corretta
}
