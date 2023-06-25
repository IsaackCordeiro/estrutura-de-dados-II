#include <stdio.h>
#define N 5

void partition(int *dados, int esq, int dir, int *i, int *j){
    int pivo, aux;
    *i = esq;
    *j = dir;
    pivo = dados[(esq + dir) / 2];

    while (*i <= *j){
        while (dados[*i] < pivo && *i < dir)
            (*i)++;

        while (dados[*j] > pivo && *j > esq)
            (*j)--;

        if (*i <= *j){
            aux = dados[*i];
            dados[*i] = dados[*j];
            dados[*j] = aux;
            (*i)++;
            (*j)--;
        }
    }
}

void quickSort(int *dados, int esq, int dir){
    int i = 0, j = 0;
    partition(dados, esq, dir, &i, &j);

    if (esq < j){
        quickSort(dados, esq, j);
    }
    if (dir > i){
        quickSort(dados, i, dir);
    }
}

int main(void){
    int dados[] = {5, 4, 3, 2, 1};

    printf("Dados desordenados\n");
    for (int i = 0; i < N; i++){
        printf("%d ", dados[i]);
    }

    quickSort(dados, 0, N - 1);

    printf("\n\n");

    printf("Dados ordenados\n");
    for (int i = 0; i < N; i++){
        printf("%d ", dados[i]);
    }

    return 0;
}