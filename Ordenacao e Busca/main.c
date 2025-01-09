#include "lib.h"

int main() {

	int vetor[] = {5,4,3,2,1};

	imprimir(vetor, 5);

	bubbeSort(vetor, 5);

	imprimir(vetor, 5);

	int retorno = buscaBinariaRecusiva(vetor, 0, 5, 4);

	printf("O indice do elemento buscado eh %d o valor eh %d\n", retorno, vetor[retorno]);

	retorno = buscaBinariaNaoRecusiva(vetor, 0, 5, 3); //buscando o índice do elemento 3

	printf("O indice do elemento buscado eh %d o valor eh %d\n", retorno, vetor[retorno]);

}
