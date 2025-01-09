#include "lib.h"
Lista* criarLista(int tamanho_lista){
    Lista l;
    l.vetor = (int *)malloc(tamanho_lista*sizeof(int));;
    l.tamanho = 0;
    return &l;
}
void inserir(Lista* l, int dado){
    l->vetor[l->tamanho] = dado;
    l->tamanho = l->tamanho + 1;
}
