#include <stdio.h>

// definisco la struct
struct s_punto
{
    int x;
    int y;
    int z;
} punto1; // definisco una var di quel tipo struttura

main(int argc, char *argv[])
{
    punto1.x = 5;
    punto1.y = -2;
    punto1.z = 7;
    print("Punto 1")
        stampa(punto1);

    struct s_punto punto2 = puntoMod

        return 0;
}

void stampa(struct s_punto p1)
{
    printf("X %d, Y%d, Z %d", p1.x, p1.y, p1.z);
}

void puntoMod(struct s_punto p1)
{
    p1.x++;
    p1.y++;
    p1.z++;
}