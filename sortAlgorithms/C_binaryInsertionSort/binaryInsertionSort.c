#include <stdio.h>
#define N 5

void ordenarPorInsercaoBinaria(int *dados){
  int aux = 0;
  int j, esq, dir, meio;

  for (int i = 1; i < N; i++){
    aux = dados[i];
    esq = 0;
    dir = i;
    while (esq < dir){
      meio = (esq + dir) / 2;
      if (dados[meio] <= aux){
        esq = meio + 1;
      }
      else{
        dir = meio;
      }
    }

    for (j = i; j > esq; j--){
      dados[j] = dados[j - 1];
    }

    dados[dir] = aux;
  }
}

int main(void){
  int dados[] = {5, 4, 3, 2, 1};

  printf("Dados desordenados\n");
  for (int i = 0; i < N; i++){
    printf("%d ", dados[i]);
  }

  ordenarPorInsercaoBinaria(dados);

  printf("\n\n");

  printf("Dados ordenados\n");
  for (int i = 0; i < N; i++){
    printf("%d ", dados[i]);
  }

  return 0;
}