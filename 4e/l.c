#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Creare una biblioteca (3 libri) dove ogni libro ha un titolo, un autore e un prezzo;
 queste tre caratteristiche sono introdotte dall'utente.
Realizzare:
-1 un metodo per inserire i valori scelti dall'utente;

-1 un metodo per stampare il contenuto della bilblioteca(titolo, autore, prezzo);

-2 un metodo per applicare uno sconto al prezzo dei libri (il metodo riceve lo sconto in ingresso,
 per esempio 10% e sconta tutti i libri del 10%. Questo sconto è inserito dall'utente).
Nel main chiamare i metodi1,2.3 e ancora 1 per vedere se lo sconto è stato applicato correttamente.
NELL'IMPLEMENTAZIONE E' OBBLIGATORIO L'UTILIZZO DEI PUNTATORI*/

    typedef struct
    {
        char titolo[50];
        char autore[50]; 
        float prezzo;
    }libro; 
        
    void Inserimento(libro *array[], int i)
    {
            printf("Inserire il titolo del %d° libro: ", i+1); 
            scanf("%s\n", array[i]->titolo); 
            printf("Inserire l'autore del %d° libro: ", i+1);
            scanf("%s\n", array[i]->autore); 
            printf("Inserire il prezzo %d° libro: ", i+1);
            scanf("%f\n", &array[i]->prezzo);
    }

    void Visualizzazione(libro *array[], int lung)
    {
        for(int i = 0; i<lung; i++)
        {
            printf("Libro %d", i+1);
            printf("Ttitolo: %s\n", array[i]->titolo);
            printf("Autore: %s\n", array[i]->autore);
            printf("Prezzo: %.2f\n", array[i]->prezzo);
        }
    }

    int main()
    {
        const int lung = 3;
        
        libro *biblioteca[lung]; 
        
        for(int i = 0; i<lung; i++)
        {
            biblioteca[i] = (libro *)malloc(lung * sizeof(libro));
            Inserimento(biblioteca, i);
        }

        Visualizzazione(biblioteca, lung); 

    return 0; 
}