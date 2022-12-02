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
 * $Date: 2021/08/10 21:18:19 $
 * $Log: aula0302.c,v $
 * Revision 1.1  2021/08/10 21:18:19  rafael.jesus
 * Initial revision
 *
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
#include <limits.h>
#include <float.h>
#include "aula0301.h"

#define OK															0
#define ARGUMENTO_INVALIDO							1
#define NUMERO_ARGUMENTOS_INVALIDO			2
#define NUMERO_ARGUMENTOS								3
#define VALOR_MAXIMO_EXCEDIDO						4
#define END_OF_STRING										'\0'

int main(int argc, char* argv[])
{
	unsigned long long n1, n2;
	char* verificacao;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\"\nUso: <dois-inteiros-nao-negativo>\"\n");
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	if (argv[1][0] == '-')
	{
		printf ("\nCaractere invalido: '-'\n");
		printf ("\"Uso: <dois-inteiros-nao-negativo>\"\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (argv[2][0] == '-')
	{
		printf ("\nCaractere invalido: '-'\n");
		printf ("\"Uso: <dois-inteiros-nao-negativo>\"\n");
		exit (ARGUMENTO_INVALIDO);
	}

	n1 = strtoul(argv[1], &verificacao, 10);
	n2 = strtoul(argv[2], &verificacao, 10);

	if (n1<0)
	{
		printf ("\n\"Uso: <dois-inteiros-nao-negativo>\"\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	if (n2<0)
	{
		printf ("\n\"Uso: <dois-inteiros-nao-negativo>\"\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	if (*verificacao != END_OF_STRING)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		printf ("\n\"Uso: <dois-inteiros-nao-negativo>\"\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (n1 > ULLONG_MAX)
	{
		printf ("\nEntrada excede o valor maximo permitido para \"unsigned long long\" (%llu)\n", ULLONG_MAX);
		exit (VALOR_MAXIMO_EXCEDIDO);
	}

	if (n2 > ULLONG_MAX)
	{
		printf ("\nEntrada excede o valor maximo permitido para \"unsigned long long\" (%llu)\n", ULLONG_MAX);
		exit (VALOR_MAXIMO_EXCEDIDO);
	}


	printf ("O MDC de %llu e %llu eh %llu.\n", n1, n2, CalcularMaximoDivisorComum(n1,n2));
	
	return OK;
}

/* $RCSfile: aula0302.c,v $ */
