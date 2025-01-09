typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Protótipos das funções para manipulação da árvore binária
No* criarNo(int valor);
No* inserir(No* raiz, int valor);
void exibirInOrdem(No* raiz);
No* buscar(No* raiz, int x);
int altura(No* raiz);