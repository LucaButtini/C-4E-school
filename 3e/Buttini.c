#include <stdio.h>
void main()
{ // Buttini Luca fila 3
    /*Scrivere un programma in c che dopo aver acquisito da tastiera un elenco di coppie di valori relativi al peso
ed al volume di una serie di contenitori di un magazzino, visualizzi a video:
1) Il peso specifico (peso/volume) per ciascun contenitore;
2) La media dei pesi specifici;
3) La media dei pesi specifici compresi tra i valori pari a 5 e 10 estremi inclusi;*/
    int numeroVolte = 0, contaSpec510 = 0;
    float peso = 0, volume = 0, pesoSpecifico = 0, mediaPesiSpec = 0, mediaPesiSpec510 = 0;//, pesoSpecifico510 = 0; // la variabile mediaPesiSpec510 indica la media dei pesi specifici col valore compreso fra 5 e 10.
    do
    {
        printf("Inserisci quante coppie di valori vuoi inserire\n");
            scanf("%d", &numeroVolte);
    } while (numeroVolte < 0); // questo ciclo do while effettua il controllo che l'utente inserisca un valore maggiore di 0.

    for (int i = 0; i < numeroVolte; i++) // il ciclo for ripete le istruzioni al suo interno in base a quante volte l'utente vuole inserire le coppie di valori.
    {

        do
        {
            printf("Inserisci il peso del contenitore\n");
            scanf("%f", &peso);
        } while (peso < 0); // questo ciclo do while effettua il controllo che l'utente inserisca un valore maggiore di 0.
         do
        {
            printf("Inserisci i>= volume del contenitore\n");
            scanf("%f", &volume);
        } while (volume < 0); // questo ciclo do while effettua il controllo che l'utente inserisca un valore maggiore di 0.
    
        pesoSpecifico = peso / volume;//calcolo e output volume specifico
        printf("Il peso specifico del contenitore è: %f\n", pesoSpecifico);
        
        if (pesoSpecifico > 5 || pesoSpecifico < 10)//se il peso specifico è compreso tra 5 e 10 mi fa la media dei pesi specifi
        {
            contaSpec510++;
            mediaPesiSpec510 = pesoSpecifico / contaSpec510;
        }
    }
    mediaPesiSpec = pesoSpecifico / numeroVolte;
    printf("La media dei pesi specifici è: %f\n", mediaPesiSpec);
    printf("La media dei pesi specifici compresi tra 5 e 10 è: %f\n", mediaPesiSpec510);
}