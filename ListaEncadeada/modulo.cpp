#include "lib.h"

struct Nodo {
    int dados;
    Nodo* proximo;
    Nodo* anterior;
};

struct ListaDuplamenteEncadeada {
    Nodo* cabeca;
    Nodo* pe;
    int tamanho;
};

ListaDuplamenteEncadeada* criarLista() {
 	ListaDuplamenteEncadeada* lista = (ListaDuplamenteEncadeada*) malloc(sizeof(ListaDuplamenteEncadeada)) ;
	if(lista != NULL){
		lista->cabeca = NULL;
		lista->pe = NULL;
		lista->tamanho = 0;
	}
	return lista;
}

void adicionarInicio(ListaDuplamenteEncadeada* lista, int valor) {
    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if(no != NULL) {
        no->dados = valor;
        no->proximo = lista->cabeca;
        no->anterior = NULL;

        if(lista->cabeca != NULL) {
            lista->cabeca->anterior = no;
        }
        lista->cabeca = no;

        if(lista->pe == NULL) {
            lista->pe = no;
        }

        lista->tamanho++;
    } else {
        printf("/nErro ao alocar memoria");
    }
}

void adicionarFim(ListaDuplamenteEncadeada* lista, int valor) {
    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if(no != NULL) {
        no->dados = valor;
        no->anterior = lista->pe;
        no->proximo = NULL;

        if(lista->pe != NULL) {
            lista->pe->proximo = no;
        }
        lista->pe = no;

        if(lista->cabeca == NULL) {
            lista->cabeca = no;
        }

        lista->tamanho++;
    } else {
        printf("/nErro ao alocar memoria");
    }
}

void removerInicio(ListaDuplamenteEncadeada* lista) {
    if(lista != NULL) {
        if(lista->cabeca != NULL) {
            Nodo* aux = lista->cabeca;
            lista->cabeca = lista->cabeca->proximo;
            lista->cabeca->anterior = NULL;

            free(aux);
            lista->tamanho--;
        } else {
            printf("/nA lista esta vazia");
        }
    }else {
        printf("/nA lista não existe");
    }
}

void removerFinal(ListaDuplamenteEncadeada* lista) {
    if(lista != NULL) {
        if(lista->pe != NULL) {
            Nodo* aux = lista->pe;
            lista->pe = lista->pe->anterior;
            lista->pe->proximo = NULL;

            free(aux);
            lista->tamanho--;
        } else {
            printf("/nA lista não tem final");
        }
    }else {
        printf("/nA lista não existe");
    }
}

int obterElemento(ListaDuplamenteEncadeada* lista, int indice) {
    if(lista->tamanho > indice && indice >= 0) {
        Nodo* aux = lista->cabeca;
        int cont = 0;
        while(cont < indice && aux != NULL) {
            aux = aux->proximo;
            cont++;
        }
        return aux->dados;
    } else {
        printf("/nIndice invalido");
        return -1;
    }
}

int estaVazia(ListaDuplamenteEncadeada* lista) {
    if(lista->tamanho == 0) {
        return 0;
    } else {
        printf("/nA lista não esta vazia");
        return -1;
    }
}

int obterTamanho(ListaDuplamenteEncadeada* lista) {
    if(lista != NULL) {
        return lista->tamanho;
    }else {
        printf("/nA lista não existe");
        return -1;
    }
}

void lerArquivo(ListaDuplamenteEncadeada* lista) {
    FILE* file = fopen("entrada.txt", "r");

    if(file != NULL) {
        int cont = 0;
        int n;
        while(fscanf(file, "%d\n", &n) != EOF && cont < 10) {
            if(cont < 5) {
                adicionarInicio(lista, n);
            } else{
                adicionarFim(lista, n);
            }
            cont++;
        }
        fclose(file);
    }else {
        printf("\nError ao ler arquivo de entrada ou nao existe");
    }
}

void escreverArquivo(ListaDuplamenteEncadeada* lista) {
    FILE* file = fopen("saida.txt", "w");

    if(file != NULL) {
        Nodo* aux = lista->cabeca;
        while(aux != NULL) {
            fprintf(file, "%d\n",aux->dados);
            aux = aux->proximo;
        }
        fclose(file);
    }
}

void imprimirLista(ListaDuplamenteEncadeada* lista) {
    if (lista != NULL) {
        Nodo* aux = lista->cabeca;
        while (aux != NULL) {
            printf("%d ", aux->dados);
            aux = aux->proximo;
        }
        printf("\n");
    } else {
        printf("\nA lista não existe");
    }
}
