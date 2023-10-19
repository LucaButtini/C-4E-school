#include <stdio.h>
#include <stdlib.h>
// tastiera e monitor sono due file
// tastiera di input e monitor output
// stdi, stdout

int main(int argc, char *argv[])
{
    // è una libreria
    FILE *nomi;
    const int DIMARR = 100;
    const int DIM = 4;
    char vetNome[DIMARR];
    char c;
    nomi = fopen("nomi.txt", "r"); // apro il file in lettura
    if (nomi == NULL)
    {
        printf("File non aperto: errore\n");
        exit(1);
    }

    do
    {
        c = fgetc(nomi); // lo fa per ogni carattere del file
        putchar(c);      // stampo a video
    } while (c != EOF);  // EOF è la fine del file
    // il file va chiuso alla fine
    fclose(nomi);
    return 0;
}