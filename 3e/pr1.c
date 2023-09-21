//programma che calcola la somma di due numeri
#include<stdio.h>
void main() {
    int contatore,add=5 ,add2=3, somma; //quando le creo sto inizializzando la variabile
    float add3,add4,somma2, diff,prod,quoz;
    somma=add+add2;
    
    printf("LE OPERAZIONI COL C \n");

    printf("la somma tra numeri interi è: %d \n",somma); //scrittura a video
    add3=2.5;
    add4=3.75;//assegno un valore alla variabile = assegnazione
    somma2=add3+add4;
    printf("la somma tra numeri reali è: %.2f \n",somma2); //scrittura a video
    contatore=contatore+1; //se non le do un valore il computer da una cifra a caso, molte delle volte zero.
    printf("la variabile contatore vale: %d\n", contatore); //scrittura a video
    contatore++;//qui è in forma sintetica in base a quanti operatori scrivi
    printf("la variabile contatore vale: %d\n", contatore); //scrittura a video
    contatore--;
    printf("la variabile contatore vale: %d\n", contatore); //scrittura a video

    //le altre operazioni

    diff=add3-add4;
    quoz=add3/add4;
    prod=add3*add4;
    printf("la differenza tra numeri reali è: %.2f \n",diff); //mettendo %.2f approssimo a due cifre il numero decimale 
    printf("il prodotto tra numeri reali è: %.2f \n",prod);
    printf("il quoziente  tra numeri reali è: %.2f \n",quoz);

  


}
