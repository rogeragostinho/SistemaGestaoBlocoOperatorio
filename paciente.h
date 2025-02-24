#include "date.h"

typedef struct
{
	int id, idade, contacto;
	char nome[50], genero[10], diagnostico[100];
	DATE dataCadastro;
}PACIENTE;

int getNextPacienteAutoID();
void pedirDadosNovoPaciente(PACIENTE *paciente); // Pede dados para um novo paciente
void pedirNovosDadosPaciente(PACIENTE *paciente); //Pede novos dados para um paciente existente
void mostrarDadosPaciente(PACIENTE paciente);
void salvarDadosPaciente();
void listarDadosPaciente();
void pesquisarPacientePorNome();
void removerDadosPaciente();
void editarDadosPaciente();
int verificarExistenciaPaciente(int id);
