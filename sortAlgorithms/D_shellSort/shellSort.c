#include <stdio.h>
#define N 5

void shellSort(int* dados){
  int h = 1, aux, j;
  while(h < N){
    h = 3 * h + 1;
  }
  while(h > 1){
    h = h/3;
    for(int i = h ; i < N ; i++){
      aux = dados[i];
      j = i - h;
      while(j >= 0 && aux < dados[j]){
        dados[j+h] = dados[j];
        j = j - h;
      }
      dados[j+h] = aux;
    }
    
  }
}

int main(void) {
  int dados[] = {5,4,3,2,1};

  printf("Dados desordenados\n");
  for(int i = 0 ; i < N ; i++){
    printf("%d ", dados[i]);
  }
  
  shellSort(dados);

  printf("\n\n");

  printf("Dados ordenados\n");
  for(int i = 0 ; i < N ; i++){
    printf("%d ", dados[i]);
  }
  
  return 0;
}