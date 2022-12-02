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
 * $Date: 2021/08/06 14:54:04 $
 * $Log: aula0201b.c,v $
 * Revision 1.1  2021/08/06 14:54:04  rafael.jesus
 * Initial revision
 *
 *
 */

#include "aula0201.h"

ull CalcularTermoSerieFibonacci (us n)
{
	int i=1,f=0,f1=1,f2=1;
	do
	{
		i++;
		f1=f2;
		f2=f;
		f=f1+f2;
	}
	while (i<=n);
	return f;
}

/* $RCSfile: aula0201b.c,v $ */
