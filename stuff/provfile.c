#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file_origine;
    file_origine = fopen("newfile.txt", "r");
    if (file_origine == NULL)
    {
        printf("File non esiste\n");
        exit(1);
    }
    else
    {
        printf("File aperto\n");
        if (fclose(file_origine) == 0)
            printf("Chiusura avvenuta con successo\n");
        else
            printf("Chiusura non avvenuta\n");
    }

    return 0;
}
