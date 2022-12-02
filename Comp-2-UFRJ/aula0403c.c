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
 * $Date: 2021/08/20 23:52:21 $
 * $Log: aula0403c.c,v $
 * Revision 1.1  2021/08/20 23:52:21  rafael.jesus
 * Initial revision
 *
 */

#include "aula04.h"

float
CalcularSerieHarmonicaAlternada (unsigned short int ntermos)
{
	unsigned short int i=ntermos;
	int sinal=-1;
	float saida=0;

	if (ntermos == 0)
		return 0;
	
	else if (ntermos == 1)
		return 1;
	
	else
	{
		if (ntermos%2 != 0)
			sinal = -(sinal);
		
		for (i=ntermos; i>=1; i--)
		{
			saida = saida + sinal * 1 / CalcularExponencial(i,i);
			sinal = -1*sinal;
		}
		return saida;
	}
}


/* $RCSfile: aula0403c.c,v $ */
