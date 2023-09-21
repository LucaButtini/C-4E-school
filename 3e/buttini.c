#include <stdio.h>
void main()
{ // Buttini Luca fila 1

    /*Esercizio
Scrivere un programma in c che dopo aver acquisito da tastiera un elenco di prezzi relativi alle vendite di N
prodotti ed il relativo incremento del prezzo secondo una percentuale, visualizzi a video:
1) Il prezzo incrementato per ogni inserimento effettuato;
2) Il totale e la media dei prezzi incrementati;
3) La media dei prezzi incrementati maggiori di 50€;
Miglioreranno la qualità del software i giusti commenti e l’interazione con l’utente. Ogni azione diversa da
quelle richieste o non specificata, che possa essere tramutata in vincolo, dovrà essere necessariamente
esplicitata.*/

    int prodotti = 0, prodotti50 = 0;
    float prezzo = 0, percentuale = 0, totaleIncrementati = 0, mediaIncrementati = 0, mediaIncr50 = 0, prezzoIncrementato = 0; // Prezzo incrementato = prezzo*percentuale/100.
    do
    {
        printf("Inserisci il numero di prodotti acquistati\n");
        scanf("%d", &prodotti);
    } while (prodotti < 0); // controllo che l'utente inserisca una quantità di prodotti maggiore di zero.

    for (int i = 0; i < prodotti; i++)
    // in base al numero di prodotti inserita, eseguiro il ciclo tot volte.
    {
        do
        { // controllo che il prezzo inserito sia maggiore di zero
            printf("Inserisci il prezzo del prodotto \n");
            scanf("%f", &prezzo);
        } while (prezzo < 0);

        do
        { // controllo che la percentuale inserita sia maggiore di zero
            printf("Inserisci la percentuale per l'incremento del prezzo \n");
            scanf("%f", &percentuale);
        } while (percentuale < 0);

        prezzoIncrementato = (prezzo * percentuale) / 100; // calcolo del prezzo incrementato
        printf("Il prezzo incrementato è: %f\n", prezzoIncrementato);

        mediaIncrementati = (mediaIncrementati + prezzoIncrementato) / prodotti; // calcolo mediaIncrementati
        totaleIncrementati = totaleIncrementati + prezzoIncrementato;            // calcolo tot Incrementati

        if (prezzoIncrementato > 50) // se il prezzo incrementato è maggiore di 50, calcola la media degli incrementati
        {
            prodotti50++;
            mediaIncr50 = (mediaIncr50 + prezzoIncrementato) / prodotti50;
        }
    }
    printf("Il totale dei prezzi incrementati è: %f\n", totaleIncrementati);
    printf("La media dei prezzi incrementati è: %f\n", mediaIncrementati);
    printf("Il totale dei prezzi incrementati è: %f\n", mediaIncr50);
}