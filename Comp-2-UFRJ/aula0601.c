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
 * $Date: 2021/09/08 19:43:49 $
 * $Log: aula0601.c,v $
 * Revision 1.4  2021/09/08 19:43:49  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcoes referente a funcao CalcularMenorComplementar.
 *
 * Revision 1.3  2021/09/08 18:21:58  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Implementacao das funcoes CalcularMenorComplementar, CalcularComplementoAlgebrico e CalcularDeterminanteMatriz.
 *
 * Revision 1.2  2021/09/01 14:05:27  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao da funcao ObterMatrizTransposta.
 *
 * Revision 1.1  2021/09/01 01:58:25  rafael.jesus
 * Initial revision
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "aula0601.h"


tipoErros
MultiplicarMatrizes (unsigned short nLinhasM1,
											unsigned short nColunasM1,
                      unsigned short nLinhasM2,
                      unsigned short nColunasM2,
                      double Matriz1[MAX_LINHAS][MAX_COLUNAS],
                      double Matriz2[MAX_LINHAS][MAX_COLUNAS],
                      double MatrizProduto[MAX_LINHAS][MAX_COLUNAS])
{
	unsigned short linhaA, colunaA, colunaB;

	if (nColunasM1 != nLinhasM2)
		return argumentoInvalido;

	for (linhaA = 0; linhaA < nLinhasM1; linhaA++) {
		for (colunaB = 0; colunaB < nColunasM2; colunaB++) {
			MatrizProduto[linhaA][colunaB] = 0;
			for (colunaA = 0; colunaA < nColunasM1; colunaA++) {
				MatrizProduto[linhaA][colunaB] += Matriz1[linhaA][colunaA] * Matriz2[colunaA][colunaB];
			}
		}
	}

	return ok;
}


tipoErros
ObterMatrizTransposta (unsigned short nLinhas,
                        unsigned short nColunas,
                        double Matriz[MAX_LINHAS][MAX_COLUNAS],
                        double MatrizTransposta[MAX_LINHAS][MAX_COLUNAS])
{
	unsigned short linha, coluna;
	
	for (linha = 0; linha < nLinhas; linha++) {
		for (coluna = 0; coluna < nColunas; coluna++) {
			MatrizTransposta[coluna][linha] = Matriz[linha][coluna]; 
		}
	}

	return ok;
}


tipoErros
CalcularDeterminanteMatriz (unsigned short ordem,
                            double Matriz[MAX_LINHAS][MAX_COLUNAS],
                            double *determinante)
{
	unsigned short linha, coluna;
	double *cofator;
	double resultado;

	resultado = 0;
	cofator = &resultado;

	if (ordem == 1) {
		determinante[0] = Matriz[0][0];
		return ok;
	}


	if (ordem == 2) {
		determinante[0] = (Matriz[0][0] * Matriz[1][1]) - (Matriz[0][1] * Matriz[1][0]);
		return ok;
	}


	if (ordem == 3) {
		determinante[0] = ((Matriz[0][0] * Matriz[1][1] * Matriz[2][2]) +\
											(Matriz[0][1] * Matriz[1][2] * Matriz[2][0]) +\
											(Matriz[0][2] * Matriz[1][0] * Matriz[2][1]) -\
											((Matriz[2][0] * Matriz[1][1] * Matriz[0][2]) +\
											(Matriz[2][1] * Matriz[1][2] * Matriz[0][0]) +\
											(Matriz[2][2] * Matriz[1][0] * Matriz[0][1])));
		return ok;
	}


	if (ordem > 3)	
	{
		linha = ordem - 1;
		for (coluna = 0 ; coluna < ordem; coluna++){
			CalcularComplementoAlgebrico(ordem, linha, coluna, Matriz, cofator);
			determinante[0] += cofator[0] * Matriz[linha][coluna];		
		}
		return ok;
	}	

	return argumentoInvalido;
}


tipoErros
CalcularComplementoAlgebrico (unsigned short ordem,
															unsigned short linha,
                              unsigned short coluna,
															double Matriz[MAX_LINHAS][MAX_COLUNAS],
                              double *cofator)
{
	double *menorComplementar;
	double resultado;

	resultado = 0;
	menorComplementar = &resultado;

	CalcularMenorComplementar(ordem, linha, coluna, Matriz, menorComplementar);

	if ((linha + coluna) % 2 != 0)
		cofator[0] = -(menorComplementar[0]);
	else
		cofator[0] = (menorComplementar[0]);
	
	return ok;
}


tipoErros
CalcularMenorComplementar (unsigned short ordem,
													unsigned short linha,
                          unsigned short coluna,
                          double Matriz[MAX_LINHAS][MAX_COLUNAS],
                          double *menorComplementar)
{
	double temp[MAX_LINHAS][MAX_COLUNAS], resultado;
	double *determinante;
	unsigned short linhaTemp, colunaTemp, linhaMatriz, colunaMatriz;

	resultado = 0;
	determinante = &resultado;

	for (linhaTemp = linhaMatriz = 0; linhaTemp < ordem - 1; linhaTemp++){
		if (linhaTemp == linha)
			linhaMatriz += 1;

		for (colunaTemp = colunaMatriz = 0; colunaTemp < ordem - 1; colunaTemp++){
			if (colunaTemp == coluna)
				colunaMatriz += 1;

			temp[linhaTemp][colunaTemp] = Matriz[linhaMatriz][colunaMatriz];
			colunaMatriz += 1;
		}
		linhaMatriz += 1;
	}

	CalcularDeterminanteMatriz (ordem-1, temp, determinante); 
	menorComplementar[0] += determinante[0];

	return ok;
}


/* $RCSfile: aula0601.c,v $ */
