#include "lib.h"

struct Paciente {
    char nome[50];
    char especialidade[20];
    time_t chegada;
};

struct Nodo {
    Paciente Paciente;
    struct Nodo* proximo;
};

struct No {
    Especialista* especialista;
    struct No* proximo;
};

struct Especialista {
    char especialidade[20];
    Nodo* topo;
};

struct Especialidades {
    No* proximo;
};

struct Triagem {
    Nodo* proximo;
    Nodo* fim;

};

Triagem* criarTriagem() {
    char mensagem[100];
    Triagem* triagem = (Triagem*) malloc(sizeof(Triagem));

	if(triagem){
        triagem->fim = NULL;
        triagem->proximo = NULL;
	}
	escreverArquivo(mensagem);
	return triagem;
}

void enfileirar(Triagem* triagem, Paciente paciente) {
    char mensagem[100];
    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if(no) {
        no->Paciente = paciente;
        no->proximo = NULL;

        if(triagem->fim == NULL) {
            triagem->proximo = no;
            triagem->fim = no;
        } else {
            triagem->fim->proximo = no;
            triagem->fim = no;
        }
    }
}

int triagemVazia(Triagem* triagem) {
    if(triagem->proximo == NULL) return 1;

    return 0;
}

Paciente desenfileirar(Triagem* triagem) {
    if(triagemVazia(triagem) == 1) {
        printf("Triagem vazia.");
    } else {
        Nodo* aux = triagem->proximo;
        Paciente paciente = aux->Paciente;
        triagem->proximo = triagem->proximo->proximo;

        if(triagem->proximo == NULL)
            triagem->fim = NULL;

        free(aux);
        return paciente;
    }
}

void criarEspecialidade(Especialidades* especialidades) {
    char mensagem[100];
    Especialista* especialista = (Especialista*) malloc(sizeof(Especialista));

    system("cls");

    if(especialista) {
        printf("\nQual o nome da especialidade: ");
        scanf("%s", &especialista->especialidade);
        snprintf(mensagem, sizeof(mensagem), "Especialidade %s foi criada", especialista->especialidade);

        especialista->topo = NULL;

        No* no = (No*) malloc(sizeof(No));

        if(no) {
            no->especialista = especialista;
            no->proximo = especialidades->proximo;
            especialidades->proximo = no;
        }
    }
    escreverArquivo(mensagem);
}

void empilhar(Especialista* especialista, Paciente paciente) {
    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if(no) {
        no->Paciente = paciente;
        no->proximo = especialista->topo;
        especialista->topo = no;
    }
}

Paciente desempilhar(Especialista* especialista) {
    if(especialistaVazio(especialista) == 1) {
        printf("\nEsta vazio");
    } else {
        Nodo* aux = especialista->topo;
        Paciente paciente = aux->Paciente;
        especialista->topo = especialista->topo->proximo;
        free(aux);
        return paciente;
    }
}

int especialistaVazio(Especialista* especialista) {
    if(especialista->topo == NULL) return 1;

    return 0;
}

void cadastrarPaciente(Triagem* triagem) {
    char mensagem[100];
    system("cls");
    Nodo* no = (Nodo*) malloc(sizeof(Nodo));

    if(no) {
        printf("\nCadastro de Paciente\n\n");
        printf("\nDigite seu nome: ");
        scanf("%s", &no->Paciente.nome);
        time(&no->Paciente.chegada);
        no->proximo = NULL;

        if(triagem->fim == NULL) {
            triagem->proximo = no;
        } else {
            triagem->fim->proximo = no;
        }
        triagem->fim = no;

        system("cls");
        snprintf(mensagem, sizeof(mensagem), "O paciente %s foi cadastrado e diredirecionado no sitema de triagem", no->Paciente.nome);
        escreverArquivo(mensagem);
        printf("%s foi cadastrado no sistema de triagem!\n\n", no->Paciente.nome);
    }
}

Especialidades* criarListaDeEspecialidades() {
    Especialidades* especialidades = (Especialidades*) malloc(sizeof(Especialidades));

    if(especialidades) {
        especialidades->proximo = NULL;
        return especialidades;
    }
}

int especialistasVazio(Especialidades* especialidades) {
    if(especialidades->proximo == NULL) return 1;

    return 0;
}

void exibirTriagem(Triagem* triagem) {
    system("cls");
    if(triagemVazia(triagem) == 1) {
        printf("Nenhum paciente na fila de triagem");
        return;
    } else {
        int indice = 1;
        printf("\n\nFila de Triagem:\n\n");
        Nodo* aux = triagem->proximo;
        while(aux != NULL) {
            printf("%d - Paciente: %s\n", indice, aux->Paciente.nome);
            aux = aux->proximo;
            indice++;
        }
    }
}

void exibirPacientesEmEspecialidades(Especialidades* especialidades) {
    system("cls");
    if(especialistasVazio(especialidades) == 1) {
        printf("\nNenhuma especialidade cadastrada...\n\n");
        return;
    }

    printf("\nExibicao de pacientes por especialidade");
    No* aux = especialidades->proximo;
    int indiceEspecilidade = 1;

    while(aux != NULL) {
        printf("\n%d - %s\n\n", indiceEspecilidade, aux->especialista->especialidade);

        Nodo* aux2 = aux->especialista->topo;
        int indicePaciente = 1;

        while(aux2 != NULL) {
            printf(" %d - Paciente: %s\n", indicePaciente, aux2->Paciente.nome);
            aux2 = aux2->proximo;
            indicePaciente++;
        }

        aux = aux->proximo;
        indiceEspecilidade++;
    }
}

void triagemDePaciente(Triagem* triagem, Especialidades* especialidades) {
    system("cls");
    char mensagem[100];
    if(triagemVazia(triagem) == 1) {
        printf("\n\nSem pacientes em triagem ou sem especialistas disponiveis");
        return;
    } else {
        printf("\nPaciente atual: %s", triagem->proximo->Paciente.nome);
        printf("\n\nEspecialistas disponiveis: ");
        snprintf(mensagem, sizeof(mensagem), "Paciente %s esta sendo atendido na fila de triagem", triagem->proximo->Paciente.nome);
        escreverArquivo(mensagem);

        No* aux = especialidades->proximo;

        while(aux != NULL) {
            printf("\n  Especialista em %s", aux->especialista->especialidade);
            aux = aux->proximo;
        }
        char especialidadeDesejada[20];
        printf("\n\nDigite o nome da especialidade que deseja: ");
        scanf("%s", &especialidadeDesejada);

        aux = especialidades->proximo;
        int existeEspecialidade = 0;
        while(aux != NULL) {
            if(strcmp(aux->especialista->especialidade, especialidadeDesejada) == 0) {
                strcpy(triagem->proximo->Paciente.especialidade, especialidadeDesejada);
                empilhar(aux->especialista, triagem->proximo->Paciente);
                system("cls");
                printf("\nPaciente: %s, foi movido para a especialidade %s\n", triagem->proximo->Paciente.nome, triagem->proximo->Paciente.especialidade);
                snprintf(mensagem, sizeof(mensagem), "Paciente %s foi movido para %s", triagem->proximo->Paciente.nome, triagem->proximo->Paciente.especialidade);
                desenfileirar(triagem);
                existeEspecialidade = 1;
            }
            aux = aux->proximo;
        }
        if(existeEspecialidade == 0)
            printf("\nEspecialidade invalida");
    }
}

void atenderPaciente(Especialidades* especialidades) {
    char mensagem[100];
    system("cls");
    No* aux = especialidades->proximo;
    printf("\nEspecialistas: ");
    while(aux != NULL) {
        printf("\n\tEspecialista em %s", aux->especialista->especialidade);
        aux = aux->proximo;

    }

    printf("\n\nDigite qual especialista ira fazer o atendimento: ");
    char especialistaEscolhido[20];
    scanf("%s", &especialistaEscolhido);
    snprintf(mensagem, sizeof(mensagem), "%s ira fazer o atendimento", especialistaEscolhido);
    escreverArquivo(mensagem);

    aux = especialidades->proximo;
    while(aux != NULL) {
        if(strcmp(aux->especialista->especialidade, especialistaEscolhido) == 0) {
            system("cls");
            printf("Paciente %s foi atendido pelo especialista %s", aux->especialista->topo->Paciente.nome, aux->especialista->especialidade);
            time_t saida;
            time(&saida);
            difftime(saida, aux->especialista->topo->Paciente.chegada);
            double espera = difftime(saida, especialidade->pilha->topo->chegada);

            int horas = (int)(espera / 3600);
            int minutos = (int)((espera - (horas * 3600)) / 60);
            int segundos = (int)(espera - (horas * 3600) - (minutos * 60));
            snprintf(mensagem, sizeof(mensagem), "Paciente %s foi atendido pelo especialista %s. Tempo de atendimento: %d horas, %d minutos, %d segundos ",
            aux->especialista->topo->Paciente.nome, aux->especialista->especialidade,
            horas,
            minutos,
            segundos);
            escreverArquivo(mensagem);
            desempilhar(aux->especialista);
        }
        aux = aux->proximo;
    }
}

void escreverArquivo(char* descricao) {
    FILE* arquivo_acoes = fopen("registro_hospitar.txt", "a");
    if(arquivo_acoes) {
        fprintf(arquivo_acoes,"%s\n", descricao);
    }
    fclose(arquivo_acoes);
}
