#include <stdio.h> 
#include <string.h>
//
void preencherNotas(float notas[][3], char nomeArquivo[]);
void gerarRelatorio(float notas[][3]);
//
int main(){
    //
    float not[10][3];
    char nomeArq[30];
    //
    scanf("%s", nomeArq);
    //
    preencherNotas(not, nomeArq);
    gerarRelatorio(not);
    //
    return 0;
}
//
void preencherNotas(float notas[][3], char nomeArquivo[]){
    FILE *arq;
    arq = fopen(nomeArquivo, "r");
    if(aeq == NULL){
        return;
    }
    //
    int cont = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 3; j++ ){
            while(fscanf(arq, "%f", &notas[i][j]) == 3){
                cont++;
            }
        }
    }
}
//
void gerarRelatorio(float notas[][3]){
    float piorNota;
    int piorNota1 = 0;
    int piorNota2 = 0;
    int piorNota3 = 0;
    int indice;
    //
    for(int i = 0; i < 10; i++){
        indice = 0;
        piorNota = notas[i][0];
        for(int j = 0; j < 3; j++){
            if(notas[i][j] < piorNota){
                indice = j;
                piorNota = notas[i][j];
            }
        } if(indice == 0){
            piorNota1++;
        } else if(indice == 1){
            piorNota2++;
        } else if(indice == 2){
            piorNota3++;
        }
    }
    printf("%d %d %d", piorNota1, piorNota2, piorNota3);
}
