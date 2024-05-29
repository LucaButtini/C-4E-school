#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#define BUFFER_DIM 1024
typedef struct {
  char nome[100];
  char cognome[100];
  int media;
} studente;

void *print_student(void *par) {
  studente *std = (studente *)par; // faccio il cast del parametro a studente
  // studente stud = *(studente*) par; //con la struct senza puntatore
  // printf("Nome: %s, Cognome: %s, Media: %d\n", std.nome, std.cognome,
  // std.media); //con la struct no puntatore
  printf("Nome: %s, Cognome: %s, Media: %d\n", std->nome, std->cognome,
         std->media);
  pthread_exit NULL;
}

void *file_student(void *par) {
  studente *std = (studente *)par;
  FILE *file;
  unsigned char buffer[BUFFER_DIM];
  file = fopen("file.txt", "wb");
  if (file == NULL) {
    printf("Errore apertura file origine\n");
    pthread_exit NULL;
  }
  // fwrite(std, sizeof(studente), 1, file);
  fprintf(file, "Nome: %s Cognome: %s Media: %d", std->nome, std->cognome, std->media);

  fclose(file);
  pthread_exit NULL;
}

int main(int argc, char *argv[]) {
  studente std;
  pthread_t printStd, fileStd;
  strcpy(std.nome, "marco");
  strcpy(std.cognome, "verdi");
  std.media = 9;
  pthread_create(&printStd, NULL, &print_student,(void *)&std); // casto lo std a void per passarlo come parametro
  pthread_create(&fileStd, NULL, &file_student, (void *)&std);
  pthread_join(printStd, NULL);
  pthread_join(fileStd, NULL);
  return 0;
}
