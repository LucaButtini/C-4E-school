#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    int media;
} student_t;

void stampa(student_t *st)
{
    printf("Nome: %s\n", st->nome);
    printf("Cognome: %s\n", st->cognome);
    printf("Media: %d\n", st->media);
}

void popola(student_t *st, int i)
{
    printf("Inserisci nome alunno %d: ", i + 1);
    scanf("%s", st[i].nome);
    printf("Inserisci cognome alunno %d: ", i + 1);
    scanf("%s", st[i].cognome);
    printf("Inserisci media alunno %d: ", i + 1);
    scanf("%d", &st[i].media);
}

int main(int argc, char *argv[])
{
    int l = 3;
    student_t *studenti[l];

    for (int i = 0; i < l; i++)
    {
        studenti[i] = (student_t *)malloc(sizeof(student_t)); // alloco la memoria
        popola(studenti[i], i);
    }

    for (int i = 0; i < l; i++)
    {
        printf("\nStudente %d\n", i + 1);
        stampa(studenti[i]);
        free(studenti[i]); // libero la memoria
    }
    return 0;
}
