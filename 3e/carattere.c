#include <stdio.h>

int main(int argc, char *argv[])
{
    //ogni carattere ha un codice in decimale che rappresenta nel codice ASCII. Possiamo anche stampare il suo valore numerico
    char carattere;
    printf("Inserisci un carattere\n");
    // scanf("%c", &carattere);
    carattere = getchar(); // alternativa di lettura per il carattere
    // printf("Hai inserito il seguente carattere: %c\n", carattere);
    //putchar(carattere); // alternativa per stampare
    printf("Il codice relativo del carattere inserito è: %d\n", carattere); //dato che il codice è intero metto %d
    return 0;
}