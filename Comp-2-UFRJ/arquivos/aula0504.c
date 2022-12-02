/* 
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2021/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Rafael Alves de Jesus
 * Descricao: <descrição sucinta dos objetivos do program
 *
 * $Author: rafael.jesus $
 * $Date: 2021/08/28 02:47:25 $
 * $Log: aula0504.c,v $
 * Revision 1.2  2021/08/28 02:47:25  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Incremento da funcao ValidarCpf.
 *
 * Revision 1.1  2021/08/28 02:00:06  rafael.jesus
 * Initial revision
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aula0504.h"


tipoErros
GerarDigitosVerificadoresCpf (char *cpf, char *DV1, char *DV2)
{
	unsigned short indice, soma1, soma2, peso1=10, peso2=11;
	unsigned digito;

	if (!cpf)
		return ARGUMENTO_IGUAL_A_NULL;

	for (indice = soma1 = soma2 = 0; indice < COMPRIMENTO_CPF - 2; indice++)
	{
		digito = cpf [indice] - '0';
		soma1 += (peso1) * digito;	
		soma2 += (peso2) * digito;
		peso1 -= 1;
		peso2 -= 1;
	}	

	if ((soma1 % 11) == 1 || (soma1 % 11) == 0)
		cpf[indice] = (char) (0 + '0');
	else
	{
		cpf [indice] = (char) ((11 - (soma1 % 11)) + '0');
		soma2 += (11 - (soma1 % 11)) * 2;
	}

	if ((soma2 % 11) == 1 || (soma2 % 11) == 0)
		cpf[indice + 1] = (char) (0 + '0');
	else
		cpf [indice + 1] = (char) ((11 - (soma2 % 11)) + '0');


	cpf [indice + 2] = '\0';
	return ok;
}

tipoErros
ValidarCpf (char *cpf) 
{
	unsigned short indice, peso1=10, peso2=11, soma1, soma2;
	unsigned digito;

	for (indice = soma1 = soma2 = 0 ; indice < COMPRIMENTO_CPF - 2; indice++)
	{
		digito = cpf [indice] - '0';
		soma1 += (peso1) * digito;
		soma2 += (peso2) * digito;
		peso1 -= 1;
		peso2 -= 1;
	}

	if ((soma1 % 11) == 1 || (soma1 % 11) == 0)
	{
		if (cpf [indice == (0 + '0')])
		{
			if (cpf [indice + 1] == (0 + '0'))
				return ok;
		}
		else
			return argumentoInvalido;
	}

	else if (cpf [indice] == ((11 - (soma1 % 11)) + '0'))
		{
			soma2 += (11 - (soma1 % 11)) * 2;

			if ((soma2 % 11) == 1 || (soma2 % 11) == 0)
			{
				if (cpf [indice + 1] == (0 + '0'))
					return ok;
			}

			else if (cpf [indice + 1] == ((11 - (soma2 % 11)) + '0'))
				return ok;

			else
				return argumentoInvalido;
		}

	return argumentoInvalido;
}



/* $RCSfile: aula0504.c,v $ */
