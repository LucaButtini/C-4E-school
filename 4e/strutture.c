#include <stdio.h>

// Definizione della struttura
struct s_punto
{
    int x;
    int y;
    int z;
} punto1; // Definizione di una variabile di quel tipo di struttura
void stampa(struct s_punto p1)
{
    printf("\nX %d, Y %d, Z %d\n", p1.x, p1.y, p1.z);
}
void puntoMod(struct s_punto p1)
{
    p1.x++;
    p1.y++;
    p1.z++;
    printf("\nX %d, Y %d, Z %d\n", p1.x, p1.y, p1.z);
}
int main(int argc, char *argv[])
{
    punto1.x = 5;
    punto1.y = -2;
    punto1.z = 7;
    printf("Punto 1");
    stampa(punto1);
    puntoMod(punto1);
    return 0;
}