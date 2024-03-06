#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

#define STRING_LEN 50
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"

void Error(char *s)
{
    perror(s);
    exit(EXIT_FAILURE);
}

int main()
{
    if (mkfifo("fifo1", 0777) < 0)
    {
        if (errno != EEXIST)
            Error("Errore nella creazione della fifo1");
    }
    if (mkfifo("fifo2", 0777) < 0)
    {
        if (errno != EEXIST)
            Error("Errore nella creazione della fifo2");
    }
    char *buffer;
    int fd;
    int p;
    if ((p = fork()) < 0)
        Error("Errore nella creazione del processo figlio\n");
    if (p > 0)
    {
        if ((fd = open("fifo2", O_WRONLY)) < 0)
            Error("Errore nell'apertura di fifo2 in writeonly");
        buffer = malloc(STRING_LEN);
        while (1)
        {
            printf(ANSI_COLOR_BLUE "CHAT2: ");
            fgets(buffer, STRING_LEN, stdin);
            write(fd, buffer, STRING_LEN);
            if (strcmp(buffer, "HALT\n\0") == 0)
            {
                printf("\nTerminazione programma\n");
                close(fd);
                kill(p, SIGKILL);
                free(buffer);
                exit(EXIT_SUCCESS);
            }
        }
    }
    else
    {
        if ((fd = open("fifo1", O_RDONLY)) < 0)
            Error("Errore nell'apertura di fifo1 in readonly");
        buffer = malloc(STRING_LEN);
        while (1)
        {
            printf("\33[2K\r"); // erases the entire line your cursor is currently on, \r resetta il cursore all'inizio
            read(fd, buffer, STRING_LEN);
            printf(ANSI_COLOR_GREEN "CHAT1: %s" ANSI_COLOR_BLUE "CHAT2: ", buffer);
            fflush(stdout);
            if (strcmp(buffer, "HALT\n\0") == 0)
            {
                printf("\nTerminazione programma\n");
                close(fd);
                kill(getppid(), SIGKILL);
                free(buffer);
                exit(EXIT_SUCCESS);
            }
        }
    }
}