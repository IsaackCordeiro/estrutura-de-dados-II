#include <stdio.h>
#include <stdlib.h>
#define n 10  // Texto
#define m 3   // Padrão

int forcaBruta(char *texto, char *padrao);

int main()
{
    char texto[n];
    char padrao[m];
    int retorno;

    printf("Digite o texto: ");
    scanf("%s", texto);

    printf("Digite a o padrao: ");
    scanf("%s", padrao);

    retorno = forcaBruta(texto, padrao);

    if(retorno == -1){
      printf("Error! Padrao nao encontrado\n");
    }else{
      printf("Padrao encontrado!\n A partir da posicao: %d\n", retorno);
    }

    return 0;
}


int forcaBruta(char *texto, char *padrao){
    int j;

    for(int i = 0 ; i <= n-m ; i++){
        j = 0;
        while(j < m && texto[i+j] == padrao[j]){
            j++;
            if(j == m){
                return i;
            }
        }
    }

    return -1;
}
