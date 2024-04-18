#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
init= systemd
*/
int p, p_p_naturale, p_padre_dopo;
int main(int argc, char *argv[])
{
    p = fork();
    if (p != 0)
    {
        printf("padre, pid %d, mio figlio ha pid\n", p);
    }
    return 0;
}