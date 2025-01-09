#include <stdio.h>
#include <stdlib.h>

typedef struct conta{
    int numero_conta;
    float saldo;
}Tconta;

void criarConta(Tconta* conta, int numero_conta, float saldo);
void depositar(Tconta* conta, int numero_conta, float deposito);
void sacar(Tconta* conta, float saque);
void imprimir(Tconta conta);
