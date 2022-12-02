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
 * $Date: 2021/08/06 00:08:54 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2021/08/06 00:08:54  rafael.jesus
 * Initial revision
 *
 */

#include "aula0201.h"

ull CalcularTermoSerieFibonacci (us n)
{
	if (n<=1)
		return n;
	return CalcularTermoSerieFibonacci(n-1) + CalcularTermoSerieFibonacci(n-2);
}

/* $RCSfile: aula0201a.c,v $ */
