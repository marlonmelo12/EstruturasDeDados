#include "lib.h"

int main()
{
    int numero;
    int tamanho;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d",&tamanho);
    Lista* l = criarLista(tamanho);

    do{
        printf("Digite um numero\n");
        scanf("%d",&numero);
        inserir(&l, numero);
    }while(numero != 0);
    return 0;
}
