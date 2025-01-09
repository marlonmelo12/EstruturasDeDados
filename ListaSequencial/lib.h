#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int* vetor;
    int tamanho;
}Lista;

Lista* criarLista(int tamanho_lista);
void inserir(Lista* l, int dado);
int buscarDadoValor(Lista l, int posicao);
int buscarDadoPosicao(Lista l, int posicao);
void lista(Lista l);
void atualizar(Lista* l, int dado_antigo, int dado_novo);
void apagarLista(Lista* l);
