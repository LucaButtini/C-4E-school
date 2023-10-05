#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    typedef struct // in questo caso la dichiaro nel main dato che non mi serve renderla visibile ad altre funzioni
    {
        char nome[20];
        char cognome[20];
        int media;
    } studente_t;
    studente_t studente;
    studente_t *stud;
    // passo col puntatore per accedere ai campi della struct. Con l'indirizzo lo casto al tipo di struct
    //studente_t *stud = (studente_t *)&studente;
    stud = malloc(sizeof(studente_t));//memory allocation
    // student_t *stud = &studente; analoga alla riga sopra, però meno ottimizzata perchè non sa che dentro c'è una struct

    // popolazione campi
    strcpy(stud->nome, "nome"); //->notazione per accedere ai campi della struttura attraverso il puntatore
    strcpy(stud->cognome, "cognome");
    stud->media = 8;
    free(stud);//memory de-allocation

    printf("%s\n", stud->cognome);
    printf("%s\n", stud->nome);
    printf("%d\n", stud->media);
}
