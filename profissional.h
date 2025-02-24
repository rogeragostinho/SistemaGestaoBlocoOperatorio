#include "date.h"

typedef struct
{
	int id;
	char nome[50], especialidade[50];
	DATE dataCadastro;
}PROFISSIONAL;

int getNextProfissionalAutoID();
void pedirDadosProfissional(PROFISSIONAL *profissional); // Pede dados para um novo profissional
void pedirNovosDadosProfissional(PROFISSIONAL *profissional); //Pede novos dados para um profissional existente
void mostrarDadosProfissional(PROFISSIONAL profissional);
void salvarDadosProfissional();
void listarDadosProfissional();
void pesquisarProfissionalPorNome();
void removerDadosProfissional();
void editarDadosProfissional();
int verificarExistenciaProfissional(int id);
