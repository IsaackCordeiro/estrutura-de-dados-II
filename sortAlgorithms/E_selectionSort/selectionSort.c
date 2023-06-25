#include <stdio.h>
#define N 5

void selecaoDireta(int* dados){
  int aux;
  
for(int i = 0 ; i < N-1 ; i++){
    int min = i;
    // Percorre a lista buscando o menor valor
    for(int j = i+1 ; j < N ; j++){
      if(dados[j] < dados[min]){
        min = j;
      }
    }

    // Se min tiver sido alterado, significa que existe um menor valor do que a posição i, portanto troca
    if(i != min){
      aux = dados[min];
      dados[min] = dados[i];
      dados[i] = aux;
    }
  }
}

int main(void) {
  int dados[] = {5,4,3,2,1};

  printf("Dados desordenados\n");
  for(int i = 0 ; i < N ; i++){
    printf("%d ", dados[i]);
  }
  
  selecaoDireta(dados);

  printf("\n\n");

  printf("Dados ordenados\n");
  for(int i = 0 ; i < N ; i++){
    printf("%d ", dados[i]);
  }
  
  return 0;
}