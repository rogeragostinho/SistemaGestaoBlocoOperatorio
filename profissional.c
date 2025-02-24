#include <stdio.h>
#include "profissional.h"

int getNextProfissionalAutoID() // pega o proximo Id
{
	FILE *fp;
	PROFISSIONAL profissional;
	int nextID = 1;
	
	fp = fopen("PROFISSIONAIS.DAT", "rb"); // abre o arquivo para leitura
	if ( fp == NULL)
	{
		puts("\t** Erro ao tentar abrir o ficheiro! **");
		return;
	}
	
	rewind(fp); // reposiciona o ponteiro para o inicio
	
	// conta os registos existentes
	while(fread(&profissional, sizeof(PROFISSIONAL), 1, fp) == 1) 
		nextID++;
		
	fclose(fp);
	
	return nextID;
}

void pedirDadosNovoProfissional(PROFISSIONAL *profissional)
{			
	system("cls");

	putchar('\n');
	printf("\t-------------------------------\n");
	printf("\t!!!! NOVO PACIENTE !!!!\n");
	printf("\t-------------------------------\n");
	
	printf("\tId: %d\n", getNextProfissionalAutoID());
	profissional->id = getNextProfissionalAutoID();
	
	printf("\tNome: ");
	getchar();
	gets(profissional->nome);
	
	printf("\tEspecialidade: ");
	gets(profissional->especialidade);
	
	printf("\tData cadastro[DD/MM/AAAA]\n");
	
	printf("\tDia: ");
	scanf("%d", &profissional->dataCadastro.dia);
	
	printf("\tMes: ");
	scanf("%d", &profissional->dataCadastro.mes);
	
	printf("\tAno: ");
	scanf("%d", &profissional->dataCadastro.ano);
}

void pedirNovosDadosProfissional(PROFISSIONAL *profissional)
{			
	putchar('\n');
	printf("\t-------------------------------\n");
	printf("\t!!!! NOVOS DADOS !!!!\n");
	printf("\t-------------------------------\n");
	
	printf("\tNome: ");
	getchar();
	gets(profissional->nome);
	
	printf("\tEspecialidade: ");
	gets(profissional->especialidade);
	
	printf("\tData cadastro[DD/MM/AAAA]\n");
	
	printf("\tDia: ");
	scanf("%d", &profissional->dataCadastro.dia);
	
	printf("\tMes: ");
	scanf("%d", &profissional->dataCadastro.mes);
	
	printf("\tAno: ");
	scanf("%d", &profissional->dataCadastro.ano);
	
	system("cls");
}

void mostrarDadosProfissional(PROFISSIONAL profissional)
{
	printf("\t-------------------------------\n");
	
	printf("\tId: %d\n", profissional.id);
	
	printf("\tNome: %s\n", profissional.nome);
	
	printf("\tEspecialidade: %s\n", profissional.especialidade);
	
	printf("\tData cadastro: %d/%d/%d\n", 
		profissional.dataCadastro.dia,
		profissional.dataCadastro.mes,
		profissional.dataCadastro.ano);
	
	printf("\t-------------------------------\n");
}

void salvarDadosProfissional()
{
	FILE *fp;
	PROFISSIONAL profissional;
	
	fp = fopen("PROFISSIONAIS.DAT", "ab"); // abrir ou criar o ficheiro 
	if ( fp == NULL)
	{
		puts("\t** Erro ao tentar abrir o ficheiro! **");
		return;
	}
	
	pedirDadosNovoProfissional(&profissional); // pedir dados ao utilizador
	
	system("cls");
	
	// escrever os dados da estrutura para o ficheiro
	if( fwrite(&profissional, sizeof(PROFISSIONAL), 1, fp) != 1) 
		puts("\t** Erro ao tentar escrever no ficheiro! **");
	else
		puts("\t** Registo adicionado com sucesso no Ficheiro **");
	
	fclose( fp );
}

void listarDadosProfissional()
{
	FILE *fp;
	PROFISSIONAL profissional;
	
	fp = fopen("PROFISSIONAIS.DAT", "rb"); // abre o arquivo para leitura
	if (fp == NULL)
    {
        puts("\t** Erro ao tentar abrir o ficheiro! **");
        return;
    }
	
	rewind(fp); // movimentar o File Pointer para o inicio
	
	system("cls");
	
	putchar('\n');
	printf("\t-------------------------------\n");
	printf("\t!!!! LISTA DE PROFISSIONAIS !!!!\n");
	printf("\t-------------------------------\n");
	
	//escrever os dados da estrutura para o ficheiro
	while( fread(&profissional, sizeof(PROFISSIONAL), 1, fp) == 1)
		mostrarDadosProfissional(profissional);
		
	fclose( fp );
}

void pesquisarProfissionalPorNome()
{
	FILE *fp;
	PROFISSIONAL profissional;
	char nomeProcurado[50];
	
	fp = fopen("PROFISSIONAIS.DAT", "rb"); //abre o ficheiro para leitura
	
	rewind(fp); // movimentar o File Pointer para o inicio
	
	system("cls");
	
	printf("\tDigite o Nome Procurado: ");
	getchar();
	gets(nomeProcurado);
	
	system("cls");
	
	// escrever os dados do arquivo para a estrutura
	while( fread(&profissional, sizeof(PROFISSIONAL), 1, fp) == 1)
	{	
		if ( strcmp(profissional.nome, nomeProcurado) == 0)
		{	
			puts("\t** Registo localizado **");
			printf("\t-------------------------------\n");
			mostrarDadosProfissional(profissional);
			
			fclose(fp);
			return;
		}
	}
	puts("\t** Registo nao localizado **");
		
	fclose( fp );
}

void removerDadosProfissional()
{
	FILE *fp, *temp;
    PROFISSIONAL profissional;
    int idParaRemover, encontrado = 0;

    // Abrir o arquivo original para leitura
    fp = fopen("PROFISSIONAIS.DAT", "rb");
    if (fp == NULL) {
        printf("\t** Erro ao abrir o arquivo original! **\n");
        return;
    }

    // Criar um arquivo temporário para armazenar os registros restantes
    temp = fopen("TEMP.DAT", "wb");
    if (temp == NULL) {
        printf("\t** Erro ao criar o arquivo temporário! **\n");
        fclose(fp);
        return;
    }

	system("cls");

	printf("\tId do Profissional a ser removido: ");
	scanf("%d", &idParaRemover);

	system("cls");
	
    // Percorrer o arquivo e copiar os registros que não serão removidos
    while (fread(&profissional, sizeof(PROFISSIONAL), 1, fp) == 1) {
        if (profissional.id != idParaRemover) 
            fwrite(&profissional, sizeof(PROFISSIONAL), 1, temp);
        else 
            encontrado = 1;
    }

    fclose(fp);
    fclose(temp);

    // Substituir o arquivo original pelo temporário se um registro foi removido
    if (encontrado) {
        remove("PROFISSIONAIS.DAT");          // Apaga o arquivo original
        rename("TEMP.DAT", "PROFISSIONAIS.DAT"); // Renomeia o temporário para original
        printf("\t** Profissional removido com sucesso! **\n");
    } else {
        remove("TEMP.DAT"); // Se o ID não foi encontrado, apagar o temporário
        printf("\t** Profissional com ID %d nao encontrado. **\n", idParaRemover);
    }
}

void editarDadosProfissional()
{
    FILE *fp;
    PROFISSIONAL profissional;
    int id, encontrado = 0;

    fp = fopen("PROFISSIONAIS.DAT", "rb+"); // Abre para leitura e escrita
    if (fp == NULL)
    {
        puts("\t** Erro ao tentar abrir o ficheiro! **");
        return;
    }

	system("cls");

    printf("\tDigite o ID do paciente que deseja editar: ");
    scanf("%d", &id);

	system("cls");

    while (fread(&profissional, sizeof(PROFISSIONAL), 1, fp) == 1)
    {
        if (profissional.id == id)
        {
            encontrado = 1;
            printf("\t** Profissional encontrado! Insira os novos dados **\n");
            
            mostrarDadosProfissional(profissional);
            
            // Função que coleta os novos dados do paciente
            pedirNovosDadosProfissional(&profissional);

            // Voltar o ponteiro do ficheiro para reescrever os dados
            fseek(fp, -sizeof(PROFISSIONAL), SEEK_CUR);
            fwrite(&profissional, sizeof(PROFISSIONAL), 1, fp);

            printf("\t** Dados atualizados com sucesso! **\n");
            break;
        }
    }

    if (!encontrado)
        printf("\t** Profissional com ID %d nao encontrado! **\n", id);

    fclose(fp);
}

int verificarExistenciaProfissional(int id)
{
	  FILE *fp;
    
	fp = fopen("PROFISSIONAIS.DAT", "rb");
	
    if (fp == NULL) 
        return 0; // Arquivo não encontrado, logo profissional não existe

    PROFISSIONAL p;
    while (fread(&p, sizeof(PROFISSIONAL), 1, fp)) {
        if (p.id == id) {
            fclose(fp);
            return 1; // Profissional encontrado
        }
    }

    fclose(fp);
    return 0; // Profissional não encontrado
}
