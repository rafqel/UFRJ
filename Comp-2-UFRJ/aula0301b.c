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
 * $Date: 2021/08/10 22:18:00 $
 * $Log: aula0301b.c,v $
 * Revision 1.1  2021/08/10 22:18:00  rafael.jesus
 * Initial revision
 *
 *
 */

#include "aula0301.h"

ull
CalcularMaximoDivisorComum (ull n1,ull n2)
{
	do
	{
		if (n1>n2)
			n1 -= n2;
		else
			n2 -= n1;
	}
	while(n1!=n2);
	
	return n1;
}

/* $RCSfile: aula0301b.c,v $ */
