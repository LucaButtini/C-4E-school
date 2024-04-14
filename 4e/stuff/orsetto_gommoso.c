#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 20
#define qtaNomi 3
int main(int argc, char *argv[])
{
    int i = 0;
    FILE *dest;
    char array[MAX_STR];

    dest = fopen("nomi.txt", "w");
    if (dest == NULL)
        exit(69);
    else
    {
        for (int i = 0; i < qtaNomi; i++)
        {
            printf("Inserisci il nome della persona %d\n", i + 1);
            scanf("%s", array);
        }
    }

    return 0;
}