#include <stdio.h>

int main(int argc, char *argv[])
{
    /*Esercizio 1
Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero.*/
    int numero1, numero2;
    float rapporto;

    do
    {
        printf("Inserisci il primo numero\n");
        scanf("%d", &numero1);
        printf("Inserisci il secondo numero\n");
        scanf("%d", &numero2);
        if (numero1 < numero2)
        {
            rapporto = (float)numero1 / numero2;
        }
        else
        {
            if (numero2 < numero1)
            {
                rapporto = (float)numero2 / numero1;
            }
        }
        printf("Il rapporto è: %f\n", rapporto);
    } while (numero1 != 0 || numero2 != 0);


    return 0;
}