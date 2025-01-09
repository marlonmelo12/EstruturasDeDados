#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

struct Pilha {
    int topo;
    int capacidade;
    int* vetor;
};

// Função para criar uma pilha de capacidade dada. Inicializa o tamanho da pilha como 0.
Pilha* criarPilha(unsigned capacidade) {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->capacidade = capacidade;
    pilha->topo = -1;
    pilha->vetor = (int*)malloc(pilha->capacidade*sizeof(int));
    return pilha;
}

// Pilha está cheia quando o índice do topo é igual à última posição do vetor
int estaCheia(Pilha* pilha) {
    if(pilha->topo==pilha->capacidade-1)
        return 1;
    return 0;
}

// Pilha está vazia quando o índice do topo é -1
int estaVazia(Pilha* pilha) {
    if(pilha->topo==-1)
        return 1;
    return 0;
}

// Função para adicionar um item à pilha. Incrementa o índice do topo e adiciona o item ao vetor.
void empilhar(Pilha* pilha, int item) {
    if(estaCheia(pilha)!=1){
        pilha->topo++;
        pilha->vetor[pilha->topo] = item;
    }
}

// Função para remover um item da pilha. Decrementa o índice do topo e retorna o item do topo.
int desempilhar(Pilha* pilha) {
    if(estaVazia(pilha)!=1){
        int aux = pilha->vetor[pilha->topo];
        pilha->topo--;
        return aux;
    }
    return;
}

// Função para retornar o item do topo da pilha sem removê-lo.
int topo(Pilha* pilha) {
    if(estaVazia == 1)
        return;
    return pilha->vetor[pilha->topo];
}
