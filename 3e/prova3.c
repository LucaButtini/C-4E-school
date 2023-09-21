//scrivere un programma in c che dopo aver letto due numeri in input calcoli la somma

#include<stdio.h>
void main() {
int var1, var2, somma;

printf("Inserisci il primo numero\n");
scanf("%d",&var1); //per inserire un dato da tastiera
printf("Ho inserito:%d\n",var1);
printf("Inserisci il secondo numero\n");
scanf("%d",&var2);
printf("Ho inserito:%d\n",var2);
somma=var1+var2;
printf("La somma tra i due numeri e': %d\n",somma);

} 
