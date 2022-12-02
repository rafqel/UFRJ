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
 * $Date: 2021/08/06 19:14:41 $
 * $Log: aula0201c.c,v $
 * Revision 1.1  2021/08/06 19:14:41  rafael.jesus
 * Initial revision
 *
 *
 */

#include "aula0201.h"

ull CalcularTermoSerieFibonacci (us n)
{
	int f[n+2], i;
	f[0] = 0;
	f[1] = 1;
	
	for (i=2; i<=n; i++)
	{
		f[i] = f[i-1]+f[i-2];
	}	
	return f[n];
}

/* $RCSfile: aula0201c.c,v $ */
