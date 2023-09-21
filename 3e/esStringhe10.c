#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    /*Es 10
    Scrivere un programma in C che dopo aver inserito 2 stringhe visualizzi a video le lettere comuni ad entrambe.*/
    char s1[100], s2[100];
    int lunString1, lunString2, boolean = 0;

    printf("Inserisci due stringhe stringhe\n");
    scanf("%s", s1);
    scanf("%s", s2);
    printf("stringa 1 è %s\n", s1);
    printf("stringa 2 è %s\n", s2);

    lunString1 = strlen(s1);
    lunString2 = strlen(s2);
    /*if (lunString1 < lunString2)
    {
        var1 = lunString2;
    }
    else
    {
        var2 = lunString1;
    }*/
    for (int i = 0; i < lunString1; i++)
    {
        boolean = 1;
        for (int j = 0; j < lunString2; j++)
            if (s1[i] == s2[j])
            {
                printf("Caratteri comuni %s", s1[i]);
                boolean = 1;
            }
        if (boolean == 1)
        {
            
        }
    }
    return 0;
}