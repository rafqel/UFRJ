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
 * $Date: 2021/08/08 13:20:22 $
 * $Log: aula0202.c,v $
 * Revision 1.1  2021/08/08 13:20:22  rafael.jesus
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
#include <errno.h>
#include "aula0201.h"

#define NUMERO_ARGUMENTOS								2
#define NUMERO_ARGUMENTOS_INVALIDO			3
#define VALOR_MAXIMO_EXCEDIDO						4
#define END_OF_STRING										'\0'

int main(int argc, char* argv[])
{
	unsigned long long n;
	unsigned short i;
	char* verificacao;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("\"\nUso: <inteiro-nao-negativo-curto>\"\n");
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	if (argv[1][0] == '-')
	{
		printf ("\nCaractere invalido: '-'\n");
		printf ("\"Uso: <inteiro-nao-negativo-curto>\"\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	n = strtoul(argv[1], &verificacao, 10);
	if (n<0)
	{
		printf ("\n\"Uso: <inteiro-nao-negativo-curto>\"\n");
		exit (ARGUMENTO_INVALIDO);
	}
	
	if (*verificacao != END_OF_STRING)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (n > USHRT_MAX)
	{
		printf ("\nEntrada excede o valor maximo permitido para \"unsigned short\" (%u)\n", USHRT_MAX);
		exit (VALOR_MAXIMO_EXCEDIDO);
	}

	for (i=0;i<n+1;i++)
	{
		printf ("F (%hu): %llu\n", i, CalcularTermoSerieFibonacci(i));
	}
	return OK;
}

/* $RCSfile: aula0202.c,v $ */
