#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    int media;
} student_t;

void stampa(student_t *st, int l)
{
    for (int i = 0; i < l, i++)
    {
        printf("Nome: %s\n", st->nome);
        printf("Cognome: %s\n", st->cognome);
        printf("Media: %d\n", st->media);
        free(studenti[i]); // libero la memoria
    }
}

void popola(student_t *st, int l)
{
    for (int i = 0; i < l; i++)
    {
        studenti[i] = (student_t *)malloc(sizeof(student_t)); // alloco la memoria
        printf("Inserisci nome alunno %d: ", i + 1);
        scanf("%s", st[i].nome);
        printf("Inserisci cognome alunno %d: ", i + 1);
        scanf("%s", st[i].cognome);
        printf("Inserisci media alunno %d: ", i + 1);
        scanf("%d", &st[i].media);
    }
}

int main(int argc, char *argv[])
{
    int l = 3;
    student_t *studenti[l];

    popola(studenti[i], l);

    stampa(studenti[i], l);
    return 0;
}