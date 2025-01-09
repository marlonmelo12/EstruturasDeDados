#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <time.h>

typedef struct Paciente Paciente;
typedef struct Nodo Nodo;
typedef struct Triagem Triagem;
typedef struct Especialista Especialista;
typedef struct Especialidades Especialidades;

Triagem* criarTriagem();

Especialidades* criarListaDeEspecialidades();

void criarEspecialidade(Especialidades* especialidades);

void cadastrarPaciente(Triagem* triagem);

void enfileirar(Triagem* triagem, Paciente paciente);

Paciente desenfileirar(Triagem* triagem);

int triagemVazia(Triagem* triagem);

void empilhar(Especialista* especialista, Paciente paciente);

Paciente desempilhar(Especialista* especialista);

int especialistaVazio(Especialista* especialista);

void exibirTriagem(Triagem* triagem);

void exibirPacientesEmEspecialidades(Especialidades* especialidades);

int especialistasVazio(Especialidades* especialidades);

void triagemDePaciente(Triagem* triagem, Especialidades* especialidades);

void atenderPaciente(Especialidades* especialidades);

void fecharSistema();

void escreverArquivo(char descricao[100]);
