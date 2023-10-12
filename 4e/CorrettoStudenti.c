#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int const DIM = 3;
    typedef struct
    {
        char nome[40];
        char cognome[40];
        int media;
    } student_t;

    student_t *classePtr[DIM]; // array struct puntatori
    for (int i = 0; i < DIM; i++)
    {
        classePtr[i] = malloc(sizeof(student_t)); // alloco memoria per la struct, e lo inserisco dentro all'array
        printf("Inserisci il nome:\n");
        scanf("%s", classePtr[i]->nome);
        printf("Inserisci il cognome:\n");
        scanf("%s", classePtr[i]->cognome);
        printf("Inserisci la media:\n");
        scanf("%d", &classePtr[i]->media);
    }
    for (int i = 0; i < DIM; i++)
    {
        printf("\nStudente %d\n", i + 1);
        printf("%s\n", classePtr[i]->nome);
        printf("%s\n", classePtr[i]->cognome);
        printf("%d\n", classePtr[i]->media);
        free(classePtr[i]);
    }
    return 0;
}