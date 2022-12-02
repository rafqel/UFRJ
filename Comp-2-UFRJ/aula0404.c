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
 * $Date: 2021/08/21 00:07:31 $
 * $Log: aula0404.c,v $
 * Revision 1.2  2021/08/21 00:07:31  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao referente a tratamento de excecao.
 *
 * Revision 1.1  2021/08/20 22:22:58  rafael.jesus
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
#include <limits.h>
#include <float.h>
#include <errno.h>
#include "aula04.h"

#define OK															0
#define ARGUMENTO_INVALIDO							1
#define NUMERO_ARGUMENTOS								2
#define NUMERO_ARGUMENTOS_INVALIDO			3
#define VALOR_MAXIMO_EXCEDIDO						4
#define END_OF_STRING										'\0'

int main(int argc, char* argv[])
{
	float p;
	int n=1;
	float modulo, segundo;
	char* verificacao;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\"Uso: <valor-maior-que-0-e-menor-que-1.>\"\n");
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	if (argv[1][0] == '-')
	{
		printf ("\"Uso: <valor-maior-que-0-e-menor-que-1.>\"\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	p = strtof(argv[1], &verificacao);
	if (p<0)
	{
		printf ("\n\"Uso: <valor-maior-que-0-e-menor-que-1.>\"\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (p>1)
	{
		printf ("\n\"Uso: <valor-maior-que-0-e-menor-que-1.>\"\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (*verificacao != END_OF_STRING)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (p > USHRT_MAX)
	{
		printf ("\nEntrada excede o valor maximo permitido para \"unsigned short\" (%u)\n", USHRT_MAX);
		exit (VALOR_MAXIMO_EXCEDIDO);
	}


	printf ("S (0) = 0 \n");

	do
	{	
		modulo = (CalcularSerieHarmonicaAlternada(n)-CalcularSerieHarmonicaAlternada(n-1));
		if (modulo < 0)
			modulo = -(modulo);
		segundo = p * (CalcularSerieHarmonicaAlternada(n-1));
		printf ("S (%d) = %f \n", n, CalcularSerieHarmonicaAlternada(n));
		n++;
	}
	while (modulo > segundo);
	
	return OK;
}

/* $RCSfile: aula0404.c,v $ */
