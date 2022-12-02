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
 * $Date: 2021/08/18 00:09:25 $
 * $Log: aula0402.c,v $
 * Revision 1.2  2021/08/18 00:09:25  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao da saida quando infinito.
 *
 * Revision 1.1  2021/08/17 21:48:51  rafael.jesus
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
#include "aula04.h"

#define OK															0
#define ARGUMENTO_INVALIDO							1
#define NUMERO_ARGUMENTOS_INVALIDO			2
#define NUMERO_ARGUMENTOS								3
#define VALOR_MAXIMO_EXCEDIDO						4
#define VALOR_MINIMO_EXCEDIDO						5
#define END_OF_STRING										'\0'

int main(int argc, char* argv[])
{
	double base;
	int expoente;
	long double saida;
	char* verificacao;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Numero de argumentos invalido. \n");
		printf ("\"Uso: <uma-base-do-tipo-real-e-um-expoente-do-tipo-inteiro.>\"\n");
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	base = strtod(argv[1], &verificacao);
	expoente = strtoul(argv[2], &verificacao, 10);	
	
	if (*verificacao != END_OF_STRING)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		printf ("\n\"Uso: <uma-base-do-tipo-real-e-um-expoente-do-tipo-inteiro.\"\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	if (base > DBL_MAX)
	{
		printf ("\nEntrada excede o valor maximo permitido para \"double\" (%lf)\n", DBL_MAX);
		exit (VALOR_MAXIMO_EXCEDIDO);
	}
	
	if (expoente > INT_MAX)
	{
		printf ("\nEntrada excede o valor maximo permitido para \"int\" (%d)\n", INT_MAX);
		exit (VALOR_MAXIMO_EXCEDIDO);
	}

	if (expoente < INT_MIN)
	{
		printf ("\nEntrada excede o valor minimo permitido para \"int\" (%d)\n", INT_MIN);
		exit (VALOR_MINIMO_EXCEDIDO);
	}
	
	saida = CalcularExponencial(base,expoente);
	printf ("%lf^%d = %Lf \n", base, expoente, saida);
	
	return OK;
}

/* $RCSfile: aula0402.c,v $ */
