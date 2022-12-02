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
 * $Date: 2021/08/27 18:37:58 $
 * $Log: aula0501.c,v $
 * Revision 1.4  2021/08/27 18:37:58  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao da funcao ValidarCpf.
 *
 * Revision 1.3  2021/08/27 14:43:37  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Remocao dos simbolos do CPF.
 *
 * Revision 1.2  2021/08/27 14:28:26  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Adicao de simbolos no CPF.
 *
 * Revision 1.1  2021/08/25 18:37:37  rafael.jesus
 * Initial revision
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "aula0501.h"

#define CPF_INVALIDO								1

tipoErros
GerarDigitosVerificadoresCpf (byte cpf [COMPRIMENTO_CPF - 2])
{
	unsigned short indice, soma1, soma2, peso1=10, peso2=11;
	unsigned digito;

	if (cpf == NULL)
		return argumentoInvalido;

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
ValidarCpf (byte cpf[COMPRIMENTO_CPF]) 
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

/* $RCSfile: aula0501.c,v $ */
