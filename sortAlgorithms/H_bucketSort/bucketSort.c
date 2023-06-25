#include <stdio.h>
#include <stdlib.h>
#define tam_bucket 100
#define num_bucket 10
#define N 5

typedef struct {
	int topo;
    int balde[tam_bucket];
} bucket;

void bucketSort(int v[],int tam);  //cabeçalho das funções
void bubbleSort(int v[], int tam);

void bucketSort(int v[],int tam){
    bucket b[num_bucket];
    int i,j,k;

	for(i=0;i<num_bucket;i++) //inicializa todos os "topo"
        b[i].topo = 0;

	for(i=0;i<tam;i++){  //verifica em que balde o elemento deve ficar
		j = num_bucket - 1;
		while(1){
			if(j < 0)
				break;

			if(v[i]>=j*10){
				b[j].balde[b[j].topo]=v[i];
				(b[j].topo)++;
				break;
			}
			j--;
		}
	}

	for(i=0;i<num_bucket;i++) { //ordena os baldes
        if(b[i].topo > 0)
			bubbleSort(b[i].balde,b[i].topo);
	}
    i=0;
	for(j=0;j<num_bucket;j++){ //põe os elementos dos baldes de volta no vetor
		for(k=0;k<b[j].topo;k++){
			v[i]=b[j].balde[k];
            i++;
        }
    }
}

void bubbleSort(int v[], int tam)
{
    int i, j, aux;
    for(i=tam-1; i >= 1; i--)
    {
        for(j=0; j < i; j++)
        {
            if(v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

int main(){
    int i;
    int vet[N] = {5,4,3,2,1};

    printf("Dados desordenados\n");
    for (i=0; i<N; i++){
        printf("%d ", vet[i]);
    }

    bucketSort(vet, N);
    printf("\n\n");

    printf("Dados ordenados\n");
    for (i=0; i<N; i++){
        printf("%d ", vet[i]);
    }
    return 0;
}