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
 * $Date: 2021/09/21 03:31:22 $
 * $Log: aula0701.c,v $
 * Revision 1.6  2021/09/21 03:31:22  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Incremento da funcao PreencherPoligono.
 *
 * Revision 1.5  2021/09/20 05:33:41  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao da funcao DesenharPoligono.
 *
 * Revision 1.4  2021/09/19 22:44:29  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao da funcao DesenharReta.
 *
 * Revision 1.3  2021/09/18 20:55:52  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao do cabecalho e das funcoes com o intento de rodar no Linux.
 *
 * Revision 1.2  2021/09/18 08:01:52  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao da funcao LimparMonitor.
 *
 * Revision 1.1  2021/09/18 00:16:47  rafael.jesus
 * Initial revision
 *
 */

#define LIMPAR "clear"
#include "aula0701.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>


tipoErros
MostrarMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS], 
								unsigned numeroMaximoLinhas, 
								unsigned numeroMaximoColunas, 
								useconds_t tempoEspera){

	unsigned short linha, coluna;


	/* TRATAMENTO DE EXCECAO */

	if (monitor == NULL)
		return matrizNula;
	
	if (numeroMaximoLinhas == 0 || numeroMaximoColunas == 0)
		return dimensaoInvalida;
	
	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
		return dimensaoInvalida;

	if (numeroMaximoLinhas < 1 || numeroMaximoColunas < 1)
		return dimensaoInvalida;


	/* MOSTRAR MONITOR */

	system(LIMPAR);	

	printf ("\n");
	for (linha = 0; linha < numeroMaximoLinhas; linha++) {
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++) {

			if (monitor[linha][coluna] != apagado &&\
					monitor[linha][coluna] != aceso &&\
					monitor[linha][coluna] != defeituoso)
				return caractereInvalido;

			printf (monitor[linha][coluna] == apagado ? "-" :\
							monitor[linha][coluna] == aceso ? "+" : "X");
		}
		printf ("\n");
	}

	usleep(tempoEspera);	

	return ok;
}


tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
								unsigned numeroMaximoLinhas,
								unsigned numeroMaximoColunas){

	unsigned short linha, coluna;

	/* TRATAMENTO DE EXCECAO */

	if (monitor == NULL)
		return matrizNula;
	
	if (numeroMaximoLinhas == 0 || numeroMaximoColunas == 0)
		return dimensaoInvalida;
	
	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
		return dimensaoInvalida;

	if (numeroMaximoLinhas < 1 || numeroMaximoColunas < 1)
		return dimensaoInvalida;

	
	/* LIMPANDO MONITOR */

	for (linha = 0; linha < numeroMaximoLinhas; linha++) {
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++) {

			if (monitor[linha][coluna] != apagado &&\
					monitor[linha][coluna] != aceso &&\
					monitor[linha][coluna] != defeituoso)
				return caractereInvalido;

			else if (monitor [linha][coluna] == aceso || monitor [linha][coluna] == apagado)
				monitor [linha][coluna] = apagado;

			else if (monitor [linha][coluna] == defeituoso)
				monitor [linha][coluna] = defeituoso;
		}
	}
	return ok;
}


tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
							unsigned numeroMaximoLinhas,
							unsigned numeroMaximoColunas,
							unsigned linhaA, unsigned colunaA,
							unsigned linhaB, unsigned colunaB){

	int linha, coluna, valorTemporario;
	double deltaLinha, deltaColuna, inclinacao, parametro;


	/* TRATAMENTO DE EXCECAO */

	if (monitor == NULL)
		return matrizNula;
	
	if (numeroMaximoLinhas == 0 || numeroMaximoColunas == 0)
		return dimensaoInvalida;
	
	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
		return dimensaoInvalida;

	if (numeroMaximoLinhas < 1 || numeroMaximoColunas < 1)
		return dimensaoInvalida;

	if (linhaA > numeroMaximoLinhas || linhaB > numeroMaximoLinhas)
		return linhaInvalida;

	if (colunaA > numeroMaximoColunas || colunaB > numeroMaximoColunas)
		return colunaInvalida;

	if (linhaA == 0 || colunaA == 0 || linhaB == 0 || colunaB == 0)
		return dimensaoInvalida;


	/* SUBTRAINDO AS LINHAS E COLUNAS PARA USAR COMO INDICE */

	linhaA -= 1;
	linhaB -= 1;
	colunaA -= 1;
	colunaB -= 1;


	/* DESENHANDO RETA */

	if (linhaA == linhaB && colunaA == colunaB) {
		monitor[linhaA][colunaA] = aceso;
		return ok;
	} /* 1 PIXEL */


	if ((linhaB - linhaA) == 0) {
		inclinacao = (colunaB - colunaA);
	}
	else {
		if (linhaB < linhaA && colunaB > colunaA)
			inclinacao = (int) -((colunaB - colunaA) / (linhaA - linhaB));
		else if (linhaB > linhaA && colunaB < colunaA)
			inclinacao = (int) -((colunaA - colunaB) / (linhaB - linhaA));
		else if (linhaB < linhaA && colunaB < colunaA)
			inclinacao = (int) ((colunaA - colunaB) / (linhaA - linhaB));
		else
			inclinacao = (int) ((colunaB - colunaA) / (linhaB - linhaA));
	}

	if (fabs(inclinacao) < 1)
	{
		if (linhaA > linhaB)
		{
			valorTemporario = linhaA;
			linhaA = linhaB;
			linhaB = valorTemporario;

			valorTemporario = colunaA;
			colunaA = colunaB;
			colunaB = valorTemporario;
		}


		deltaLinha = (float) (linhaB < linhaA ? linhaA - linhaB : linhaB - linhaA);
		deltaColuna = (float) (colunaB < colunaA ? colunaA - colunaB : colunaB - colunaA);

		parametro = (float) (2 * deltaColuna - deltaLinha);

		linha = linhaA;
		coluna = colunaA;

		while (linha <= linhaB)
		{
			if (monitor[linha][coluna] == defeituoso)
				return pixelInvalido;
			else
				monitor[linha][coluna] = aceso;
			linha += 1;
		
			if (parametro >= 0)
			{
				if (inclinacao < 1)
					coluna += 1;
				else
					coluna -= 1;
				parametro += 2 * deltaColuna - 2 * deltaLinha;
			}
			else
				parametro += 2 * deltaColuna;
		}
	}


	if (fabs(inclinacao) >= 1)
	{
		if (colunaA > colunaB)
		{
			valorTemporario = linhaA;
			linhaA = linhaB;
			linhaB = valorTemporario;

			valorTemporario = colunaA;
			colunaA = colunaB;
			colunaB = valorTemporario;
		}
		
		deltaLinha = (float) (linhaB < linhaA ? linhaA - linhaB : linhaB - linhaA);
		deltaColuna = (float) (colunaB < colunaA ? colunaA - colunaB : colunaB - colunaA);

		parametro = 2 * deltaLinha - deltaColuna;

		linha = linhaA;
		coluna = colunaA;

		while (coluna <= colunaB)
		{
			if (monitor[linha][coluna] == defeituoso)
				return pixelInvalido;
			else
				monitor[linha][coluna] = aceso;

			coluna += 1;
		
			if (parametro >= 0)
			{
				if (inclinacao >= 1)
					linha += 1;
				else
					linha -= 1;
				parametro += 2 * deltaLinha - 2 * deltaColuna;
			}
			else
				parametro += 2 * deltaLinha;
		}
	}

	
	return ok;
}


tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
									unsigned numeroMaximoLinhas,
									unsigned numeroMaximoColunas,
									unsigned numeroVertices,
									unsigned linhasVertices [NUMERO_MAXIMO_LINHAS],
									unsigned colunasVertices [NUMERO_MAXIMO_COLUNAS]) {

	unsigned indice, linhaA, colunaA, linhaB, colunaB;
	tipoErros codigoRetorno;

	/* TRATAMENTO DE EXCECAO */

	if (monitor == NULL)
		return matrizNula;
	
	if (numeroMaximoLinhas == 0 || numeroMaximoColunas == 0)
		return dimensaoInvalida;
	
	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
		return dimensaoInvalida;

	if (numeroMaximoLinhas < 1 || numeroMaximoColunas < 1)
		return dimensaoInvalida;

	/* DESENHANDO POLIGONO*/

	for (indice = 0; indice < numeroVertices; indice++) {
		linhaA = linhasVertices[indice];
		colunaA = colunasVertices[indice];

		if (indice + 1 == numeroVertices){
			linhaB = linhasVertices[0];
			colunaB = colunasVertices[0];
		}
		else {
			linhaB = linhasVertices[indice + 1];
			colunaB = colunasVertices[indice + 1];
		}

		codigoRetorno = DesenharReta (monitor, numeroMaximoLinhas, numeroMaximoColunas, linhaA, colunaA, linhaB, colunaB);
		
		if (codigoRetorno != ok)
			return pixelInvalido;
	}

	return ok;
}


tipoErros
PreencherPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
										unsigned numeroMaximoLinhas,
										unsigned numeroMaximoColunas,
										unsigned linha, unsigned coluna,
										useconds_t tempoEspera) {

	tipoErros codigoRetorno;

	/* TRATAMENTO DE EXCECAO */

	if (monitor == NULL)
		return matrizNula;
	
	if (numeroMaximoLinhas == 0 || numeroMaximoColunas == 0)
		return dimensaoInvalida;
	
	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
		return dimensaoInvalida;

	if (numeroMaximoLinhas < 1 || numeroMaximoColunas < 1)
		return dimensaoInvalida;

	if (linha > numeroMaximoLinhas)
		return linhaInvalida;

	if (coluna > numeroMaximoColunas)
		return colunaInvalida;


	/* PREENCHENDO POLIGONO */

	if (linha < 1 || linha > numeroMaximoLinhas)
		return ok;
	
	if (coluna < 1 || coluna > numeroMaximoColunas)
		return ok;
	
	if (monitor [linha - 1][coluna - 1] == aceso)
		return ok;

	if (monitor [linha - 1][coluna - 1] == defeituoso)
		return pixelInvalido;

	if (monitor [linha - 1][coluna - 1] == apagado) 
	{
		monitor [linha - 1][coluna - 1] = aceso;

		codigoRetorno = PreencherPoligono (monitor, numeroMaximoLinhas, numeroMaximoColunas, linha, coluna - 1, tempoEspera);
		if (codigoRetorno == pixelInvalido)
			return pixelInvalido;

		codigoRetorno = PreencherPoligono (monitor, numeroMaximoLinhas, numeroMaximoColunas, linha, coluna + 1, tempoEspera);
		if (codigoRetorno == pixelInvalido)
			return pixelInvalido;

		codigoRetorno = PreencherPoligono (monitor, numeroMaximoLinhas, numeroMaximoColunas, linha - 1, coluna, tempoEspera);
		if (codigoRetorno == pixelInvalido)
			return pixelInvalido;

		codigoRetorno = PreencherPoligono (monitor, numeroMaximoLinhas, numeroMaximoColunas, linha + 1, coluna, tempoEspera);
		if (codigoRetorno == pixelInvalido)
			return pixelInvalido;
	}


	return ok;
}


/* $RCSfile: aula0701.c,v $ */
