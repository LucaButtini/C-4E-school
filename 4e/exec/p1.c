#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
typedef struct
{
    char nome[100];
    char cognome[100];
    int eta;
} studente;
int p, status;
int main(int argc, char *argv[])
{
    studente std;
    strcpy(std.nome, "carmine");
    strcpy(std.cognome, "valacchio");
    std.eta = 18;
    p = fork();
    if (p < 0)
    {
        printf("Errore creazione processo figlio\n");
        exit(-1);
    }
    else if (p > 0) // padre
    {
        wait(&status);
        exit(0);
    }
    else // figlio
    {
        char eta_str[20];                // Definizione di un array di caratteri per contenere la stringa formattata
        sprintf(eta_str, "%d", std.eta); // Conversione dell'età da int a stringa e salvataggio in eta_str
        printf("%s\n", eta_str);
        // execl("./p2.exe", std.nome, std.cognome, eta_str, NULL);
        execl("./p2", "p2", std.nome, std.cognome, eta_str, NULL);

        printf("\nse visuaizzi questo messaggio, la chiamata ha avuto esito negativo\n");
        exit(-1);
    }
    return 0;
}