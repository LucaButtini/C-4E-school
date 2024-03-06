#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define DIM 1024
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_RESET "\x1b[0m"  // Reset color to default

int fd, p, n;
unsigned char *buffer;

int main(int argc, char *argv[])
{
    buffer = (unsigned char *)malloc(DIM * sizeof(unsigned char));
    if (buffer == NULL)
    {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    do
    {
        p = fork();
        if (p < 0)
        {
            printf("errore generazione figlio\n");
            exit(EXIT_FAILURE);
        }
        if (p > 0) // padre
        {
            fd = open("fchat1", O_WRONLY);
            printf(ANSI_COLOR_BLUE "CHAT1: ");
            scanf(" %[^\n]", buffer);
            n = write(fd, buffer, strlen(buffer) + 1); // +1 to include the null terminator
            if (n < 0)
            {
                printf("errore scrittura\n");
                exit(EXIT_FAILURE);
            }
            close(fd);
        }
        else // figlio
        {
            fd = open("fchat2", O_RDONLY);
            n = read(fd, buffer, DIM);
            if (n < 0)
            {
                printf("errore lettura\n");
                exit(EXIT_FAILURE);
            }
            printf(ANSI_COLOR_GREEN "CHAT2: %s" ANSI_COLOR_RESET ANSI_COLOR_BLUE "CHAT1: \n", buffer);
            close(fd);
        }
    } while (1);

    free(buffer); // Don't forget to free the allocated memory
    return 0;
}
