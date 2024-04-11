#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

// POSIX
void *stampabuongiorno(void *par)
{
    printf("%s\n", (char *)par);
    return NULL;
}
void *stampasera(void *par)
{
    printf("%s\n", (char *)par);
    return NULL;
}
void *stampabuonanotte(void *par)
{
    printf("%s\n", (char *)par);
    return NULL;
}

int main()
{
    pthread_t theadGiorno, ThreadSera, ThreadNotte;
    char *msg1 = "buongiorno", msg2 = "buonasera", msg3 = "buonanotte";
    printf("ciao\n");
    pthread_create(&theadGiorno, NULL, &stampabuongiorno, msg1);
    pthread_create(&ThreadSera, NULL, &stampasera, msg2);
    pthread_create(&ThreadNotte, NULL, &stampabuonanotte, msg3); // PRIMO PARAMETRO ha bisogno del thread, SECONDO PARAMETRO è semrpre null, TERZO PARAMETRO funzione
    pthread_join(theadGiorno, NULL);
    pthread_join(ThreadSera, NULL);
    pthread_join(ThreadNotte, NULL);
    // printf("buonasera\n");
    // printf("buongiorno\n");
    // printf("buonanotte\n");
    return 0;
}