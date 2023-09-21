#include <stdio.h>

int main(int argc, char *argv[])
{
    int vett[100], n, pari[100], disp[100], k = 0, t = 0, max_pari, min_pari, pos_max_pari, pos_min_pari, max_dispari, min_dispari, pos_max_dispari, pos_min_dispari;
    printf("Inserisci la dimensione dell'array: ");
    scanf("%d", &n);

    printf("Inserisci %d numeri interi nell'array:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vett[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (vett[i] % 2 == 0)
        { // pari
            pari[k] = vett[i];
            k++;
        }
        else
        { // dispari
            disp[t] = vett[i];
            t++;
        }
    }
    max_pari = pari[0];
    min_pari = pari[0];
    max_dispari = min_dispari = disp[0];
    for (int i = 0; i < k; i++)
    {
        if (max_pari < pari[i]) // pari
            max_pari = pari[i];
        if (min_pari > pari[i]) // pari
            min_pari = pari[i];
    }
    for (int i = 0; i < t; i++)
    {
        if (max_dispari < disp[i]) // dispari
            max_dispari = disp[i];
        if (min_dispari > disp[i]) // dispari
            min_dispari = disp[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (max_pari == vett[i])
            pos_max_pari = i;
        if (min_pari == vett[i])
            pos_min_pari = i;
        if (max_dispari == vett[i])
            pos_max_dispari = i;
        if (min_dispari == vett[i])
            pos_min_dispari = i;
    }

    printf("Massimo dei numeri pari: %d (in posizione %d)\n", max_pari, pos_max_pari + 1);
    printf("Minimo dei numeri pari: %d (in posizione %d)\n", min_pari, pos_min_pari + 1);
    printf("Massimo dei numeri dispari: %d (in posizione %d)\n", max_dispari, pos_max_dispari + 1);
    printf("Minimo dei numeri dispari: %d (in posizione %d)\n", min_dispari, pos_min_dispari + 1);

    return 0;
}