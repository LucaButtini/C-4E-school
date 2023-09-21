//scrivere un programma che dopo aver letto N numeri calcoli la somma solo dei numeri maggiori di5
#include <stdio.h>
void main() {
float num, somma;
int n;
printf("Quanti numeri vuoi inserire?\n");
scanf("%d",&n);
do {
printf("Inserisci un numero\n");
scanf("%f", &num);
n--;
if (num>5)
{
somma=somma+num;
}
else 
{
    printf("numero errato\n");
}
}while(n>0);
printf("\n");
printf("La somma risulta: %f",somma);
}
