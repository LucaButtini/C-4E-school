#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // questo prende il posto dell'altro
    printf("sono l'exe chiamato: mio pid %d\n", getpid());
    printf("%s\n", argv[0]);
    printf("%s\n", argv[1]);

    return 0;
}