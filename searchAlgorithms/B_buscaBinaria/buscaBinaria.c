#include <stdio.h>
#define N 5

int buscaBinaria(int *vet, int key);

int main(){
    
    int vetor[N], retorno, chave;

    for(int i = 0 ; i < N ; i++){
        printf("Digite um numero na posicao %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("Digite a chave que queria buscar: ");
    scanf("%d", &chave);

    retorno = buscaBinaria(vetor, chave);

    if(retorno == -1){
        printf("Error! Chave nao encontrada!\n");
    }else{
        printf("Chave encontrada: %d\n", retorno);
    }

    return 0;
}

int buscaBinaria(int *vet, int key){
    int inicio = 0;
    int fim = N-1;
    int meio;

    while(inicio <= fim){
        meio = (inicio + fim) / 2;

        if(key > vet[meio]){
            inicio = meio + 1;
        }else if(key < vet[meio]) {
            fim = meio - 1;
        }else{
            return vet[meio];
        }
    }

    return -1;
}
