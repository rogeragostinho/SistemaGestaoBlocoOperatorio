#include "date.h"
#include "equipemedica.h"

typedef struct 
{
	int id, idPaciente, nMembrosEquipe;
	char tipo[50], status[20], sala[30];
	EQUIPEMEDICA equipeMedica[10];
	DATE dataCirurgia;
}CIRURGIA;

int getNextCirurgiaAutoID();
void pedirDadosNovaCirurgia(CIRURGIA *cirurgia); // Pede dados para uma nova cirurgia
void pedirNovosDadosCirurgia(CIRURGIA *cirurgia); // Pede dados para uma cirurgia existente
void mostrarDadosCirurgia(CIRURGIA cirurgia);
void salvarDadosCirurgia();
void listarDadosCirurgia();
void pesquisarCirurgiaPorID();
void removerDadosCirurgia();
void editarDadosCirurgia();



