#include <stdio.h>
#define N 5

void insertionSort(int *dados){
    int aux;
    int j;
    for (int i = 1; i < N; i++){
        aux = dados[i];
        j = i - 1;
        while (j >= 0 && aux < dados[j]){
            dados[j + 1] = dados[j];
            j--;
        }
        if (j != i-1){
            dados[j + 1] = aux;
        }
    }
}

int main(void){
    int dados[] = {5, 4, 3, 2, 1};

    printf("Dados desordenados\n");
    for (int i = 0; i < N; i++){
        printf("%d ", dados[i]);
    }

    insertionSort(dados);

    printf("\n\n");

    printf("Dados ordenados\n");
    for (int i = 0; i < N; i++){
        printf("%d ", dados[i]);
    }

    return 0;
}