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
 * $Date: 2021/10/02 08:35:13 $
 * $Log: aula0807.c,v $
 * Revision 1.1  2021/10/02 08:35:13  rafael.jesus
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
#define NUMERO_ARGUMENTOS												3
#define ERRO_FUNCAO_DECODIFICAR_BASE_64					4
#define MEMORIA_INSUFICIENTE										5

int
main (int argc, char *argv [])
{
	byte *conjuntoBytes;
	tipoFinalLinha indicador;
	unsigned long long *numBytes;
	char *string, *verificacao;
	unsigned indice;
	tipoErros codigoRetorno;


	/* TRATAMENTO DE EXCECAO */

	indicador = strtoul (argv[1], &verificacao, 10);

	if (argc != NUMERO_ARGUMENTOS){
		printf ("Erro: Numero de argumentos invalido. \n");
		printf ("Uso: %s <Indicador de final de linha e string a ser decodificada.> \n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

	if (argv[1][0] == '-')
	{
		printf ("Erro: Caractere invalido: '-' \n");
		printf ("Uso: 0 ou 1. \n");
		exit (ARGUMENTO_INVALIDO);
	}


	/* ALOCANDO MEMORIA */


	numBytes = (unsigned long long *) malloc (sizeof(unsigned long long));	
	if (numBytes == NULL){
		printf ("Memoria insuficiente. \n");
		exit (MEMORIA_INSUFICIENTE);
	}

	numBytes[0] = strlen(argv[1]);

	string = (char *) malloc (6 * numBytes[0] * sizeof(char) + 1);	
	if (string == NULL)
	{
		free (numBytes);
		printf ("Memoria insuficiente. \n");
		exit (MEMORIA_INSUFICIENTE);
	}

	conjuntoBytes = (byte *) malloc ((numBytes[0]) * sizeof(byte));
	if (conjuntoBytes == NULL)
	{
		free (numBytes);
		free (string);
		printf ("Memoria insuficiente. \n");
		exit (MEMORIA_INSUFICIENTE);
	}


	/* OBTENDO VALORES*/

	for (indice = 0 ; indice < numBytes[0] ; indice++)
		string[indice] = argv[1][indice];


	/* TRATAMENTO DE EXCECAO */

	if (*verificacao != END_OF_STRING)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}

	/* INDO PARA A FUNCAO */

	codigoRetorno = DecodificarBase64 (string, indicador, conjuntoBytes, numBytes);
	if (codigoRetorno != ok)
	{
		free(conjuntoBytes);
		free(string);
		printf ("Funcao DecodificarBase64 retornou o erro: %i \n", codigoRetorno);
		exit (ERRO_FUNCAO_DECODIFICAR_BASE_64);
	}


	for (indice = 0 ; indice < strlen(string)*6; indice++)
		printf ("%d ", conjuntoBytes[indice]);
	printf ("\n");

	free(numBytes);
	free(conjuntoBytes);
	free(string);

	return OK;
}

/* $RCSfile: aula0807.c,v $ */
