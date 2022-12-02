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
 * $Log: aula0506a.c,v $
 * Revision 1.1  2021/08/28 02:47:25  rafael.jesus
 * Initial revision
 *
 */

#ifdef __linux__
#define _XOPEN_SOURCE 600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __ISO_C_VISIBLE         1999
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0504.h"

#define OK																	0
#define NUMERO_ARGUMENTOS_INVALIDO					1
#define ERRO_FUNCAO_GERAR_CPF								2

#define NUMERO_ARGUMENTOS										12

int
main (int argc, char *argv [])
{
	char cpf[11];
	short unsigned indice,len=0,valor=0,i=0;
	char* verificacao;
	tipoErros codigoRetorno;

	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Uso: %s <11 digitos do CPF>\n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);    
  }
 
	for (indice = 1; indice < argc; indice++)
	{
		valor = strtoul (argv[indice],&verificacao,10);
		cpf[i] = (unsigned char) (valor + '0');
		len += 1;
		i += 1;
	}

	if ((len) != 11)
	{
		printf ("Uso: %s <11 digitos do CPF>\n", argv [0]);
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
  codigoRetorno = ValidarCpf (cpf);

	cpf[14] = '\0';
	cpf[13] = cpf[10];
	cpf[12] = cpf[9];
	cpf[11] = '/';
	cpf[10] = cpf[8];
	cpf[9] = cpf[7];
	cpf[8] = cpf[6];
	cpf[7] = '.';
	cpf[6] = cpf[5];
	cpf[5] = cpf[4];
	cpf[4] = cpf[3];		
	cpf[3]= '.';

  if (codigoRetorno != ok)
  {
	  printf ("CPF: %s - invalido. \n", cpf);
		exit (ERRO_FUNCAO_GERAR_CPF);
  }
	
  printf ("CPF: %s - valido. \n", cpf);
	return OK;
}

/* $RCSfile: aula0506a.c,v $ */
