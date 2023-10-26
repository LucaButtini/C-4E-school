#include <stdio.h>
#include <stdlib.h>
#define BUFFER_DIM 1024

int main(int argc, char *argv[])
{
    FILE *origine, *destinazione;
    int n;
    unsigned char buffer[BUFFER_DIM];
    if(argc != 3){
        printf("Inserire correttamente i parametri\n");
        exit(1);
    }

    origine = fopen(argv[1], "r");
    if(origine == NULL){
        printf("Errore nell'apertura del file origine\n");
        exit(1);
    }
        destinazione = fopen(argv[2], "w");
        if(destinazione == NULL){
    printf("Errore nell'apertura del file destinazione\n");
    exit(1);
    }
    while(!feof(origine)){
        n = fread(buffer, 1, BUFFER_DIM, origine);// inserisce gli elementi di origine nel vettore 
        if(n > 0){
            fwrite(buffer, 1, n, destinazione); // 1 si riferisce ai byte presi per volta, serve per stampare in destinazione gli elementi del puntatore buffer
        }
    }
    fclose(origine);
    fclose(destinazione);

    return 0;
}