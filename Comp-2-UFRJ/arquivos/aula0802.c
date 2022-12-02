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
 * $Date: 2021/09/29 21:45:36 $
 * $Log: aula0802.c,v $
 * Revision 1.1  2021/09/29 21:45:36  rafael.jesus
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
#define ERRO_FUNCAO_CODIFICAR_BASE_16						3
#define MEMORIA_INSUFICIENTE										4

int
main (int argc, char *argv [])
{
	byte *conjuntoBytes;
	unsigned long long numBytes;
	char *string, *verificacao;
	unsigned nArgumentos, indice, indiceAuxiliar;
	tipoErros codigoRetorno;


	/* TRATAMENTO DE EXCECAO */

	nArgumentos = 2 + (strtoul (argv[1], &verificacao, 10));

	if (argc != nArgumentos)
	{
		printf ("Erro: Numero de argumentos invalido. \n");
		printf ("Uso: %s <Insira o numero de bytes a codificar e os bytes em notacao decimal (valores entre 0 e 255).> \n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);    
  }

	for (indice = 1; indice < argc ; indice++) {
		if (argv[indice][0] == '-')
		{
			printf ("Erro: Caractere invalido: '-' \n");
			printf ("Uso: <Numero nao negativo. Numero entre 0 e 255.> \n");
			exit (ARGUMENTO_INVALIDO);
		}
	}


	/* ALOCANDO MEMORIA */

 	numBytes = strtoul (argv[1], &verificacao, 10);

	string = (char *) malloc ((2 * numBytes + 1) * sizeof(char));	
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

	indiceAuxiliar = 0;
	for (indice = 2 ; indice < argc ; indice++)
	{
		conjuntoBytes[indiceAuxiliar] = (byte) strtoul (argv[indice], &verificacao, 10);
		if (strtoul (argv[indice], &verificacao, 10) > 255)
		{
			printf ("Erro: Valor invalido. \n");
			printf ("Uso: <Valor deve ser entre 0 e 255.> \n");
			exit (ARGUMENTO_INVALIDO);
		}
		indiceAuxiliar++;
	}


	/* TRATAMENTO DE EXCECAO */

	if (*verificacao != END_OF_STRING)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}

	/* INDO PARA A FUNCAO */

	codigoRetorno = CodificarBase16 (conjuntoBytes, numBytes, string);
	if (codigoRetorno != ok)
	{
		free(conjuntoBytes);
		free(string);
		printf ("Funcao CodificarBase16 retornou o erro: %i \n", codigoRetorno);
		exit (ERRO_FUNCAO_CODIFICAR_BASE_16);
	}


	for (indice = 0 ; indice < numBytes*2; indice++) 
	{
		printf ("%c", BASE_16[(unsigned) string[indice]]);
	}
	printf ("\n");

	free(conjuntoBytes);
	free(string);

	return OK;
}

/* $RCSfile: aula0802.c,v $ */
