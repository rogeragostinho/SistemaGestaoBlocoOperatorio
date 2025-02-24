#include <stdio.h>
#include "paciente.h"

int getNextPacienteAutoID() // pega o proximo Id
{
	FILE *fp;
	PACIENTE paciente;
	int nextID = 1;
	
	fp = fopen("PACIENTES.DAT", "rb"); // abre o arquivo para leitura
	if ( fp == NULL)
	{
		puts("\t** Erro ao tentar abrir o ficheiro! **");
		return;
	}
	
	rewind(fp); // reposiciona o ponteiro para o inicio
	
	// conta os registos existentes
	while(fread(&paciente, sizeof(PACIENTE), 1, fp) == 1) 
		nextID++;
		
	fclose(fp);
	
	return nextID;
}

void pedirDadosNovoPaciente(PACIENTE *paciente)
{			
	system("cls");

	putchar('\n');
	printf("\t-------------------------------\n");
	printf("\t!!!! NOVO PACIENTE !!!!\n");
	printf("\t-------------------------------\n");
	
	printf("\tId: %d\n", getNextPacienteAutoID());
	paciente->id = getNextPacienteAutoID();
	
	printf("\tIdade: ");
	scanf("%d", &paciente->idade);
	
	printf("\tContacto: ");
	scanf("%d", &paciente->contacto);
	
	getchar();
	printf("\tNome: ");
	gets(paciente->nome);
	
	printf("\tGenero: ");
	gets(paciente->genero);
	
	printf("\tDiagnostico: ");
	gets(paciente->diagnostico);
	
	printf("\tData cadastro[DD/MM/AAAA]\n");
	
	printf("\tDia: ");
	scanf("%d", &paciente->dataCadastro.dia);
	
	printf("\tMes: ");
	scanf("%d", &paciente->dataCadastro.mes);
	
	printf("\tAno: ");
	scanf("%d", &paciente->dataCadastro.ano);
}

void pedirNovosDadosPaciente(PACIENTE *paciente)
{			
	putchar('\n');
	printf("\t-------------------------------\n");
	printf("\t!!!! NOVOS DADOS !!!!\n");
	printf("\t-------------------------------\n");
	
	printf("\tIdade: ");
	scanf("%d", &paciente->idade);
	
	printf("\tContacto: ");
	scanf("%d", &paciente->contacto);
	
	getchar();
	printf("\tNome: ");
	gets(paciente->nome);
	
	printf("\tGenero: ");
	gets(paciente->genero);
	
	printf("\tDiagnostico: ");
	gets(paciente->diagnostico);
	
	printf("\tData cadastro[DD/MM/AAAA]\n");
	
	printf("\tDia: ");
	scanf("%d", &paciente->dataCadastro.dia);
	
	printf("\tMes: ");
	scanf("%d", &paciente->dataCadastro.mes);
	
	printf("\tAno: ");
	scanf("%d", &paciente->dataCadastro.ano);
	
	system("cls");
}

void mostrarDadosPaciente(PACIENTE paciente)
{
	//putchar('\n');
	//printf("\t-------------------------------\n");
	//printf("\t!!!! PACIENTE !!!!\n");
	printf("\t-------------------------------\n");
	
	printf("\tId: %d\n", paciente.id);
	
	printf("\tIdade: %d\n", paciente.idade);
	
	printf("\tContacto: %d\n", paciente.contacto);
	
	printf("\tNome: %s\n", paciente.nome);
	
	printf("\tGenero: %s\n", paciente.genero);
	
	printf("\tDiagnostico: %s\n", paciente.diagnostico);
	
	printf("\tData cadastro: %d/%d/%d\n", 
		paciente.dataCadastro.dia,
		paciente.dataCadastro.mes,
		paciente.dataCadastro.ano);
	
	printf("\t-------------------------------\n");
}

void salvarDadosPaciente()
{
	FILE *fp;
	PACIENTE paciente;
	
	fp = fopen("PACIENTES.DAT", "ab"); // abrir ou criar o ficheiro 
	if ( fp == NULL)
	{
		puts("\t** Erro ao tentar abrir o ficheiro! **");
		return;
	}
	
	pedirDadosNovoPaciente(&paciente); // pedir dados ao utilizador
	
	system("cls");
	
	// escrever os dados da estrutura para o ficheiro
	if( fwrite(&paciente, sizeof(PACIENTE), 1, fp) != 1) 
		puts("\t** Erro ao tentar escrever no ficheiro! **");
	else
		puts("\t** Registo adicionado com sucesso no Ficheiro **");
	
	fclose( fp );
}

void listarDadosPaciente()
{
	FILE *fp;
	PACIENTE paciente;
	
	fp = fopen("PACIENTES.DAT", "rb"); // abre o arquivo para leitura
	if (fp == NULL)
    {
        puts("\t** Erro ao tentar abrir o ficheiro! **");
        return;
    }
	
	rewind(fp); // movimentar o File Pointer para o inicio
	
	system("cls");
	
	putchar('\n');
	printf("\t-------------------------------\n");
	printf("\t!!!! LISTA DE PACIENTES !!!!\n");
	printf("\t-------------------------------\n");
	
	//escrever os dados da estrutura para o ficheiro
	while( fread(&paciente, sizeof(PACIENTE), 1, fp) == 1)
		mostrarDadosPaciente(paciente);
		
	fclose( fp );
}

void pesquisarPacientePorNome()
{
	FILE *fp;
	PACIENTE paciente;
	char nomeProcurado[50];
	
	
	fp = fopen("PACIENTES.DAT", "rb"); //abre o ficheiro para leitura
	if (fp == NULL)
    {
        puts("\t** Erro ao tentar abrir o ficheiro! **");
        return;
    }

	rewind(fp); // movimentar o File Pointer para o inicio
	
	system("cls");
	
	printf("\tDigite o Nome Procurado: ");
	getchar();
	gets(nomeProcurado);
	
	system("cls");
	
	//escrever os dados da estrutura para o ficheiro
	while( fread(&paciente, sizeof(PACIENTE), 1, fp) == 1)
	{	
		if ( strcmp(paciente.nome, nomeProcurado) == 0)
		{	
			puts("\t** Registo localizado **");
			printf("\t-------------------------------\n");
			mostrarDadosPaciente(paciente);
			
			fclose(fp);
			return;
		}
	}
	puts("\t** Registo nao localizado **");
		
	fclose( fp );
}

void removerDadosPaciente()
{
	FILE *fp, *temp;
    PACIENTE paciente;
    int idParaRemover, encontrado = 0;

    // Abrir o arquivo original para leitura
    fp = fopen("PACIENTES.DAT", "rb");
    if (fp == NULL) {
        printf("\t** Erro ao abrir o arquivo original! **\n");
        return;
    }

    // Criar um arquivo temporario para armazenar os registros restantes
    temp = fopen("TEMP.DAT", "wb");
    if (temp == NULL) {
        printf("\t** Erro ao criar o arquivo tempor�rio! **\n");
        fclose(fp);
        return;
    }

	system("cls");

	printf("\tId do Paciente a ser removido: ");
	scanf("%d", &idParaRemover);

	system("cls");
	
    // Percorrer o arquivo e copiar os registros que n�o ser�o removidos
    while (fread(&paciente, sizeof(PACIENTE), 1, fp) == 1) {
        if (paciente.id != idParaRemover) 
            fwrite(&paciente, sizeof(PACIENTE), 1, temp);
        else 
            encontrado = 1;
    }

    fclose(fp);
    fclose(temp);

    // Substituir o arquivo original pelo tempor�rio se um registro foi removido
    if (encontrado) {
        remove("PACIENTES.DAT");          // Apaga o arquivo original
        rename("TEMP.DAT", "PACIENTES.DAT"); // Renomeia o tempor�rio para original
        printf("\t** Paciente removido com sucesso! **\n");
    } else {
        remove("TEMP.DAT"); // Se o ID n�o foi encontrado, apagar o tempor�rio
        printf("\t** Paciente com ID %d nao encontrado. **\n", idParaRemover);
    }
}

void editarDadosPaciente()
{
    FILE *fp;
    PACIENTE paciente;
    int id, encontrado = 0;

    fp = fopen("PACIENTES.DAT", "rb+"); // Abre para leitura e escrita
    if (fp == NULL)
    {
        puts("\t** Erro ao tentar abrir o ficheiro! **");
        return;
    }

	system("cls");

    printf("\tDigite o ID do paciente que deseja editar: ");
    scanf("%d", &id);

	system("cls");

    while (fread(&paciente, sizeof(PACIENTE), 1, fp) == 1)
    {
        if (paciente.id == id)
        {
            encontrado = 1;
            printf("\t** Paciente encontrado! Insira os novos dados **\n");
            
            mostrarDadosPaciente(paciente);
            
            // Fun��o que coleta os novos dados do paciente
            pedirNovosDadosPaciente(&paciente);

            // Voltar o ponteiro do ficheiro para reescrever os dados
            fseek(fp, -sizeof(PACIENTE), SEEK_CUR);
            fwrite(&paciente, sizeof(PACIENTE), 1, fp);

            printf("\t** Dados atualizados com sucesso! **\n");
            break;
        }
    }

    if (!encontrado)
        printf("\t** Paciente com ID %d nao encontrado! **\n", id);

    fclose(fp);
}

// Verifica se um paciente existe pelo id
int verificarExistenciaPaciente(int id)
{
    FILE *fp;
    
	fp = fopen("PACIENTES.DAT", "rb");
	
    if (fp == NULL) 
        return 0; // Arquivo n�o encontrado, logo paciente n�o existe

    PACIENTE p;
    while (fread(&p, sizeof(PACIENTE), 1, fp)) {
        if (p.id == id) {
            fclose(fp);
            return 1; // Paciente encontrado
        }
    }

    fclose(fp);
    return 0; // Paciente n�o encontrado
}
