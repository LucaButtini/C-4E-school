#include <stdio.h>
#include <stdlib.h> // Per la funzione atoi

int main(int argc, char *argv[])
{
    // uso atoi per convertire la stringa in intero
    int limite_minimo = atoi(argv[1]);
    int limite_massimo = atoi(argv[2]);

    int limite1, limite2, grandezza = 5, somma = 0, j = 0;
    int n[grandezza]; // array di numeri

    do
    { // inserimento limite 1
        printf("Inserisci limite 1\n");
        scanf("%d", &limite1);
    } while (limite1 < limite_minimo || limite1 > limite_massimo);

    do
    { // inserimento limite 2
        printf("Inserisci limite 2\n");
        scanf("%d", &limite2);
    } while (limite2 < limite_minimo || limite2 > limite_massimo);

    // stampo i limiti
    printf("\n%d\n", limite1);
    printf("%d\n", limite2);

    for (int i = 0; i < grandezza; i++)
    {//input
        printf("\nInserisci numero\n");
        scanf("%d", &n[i]);
    }

    for (int i = 0; i < 5; i++)
    {

        // se il numero è compreso tra i limiti, verranno stampati anche indice e posizione. In caso contrario verrà stampato solamente il numero
        if (n[i] >= limite1 && n[i] <= limite2)
        {
            printf("\nnumero  [%d] indice  [%d] posizione  [%d]\n", n[i], i, j);
        }
        else
        {
            printf("\nnumero  %d\n", n[i]);
        }
        j++;
    }
    //calcolo della somma
    for (int i = 0; i < grandezza; i++)
    {
        if (n[i] >= limite1 && n[i] <= limite2)
        {
            somma += n[i];
        }
    }
    //stampo somma
    printf("\nLa somma è %d\n", somma);
    return 0;
}