#include <stdio.h>
#include <stdlib.h>

#define BUFFER_DIM 1024 // definizione capacità
int main(int argc, char *argv[])
{
    FILE *origine, *destinazione; // definiziona file origine e destinazione
    int n;
    unsigned char buffer[BUFFER_DIM];
    if (argc != 3) // controllo che l'utente inserisca correttamente i parametri dalla riga di comando
    {
        printf("Inserire correttamente il numero di parametri\n");
        exit(1);
    }
    origine = fopen(argv[1], "r"); // apro in lettura il file di origine
    if (origine == NULL)           // controllo che l'apertura vada a buon fine
    {
        printf("Errore apertura file origine\n");
        exit(1);
    }
    destinazione = fopen(argv[2], "w"); // apro in scrittuyra il file di destinazioneu
    if (destinazione == NULL) // controllo che l'apertura vada a buon fine
    {
        printf("Errore apertura file origine\n");
        exit(1);
    }
    // passo da un file all'altro senza monitor e tastiera
    // finchè non raggiungo la fine del file, legge dal file di origine buffer dim e li mette in write in destinazione da sorgente
    while (!feof(origine))
    {
        n = fread(buffer, 1, BUFFER_DIM, origine);
        if (n > 0)
        {
            fwrite(buffer, 1, n, destinazione);
        }
    }
    fclose(origine);
    fclose(destinazione);

    return 0;
}