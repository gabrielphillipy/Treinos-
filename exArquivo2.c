#include <stdio.h>
#include <string.h>
//
struct produto {
    char nomeProduto[50];
    int codigo;
    float preco;
};
//
typedef struct produto produto;
//
int carregarProdutos(produto vetor[], char nomeArquivo[]);
int buscarPorNome(produto vetor[], int tam, char nomeProduto[]);
//
int main(){
    int total;
    produto vet[100];
    char nomeArq[] = "produtos.txt";
    char nomeProduto[40];
    int posicao;
    //
    total = carregarProdutos(vet, nomeArq);
    //
    scanf("%s", nomeProduto);
    //
    posicao = buscarPorNome(vet, total, nomeProduto);
    //
    if(posicao != -1){
        printf("Produto Encontrado:\n");
        printf("Nome: %s\n", vet[posicao].nomeProduto);
        printf("Codigo: %d\n", vet[posicao].codigo);
        printf("Valor: %0.2f\n", vet[posicao].preco);
    } else {
        printf("Produto não encontrado\n");
    }
    //
    return 0;
}
//
int carregarProdutos(produto vetor[], char nomeArquivo[]){
    FILE *arq;
    arq = fopen(nomeArquivo, "r"); 
    if(arq == NULL){
        return 1;
    }
    int i = 0;
    while(fscanf(arq, "%s %d %f", vetor[i].nomeProduto, &vetor[i].codigo, &vetor[i].preco) == 3){
        i++;
    }
    fclose(arq);
    //
    return i;
}
//
int buscarPorNome(produto vetor[], int tam, char nomeProduto[]){
    for(int i = 0; i < tam; i++){
        if(strcmp(nomeProduto, vetor[i].nomeProduto) == 0){
            return i;
        }
    }
    return -1;
}
