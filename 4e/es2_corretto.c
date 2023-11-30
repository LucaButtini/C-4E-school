#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int p, i;

int main(int argc, char *argv[])
{
    p = getpid();
    printf("Sono il Padre: %d\n", p);

    for (i = 0; i < 2; i++)
    {
        if (p != 0)
        {
            p = fork();
            if (p == 0)
            {
                printf("\nsono il figlio %d\n", p);
            }
        }

    }
    return 0;
}