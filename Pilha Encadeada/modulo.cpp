#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

// Estrutura do nó da pilha
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Estrutura da pilha
struct Pilha {
    No* topo;
};

// Função para criar uma nova pilha
Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if(pilha){
        pilha->topo =  NULL;
        return pilha;
    }
}

// Função para destruir a pilha e liberar memória
void destruirPilha(Pilha* pilha) {
    if(estaVazia(pilha)==1){
        printf("A pilha esta vazia");
        return;
    }
    No* aux = pilha->topo;
    while(pilha->topo!=NULL){
        pilha->topo = pilha->topo->proximo;
        free(aux);
        aux = pilha->topo;
    }
    free(pilha);
}


// Verifica se a pilha está vazia
int estaVazia(Pilha* pilha) {
    if(pilha == NULL)
        return 1;
    return 0;
}

// Empilha um valor
void empilhar(Pilha* pilha, int valor) {
    No* no=(No*)malloc(sizeof(No));
    if(no){
        no->dado = valor;
        no->proximo = pilha->topo;
        pilha->topo = no;
    }else{
        printf("ERRO");
        return;
    }
}

// Desempilha um valor
int desempilhar(Pilha* pilha) {
    if(estaVazia(pilha)==1){
        printf("A pilha está vazia!");
        return -1;
    }else{
        No* aux = pilha->topo;
        pilha->topo = aux->proximo;
        int resultado = aux->dado;
        free(aux);
        return resultado;
    }
}

// Retorna o valor do topo da pilha sem desempilhar
int verTopo(Pilha* pilha) {
    if(estaVazia(pilha)==1){
        printf("A pilha esta vazia");
        return -1;
    }
    return pilha->topo->dado;
}

// Exibe os elementos da pilha
void exibirPilha(Pilha* pilha) {
    if(estaVazia(pilha)==1){
        printf("Pilha vazia");
        return;
    }
    No* aux = pilha->topo;
    while(aux!=NULL){
        printf("%d ", aux->dado);
        aux=aux->proximo;
    }
}
