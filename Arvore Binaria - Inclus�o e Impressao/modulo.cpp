#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

// Função para criar um novo nó
No* criarNo(int valor) {
    No* no = (No*)malloc(sizeof(No));
    if(no){
        no->valor = valor;
        no->esquerda=NULL;
        no->direita=NULL;
    }
    return no;
}


// Função para inserir um valor na árvore
No* inserir(No* raiz, int valor) {
    if(raiz==NULL)
        return criarNo(valor);
    if(valor < raiz->esquerda)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else
        raiz->direita = inserir(raiz->direita, valor);
}
// Função para exibir os valores da árvore em ordem
void exibirInOrdem(No* raiz) {
}

int remover(No* raiz, int dado){
    No* pai = raiz;
    while(raiz != NULL && raiz->valor!=dado){
        pai=raiz;
        if(dado > raiz->valor)
            raiz = raiz->direita;
        else
            raiz = raiz->esquerda;
    }
    if(raiz!=NULL){
        if(raiz->esquerda != NULL && raiz->direita != NULL){
            No* aux = raiz;
            pai = raiz;
            raiz = raiz->direita;
            while(raiz->esquerda!=NULL){
                pai=raiz;
                raiz=raiz->esquerda;
            }
            aux->valor=raiz->valor;
        }

        if(raiz->esquerda == NULL && raiz->direita != NULL){
            if(pai->esquerda == raiz)
                pai->esquerda = raiz->direita;
            else
                pai->direita = raiz->direita;
        }else if(raiz->esquerda != NULL && raiz->direita == NULL){
            if(pai->esquerda == raiz)
                pai->esquerda = raiz->esquerda;
            else
                pai->direita = raiz->esquerda;
        }else if (raiz->esquerda == NULL && raiz->direita == NULL){
            if(pai->esquerda == raiz)
                pai->esquerda = NULL;
            else
                pai->direita = NULL;
        }
        free(raiz);
    }
}
