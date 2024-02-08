#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define BUFFER_DIM 1024

int main(int argc, char *argv[])
{
    int p, n;
    int fd[2];
    FILE *origine, *destinazione;
    unsigned char buffer[BUFFER_DIM]; // char senza segno

    // Creazione della pipe
    if (pipe(fd) == -1)
    {
        printf("errore creazione pipe\n");
        exit(-1);
    }

    // Creazione del primo figlio
    p = fork();

    if (p < 0)
    {
        printf("errore generazione figlio\n");
        exit(-1);
    }

    if (p > 0) // padre
    {
        // Chiusura dell'estremità di lettura nella pipe nel processo padre
        close(fd[0]);

        // Controllo del numero corretto di parametri
        if (argc != 4)
        {
            printf("numero parametri errato\n");
            exit(-1);
        }

        // Apertura del file di origine in modalità lettura
        origine = fopen(argv[1], "r");

        // Controllo dell'apertura del file di origine
        if (origine == NULL)
        {
            printf("Errore apertura file origine\n");
            exit(-1);
        }

        // Lettura dal file di origine e scrittura sulla pipe
        while ((n = fread(buffer, 1, sizeof(buffer), origine)) > 0)
        {
            write(fd[1], buffer, n);
        }

        // Chiusura del file di origine e dell'estremità di scrittura nella pipe
        fclose(origine);
        close(fd[1]);

        // Creazione del secondo figlio
        p = fork();

        if (p == 0) // figlio 1
        {
            // Chiusura dell'estremità di scrittura nella pipe nel processo figlio 1
            close(fd[1]);

            // Apertura del file di destinazione in modalità scrittura
            destinazione = fopen(argv[2], "w");

            // Controllo dell'apertura del file di destinazione
            if (destinazione == NULL)
            {
                printf("Errore apertura file destinazione\n");
                close(fd[0]);
                exit(-1);
            }

            // Lettura dalla pipe e scrittura nel file di destinazione
            while ((n = read(fd[0], buffer, sizeof(buffer))) > 0)
            {
                fwrite(buffer, 1, n, destinazione);
            }

            // Chiusura del file di destinazione e dell'estremità di lettura nella pipe
            fclose(destinazione);
            close(fd[0]);
        }
        else // secondo figlio
        {
            char car;
            int conta = 0;

            // Riapertura del file di origine in modalità lettura
            origine = fopen(argv[1], "r");

            // Conteggio delle occorrenze del carattere specificato
            while ((car = fgetc(origine)) != EOF)
            {
                if (car == argv[3][0]) // confronta il carattere letto con il carattere specificato
                {
                    conta++;
                }
            }

            // Stampa del risultato
            printf("\nIl carattere [%s] è presente [%d] volte\n", argv[3], conta);

            // Chiusura del file di origine
            fclose(origine);
        }
    }

    return 0;
}
