#include "libVetor.h"

void criarListaDeContas(VetorContas* vetor, int tamanho_vetor){
    vetor->vet=(Tconta*)malloc(sizeof(Tconta));
    vetor->tamanho_vetor=tamanho_vetor;
}
void inserirConta(VetorContas *vetor, Tconta *conta){
    vetor->vet[vetor->tamanho_vetor] = *conta;
    vetor->tamanho_vetor = vetor->tamanho_vetor+1;
}
int buscarConta(VetorContas* vetor, Tconta* conta, int numero_conta){
    for(int i=0;i<vetor->tamanho_vetor;i++){
        if(vetor->vet[i].numero_conta == numero_conta){
            return i;
        }
    }
    return -1;
}
void depositarConta(VetorContas* vetor, Tconta* conta, int numero_conta, float deposito){
    int retorno = buscarConta(vetor, conta, numero_conta);
    if(retorno >= 0){
        depositar(*conta, deposito);
    }

}
