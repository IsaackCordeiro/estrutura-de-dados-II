#include <stdio.h>
#include <stdlib.h>
#define M 5 // tamanho do padrão
#define N 15 // tamanho do texto

int *preProcessamentoKMP(char *padrao);

int buscaKMP(char *texto, char *padrao);

int main(){
    char texto[N] = "ababcabcabababd";
    char padrao[M] = "ababd";
    int retorno, *retornoPre;

    retorno = buscaKMP(texto, padrao);

    if(retorno != -1){
        printf("Achou. Pos: %d\n", retorno);
    }else{
        printf("Padrao nao encontrado\n");
    }

    return 0;
}

int *preProcessamentoKMP(char *padrao){
    int i, j = -1;
    
    int *preProcess = malloc(M * sizeof(int)); // Vetor que armazena os estados dos prefixos que são sufixos

    preProcess[0] = j;

    for(i = 1 ; i < M ; i++){
        while (j > -1 && padrao[j+1] != padrao[i]){
            j = preProcess[j];
        }
        if(padrao[i] == padrao[j+1]){
            j++;
        }
        preProcess[i] = j;
        
    }
    for(int x = 0; x < M ; x++){
        printf("%d | ", preProcess[x]);
    }

    return preProcess;

}

int buscaKMP(char *texto, char *padrao){
    int i;
    int *preProcess = preProcessamentoKMP(padrao);
    int j = -1;

    if(!preProcess){
        return -1;
    }

    for(i = 0 ; i < N ; i++){
        while (j > -1 && padrao[j+1] != texto[i]){
            j = preProcess[j];
        }

        if(texto[i] == padrao[j+1]){
            j++;
        }

        if(j == M-1){
            return i-j;
        }
        
    }

    return -1;
}