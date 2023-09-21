#include <stdio.h>

int main(int argc, char *argv[])
{
    //la variabile stringa è un vettore (array) di caratteri.
    //Alla fine dell'array la stringa aggiunge un carattere \0 che serve per indicare la fine della stringa.
    char stringa[10]; //mettiamo la lenght, grandezza di quanti elementi ci sono dentro l'array
    printf("Inserisci una stringa\n");
    scanf("%s", stringa);  //lo deve leggere come stringa quindi %s. L'array non vuole & davanti.
    printf("Hai inserito la seguente stringa; %s\n", stringa);
    return 0;
}