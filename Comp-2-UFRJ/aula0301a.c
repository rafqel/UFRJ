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
 * $Log: aula0301a.c,v $
 * Revision 1.1  2021/08/10 21:18:19  rafael.jesus
 * Initial revision
 *
 */

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull n1,ull n2)
{
	if (n2 != 0)
		return CalcularMaximoDivisorComum(n2, n1%n2);
	else
		return n1;
}

/* $RCSfile: aula0301a.c,v $ */
