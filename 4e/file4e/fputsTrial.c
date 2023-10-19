#include <stdio.h>
#include <stdlib.h>
// tastiera e monitor sono due file
// tastiera di input e monitor output
// stdi, stdout

int main(int argc, char *argv[])
{
    // è una libreria
    FILE *nomi; // var di tipo puntatore a file

    nomi = fopen("nomi.txt", "w"); // apertura del file. Lo metto in w dato che lo devo scrivere. Fopen ritorna un valore
    if (nomi == NULL)              // se è cosi vuol dire che il file non si può aprire
    {
        printf("File non aperto: errore\n");
        exit(1); // esco dal programma
    }
    printf("Ok file aperto\n");
    return 0;
}