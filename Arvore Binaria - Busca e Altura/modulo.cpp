#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

// Função para criar um novo nó
No* criarNo(int valor) {
	 No* novoNo = (No*) malloc (sizeof(No));
	 if(novoNo != NULL){
	 	novoNo->valor = valor;
	 	novoNo->esquerda = NULL;
	 	novoNo->direita = NULL;
	 }
	 return novoNo;
}


// Função para inserir um valor na árvore
No* inserir(No* raiz, int valor) {
	 if(raiz == NULL)
	 	return criarNo(valor);
	if(valor < raiz->valor)
		raiz->esquerda = inserir(raiz->esquerda, valor);
	else
		raiz->direita = inserir(raiz->direita, valor);
	return raiz;
}

No* buscar(No* raiz, int x){
	if((raiz==NULL)||(raiz->valor == x))
		return raiz;
	if(raiz->valor > x)
		return buscar(raiz->esquerda, x);
	else
		return buscar(raiz->direita, x);
	
}

int altura(No* raiz){
	if(raiz ==NULL)
		return -1;
	int esq = altura(raiz->esquerda);
	int dir = altura(raiz->direita);
	if(esq>=dir)
		return esq+1;
	else
		return dir+1;
}



// Função para exibir os valores da árvore em ordem
void exibirInOrdem(No* raiz) {
    if (raiz != NULL) {
        exibirInOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibirInOrdem(raiz->direita);
    }
}