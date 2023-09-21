#include <stdio.h>
#include <stdlib.h>

int positivi(int *v1[], int *v2, int l, int i) // i è la partenza
{
    int c = 0;
    for (i; i < l; i++) // abbiamo parametrizzato l'indice di partenza
    {
        if (atoi(*(v1 + i)) > 0)
        {
            *(v2 + c) = atoi(*(v1 + i));
            c++;
        }
    }
    return c;
}
// posso usare direttamente argc e argv
int main(int argc, char *argv[])
{
    int h = 5;
    int array2[h];
    int array1[h] = {1, 2, 3, 4, -25};
    // int v2[argc - 1]; // dato che non mi serve la parte di "./a.out"
    int partenza = 0;
    int l = positivi(array1, array2, h, partenza);
    printf("I numeri positivi sono %d\n", l);
    return 0;
}