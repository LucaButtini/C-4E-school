#include <stdio.h>
void main () {

float base,altezza,perimetro,area;
//base e altezza rettangolo calcola area e perimetro.
printf("Inserisci base \n");
scanf("%f", &base);
printf("Inserisci altezza \n");
scanf("%f", &altezza);
perimetro= (base+altezza)*2;
area= base*altezza;
printf("Il perimetro è %f \n", perimetro);
printf ("L'area è %f \n", area);



}