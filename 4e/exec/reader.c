// La differenza è che qua si usa la funzione execv al posto di execl. Abbiamo poi la lettura e scrittura di dati da file e nell'altro c'era il passaggio di una struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// definizione costanti
#define BLOCK_DIM 1024
#define PROGRAM "writer"
// funzione di spawn
int spawn(char program[], char *argument[])
{
  int pid;
  pid = fork(); // creo nuovo processo
  if (pid < 0)  // controllo se il fork ha fallito
    return -1;
  if (pid > 0) // padre
    return 0;
  // figlio
  execv(program, argument); // eseguo il nuovo processo, argomenti nome programma e la sua riga di comando
  abort();                  // se l'esecuzione del nuovo processo fallisce, termino il processo figlio
}

int main(int argc, char *argv[])
{
  FILE *file;
  int fifo;
  unsigned char buffer[BLOCK_DIM];
  int n;
  char *arg[3];
  // controllo argomenti di argc
  if (argc != 3)
  {
    printf("Uso: %s file-origine file-destinazione\r\n", argv[0]);
    return 0;
  }
  // creo la riga di comando che passerò al figlio
  // questa serve a mandare in esecuzione il processo consumatore, writer
  arg[0] = (char *)malloc(strlen(PROGRAM) + 1);
  strcpy(arg[0], PROGRAM);
  arg[1] = (char *)malloc(strlen(argv[2]) + 1);
  strcpy(arg[1], argv[2]);
  arg[2] = NULL;

  if (spawn(PROGRAM, arg) < 0) // controllo valore restituito dalla funzione spawn 
  {
    printf("Errore creazione processo\r\n");
    free(arg[0]);
    free(arg[1]);
    return 0;
  }
  // creazione della fifo e controllo se è già stata creata
  fifo = open("my_fifo", O_WRONLY);
  if (fifo < 0)
  {
    printf("Errore apertura FIFO\r\n");
    free(arg[0]);
    free(arg[1]);
    return 0;
  }
  // apertura in lettura del file binario e controllo corretta apertura
  file = fopen(argv[1], "rb");
  if (file == NULL)
  {
    printf("Errore apertura file \"%s\"\r\n", argv[1]);
    close(fifo);
    free(arg[0]);
    free(arg[1]);
    return 0;
  }
  // lettura dati dal file di origine e scrittura nella fifo
  while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0)
    write(fifo, buffer, n);

  fclose(file);
  close(fifo);
  free(arg[0]);
  free(arg[1]);
  return 1;
}
