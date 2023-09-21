#include <stdio.h>
#include <string.h>

/*Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
1)  Che contenga solo lettere;
2) Crei 2 ulteriori stringhe che contengano: la 1° le lettere di posizione pari; la 2° le lettere di posizione dispari;
Inserita una 2° stringa determinare:
1) Quale delle 2 è più lunga e più corta;
2) Quale delle 2 stringhe contiene più vocali;
3) Quale delle 2 stringhe contiene più consonanti.*/
int main(int argc, char *argv[])
{
    char string[100], string2[100], stringPari[100], stringDispari[100];
    int lunghString, j = 0, k=0;
    do
    {
        printf("Inserisci una stringa\n");
        scanf("%s", string);

    } while ();
    lunghString = strlen(string);
    for (int i = 0; i < lunghString; i++)
    {
        if (string[i] % 2 == 0)
        {
            j++;
            stringPari[j] = string[i];
        }
        else
        {
            k++;
            stringDispari[k]=string[i];
        }
    }
    return 0;
}