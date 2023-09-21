#include <stdio.h>
void main () {

float lato,perimetro,area;
//lato quadrato calcola perimetro e area
printf("Inserisci il lato \n");
scanf("%f", &lato);

perimetro= lato*4;
area= lato*lato;
printf("Il perimetro è %f \n", perimetro);
printf ("L'area è %f \n", area);



}