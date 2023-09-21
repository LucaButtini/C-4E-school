#include <stdio.h>
void main() {
   
//Dopo aver letto N numeri interi calcolare la somma e la media dei numeri pari maggiori di 5 visualizzando a video i risultati .

int volte, numero, media=0, somma=0;

printf("Inserisci quante volte vuoi ripetere il numero\n");
scanf("%d", &volte);

for (int i = 0; i<volte; i++)
{
    printf("Inserisci il numero\n");
    scanf("%d", &numero);

    if (numero%2 == 0 && numero>5)
    {
        
        somma=somma+numero;
        media = somma/volte;
    }
}

printf("SOMMA: %d ", somma);
printf("MEDIA: %d", media);
}