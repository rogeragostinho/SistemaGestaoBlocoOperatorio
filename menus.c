#include <stdio.h>
#include "menus.h"
#include "paciente.h"
#include "cirurgia.h"
#include "profissional.h"

#define MENU_PACIENTE 1
#define MENU_PROFISSIONAL 2
#define MENU_CIRURGIA 3
#define SAIR_DA_APLICACAO 4

#define NOVO_PACIENTE 1
#define EDITAR_PACIENTE 2
#define ELIMINAR_PACIENTE 3
#define LISTAR_PACIENTES 4
#define PESQUISAR_PACIENTE 5
#define VOLTAR_PACIENTE 6

#define NOVO_PROFISSIONAL 1
#define EDITAR_PROFISSIONAL 2
#define ELIMINAR_PROFISSIONAL 3
#define LISTAR_PROFISSIONAIS 4
#define PESQUISAR_PROFISSIONAL 5
#define VOLTAR_PROFISSIONAL 6

#define NOVA_CIRURGIA 1
#define EDITAR_CIRURGIA 2
#define ELIMINAR_CIRURGIA 3
#define LISTAR_CIRURGIAS 4
#define PESQUISAR_CIRURGIA 5
#define VOLTAR_CIRURGIA 6


void apresentacao()
{
	int opcao;
	
	putchar('\n');
	printf("\t------------------------------------------------\n");
	printf("\tUNIVERSIDADE CATOLICA DE ANGOLA\n");
	printf("\tFACULDADE DE ENGENHARIA\n");
	printf("\tPROJECTO DE FUNDAMENTOS DE PROG. I ANO 24-25\n");
	printf("\tAUTOR: ROGER AGOSTINHO, N. 35031\n");
	printf("\t------------------------------------------------\n");
	printf("\tTEMA: GESTAO DE UM BLOCO OPERATORIO\n");
	printf("\tDOCENTE: ENG. OSVALDO RAMOS\n");
	printf("\tOBS: USO EXCLUSIVO DENTRO DA UCAN\n");
	printf("\t------------------------------------------------\n");
	printf("\tSE CONCORDA COM OS TERMOS DE USO DIGITE \"S\", \"N\" CASO CONTRARIO\n");
	
	printf("        >");
	
	scanf("%c", &opcao);	
	
	if (opcao == 'S' || opcao == 's')
		//menuPrincipal();
		login();
	else
		return;
}

#define USER "admin"
#define PASSWORD "admin"

void login()
{
	char user[10], password[10];
	int erros = 1, login = 0;
	
	while(login == 0)
	{		
		system("cls");
		
		putchar('\n');
		printf("\t-------------------------------\n");
		printf("\t!!! LOGIN !!!\n");
		printf("\t-------------------------------\n");
		printf("\tUser: ");
		scanf("%s", user);
		
		printf("\tPassword: ");
		scanf("%s", password);
		
		if((strcmp(user, USER) == 0) && (strcmp(password, PASSWORD) == 0))
			login = 1;
		else
		{
			putchar('\n');
			printf("\t**User ou password invalidos**\n\n");
			printf("\tPressione <ENTER> para continuar");
			getchar();
			getchar();
		}
	}
	menuPrincipal();
}

void menuPrincipal()
{
	int opcao;
	
	do
	{
		system("cls");
		
		putchar('\n');
		printf("\t-------------------------------\n");
		printf("\t!!!! MENU PRINCIPAL !!!!\n");
		printf("\t-------------------------------\n");
		printf("\t1 - MENU PACIENTE\n");
		printf("\t2 - MENU PROFISSIONAL\n");
		printf("\t3 - MENU CIRURGIA\n");
		printf("\t4 - SAIR DA APLICACAO\n");
		
		printf("        >");
		scanf("%d", &opcao);
		
		switch(opcao)
		{
			case MENU_PACIENTE:
				menuPaciente();
			break;
			
			case MENU_PROFISSIONAL:
				menuProfissional();
			break;
			
			case MENU_CIRURGIA:
				menuCirurgia();
			break;
			
			case SAIR_DA_APLICACAO:
				return;
			break;
			
			default:
				printf("Opcao Invalida!\n");
			break;
		}
	}
	while(opcao != SAIR_DA_APLICACAO);
}

void menuPaciente()
{
	int opcao;
	
	system("cls");
	
	do
	{
		putchar('\n');
		printf("\t-------------------------------\n");
		printf("\t!!!! MENU PACIENTE !!!!\n");
		printf("\t-------------------------------\n");
		printf("\t1 - NOVO PACIENTE\n");
		printf("\t2 - EDITAR PACIENTE\n");
		printf("\t3 - ELIMINAR PACIENTE\n");
		printf("\t4 - LISTAR PACIENTES\n");
		printf("\t5 - PESQUISAR PACIENTE\n");
		printf("\t6 - VOLTAR\n");
		
		printf("        >");
		scanf("%d", &opcao);
		
		switch (opcao)
		{
			case NOVO_PACIENTE:
				salvarDadosPaciente();			
			break;
			
			case EDITAR_PACIENTE:
				editarDadosPaciente();
			break;
			
			case ELIMINAR_PACIENTE:
				removerDadosPaciente();
			break;
		
			case LISTAR_PACIENTES:
				listarDadosPaciente();
			break;
			
			case PESQUISAR_PACIENTE:
				pesquisarPacientePorNome();
			break;
				
			case VOLTAR_PACIENTE:
				return;
			break;
			
			default:
				printf("**Opcao Invalida**\n");
			break;
		}
	}while(opcao != VOLTAR_PACIENTE);
}

void menuProfissional()
{
	int opcao;
	
	system("cls");
	
	do
	{
		putchar('\n');
		printf("\t-------------------------------\n");
		printf("\t!!!! MENU PROFISSIONAL !!!!\n");
		printf("\t-------------------------------\n");
		printf("\t1 - NOVO PROFISSIONAL\n");
		printf("\t2 - EDITAR PROFISSIONAL\n");
		printf("\t3 - ELIMINAR PROFISSIONAL\n");
		printf("\t4 - LISTAR PROFISSIONAIS\n");
		printf("\t5 - PESQUISAR PROFISSIONAL\n");
		printf("\t6 - VOLTAR\n");
		
		printf("        >");
		scanf("%d", &opcao);
		
		switch (opcao)
		{
			case NOVO_PROFISSIONAL:
				salvarDadosProfissional();			
			break;
			
			case EDITAR_PROFISSIONAL:
				editarDadosProfissional();
			break;
			
			case ELIMINAR_PROFISSIONAL:
				removerDadosProfissional();
			break;
		
			case LISTAR_PROFISSIONAIS:
				listarDadosProfissional();
			break;
			
			case PESQUISAR_PROFISSIONAL:
				pesquisarProfissionalPorNome();
			break;
				
			case VOLTAR_PROFISSIONAL:
				return;
			break;
			
			default:
				printf("Opcao Invalida\n");
			break;
		}	
	}
	while(opcao != VOLTAR_PROFISSIONAL);
}

void menuCirurgia()
{
	int opcao;
	
	system("cls");
	
	do{
		putchar('\n');
		printf("\t-------------------------------\n");
		printf("\t!!!! MENU CIRURGIA !!!!\n");
		printf("\t-------------------------------\n");
		printf("\t1 - NOVA CIRURGIA\n");
		printf("\t2 - EDITAR CIRURGIA\n");
		printf("\t3 - ELIMINAR CIRURGIA\n");
		printf("\t4 - LISTAR CIRURGIAS\n");
		printf("\t5 - PESQUISAR CIRURGIA\n");
		printf("\t6 - VOLTAR\n");
		
		printf("        >");
		scanf("%d", &opcao);
		
		switch (opcao)
		{
			case NOVA_CIRURGIA:
				salvarDadosCirurgia();			
			break;
			
			case EDITAR_CIRURGIA:
				editarDadosCirurgia();
			break;
			
			case ELIMINAR_CIRURGIA:
				removerDadosCirurgia();
			break;
		
			case LISTAR_CIRURGIAS:
				listarDadosCirurgia();
			break;
			
			case PESQUISAR_CIRURGIA:
				pesquisarCirurgiaPorID();
			break;
				
			case VOLTAR_CIRURGIA:
				return;
			break;
			
			default:
				printf("Opcao Invalida\n");
			break;
		}
	}while(opcao != VOLTAR_CIRURGIA);
}
