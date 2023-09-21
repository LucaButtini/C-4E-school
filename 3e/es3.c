#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>

void Stampa(int elementi, int vett[])
{

    printf("stampa degli elementi:...\n");
    for(int i=0; i<elementi; i++)
    {
        printf("elemento numero %d : %d\n", i+1, vett[i]);
    }
}

void Stampainversa(int vett[], int elementi)
{
    for(int i = elementi - 1; i >= 0; i--)
    {
        printf("elemento numero %d: %d \n", i+1, vett[i]);
    }
}

void SommaMedia(int *vett, int elementi)
{
    float s = 0;
    for(int i = 0; i < elementi; i++)
    {
        s += vett[i];
    }
    printf("%f\n",s);
    printf("%f\n", s/elementi);
}

void StampaNumeriPari(int vett[], int elementi)
{
    int a = 0;
    while (a < elementi)
    {
        if((vett[a] % 2) == 0)
        {
            printf("Il numero %d è pari \n", vett[a]);
        }
        a++;
    }
}

void StampaNumeriDispari(int vett[], int elementi)
{
    int a = 0;
    while(a < elementi)
    {
        if(vett[a] % 2 != 0)
        {
            printf("Il numero %d è dispari \n", vett[a]);
        }
        a++;
    }
}

void Ricerca(int *vett, int elementi)
{
    int n;
    printf("inserire il numero da ricercare: \n");
    scanf("%d",&n);
    for(int i = 0; i<elementi; i++)
    {
        if(vett[i]==n)
        {
            printf("numero alla posizione: %d \n",i);
        }
    }
}

void Cancella(int vett[], int elementi)
{
    int n;
    printf("inserire il numero da eliminare: \n");
    scanf("%d",&n);
    for(int i = 0; i<elementi; i++)
    {
        if(vett[i]==n)
        {
            vett[i] = 0;
        }
    }
}

void Alternato(int vett[], int elementi)
{
    int temp;
    for(int i = 0; i<elementi -1; i++){
        temp = vett[i];
        vett[i] = vett[i+1];
        vett[i+1] = temp;
        i++;
    }
}

void Ordinamento(int vett[], int elementi)
{
    int temp;

    for(int i = 0; i<elementi-1; i++)
    {
        for(int j = 0; j<elementi - i - 1; j++)
        {
            if(vett[j]> vett[j + 1])
            {
                temp = vett[j];
                vett[j] = vett[j + 1];
                vett[j + 1] = temp;
            }
        }

    }
}


int main()
{
    int n;
    int elementi = 10;
    int vett[elementi];
    printf("opzione:\n1-Stampa elementi array\n2-Stampa inversa degli elementi dell'array\n3-Somma e media degli elementi del vettore\n4-Stampa numeri pari\n5-Stampa numeri dispari\n6-Ricerca di un numero nell'array\n7-Eliminare un elemento dell'array\n8-Alternare a due a due le posizioni del vettore\n9-ordinamento del vettore\n");

    for(int i=0; i<elementi; i++)
    {
        vett[i]= 1 + rand() % 100;
    }
    do{

    do
    {
        printf("inserisci l'opzione che vuoi: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1: Stampa(elementi, vett);break;
            case 2: Stampainversa(vett, elementi);break;
            case 3: SommaMedia(vett, elementi);break;
            case 4: StampaNumeriPari(vett, elementi);break;
            case 5: StampaNumeriDispari(vett, elementi);break;
            case 6: Ricerca(vett, elementi);break;
            case 7: Cancella(vett, elementi);break;
            case 8: Alternato(vett, elementi);break;
            case 9: Ordinamento(vett, elementi);break;
        }
    }while(n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6 && n != 7 && n != 8 && n != 9);
    }while(n != 10);
    return 0;

}