#include <stdio.h>

int main(int argc, char *argv[])
{
    /*Scrivere un programa in C che dopo aver inserito una stringa (lunga a piacere) da tastiera conti quante 
vocali e consonanti contiene. Visualizzare il risultato a video.*/

    
    int contaCons=0, contaVoc=0, lunghezza=0, i=0;
    char stringa[lunghezza];
    printf("Inserisci lunghezza stringa\n");
    scanf("%d",&lunghezza);
    printf("Inserisci una stringa\n");
    scanf("%s", stringa);

    while (stringa[i] != '\0'){
        i++;
    }
    lunghezza=i;
    for (i=0; i<lunghezza; i++)
    {
            if(stringa[i]=='a'||stringa[i]=='e'||stringa[i]=='i'||stringa[i]=='o'||stringa[i]=='u')
            {
                contaVoc++;
            }
            else if ((stringa[i]!='a'||stringa[i]!='e'||stringa[i]!='i'||stringa[i]!='o'||stringa[i]!='u')&&(stringa[i]>97&&stringa[i]<122)) { 
                contaCons++; //ho messo stringa[i]>97&&stringa[i]<122) dato che devo tenere conto del carattere ascii. Quei numeri rappresentano i caratteri che vanno da A a Z
            }                   //stringa[i]>'a'&&stringa[i]<'z') si può fare anche con le lettere 
    }
    printf("Il numero di vocali è: %d\n", contaVoc);
    printf("Il numero di consonanti è: %d\n", contaCons);
    return 0;
}