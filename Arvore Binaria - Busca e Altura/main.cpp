#include <stdio.h>
#include "lib.h"

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Arvore em ordem: ");
    exibirInOrdem(raiz);
    printf("\n");
    
    No* dado;
    dado = buscar(raiz, 20);
    if(dado != NULL)
    	printf("RETORNO: %d\n", dado->valor);
    else
    	printf("Informacao nula\n");
    
    printf("Altura da arvore %d\n", altura(raiz));

    return 0;
}