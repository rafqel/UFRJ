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
 * $Log: aula0401c.c,v $
 * Revision 1.1  2021/08/18 00:09:25  rafael.jesus
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
	long double saida=1;
	int i;
	
	if (expoente == 0)
		return 1;
	
	if (expoente == 1)
		return base;
		
	if ((base == 0) && (expoente<0))
		return INFINITO;

	if (expoente<0){
		expoente = -expoente;
		for (i=1; i<=expoente; i++)
			saida = saida * base;
		return 1/saida;
	}

	else {
		for (i=1; i<=expoente; i++)
			saida = saida * base;
		return saida;
	}
}

/* $RCSfile: aula0401c.c,v $ */
