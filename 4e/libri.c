#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char titolo[100];
    char autore[100];
    float prezzo;
} Libro; // struttura libro

void inserisciLibro(Libro *biblioteca, int i) // metodo inserimento
{
    printf("Inserisci il titolo del libro:\n ");
    scanf("%s", biblioteca[i].titolo);

    printf("Inserisci l'autore del libro:\n ");
    scanf("%s", biblioteca[i].autore);

    printf("Inserisci il prezzo del libro:\n ");
    scanf("%f", &biblioteca[i].prezzo);
}

void stampaBiblioteca(Libro *biblioteca, int dimensione) // metodo di stampa
{
    printf("\n===BIBLIOTECA===\n");
    for (int i = 0; i < dimensione; i++)
    {
        printf("Libro %d:\n", i + 1);
        printf("Titolo: %s\n", biblioteca[i].titolo);
        printf("Autore: %s\n", biblioteca[i].autore);
        printf("Prezzo: %.2f\n\n", biblioteca[i].prezzo);
    }
}

void mettiSconto(Libro *biblioteca, int dim, float sconto)
{
    for (int i = 0; i < dim; i++)
    {
        biblioteca[i].prezzo -= biblioteca[i].prezzo * (sconto / 100); // applico lo sconto
    }
}

int main(int argc, char *argv[])
{
    int dim = 3;
    Libro biblioteca[dim];
    float sconto;

    for (int i = 0; i < dim; i++)
    {
        printf("Inserimento libro numero %d:\n", i + 1);
        inserisciLibro(biblioteca, i); // inserimento libro, passo l'indice che aumenta nel for
    }

    stampaBiblioteca(biblioteca, dim);
    // sconto
    printf("\nInserisci lo sconto:\n");
    scanf("%f", &sconto);
    mettiSconto(biblioteca, dim, sconto);
    printf("\nSconto del %.2f%% applicato.\n", sconto);
    stampaBiblioteca(biblioteca, dim);

    return 0;
}