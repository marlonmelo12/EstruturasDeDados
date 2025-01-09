#include <stdio.h>
#include "lib.h"

int main() {
    Pilha* pilha = criarPilha(100);
    
    empilhar(pilha, 10);
    empilhar(pilha, 20);
    empilhar(pilha, 30);
    
    printf("%d no topo da pilha\n", topo(pilha));
    
    printf("%d desempilhado\n", desempilhar(pilha));
    printf("%d desempilhado\n", desempilhar(pilha));
    printf("%d desempilhado\n", desempilhar(pilha));
    
    if (estaVazia(pilha))
        printf("A pilha esta vazia\n");
    
    return 0;
}