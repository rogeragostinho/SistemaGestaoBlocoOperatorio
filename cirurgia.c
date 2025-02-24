#include <stdio.h>
#include "cirurgia.h"
#include "paciente.h"
#include "profissional.h"

int getNextCirurgiaAutoID() // pega o proximo Id
{
	FILE *fp;
	CIRURGIA cirurgia;
	int nextID = 1;
	
	fp = fopen("CIRURGIAS.DAT", "rb"); // abre o arquivo para leitura
	if ( fp == NULL)
	{
		puts("\t** Erro ao tentar abrir o ficheiro! **");
		return;
	}
	
	rewind(fp); // reposiciona o ponteiro para o inicio
	
	// conta os registos existentes
	while(fread(&cirurgia, sizeof(CIRURGIA), 1, fp) == 1) 
		nextID++;
		
	fclose(fp);
	
	return nextID;
}

//Funções CIRURGIA
void pedirDadosNovaCirurgia(CIRURGIA *cirurgia)
{
	cirurgia->nMembrosEquipe = 0;
	
	system("cls");
	
	putchar('\n');
	printf("\t-------------------------------\n");
	printf("\t!!!! NOVA CIRURGIA !!!!\n");
	printf("\t-------------------------------\n");
	
	printf("\tId: %d\n", getNextCirurgiaAutoID());
	cirurgia->id = getNextCirurgiaAutoID();
	
	int pacienteExiste = 0;
	while(pacienteExiste == 0)
	{
		printf("\tId paciente: ");
		scanf("%d", &cirurgia->idPaciente);	
		
		pacienteExiste = verificarExistenciaPaciente(cirurgia->idPaciente);
		
		if(pacienteExiste == 0)
			printf("\t**Paciente nao encontrado**\n");
	}
	
	getchar();
	printf("\tTipo: ");
	gets(cirurgia->tipo);
	
	printf("\tStatus: ");
	gets(cirurgia->status);
	
	printf("\tSala: ");
	gets(cirurgia->sala);
	
	int i = 0, profissionalExiste;
	char opcao;
	for(i; i < 10; i++)
	{
		profissionalExiste = 0;
		while(profissionalExiste == 0)
		{
			printf("\tId profissional: ");
			scanf("%d", &cirurgia->equipeMedica[i].idProfissional);	
		
			profissionalExiste = verificarExistenciaProfissional(cirurgia->equipeMedica[i].idProfissional);
		
			if(profissionalExiste == 0)
				printf("\t**Profissional nao encontrado**\n");	
		}
		getchar();
		printf("\tFuncao na cirurgia: ");
		gets(cirurgia->equipeMedica[i].funcaoNaCirurgia);
		
		cirurgia->nMembrosEquipe++;
		
		printf("\tDeseja adicionar outro membro a equipe[s/n]: ");
		scanf("%c", &opcao);
		
		if(opcao == 's' || opcao == 'S')
			continue;
		else
			break;
	}
	
	printf("\tData da Cirurgia[DD/MM/AAAA]: \n");
	
	printf("\tDia: ");
	scanf("%d", &cirurgia->dataCirurgia.dia);
	
	printf("\tMes: ");
	scanf("%d", &cirurgia->dataCirurgia.mes);
	
	printf("\tAno: ");
	scanf("%d", &cirurgia->dataCirurgia.ano);
}

void pedirNovosDadosCirurgia(CIRURGIA *cirurgia)
{
	cirurgia->nMembrosEquipe = 0;
	
	system("cls");
	
	putchar('\n');
	printf("\t-------------------------------\n");
	printf("\t!!!! NOVA CIRURGIA !!!!\n");
	printf("\t-------------------------------\n");
	
	printf("\tId: %d\n", getNextCirurgiaAutoID());
	cirurgia->id = getNextCirurgiaAutoID();
	
	int pacienteExiste = 0;
	while(pacienteExiste == 0)
	{
		printf("\tId paciente: ");
		scanf("%d", &cirurgia->idPaciente);	
		
		pacienteExiste = verificarExistenciaPaciente(cirurgia->idPaciente);
		
		if(pacienteExiste == 0)
			printf("\t**Paciente nao encontrado**\n");
	}
	
	getchar();
	printf("\tTipo: ");
	gets(cirurgia->tipo);
	
	printf("\tStatus: ");
	gets(cirurgia->status);
	
	printf("\tSala: ");
	gets(cirurgia->sala);
	
	int i = 0, profissionalExiste;
	char opcao;
	for(i; i < 10; i++)
	{
		profissionalExiste = 0;
		while(profissionalExiste == 0)
		{
			printf("\tId profissional: ");
			scanf("%d", &cirurgia->equipeMedica[i].idProfissional);	
		
			profissionalExiste = verificarExistenciaProfissional(cirurgia->equipeMedica[i].idProfissional);
		
			if(profissionalExiste == 0)
				printf("\t**Profissional nao encontrado**\n");	
		}
		getchar();
		printf("\tFuncao na cirurgia: ");
		gets(cirurgia->equipeMedica[i].funcaoNaCirurgia);
		
		cirurgia->nMembrosEquipe++;
		
		printf("\tDeseja adicionar outro membro a equipe[s/n]: ");
		scanf("%c", &opcao);
		
		if(opcao == 's' || opcao == 'S')
			continue;
		else
			break;
	}
	
	printf("\tData da Cirurgia[DD/MM/AAAA]: \n");
	
	printf("\tDia: ");
	scanf("%d", &cirurgia->dataCirurgia.dia);
	
	printf("\tMes: ");
	scanf("%d", &cirurgia->dataCirurgia.mes);
	
	printf("\tAno: ");
	scanf("%d", &cirurgia->dataCirurgia.ano);
}

void mostrarDadosCirurgia(CIRURGIA cirurgia)
{
	printf("\t-------------------------------\n");
	
	printf("\tId: %d\n", cirurgia.id);
	
	printf("\tId Paciente: %d\n", cirurgia.idPaciente);
	
	printf("\tTipo: %s\n", cirurgia.tipo);
	
	printf("\tStatus: \n", cirurgia.status);
	
	printf("\tsala: %s\n", cirurgia.sala);
	
	printf("\tEQUIPE MEDICA: \n");
	int i = 0;
	for(i = 0; i < cirurgia.nMembrosEquipe; i++)
	{
		printf("\tId profissional: %d\n", cirurgia.equipeMedica[i].idProfissional);
		printf("\tFuncao na cirurgia: %s\n", cirurgia.equipeMedica[i].funcaoNaCirurgia);
		printf("\t--------------\n");	
	
	}
	
	printf("\tData da cirurgia: %d/%d/%d\n", 
		cirurgia.dataCirurgia.dia,
		cirurgia.dataCirurgia.mes,
		cirurgia.dataCirurgia.ano);
}

void salvarDadosCirurgia()
{
	FILE *fp;
	CIRURGIA cirurgia;
	
	//abrir ou criar o ficheiro 
	if ( (fp = fopen("CIRURGIAS.DAT", "ab")) == NULL)
	{
		puts("\t**Erro ao tentar abrir o ficheiro!**");
		return;
	}
	
	//movimentar o File Pointer
	fseek(fp, 0L, SEEK_END);	//SEEK_SET, SEEK_CUR, SEEK_END
	
	//pedir dados ao utilizador
	pedirDadosNovaCirurgia(&cirurgia);
	
	//escrever os dados da estrutura para o ficheiro
	if( fwrite(&cirurgia, sizeof(CIRURGIA), 1, fp) == 1)
	{
		system("cls");
		puts("\t**Registo adicionado com sucesso no Ficheiro**");
	}
	
	// fechar o ficheiro
	fclose( fp );
}

void listarDadosCirurgia()
{
	FILE *fp;
	CIRURGIA cirurgia;
	
	fp = fopen("CIRURGIAS.DAT", "rb"); // abre o arquivo para leitura
	if (fp == NULL)
    {
        puts("\t** Erro ao tentar abrir o ficheiro! **");
        return;
    }
	
	rewind(fp); // movimentar o File Pointer para o inicio
	
	system("cls");
	
	putchar('\n');
	printf("\t-------------------------------\n");
	printf("\t!!!! LISTA DE CIRURGIAS !!!!\n");
	printf("\t-------------------------------\n");
	
	//escrever os dados da estrutura para o ficheiro
	while( fread(&cirurgia, sizeof(CIRURGIA), 1, fp) == 1)
		mostrarDadosCirurgia(cirurgia);
		
	fclose( fp );
}

void pesquisarCirurgiaPorID()
{
	FILE *fp;
	CIRURGIA cirurgia;
	int idProcurado;
	
	//abrir ou criar o ficheiro 
	fp = fopen("CIRURGIAS.DAT", "rb");
	if (fp == NULL)
    {
        puts("\t** Erro ao tentar abrir o ficheiro! **");
        return;
    }
	
	//movimentar o File Pointer
	rewind(fp);
		
	system("cls");
	
	printf("\tDigite o ID Procurado: ");
	getchar();
	scanf("%d", &idProcurado);
	
	// escrever os dados do arquivo para e estrutura
	while( fread(&cirurgia, sizeof(CIRURGIA), 1, fp) == 1)
	{	
		if ( cirurgia.id == idProcurado)
		{				
			puts("\t** Registo localizado **");
			printf("\t-------------------------------\n");
			mostrarDadosCirurgia(cirurgia);
			
			fclose(fp);
			return;
		}
	}
	puts("\t** Registo nao localizado **");
		
	fclose( fp );
}

void removerDadosCirurgia()
{
	FILE *fp, *temp;
    CIRURGIA cirurgia; 
    int idParaRemover, encontrado = 0;

    // Abrir o arquivo original para leitura
    fp = fopen("CIRURGIAS.DAT", "rb");
    if (fp == NULL) {
        printf("\t** Erro ao abrir o arquivo original! **\n");
        return;
    }

    // Criar um arquivo temporario para armazenar os registros restantes
    temp = fopen("TEMP.DAT", "wb");
    if (temp == NULL) {
        printf("\t** Erro ao criar o arquivo temporario! **\n");
        fclose(fp);
        return;
    }

	system("cls");

	printf("\tId do cirurgia a ser removido: ");
	scanf("%d", &idParaRemover);

	system("cls");
	
    // Percorrer o arquivo e copiar os registros que não serao removidos
    while (fread(&cirurgia, sizeof(CIRURGIA), 1, fp) == 1) {
        if (cirurgia.id != idParaRemover) 
            fwrite(&cirurgia, sizeof(CIRURGIA), 1, temp);
        else 
            encontrado = 1;
    }

    fclose(fp);
    fclose(temp);

    // Substituir o arquivo original pelo temporario se um registro foi removido
    if (encontrado) {
        remove("CIRURGIAS.DAT");          // Apaga o arquivo original
        rename("TEMP.DAT", "CIRURGIAS.DAT"); // Renomeia o temporario para original
        printf("\t** Cirurgia removido com sucesso! **\n");
    } else {
        remove("TEMP.DAT"); // Se o ID nao foi encontrado, apagar o temporario
        printf("\t** Cirurgia com ID %d nao encontrado. **\n", idParaRemover);
    }
}

void editarDadosCirurgia()
{
    FILE *fp;
    CIRURGIA cirurgia;
    int id, encontrado = 0;

    fp = fopen("CIRURGIAS.DAT", "rb+"); // Abre para leitura e escrita
    if (fp == NULL)
    {
        puts("\t** Erro ao tentar abrir o ficheiro! **");
        return;
    }

	system("cls");

    printf("\tDigite o ID do cirurgia que deseja editar: ");
    scanf("%d", &id);

	system("cls");

    while (fread(&cirurgia, sizeof(CIRURGIA), 1, fp) == 1)
    {
        if (cirurgia.id == id)
        {
            encontrado = 1;
            printf("\t** Cirurgia encontrada! Insira os novos dados **\n");
            
            mostrarDadosCirurgia(cirurgia);
            
            // Funçao que coleta os novos dados do paciente
            pedirNovosDadosCirurgia(&cirurgia);

            // Voltar o ponteiro do ficheiro para reescrever os dados
            fseek(fp, -sizeof(CIRURGIA), SEEK_CUR);
            fwrite(&cirurgia, sizeof(CIRURGIA), 1, fp);

            printf("\t** Dados atualizados com sucesso! **\n");
            break;
        }
    }

    if (!encontrado)
        printf("\t** Cirurgia com ID %d nao encontrada! **\n", id);

    fclose(fp);
}
