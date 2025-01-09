#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo Nodo;
typedef struct ListaDuplamenteEncadeada ListaDuplamenteEncadeada;

ListaDuplamenteEncadeada* criarLista();

void adicionarInicio(ListaDuplamenteEncadeada* lista, int valor);

void adicionarFim(ListaDuplamenteEncadeada* lista, int valor);

void removerInicio(ListaDuplamenteEncadeada* lista);

void removerFinal(ListaDuplamenteEncadeada* lista);

int obterElemento(ListaDuplamenteEncadeada* lista, int indice);

int estaVazia(ListaDuplamenteEncadeada* lista);

int obterTamanho(ListaDuplamenteEncadeada* lista);

void lerArquivo(ListaDuplamenteEncadeada* lista);

void escreverArquivo(ListaDuplamenteEncadeada * lista);

void imprimirLista(ListaDuplamenteEncadeada* lista);
