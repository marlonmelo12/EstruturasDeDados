#include "lib.h"

void imprimir(int* vetor, int qtd){
	int i;
	printf("----- Vetor -----\n");
	for(i=0; i< qtd; i++)
		printf("%d ", vetor[i]);
	printf("\n");
}

void bubbeSort(int* vetor, int qtd){
    int i, j;
    for(i=1;i<qtd;i++){
        for(j=0;j<qtd-i;j++){
            if(vetor[j]>vetor[j+1]){
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
                }
        }
    }
}

int buscaBinariaRecusiva(int* vetor, int inicio, int fim, int elemento){
    int meio = (fim-inicio)/2;
    if(inicio<fim){
        if(vetor[meio]==elemento)
            return meio;
        else{
            if(vetor[meio]>elemento){
                return buscaBinariaRecusiva(vetor, inicio, meio+1, elemento);
            }else{
                return buscaBinariaRecusiva(vetor, meio-1, fim, elemento);
        }
    }

    }else
    return -1;

}
int buscaBinariaNaoRecusiva(int* vetor, int inicio, int fim, int elemento){

}
