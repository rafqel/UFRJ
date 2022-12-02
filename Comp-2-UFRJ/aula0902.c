/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Rafael Alves de Jesus
 * Descricao: <descrição sucinta dos objetivos do programa>
 *
 * $Author: rafael.jesus $
 * $Date: 2021/10/12 02:03:05 $
 * $Log: aula0902.c,v $
 * Revision 1.4  2021/10/12 02:03:05  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1
 * Correcao de erros no Linux.
 *
 * Revision 1.3  2021/10/12 00:42:53  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Update de macros.
 *
 * Revision 1.2  2021/10/11 03:32:06  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Update nas declaracoes.
 *
 * Revision 1.1  2021/10/10 19:51:53  rafael.jesus
 * Initial revision
 *
 */


#include "aula0901.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>

#define OK																				0
#define NUMERO_ARGUMENTOS_INVALIDO								1
#define NUMERO_ARGUMENTOS													2
#define ERRO_ABRINDO_ARQUIVO											3
#define ERRO_FUNCAO_EXIBIR_CONTEUDO_ARQUIVO				4
#define MEMORIA_INSUFICIENTE											5


int
main (int argc, char *argv [ ])
{
	FILE *arquivo;
	char *nomeArquivo;
	size_t lenNome;
	tipoErros codigoRetorno;

	/* \/ TRATAMENTO DE EXCECAO \/ ----------------------------------------------- */

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <nome-arquivo>\n", argv[0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}

	arquivo = fopen (argv[1], "r");
	if (arquivo == NULL)
	{
		printf ("Nao foi possivel abrir o arquivo \"%s\"\n", argv[1]);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		exit (ERRO_ABRINDO_ARQUIVO);
	}

	fclose (arquivo);


	/* /\ TRATAMENTO DE EXCECAO /\ ----------------------------------------------- */


	/* \/ ALOCANDO MEMORIA \/ ---------------------------------------------------- */

	lenNome = strlen(argv[1]);

	nomeArquivo = (char *) malloc ((lenNome + 1) * sizeof (char));
	if (!nomeArquivo)
	{
		printf ("Memoria insuficiente. \n");
		exit (MEMORIA_INSUFICIENTE);
	}

	/* /\ ALOCANDO MEMORIA /\ ---------------------------------------------------- */


	nomeArquivo = argv[1];	


	/* \/ RODANDO NA FUNCAO \/ --------------------------------------------------- */

	codigoRetorno = ExibirConteudoArquivo (nomeArquivo);
	if (codigoRetorno != ok)
	{
		printf ("Funcao ExibirConteudoArquivo retornou o erro: %i \n", codigoRetorno);
		exit (ERRO_FUNCAO_EXIBIR_CONTEUDO_ARQUIVO);
	}

	/* /\ RODANDO NA FUNCAO /\ --------------------------------------------------- */

	memset (nomeArquivo, 0x00, lenNome+1);
	return OK;
}

/* $RCSfile: aula0902.c,v $ */
