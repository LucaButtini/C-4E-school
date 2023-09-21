#include <stdio.h>
int main(int argc, char *argv[])
{
    /*
    Es 4
        Scrivere un programma in C che dopo aver inserito N numeri interi in un vettore,
        modifichi il vettore invertendo gli elementi inseriti.
        Esempio: vett. Ins.: 1,2,3,4 - vett. Inv.: 4,3,2,1.
    */
    int grandezza;
    do
    {
        printf("Quanti numeri vuoi inserire");
        scanf("%d", &grandezza);
    } while (grandezza <= 0);
    int k=grandezza-1;//k =grandezza per invertire l'array
    int v1[grandezza];//vettore normale
    int v2 [grandezza];//vettore invertito
    for (int i = 0; i < grandezza; i++)
    {
        printf("Inserisci un numero");
        scanf("%d", &v1[i]);
        v2[k]=v1[i]; //do a k il v1 di i (k è uguale a)
        k--; //decremento k 
    }
    printf("Il vettore normale\n");
    for (int i = 0; i < grandezza; i++) //stampo vettore normale
    {
        printf("%d\n", v1[i]);
    }
     printf("Il vettore invertito\n");
    for (int i=0; i<grandezza; i++)//stampo vettore invertito
    {
        printf("%d\n", v2[i]);
    }
    return 0;
}