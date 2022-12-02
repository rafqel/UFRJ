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
 * $Date: 2021/08/17 23:18:32 $
 * $Log: aula0401a.c,v $
 * Revision 1.1  2021/08/17 23:18:32  rafael.jesus
 * Initial revision
 *
 * Revision 1.1  2021/08/17 23:07:00  rafael.jesus
 * Initial revision
 *
 * Revision 1.1  2021/08/17 21:05:32  rafael.jesus
 * Initial revision
 *
 */

#include <math.h>
#if defined (__STRICT_ANSI__) && defined(__linux__)
#define INFINITO 1.0/0.0
#else
#define INFINITO INFINITY
#endif

#include "aula04.h"

long double
CalcularExponencial (double base, int expoente)
{
	if (expoente == 0)
		return 1;
	
	if (expoente == 1)
		return base;
		
	if ((base == 0) && (expoente<0))
		return INFINITO;

	if (expoente<0)
		return (1/CalcularExponencial (base, -expoente) * base)/2;

	else
		return CalcularExponencial (base, expoente-1) * base;
}

/* $RCSfile: aula0401a.c,v $ */
