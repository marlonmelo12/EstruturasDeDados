// Declaração do tipo Pilha
typedef struct Pilha Pilha;

// Cria uma nova pilha com a capacidade especificada
Pilha* criarPilha(unsigned capacidade);

// Verifica se a pilha está cheia
int estaCheia(Pilha* pilha);

// Verifica se a pilha está vazia
int estaVazia(Pilha* pilha);

// Adiciona um item à pilha
void empilhar(Pilha* pilha, int item);

// Remove um item da pilha
int desempilhar(Pilha* pilha);

// Retorna o item do topo da pilha sem removê-lo
int topo(Pilha* pilha);