#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    // Leggi una stringa e un carattere e, se il carattere è presente nella stringa, conta quante volte quel carattere è contenuto nella stringa.
    char string[20];
    char carattere;
    int i = 0, lunghezza = 0, carattereVoc=0, carattereCons=0;
    printf("Inserisci una stringa\n");
    scanf("%s", string);
    printf("Inserisci un carattere\n");
    scanf("%c", &carattere);
    lunghezza = strlen(string);
  
    for (i = 0; i < lunghezza; i++)
    {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
        {
           carattereVoc++;
        }
        else if ((string[i] != 'a' || string[i] != 'e' || string[i] != 'i' || string[i] != 'o' || string[i] != 'u') && (string[i] > 97 && string[i] < 122))
        {
            carattereCons++;
        }
        
     }
     if (carattereCons==0||carattereVoc==0) 
        {
            printf("Il carattere non è presente nella stringa\n");
        }
     if (carattereVoc!=0)
     {
        printf("Il carattere è apparso %d volte nella stringa\n", carattereVoc);
     }
     else 
     {
        printf("Il carattere è apparso %d volte nella stringa\n", carattereCons);
     }
    return 0;
}