#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("ciao\n");
    printf("Quanti parametri: %d\n", argc);

    for(int i=0; i<argc;i++)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}