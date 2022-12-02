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
 * $Date: 2021/10/12 04:49:47 $
 * $Log: aula0904.c,v $
 * Revision 1.1  2021/10/12 04:49:47  rafael.jesus
 * Initial revision
 *
 */

#include "aula0901.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define OK																													0
#define NUMERO_ARGUMENTOS_INVALIDO																	1
#define ERRO_ABRINDO_ARQUIVO																				2
#define ERRO_CONVERTER_ARQUIVO_FORMATO_DOS_PARA_FORMATO_UNIX				3
#define MEMORIA_INSUFICIENTE																				4

#define NUMERO_ARGUMENTOS																						3

int
main (int argc, char *argv [ ])
{
	FILE *arquivo;
	char *nomeArquivo, *nomeArquivoGerado=NULL;
	size_t lenNome;
	tipoErros codigoRetorno;

	/* \/ TRATAMENTO DE EXCECAO \/ ----------------------------------------------- */

	if ((argc != NUMERO_ARGUMENTOS) && (argc != (NUMERO_ARGUMENTOS - 1)))
	{
		printf ("Uso: %s <nome-arquivo> <nome-desejado-arquivo>\n", argv[0]);
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
	nomeArquivo = argv[1];	

	if (argc == NUMERO_ARGUMENTOS){
		lenNome = strlen(argv[2]);

		nomeArquivoGerado = (char *) malloc ((lenNome + 1) * sizeof (char));
		if (!nomeArquivoGerado)
		{
			free(nomeArquivo);
			printf ("Memoria insuficiente. \n");
			exit (MEMORIA_INSUFICIENTE);
		}
		nomeArquivoGerado = argv[2];
	}

	/* /\ ALOCANDO MEMORIA /\ ---------------------------------------------------- */


	/* \/ RODANDO NA FUNCAO \/ --------------------------------------------------- */

	codigoRetorno = ConverterArquivoFormatoDosParaFormatoUnix (nomeArquivo, nomeArquivoGerado);
	if (codigoRetorno != ok)
	{
		printf ("Funcao ConverterArquivoFormatoUnixParaFormatoDos retornou o erro: %i \n", codigoRetorno);
		exit (ERRO_CONVERTER_ARQUIVO_FORMATO_DOS_PARA_FORMATO_UNIX);
	}

	/* /\ RODANDO NA FUNCAO /\ --------------------------------------------------- */


	memset (nomeArquivo, 0x00, COMPRIMENTO_MAX_NOME_ARQUIVO);
	if (argc == NUMERO_ARGUMENTOS)
		memset (nomeArquivoGerado, 0x00, COMPRIMENTO_MAX_NOME_ARQUIVO);

	return OK;
}

/* $RCSfile: aula0904.c,v $ */
