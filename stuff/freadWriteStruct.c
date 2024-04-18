#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_DIM 1024 // Definizione di una costante per la dimensione del buffer

int main(int argc, char *argv[])
{

    // Definizione della struttura 'student' che contiene informazioni su uno studente
    typedef struct
    {
        char name[20];
        char lastname[20];
        int gradePointAverage;
    } student;

    student class[3]; // Creazione di un array di 3 strutture 'student'

    // Inizializzazione dei dati per ciascuno studente nella struttura 'class'
    strcpy(class[0].name, "name1");
    strcpy(class[0].lastname, "lastname1");
    class[0].gradePointAverage = 8;

    strcpy(class[1].name, "name2");
    strcpy(class[1].lastname, "lastname2");
    class[1].gradePointAverage = 9;

    strcpy(class[2].name, "name3");
    strcpy(class[2].lastname, "lastname3");
    class[2].gradePointAverage = 10;

    FILE *contieneStudenti; // Dichiarazione di un puntatore a un oggetto di tipo FILE

    contieneStudenti = fopen(argv[1], "w+"); // Apre o crea un file specificato dall'utente in modalità lettura/scrittura ("w+")

    if (contieneStudenti == NULL)
    {                                                            // Controllo se l'apertura del file ha avuto successo
        printf("errore apertura file destinazione %s", argv[1]); // Stampa un messaggio di errore
        return 0;                                                // Termina il programma
    }

    // Scrive i dati della struttura 'class' nel file
    fwrite(class, sizeof(student), 3, contieneStudenti);

    student secondClass[3]; // Crea un secondo array di strutture 'student'

    // Legge i dati dal file nella struttura 'secondClass'
    fread(secondClass, sizeof(student), 3, contieneStudenti);

    // Stampa i dati letti dal file
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", secondClass[i].name);
        printf("%s\n", secondClass[i].lastname);
        printf("%d\n", secondClass[i].gradePointAverage);
    }

    printf("------------------------\n");

    // Sposta il cursore alla fine del secondo record nella struttura del file
    fseek(contieneStudenti, sizeof(student) * 2, SEEK_SET);

    student stud;

    // Legge i dati dal file nella variabile 'stud'
    fread(&stud, sizeof(student), 1, contieneStudenti);

    printf("%s\n", stud.name);
    printf("%s\n", stud.lastname);
    printf("%d\n", stud.gradePointAverage);

    fclose(contieneStudenti); // Chiude il file
}
