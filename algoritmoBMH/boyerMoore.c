#include <stdio.h>
#include <string.h>
#define MAXCHAR 256

int buscaBmh(char *T, char *P){
    int pos, i, r;
    int n = strlen(T);
    int m = strlen(P);
    int alfabeto[MAXCHAR];  
    int ocorrencias = 0;

    // Pré-processamento
    for(i = 0 ; i < MAXCHAR ; i++){
        alfabeto[i] = m; // Todas as posições do vetor alfabeto recebe o tamanho do Padrão
    }
    for(i = 1 ; i < m ; i++){
        alfabeto[T[i-1]] = m - i; // Alfabeto na posição do texto na posição i-1(ou seja, alfabeto na posições do texto na tabela ascii) recebe o tamanho do padrão - i
    }

    // Busca
    pos = m;
    while(pos <= n){
        r = 1;
        while(T[pos-r] == P[m-r] && r <= n){
            r++;
        }

        if(pos == n){
            pos++;
        }

        if(r > m){
            ocorrencias++;
        }else{
            pos += alfabeto[T[pos-r]];
        }
    }

    return ocorrencias;

}

int main(int argc, char const *argv[]){
    char texto[] = "aabcacbacbacac";
	char padrao[] = "cacbac";

    int ocorr;

    ocorr = buscaBmh(texto, padrao);

    printf("Casamento na posição: %d \n", ocorr);

    return 0;
}
