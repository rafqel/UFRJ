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
 * $Log: aula0603.c,v $
 * Revision 1.4  2021/09/08 20:29:29  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao de variaveis.
 *
 * Revision 1.3  2021/09/03 16:11:47  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1
 * Substituicao do especificador %g por %lf.
 *
 * Revision 1.2  2021/09/02 13:29:59  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Substituicao do strtoul por strtod.
 *
 * Revision 1.1  2021/09/01 14:05:27  rafael.jesus
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
#define ERRO_FUNCAO_OBTER_MATRIZES_TRANSPOSTA					3


int
main (int argc, char *argv [])
{
	unsigned short nLinhas, nColunas, nLinhasMT, nColunasMT;
	double Matriz[MAX_LINHAS][MAX_COLUNAS], MatrizTransposta[MAX_LINHAS][MAX_COLUNAS];
	short unsigned linha, coluna, indice, nArgumentos = 0;
	char* verificacao;
	tipoErros codigoRetorno;

	nLinhas = strtoul (argv[1],&verificacao,10);
	nColunas = strtoul (argv[2],&verificacao,10);
 
	nArgumentos = 3 + (nLinhas * nColunas);

	if (argc != nArgumentos)
	{
		printf ("Uso: %s <Dimensoes e valor de cada elemento da matriz> \n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);    
  }
 

	indice = 3;
	for (linha = 0; linha < nLinhas; linha++) {
		for (coluna = 0; coluna < nColunas; coluna++) {
			Matriz[linha][coluna] = strtod (argv[indice], &verificacao);
			indice++;
		}
	}


  codigoRetorno = ObterMatrizTransposta(nLinhas, nColunas, Matriz, MatrizTransposta);

  if (codigoRetorno != ok)
  {
    printf ("Funcao ObterMatrizTransposta retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_OBTER_MATRIZES_TRANSPOSTA);
  }


	printf ("\nMatriz Original: \n");
	for (linha = 0; linha < nLinhas; linha++) {
		for (coluna = 0; coluna < nColunas; coluna++) {
			printf ("%lf ", Matriz[linha][coluna]);
		}
		printf ("\n");
	}


	nLinhasMT = nColunas;
	nColunasMT = nLinhas;

	printf ("\nMatriz Transposta: \n");
	for (linha = 0; linha < nLinhasMT; linha++) {
		for (coluna = 0; coluna < nColunasMT; coluna++) {
			printf ("%lf ", MatrizTransposta[linha][coluna]);
		}
		printf ("\n");
	}
	printf ("\n");	

	return OK;
}

/* $RCSfile: aula0603.c,v $ */
