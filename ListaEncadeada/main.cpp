
#include "lib.h"

int main() {

    ListaDuplamenteEncadeada* lista = criarLista();

    lerArquivo(lista);
    removerInicio(lista);
    removerInicio(lista);
    removerFinal(lista);
    removerFinal(lista);
    escreverArquivo(lista);
    return 0;
}
