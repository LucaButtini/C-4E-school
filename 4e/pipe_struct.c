#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#define DIM_ARRAY 2

typedef struct
{
    char titolo[100];
    char autore[100];
    float prezzo;
} libro;

int main(int argc, char *argv[])
{
    libro books[DIM_ARRAY];
    int p, status;
    int fd[2];

    if (pipe(fd) == -1)
    {
        printf("errore creazione pipe\n");
        exit(-1);
    }
    p = fork();
    if (p < 0)
    {
        printf("errore generazione figlio\n");
        exit(-1);
    }
    if (p > 0)
    {
        // padre
        strcpy(books[0].titolo, "Harry potter");
        strcpy(books[0].autore, "J.K. Rowling");
        books[0].prezzo = 6.90;
        strcpy(books[1].titolo, "Hunger Games");
        strcpy(books[1].autore, "Suzanne Collins");
        books[1].prezzo = 10.04;
        close(fd[0]);

        for (int i = 0; i < DIM_ARRAY; i++)
        {
            // scrivo con la pipe i due libri
            write(fd[1], books[i].titolo, sizeof(books[i].titolo));
            write(fd[1], books[i].autore, sizeof(books[i].autore));
            write(fd[1], &books[i].prezzo, sizeof(books[i].prezzo));
        }
        close(fd[1]);
        wait(&status); // aspetto con la wait
    }
    else
    {
        // figlio
        close(fd[1]);
        for (int i = 0; i < DIM_ARRAY; i++)
        {
            // leggo con la pipe i libri
            read(fd[0], books[i].titolo, sizeof(books[i].titolo));
            read(fd[0], books[i].autore, sizeof(books[i].autore));
            read(fd[0], &books[i].prezzo, sizeof(books[i].prezzo));
        }
        close(fd[0]);
        for (int i = 0; i < DIM_ARRAY; i++)
        {
            printf("\nTitolo: %s\n", books[i].titolo);
            printf("Autore: %s\n", books[i].autore);
            printf("Prezzo: %f\n", books[i].prezzo);
        }
    }
    return 0;
}