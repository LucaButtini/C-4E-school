#include <stdio.h>

int main()
{
    int limite1, limite2, somma = 0, n;
    const int MIN = 30, MAX = 50;

    // I limiti devono essere compresi fra 30 e 50
    do
    {
        printf("Inserisci il primo limite (compreso tra 30 e 50): "); // inserisco i limiti (sono anch'essi limitati)
        scanf("%d", &limite1);
    } while (limite1 < MIN || limite1 > MAX);

    do
    {
        printf("Inserisci il secondo limite (compreso tra 30 e 50): ");
        scanf("%d", &limite2);
    } while (limite2 < MIN || limite2 > MAX);

    // stampo i valori dei limiti
    printf("Il valore di limite1 è: %d\n", limite1);
    printf("Il valore di limite2 è: %d\n", limite2);

    // inserisco i numeri che devono essere compresi fra i valori dei due limiti
    for (int i = 0; i <= 5; i++)
    {
        do
        {
            printf("Inserisci il numero %d (compreso tra %d e %d): ", i + 1, limite1, limite2);
            scanf("%d", &n);
        } while (n < limite1 || n > limite2);

        somma += n; // calcolo somma
    }

    printf("Somma: %d\n", somma); // stampo somma
    return 0;
}
