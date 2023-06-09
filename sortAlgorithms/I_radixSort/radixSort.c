#include <stdio.h>
#include <stdlib.h>
#define N 10

void radixSort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };

		for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];

		for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];

		for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];

		exp *= 10;
    }

    free(b);
}

int main(){
    int i;
    int vet[N] = {10,9,8,7,6,5,4,3,2,1};

    printf("Dados desordenados\n");
    for (i=0; i<N; i++){
        printf("%d ", vet[i]);
    }

    radixSort(vet, N);
    printf("\n\n");

    printf("Dados ordenados\n");
    for (i=0; i<N; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}