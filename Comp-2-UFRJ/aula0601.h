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
 * $Date: 2021/09/08 18:21:58 $
 * $Log: aula0601.h,v $
 * Revision 1.3  2021/09/08 18:21:58  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Implementacao das funcoes CalcularMenorComplementar, CalcularComplementoAlgebrico e CalcularDeterminanteMatriz.
 *
 * Revision 1.2  2021/09/01 14:05:27  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao do prototipo da funcao ObterMatrizTransposta.
 *
 * Revision 1.1  2021/09/01 01:58:25  rafael.jesus
 * Initial revision
 *
 */

#ifndef _AULA0601_
#define _AULA0601_							"@(#)aula0601.h $Revision: 1.3 $"

#define MAX_LINHAS							100
#define MAX_COLUNAS							100

typedef enum
{
	ok,
	argumentoInvalido,
	comprimentoArgumentoInvalido,
	caractereInvalido
} tipoErros;


tipoErros
MultiplicarMatrizes (unsigned short, /* numero de linhas da matriz 1 (E) */
											unsigned short, /* numero de colunas da matriz 1 (E) */
                      unsigned short, /* numero de linhas da matriz 2 (E) */
                      unsigned short, /* numero de colunas da matriz 2 (E) */
                      double [MAX_LINHAS][MAX_COLUNAS], /* matriz 1 (E) */
                      double [MAX_LINHAS][MAX_COLUNAS], /* matriz 2 (E) */
                      double [MAX_LINHAS][MAX_COLUNAS]); /* matriz produto (S) */


tipoErros
ObterMatrizTransposta (unsigned short, /* numero de linhas da matriz original (E) */
                        unsigned short, /* numero de colunas da matriz original (E) */
                        double [MAX_LINHAS][MAX_COLUNAS], /* matriz original (E) */
                        double [MAX_LINHAS][MAX_COLUNAS]); /* matriz transposta (S) */ 


tipoErros
CalcularMenorComplementar (unsigned short, /* ordem da matriz (E) */
														unsigned short, /* linha do elemento (E) */
                            unsigned short, /* coluna do elemento (E) */
                            double [MAX_LINHAS][MAX_COLUNAS], /* matriz (E) */
                            double *); /* menor complementar (S) */


tipoErros
CalcularComplementoAlgebrico (unsigned short, /* ordem da matriz (E) */
                              unsigned short, /* linha do elemento (E) */
                              unsigned short, /* coluna do elemento (E) */
                              double [MAX_LINHAS][MAX_COLUNAS], /* matriz (E) */
                              double *); /* complemento algebrico ou cofator (S) */


tipoErros
CalcularDeterminanteMatriz (unsigned short, /* ordem da matriz (E) */
                            double [MAX_LINHAS][MAX_COLUNAS], /* matriz (E) */
                            double *); /* determinante (S) */ 


#endif

/* $RCSfile: aula0601.h,v $ */
