#include "libConta.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct vetor{
    Tconta* vet;
    int tamanho_vetor;
}VetorContas;

void criarListaDeContas(VetorContas* vetor, int tamanho_vetor);
int buscarConta(VetorContas* vetor, Tconta* conta, int numero_conta);
void inserirConta(VetorContas* vetor, Tconta* conta);
void depositarConta(VetorContas* vetor, Tconta* conta, int numero_conta, float deposito);
void sacarConta(VetorContas* vetor, int numero_conta);
void imprimirVetor(VetorContas vetor);
