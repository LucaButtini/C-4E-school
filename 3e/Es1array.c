#include <stdio.h>
/*Scrivere un programma in C che dopo aver inserito N numeri interi in un vettore,
alterni (o scambi ) a due a due le posizioni del vettore. Esempio:
vettore inserito: 1,2,3,4  vettore alternato: 2,1,4,3.*/

int main()
{
    int grandezza = 0;
    int numIns;
    int swap;
    printf("Quanti numeri vuoi inserire\n");
    scanf("%d", &grandezza);
    int numeri[grandezza];

    for (int i = 0; i < grandezza; i++)
    {
        printf("Inserisci un numero\n");
        scanf("%d", &numIns);
        numeri[i] = numIns;
    }
    for (int j = 0; j < grandezza-1; j=j+2)  //perchè deve andare avanti di due 
    {
        swap = numeri[j + 1];
        numeri[j + 1] = numeri[j];
        numeri[j] = swap;
    }

    for (int i = 0; i < grandezza; i++)
    {
        printf("%d\n", numeri[i]);
    }
    return 0;
}