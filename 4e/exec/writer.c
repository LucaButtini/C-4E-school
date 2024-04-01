#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BLOCK_DIM 1024

int main(int argc, char *argv[])
{
     FILE *file;
     unsigned char buffer[BLOCK_DIM];
     int n;
     int fifo;

     if (argc != 2) // controllo argomenti di argc
     {
          printf("Uso: %s file\r\n", argv[0]);
          return 0;
     }

     fifo = open("my_fifo", O_RDONLY); // apro fifo in lettura  e controllo la corretta apertura
     if (fifo < 0)
     {
          printf("Errore apertura FIFO\r\n");
          return 0;
     }
     // apro il file binario in scrittura e controllo la corretta apertura
     file = fopen(argv[1], "wb");
     if (file == NULL)
     {
          printf("Errore apertura file \"%s\"\r\n", argv[1]);
          close(fifo);
          return 0;
     }
     // leggo i dati dalla fifo e gli scrive nel file di destinazione
     while ((n = read(fifo, buffer, sizeof(buffer))) > 0)
          fwrite(buffer, 1, n, file);
     close(fifo);
     fclose(file);
     return 1;
}
