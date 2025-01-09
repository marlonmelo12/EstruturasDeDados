#include "libConta.h"

void criarConta(Tconta* conta, int numero_conta, float saldo){
    conta->numero_conta = numero_conta;
    conta->saldo = saldo;
}
void depositar(Tconta* conta, int numero_conta, float deposito){
    conta->saldo = conta->saldo + deposito;
}
void sacar(Tconta* conta, float saque){
    conta->saldo = conta->saldo - saque;
}
void imprimir(Tconta conta){
    printf("===Conta====\n");
	printf("Numero: %d\n", conta.numero_conta);
	printf("Saldo: %.2f\n", conta.saldo);
}

