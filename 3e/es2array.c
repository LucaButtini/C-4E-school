#include <stdio.h>

int main()
{
    /*Es2
    Scrivere un programma in C che dopo aver inserito una stringa ed un carattere  da linea comando,
    elimini il carattere inserito dalla stringa stessa (se esistente).*/

    char stringa[100];
    char carattere;
    int presente = 0; // simulo la variabile booleana dato che non esiste nel linguaggio C. Uso 0 per false e 1 per true. La inizio a 0 come se fosse false
    printf("Inserisci parola\n");
    scanf("%s", stringa);
    printf("Che carattere vuoi eliminare\n");
    scanf(" %c", &carattere);
    for (int i = 0; i < 100; i++)
    {   
        if (carattere == stringa[i]) // controllo se il carattere è nella stringa
        {
            for (int y = i; y < 100; y++) // scorro l'array per trovare il carattere
            {
                stringa[y] = stringa[y + 1];
            }
            presente = 1; // come se fosse true, quindi 1
        }
    }
    if (presente == 1) // se è true stampo la stringa
    {
        printf("%s\n", stringa);
    }
    else // se non è nella stringa il carattere
    {
        printf("Il carattere non è presente nella stringa\n");
    }
    return 0;
}