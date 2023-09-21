#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char str[100];
    int i = 0, l, cont = 0, trovata = 0, controllo = 0, freq = 0;

    do
    {
        printf("Inserisci una stringa\n");
        scanf("%s", str); // inserimento string
        l = strlen(str);
    } while (str[i] < 'a' || str[i] > 'z'); // controllo che si inseriscano solo lettere. Se non inserisci lettere richiede di inserire la stringa
    printf("Stringa inserita %s\n", str);   // stampo stringa

    // calcolo frequenza lettere
    for (int j = 0; j < l; j++)
    {
        if (str[j] > 'a' && str[j] < 'z')
        {
            cont++;
            freq = cont;
            cont = 0;
            trovata = 1;
        }
        if (!trovata)
        {
            cont++;
        }
        printf("%c %i\n", str[j], freq); // stampo frequenza lettere
    }
    return 0;
}