#include <stdio.h>

///definisco il tipo di struct e sotto creo variabile di quel tipo.
struct s_punto
{
    int x;
    int y;
    int z;
} p; 
void stampaStruct(struct s_punto p1)//stampo struct
{
    printf("\nX %d, Y %d, Z %d\n", p1.x, p1.y, p1.z);
}
void puntoModificato(struct s_punto p1)//modifico e stampo il punto modificato
{
    p1.x++;
    p1.y++;
    p1.z++;
    printf("\nX %d, Y %d, Z %d\n", p1.x, p1.y, p1.z);
}
int main(int argc, char *argv[])
{
    p.x = 5;
    p.y = -2;
    p.z = 7;
    printf("Punto 1");
    stampaStruct(p);
    puntoModificato(p);
    return 0;
}