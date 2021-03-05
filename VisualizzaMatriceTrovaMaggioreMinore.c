#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void inputmat(int mat[][MAX], int maxc, int maxr);
int inputdim();
void stampamat(int mat[][MAX], int maxc, int maxr);
void trovamaggiore(int mat[][MAX], int maxc, int maxr);
void trovaminore(int mat[][MAX], int maxc, int maxr);

int main(){
    int mat[MAX][MAX];
    int maxr, maxc, i, j, valore, cont, caseswitch, fine;
    cont = 0;
    fine = 0;
    maxr = inputdim();
    maxc = inputdim();
    inputmat(mat, maxc, maxr);
    do{
        printf("Cosa vuoi fare?\n1) Trova il valore maggiore\n2) Trova il valore minore\n3) Stampa la matrice\n4) FINE\nINSERISCI LA TUA SCELTA QUI: ");
        scanf("%d", &caseswitch);
        switch(caseswitch){
            case 1: 
                trovamaggiore(mat, maxc, maxr);
                break;
            case 2: 
                trovaminore(mat, maxc, maxr);
                break;
            case 3: 
                stampamat(mat, maxc, maxr);
                break;
            case 4: 
                printf("FINE\n");
                fine = 1;
                break;
            default:
                printf("Scelta non valida\n");
                break;
        }
    }while(fine == 0);
    system("pause");
    return 0;
}

int inputdim(){
    int maxc;
    do{
        printf("Inserisci la dimensione massima: (PRIMA RIGHE POI COLONNE; PREMERE INVIO PER OGNI VALORE; MAX %d): ", MAX);
        scanf("%d", &maxc);
    }while(maxc > MAX || maxc < 1);
    return maxc;
}


void inputmat(int mat[][MAX], int maxc, int maxr){
    int i, j;
    for(i = 0; i < maxc; i++){
        for(j = 0; j < maxr; j++){
            printf("Inserisci il numero in posizione (%d; %d): ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void stampamat(int mat[][MAX], int maxc, int maxr){
    int i, j;
    for(i = 0; i < maxc; i++){
        for( j = 0; j < maxr; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void trovamaggiore(int mat[][MAX], int maxc, int maxr){
    int i, j, cont, mag;
    cont = 0;
    mag = -9999;
    for(i = 0; i < maxc; i++){
        for(j = 0; j < maxr; j++){
            if(mat[i][j] > mag){
                mag = mat[i][j];
            }
        }
    }  
    printf("Il numero maggiore della matrice e' %d.\n", mag);
}
void trovaminore(int mat[][MAX], int maxc, int maxr){
    int i, j, cont, min;
    cont = 0;
    min = 9999;
    for(i = 0; i < maxc; i++){
        for(j = 0; j < maxr; j++){
            if(mat[i][j] < min){
                min = mat[i][j];
            }
        }
    }  
    printf("Il numero minore della matrice e' %d.\n", min);
}