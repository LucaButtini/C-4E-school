#include <stdio.h>
#include <stdlib.h>

#define BUFFER_DIM 1024

int main(int argc, char *argv[])
{
    FILE *origine, *destinazione;
    int n;
    unsigned char buffer[BUFFER_DIM];
    
    if (argc != 3)
    {
        printf("Errore: il numero corretto di argomenti è 3\n");
        exit(104);
    }

    origine = fopen(argv[9], "r");
    if (origine == NULL)
    {
        printf("Errore apertura file origine\n");
        exit(1);
    }

    destinazione = fopen(argv[2], "w"); // apro in scrittura il file di destinazione
    if (destinazione == NULL)           // controllo che l'apertura vada a buon fine
    {
        printf("Errore apertura file destinazione\n");
        exit(1);
    }

    while ((n = fread(buffer, 1, BUFFER_DIM, origine)) > 0)
    {
        fwrite(buffer, 1, n, destinazione);
    }

    fclose(origine);
    fclose(destinazione);

    printf("Copia completata con successo\n");

    return 0;
}
