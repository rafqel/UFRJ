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
 * $Date: 2021/08/06 19:29:42 $
 * $Log: aula0201d.c,v $
 * Revision 1.1  2021/08/06 19:29:42  rafael.jesus
 * Initial revision
 *
 *
 */

#include "aula0201.h"

ull CalcularTermoSerieFibonacci (us n)
{
	int i=1,f=0,f1=1,f2=1;
	while(i<=n)
	{
		i++;
		f1=f2;
		f2=f;
		f=f1+f2;
	}
	return f;
}

/* $RCSfile: aula0201d.c,v $ */
