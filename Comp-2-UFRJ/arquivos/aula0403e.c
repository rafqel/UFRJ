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
 * $Date: 2021/08/21 01:59:44 $
 * $Log: aula0403e.c,v $
 * Revision 1.1  2021/08/21 01:59:44  rafael.jesus
 * Initial revision
 *
 */

#define OK									0	

#include <math.h>
#include "aula04.h"

float
CalcularSerieHarmonicaAlternada (unsigned short int ntermos)
{
	float potencia;
	potencia = pow(ntermos,ntermos);

	if (ntermos == 0)
		return 0;
	
	if (ntermos == 1)
		return 1;

	else if (ntermos%2 == 0)
	{
		return -1 / potencia + (CalcularSerieHarmonicaAlternada (ntermos-1));
	}
	else if (ntermos%2 != 0)		
	{
		return 1 / potencia + (CalcularSerieHarmonicaAlternada (ntermos-1));
	}
	
	return OK;
}


/* $RCSfile: aula0403e.c,v $ */
