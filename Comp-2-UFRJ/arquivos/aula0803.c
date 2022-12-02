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
 * $Date: 2021/09/30 03:21:41 $
 * $Log: aula0803.c,v $
 * Revision 1.1  2021/09/30 03:21:41  rafael.jesus
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
#define ERRO_FUNCAO_DECODIFICAR_BASE_16					3
#define MEMORIA_INSUFICIENTE										4

#define NUMERO_ARGUMENTOS												2

int
main (int argc, char *argv [])
{
	byte *conjuntoBytes;
	unsigned long long *numBytes;
	char *string;
	unsigned indice;
	tipoErros codigoRetorno;


	/* TRATAMENTO DE EXCECAO */

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Erro: Numero de argumentos invalido. \n");
    exit (NUMERO_ARGUMENTOS_INVALIDO);
  }

	if (argv[1][0] == '-')
	{
			printf ("Erro: Caractere invalido: '-' \n");
			exit (ARGUMENTO_INVALIDO);
	}


	/* ALOCANDO MEMORIA */

	numBytes = (unsigned long long *) malloc (sizeof(unsigned long long));	
	if (numBytes == NULL)
	{
		printf ("Memoria insuficiente. \n");
		exit (MEMORIA_INSUFICIENTE);
	}


	numBytes[0] = strlen(argv[1]);

	string = (char *) malloc ((2 * numBytes[0] + 1) * sizeof(char));	
	if (string == NULL)
	{
		printf ("Memoria insuficiente. \n");
		exit (MEMORIA_INSUFICIENTE);
	}


	for (indice = 0 ; indice < numBytes[0] ; indice++)
		string[indice] = argv[1][indice];

	conjuntoBytes = (byte *) malloc (numBytes[0] * sizeof(byte));
	if (conjuntoBytes == NULL)
	{
		free (string);
		printf ("Memoria insuficiente. \n");
		exit (MEMORIA_INSUFICIENTE);
	}


	/* INDO PARA A FUNCAO */

	codigoRetorno = DecodificarBase16 (string, conjuntoBytes, numBytes);
	if (codigoRetorno != ok)
	{
		free(numBytes);
		free(conjuntoBytes);
		free(string);
		printf ("Funcao DecodificarBase16 retornou o erro: %i \n", codigoRetorno);
		exit (ERRO_FUNCAO_DECODIFICAR_BASE_16);
	}


	for (indice = 0 ; indice < numBytes[0]/2; indice++) 
	{
		printf ("%d ", conjuntoBytes[indice]);
	}
	printf ("\n");

	free(numBytes);
	free(conjuntoBytes);
	free(string);

	return OK;
}

/* $RCSfile: aula0803.c,v $ */
