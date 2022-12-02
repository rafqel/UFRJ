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
 * $Date: 2021/09/08 20:29:29 $
 * $Log: aula0604.c,v $
 * Revision 1.2  2021/09/08 20:29:29  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao de variaveis.
 *
 * Revision 1.1  2021/09/08 18:25:47  rafael.jesus
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

#include "aula0601.h"

#define OK																						0
#define ARGUMENTO_INVALIDO														1
#define NUMERO_ARGUMENTOS_INVALIDO										2
#define ERRO_FUNCAO_CALCULAR_DETERMINANTE_MATRIZ			3


int
main (int argc, char *argv [])
{
	unsigned short ordem;
	double Matriz[MAX_LINHAS][MAX_COLUNAS];
	double *determinante;
	short unsigned linha, coluna, indice, nArgumentos = 0;
	char* verificacao;
	tipoErros codigoRetorno;

	ordem = strtoul (argv[1],&verificacao,10);

	nArgumentos = 2 + (ordem * ordem);

	if (argc != nArgumentos)
	{
		printf ("Uso: %s <Dimensoes e valor de cada elemento da matriz> \n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);    
  }
 

	indice = 2;
	for (linha = 0; linha < ordem; linha++) {
		for (coluna = 0; coluna < ordem; coluna++) {
			Matriz[linha][coluna] = strtod (argv[indice], &verificacao);
			indice++;
		}
	}

	double resultado;
	resultado = 0;
	determinante = &resultado;
 
  codigoRetorno = CalcularDeterminanteMatriz(ordem, Matriz, determinante);

  if (codigoRetorno != ok)
  {
    printf ("Funcao CalcularDeterminanteMatriz retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_CALCULAR_DETERMINANTE_MATRIZ);
  }


	printf ("\nMatriz Original: \n");
	for (linha = 0; linha < ordem; linha++) {
		for (coluna = 0; coluna < ordem; coluna++) {
			printf ("%lf ", Matriz[linha][coluna]);
		}
		printf ("\n");
	}

	printf ("\nDeterminante: %lf \n", *determinante);

	return OK;
}

/* $RCSfile: aula0604.c,v $ */
