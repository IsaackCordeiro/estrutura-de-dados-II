#include <stdio.h>
#define N 5

void mergeSort(int* dados, int ini, int fim);
void intercalar(int* dados, int ini, int fim, int meio);

int main(void) {
  int dados[] = {5,4,3,2,1};

  printf("Dados desordenados\n");
  for(int i = 0 ; i < N ; i++){
    printf("%d ", dados[i]);
  }
  
  mergeSort(dados, 0, N-1);

  printf("\n\n");

  printf("Dados ordenados\n");
  for(int i = 0 ; i < N ; i++){
    printf("%d ", dados[i]);
  }
  
  return 0;
}

void mergeSort(int* dados, int ini, int fim){
  int meio;
  if(ini < fim){
    meio = (ini + fim)/2;
    mergeSort(dados, ini, meio);
    mergeSort(dados, meio+1, fim);
    intercalar(dados, ini, fim, meio);
  }
}

void intercalar(int* dados, int ini, int fim, int meio){
  int tmp[N], k = 0, i = ini, j = meio+1;
  while(i <= meio || j <= fim){
    if(i == meio+1 || dados[j]<dados[i] && j != fim+1){
      tmp[k] = dados[j];
      j++;
      k++;
    } else{
      tmp[k] = dados[i];
      i++;
      k++;
    }
  } 
  for(int i = ini ; i <= fim ; i++){
    dados[i] = tmp[i-ini];
  }
}