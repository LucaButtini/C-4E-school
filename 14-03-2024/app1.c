#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // exec apre un nuovo processo
    // il processo che esegue exec viene sostituito dal nuobo processo
    // il nuovo processo prende il pid di questo
    printf("sono il processo in esecuzione: mio pid %d\n", getpid());
    // nome programma, gli altri sono gli args che passerò a quel programma partendo da 0.
    // nell'altro inizio quindi da argv[0]
    // quando trova null finisce la lista dei parametri
    execl("./eseguibile_chiamato.exe", "ciao", "buongiorno", NULL);
    printf("\nse visuaizzi questo messaggio, la chiamata ha avuto esito negativo\n");
    return 0;
}