#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types
3.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> //serve per aprire la fifo
#include <errno.h>
int main(int argc, char *argv[])
{
    int fd;
    // 0777 per dare i permessi ad ogni utente
    if (mkfifo("myfifo1", 0777) == -1)
    {
        // controllo errore generazione della fifo
        if(errno!=EEXIST)
        {
            printf("Errore nella creazione della fifo\n");
        return 1;
        } 
    }

    // apro la fifo in write
    fd = open("myfifo1", O_WRONLY); // è 1 poiche ho aperto in write
    printf("\nho aperto la fifo\n");
    // le dichiarazioni vanno fatto dopo la creazione della fifo/pipe
    int x = 90;
    if (write(fd, &x, sizeof(x)) == -1)
    {
        printf("Errore in scrittura della fifo\n");
        return 2;
    }
    printf("\nho scritto  nella fifo\n");
    close(fd);
    return 0;
}
