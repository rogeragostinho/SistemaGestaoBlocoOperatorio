/*************************
File: analise.c
Tema: Gestao de um Bloco Operatorio
Nome: Roger Agostinho, 35031
Data: 15.01.2025
**************************/

/*
1. Objectivo do Projecto:
Implementar um sistema capaz de gerenciar o agendamento
e controle de cirurgias e pacientes em um bloco operatorio,
otimizando o processo de operacoes.

2. Menus
	2.1 - MENU PRINCIPAL
			1 - MENU PACIENTE
			2 - MENU PROFISSIONAL
			3 - MENU CIRURGIA
			4 - SAIR DA APLICACAO
			
		2.1.1 - MENU PACIENTE
				1 - NOVO PACIENTE
				2 - EDITAR PACIENTE
				3 - ELIMINAR PACIENTE
				4 - LISTAR PACIENTES
				5 - PESQUISAR PACIENTE
				6 - VOLTAR
				
		2.1.2 - MENU PROFISSIONAL
				1 - NOVO PROFISSIONAL
				2 - EDITAR PROFISSIONAL
				3 - ELIMINAR PROFISSIONAL
				4 - LISTAR PROFISSIONAIS
				5 - PESQUISAR PROFISSIONAL
				6 - VOLTAR

		2.1.3 - MENU CIRURGIA
				1 - NOVA CIRURGIA
				2 - EDITAR CIRURGIA
				3 - ELIMINAR CIRURGIA
				4 - LISTAR CIRURGIAS
				5 - PESQUISAR CIRURGIA
				6 - VOLTAR

3. Entidades
	3.1 - Fortes
		PACIENTE
			int id, idade, contacto;
			char nome[50], genero[10], diagnostico[100];
			DATE dataCadastro;

		PROFISSIONAL
			int id;
			char nome[50], especialidade[50];
			DATE dataCadastro;

		CIRURGIA
			int id, idPaciente, nMembrosEquipe;
			char tipo[50], status[20], sala[30];
			EQUIPEMEDICA equipeMedica[10];
			DATE dataCirurgia;
			
	3.2 - Fracas
		EQUIPEMEDICA
			int idProfissional;
			char funcaoNaCirurgia[50];

		DATE
			int dia, mes, ano;
		
4. Ficheiros de Dados
	PACIENTES.DAT
	CIRURGIAS.DAT
	PROFISSIONAIS.DAT
	
5. Implementacao
Linguagem C, no IDE: Dev-C++
*/
