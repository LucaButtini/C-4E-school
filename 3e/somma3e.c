//Dopo avere letto N numeri reali calcola la somma e la media visualizzando a video i risultati
#include <stdio.h>
void main() {
float num, somma, media, cont;
int n;
printf("Quanti numeri vuoi inserire?\n");
scanf("%d",&n);
cont=n; //serve per salvare il valore di n dato che viene diminuita dove c'è n--.
do {
printf("Inserisci un numero\n");
scanf("%f", &num);
n--;
somma=somma+num;
}while(n>0);
printf("\n");
media=somma/cont;
printf("La somma risulta: %f",somma);
printf("La media risulta: %f",media); //oppure "somma/cont" direttamente
}
