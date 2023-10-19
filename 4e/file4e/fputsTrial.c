#include <stdio.h>
#include <stdlib.h>
// tastiera e monitor sono due file
// tastiera di input e monitor output
// stdi, stdout

int main(int argc, char *argv[])
{
    // è una libreria
    FILE *nomi; // var di tipo puntatore a file
    const int DIMARR = 100;
    const int DIM = 4;
    char vetNome[DIMARR];
    nomi = fopen("nomi.txt", "a"); // apertura del file. Lo metto in w dato che lo devo scrivere. Fopen ritorna un valore
    // se esiste già inizio con "a" metto dentro altri contenuti da dove eravamo arrivati
    if (nomi == NULL) // se è cosi vuol dire che il file non si può aprire
    {
        printf("File non aperto: errore\n");
        exit(1); // esco dal programma
    }
    // mi si è creato nella directory corrente il file dato che in principio non c'era
    //-------------------------------------------------------------------------------
    // andiamo ora a scrivere nel file
    for (int i = 0; i < DIM; i++)
    {
        printf("Inserisci il nome %d\n", i + 1);
        scanf("%s", vetNome);
        fputs(vetNome, nomi); // origine del file che va grazie al puntatore nel file
        fputc('\n', nomi);    // vado a capo
    }
    // il file va chiuso alla fine
    fclose(nomi);
    return 0;
}