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
 * $Date: 2021/09/08 19:43:49 $
 * $Log: aula0605.c,v $
 * Revision 1.1  2021/09/08 19:43:49  rafael.jesus
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
#define ERRO_FUNCAO_CALCULAR_MENOR_COMPLEMENTAR				3


int
main (int argc, char *argv [])
{
	unsigned short ordem, xLinha, xColuna;
	double matriz[MAX_LINHAS][MAX_COLUNAS], resultado;
	double *determinante;
	short unsigned linha, coluna, indice, nArgumentos = 0;
	char* verificacao;
	tipoErros codigoRetorno;

	resultado = 0;
	determinante = &resultado;
 
	ordem = strtoul (argv[1],&verificacao,10);
	xLinha = strtoul (argv[2],&verificacao,10);
	xColuna = strtoul (argv[3],&verificacao,10);

	if (xLinha < 1){
		printf ("Uso: %s <Valor da linha eh menor que o numero de linhas.> \n", argv [0]);
    exit (ARGUMENTO_INVALIDO);    
  }
	
	if (xLinha > ordem){
		printf ("Uso: %s <Valor da linha ultrapassa o numero de linhas.> \n", argv [0]);
    exit (ARGUMENTO_INVALIDO);    
  }

	if (xColuna < 1){
		printf ("Uso: %s <Valor da coluna eh menor que o numero de colunas.> \n", argv [0]);
    exit (ARGUMENTO_INVALIDO);    
  }

	if (xColuna > ordem){
		printf ("Uso: %s <Valor da coluna ultrapassa o numero de colunas.> \n", argv [0]);
    exit (ARGUMENTO_INVALIDO);    
  }

	nArgumentos = 4 + (ordem * ordem);

	if (argc != nArgumentos)
	{
		printf ("Uso: %s <Ordem, linha e coluna do Menor Complementar, e cada elemento da matriz.> \n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);    
  }
 

	indice = 4;
	for (linha = 0; linha < ordem; linha++) {
		for (coluna = 0; coluna < ordem; coluna++) {
			matriz[linha][coluna] = strtod (argv[indice], &verificacao);
			indice++;
		}
	}
 
  codigoRetorno = CalcularMenorComplementar(ordem, xLinha-1, xColuna-1, matriz, determinante);

  if (codigoRetorno != ok)
  {
    printf ("Funcao CalcularMenorDeterminante retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_CALCULAR_MENOR_COMPLEMENTAR);
  }


	printf ("\nMatriz Original: \n");
	for (linha = 0; linha < ordem; linha++) {
		for (coluna = 0; coluna < ordem; coluna++) {
			printf ("%lf ", matriz[linha][coluna]);
		}
		printf ("\n");
	}

	printf ("\nD%d%d: %lf \n\n", xLinha, xColuna, *determinante);

	return OK;
}

/* $RCSfile: aula0605.c,v $ */
