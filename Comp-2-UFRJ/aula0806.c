/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Rafael Alves de Jesus
 * Descricao: <descrição sucinta dos objetivos do program
 *
 * $Author: rafael.jesus $
 * $Date: 2021/10/02 04:55:49 $
 * $Log: aula0806.c,v $
 * Revision 1.2  2021/10/02 04:55:49  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Alteracoes no printf.
 *
 * Revision 1.1  2021/10/01 17:19:23  rafael.jesus
 * Initial revision
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0801.h"

#define OK																			0
#define ARGUMENTO_INVALIDO											1
#define NUMERO_ARGUMENTOS_INVALIDO							2
#define ERRO_FUNCAO_CODIFICAR_BASE_64						3
#define MEMORIA_INSUFICIENTE										4

int
main (int argc, char *argv [])
{
	byte *conjuntoBytes;
	tipoFinalLinha indicador;
	unsigned long long numBytes;
	char *string, *verificacao;
	unsigned nArgumentos, indice;
	tipoErros codigoRetorno;


	/* TRATAMENTO DE EXCECAO */

	indicador = strtoul (argv[1], &verificacao, 10);
	numBytes = strtoul (argv[2], &verificacao, 10);
	nArgumentos = 3 + (strtoul (argv[2], &verificacao, 10));

	if (argc != nArgumentos)
	{
		printf ("Erro: Numero de argumentos invalido. \n");
		printf ("Uso: %s <Indicador de final de linha, numero de bytes, seguido pelos bytes em notacao hexadecimal.> \n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);    
  }

	for (indice = 1; indice < argc ; indice++) {
		if (argv[indice][0] == '-')
		{
			printf ("Erro: Caractere invalido: '-' \n");
			exit (ARGUMENTO_INVALIDO);
		}
	}


	/* ALOCANDO MEMORIA */

	string = (char *) malloc (6 * numBytes * sizeof(char) + 1);	
	if (string == NULL)
	{
		printf ("Memoria insuficiente. \n");
		exit (MEMORIA_INSUFICIENTE);
	}

	conjuntoBytes = (byte *) malloc (numBytes * sizeof(byte));
	if (conjuntoBytes == NULL)
	{
		free (string);
		printf ("Memoria insuficiente. \n");
		exit (MEMORIA_INSUFICIENTE);
	}


	/* OBTENDO VALORES*/

	for (indice = 0 ; indice < (argc - 3) ; indice++)
		conjuntoBytes[indice] = (byte) strtoul(argv[indice + 3], &verificacao, 16);


	/* TRATAMENTO DE EXCECAO */

	if (*verificacao != END_OF_STRING)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}

	/* INDO PARA A FUNCAO */

	codigoRetorno = CodificarBase64 (conjuntoBytes, numBytes, indicador, string);
	if (codigoRetorno != ok)
	{
		free(conjuntoBytes);
		free(string);
		printf ("Funcao CodificarBase64 retornou o erro: %i \n", codigoRetorno);
		exit (ERRO_FUNCAO_CODIFICAR_BASE_64);
	}


	for (indice = 0 ; indice < strlen(string) * 4/3; indice++) 
	{
		printf ("%c", string[indice]);
		/* FINAL DE LINHA */
		if (indice % TAMANHO_MAX_LINHA_64 == 0) {
			if (indice != 0) {
				if (indicador == habilitado)
					printf ("\n");
			}
		}
	}
	printf ("\n");

	free(conjuntoBytes);
	free(string);

	return OK;
}

/* $RCSfile: aula0806.c,v $ */
