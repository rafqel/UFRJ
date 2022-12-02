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
 * $Log: aula0602.c,v $
 * Revision 1.4  2021/09/08 20:29:29  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao de variaveis.
 *
 * Revision 1.3  2021/09/03 16:11:47  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Substituicao do especificador %g por %lf.
 *
 * Revision 1.2  2021/09/02 13:29:59  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Substituicao do strtoul por strtod.
 *
 * Revision 1.1  2021/09/01 01:58:25  rafael.jesus
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

#define OK																			0
#define ARGUMENTO_INVALIDO											1
#define NUMERO_ARGUMENTOS_INVALIDO							2
#define ERRO_FUNCAO_MULTIPLICAR_MATRIZES				3


int
main (int argc, char *argv [])
{
	unsigned short nLinhasM1, nColunasM1, nLinhasM2, nColunasM2, nLinhasMp, nColunasMp;
	double Matriz1[MAX_LINHAS][MAX_COLUNAS], Matriz2[MAX_LINHAS][MAX_COLUNAS];
	double MatrizProduto[MAX_LINHAS][MAX_COLUNAS];
	short unsigned linha, coluna, indice, nArgumentos = 0;
	char* verificacao;
	tipoErros codigoRetorno;

	nLinhasM1 = strtoul (argv[1],&verificacao,10);
	nColunasM1 = strtoul (argv[2],&verificacao,10);
	nLinhasM2 = strtoul (argv[3],&verificacao,10);
	nColunasM2 = strtoul (argv[4],&verificacao,10);
 
	nArgumentos = 5 + (nLinhasM1 * nColunasM1) + (nLinhasM2 * nColunasM2);

	if (argc != nArgumentos)
	{
		printf ("Uso: %s <Dimensoes das matrizes e os valores de cada elemento das matrizes de entrada> \n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);    
  }
 

	indice = 5;
	for (linha = 0; linha < nLinhasM1; linha++) {
		for (coluna = 0; coluna < nColunasM1; coluna++) {
			Matriz1[linha][coluna] = strtod (argv[indice], &verificacao);
			indice++;
		}
	}

	for (linha = 0; linha < nLinhasM2; linha++) {
		for (coluna = 0; coluna < nColunasM2; coluna++) {
			Matriz2[linha][coluna] = strtod (argv[indice], &verificacao);
			indice++;
		}
	}


  codigoRetorno = MultiplicarMatrizes(nLinhasM1, nColunasM1, nLinhasM2, nColunasM2, Matriz1, Matriz2, MatrizProduto);

  if (codigoRetorno != ok)
  {
    printf ("Funcao MultiplicarMatrizes retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_MULTIPLICAR_MATRIZES);
  }


	printf ("\nMatriz 1: \n");
	for (linha = 0; linha < nLinhasM1; linha++) {
		for (coluna = 0; coluna < nColunasM1; coluna++) {
			printf ("%lf ", Matriz1[linha][coluna]);
		}
		printf ("\n");
	}


	printf ("\nMatriz 2: \n");
	for (linha = 0; linha < nLinhasM2; linha++) {
		for (coluna = 0; coluna < nColunasM2; coluna++) {
			printf ("%lf ", Matriz2[linha][coluna]);
		}
		printf ("\n");
	}


	nLinhasMp = nLinhasM1;
	nColunasMp = nColunasM2;

	printf ("\nMatriz Produto: \n");
	for (linha = 0; linha < nLinhasMp; linha++) {
		for (coluna = 0; coluna < nColunasMp; coluna++) {
			printf ("%lf ", MatrizProduto[linha][coluna]);
		}
		printf ("\n");
	}
	printf ("\n");	

	return OK;
}

/* $RCSfile: aula0602.c,v $ */
