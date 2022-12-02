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
 * $Date: 2021/08/10 22:10:37 $
 * $Log: aula0301c.c,v $
 * Revision 1.1  2021/08/10 22:10:37  rafael.jesus
 * Initial revision
 *
 * 
 */

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull n1,ull n2)
{
	ull mdc, i;

	for (i=1; i<=n1 && i<= n2; i++)
	{
		if (n1%i==0 && n2%i==0)
			mdc = i;
	}
	return mdc;
}

/* $RCSfile: aula0301c.c,v $ */
