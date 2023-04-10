#include <stdio.h>
#define N 5

int buscaSequencial(int *vet, int key);

int main(){
    
    int vetor[N], retorno, chave;

    for(int i = 0 ; i < N ; i++){
        printf("Digite um numero na posicao %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("Digite a chave que queria buscar: ");
    scanf("%d", &chave);

    retorno = buscaSequencial(vetor, chave);

    if(retorno == -1){
        printf("Error! Chave nao encontrada!\n");
    }else{
        printf("Chave encontrada: %d\n", retorno);
    }

    return 0;
}

int buscaSequencial(int *vet, int key){

    for(int i = 0 ; i < N ; i++){ // Percorre lista
        if(key == vet[i]){  // Verifica se a chave é igual ao elemento na posição i da lista
            return key;
        }
    }

    return -1;
}