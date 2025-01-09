
#include "lib.h"

int main() {

    Triagem* triagem = criarTriagem();
    Especialidades* especialidades = criarListaDeEspecialidades();

    int opcao = 0;
    while(opcao != 7) {
        printf("\nMenu Hospitalar\n");
        printf("\n1. Cadastrar Paciente");
        printf("\n2. Cadastrar Especialidade");
        printf("\n3. Triagem de Pacientes");
        printf("\n4. Atender Paciente");
        printf("\n5. Exibir Fila de Triagem");
        printf("\n6. Exibir Pacientes por Especialidade");
        printf("\n7. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);


        switch(opcao) {
            case 1: {
                cadastrarPaciente(triagem);
                break;
            }
            case 2: {
                criarEspecialidade(especialidades);
                break;
            }
            case 3: {
                triagemDePaciente(triagem, especialidades);
                break;
            }
            case 4: {
                atenderPaciente(especialidades);
                break;
            }
            case 5: {
                exibirTriagem(triagem);
                break;
            }
            case 6: {
                exibirPacientesEmEspecialidades(especialidades);
                break;
            }
            default: {
                printf("Opcao invalida!");
            }
        }
    }
    return 0;
}
