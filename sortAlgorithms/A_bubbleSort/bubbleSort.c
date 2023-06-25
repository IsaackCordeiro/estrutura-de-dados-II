#include <stdio.h>
#include <string.h>
#define N 5

void bubbleSort(int *dados){
    int aux;
    for (int i = N - 1; i > 1; i--){
        for (int j = 0; j < i; j++){
            if (dados[j] > dados[j + 1]){
                aux = dados[j];
                dados[j] = dados[j + 1];
                dados[j + 1] = aux;
            }
        }
    }
}

void bubbleSortStopCodition(int *dados){
    int aux;
    int trocou = 1;
    int fim = N-1;
    while (trocou){
      trocou = 0;
      for(int j = 0 ; j < fim ; j++){
        if(dados[j] > dados[j+1]){
          aux = dados[j];
          dados[j] = dados[j+1];
          dados[j+1] = aux;
          trocou = 1;
        }
      }
      fim--;
    }  
}

int main(void){
    int dados[N] = {1, 3, 12, 9, 2};
    int dados2[N] = {1, 3, 12, 9, 2};

    int len1 = sizeof(dados) / sizeof(int);
    int len2 = sizeof(dados2) / sizeof(int);

    printf("Dados desordenados:\n");
    for (int i = 0; i < len1; i++){
        printf("%d ", dados[i]);
    }

    printf("\n\n");
    bubbleSort(dados);

    printf("Dados ordenados com Bubble Sort:\n");
    for (int i = 0; i < len1; i++){
        printf("%d ", dados[i]);
    }

    printf("\n\n");

    bubbleSortStopCodition(dados2);

    printf("Dados ordenados com Bubble Sort Stop Condition:\n");
    for (int i = 0; i < len2; i++){
        printf("%d ", dados2[i]);
    }

    return 0;
}