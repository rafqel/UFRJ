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
 * $Date: 2021/09/20 05:33:41 $
 * $Log: aula0705.c,v $
 * Revision 1.1  2021/09/20 05:33:41  rafael.jesus
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

#include "aula0701.h"

#define OK																			0
#define ARGUMENTO_INVALIDO											1
#define NUMERO_ARGUMENTOS_INVALIDO							2
#define ERRO_FUNCAO_MOSTRAR_MONITOR							3
#define ERRO_FUNCAO_DESENHAR_POLIGONO						4
#define END_OF_STRING														'\0'

int
main (int argc, char *argv [])
{
	tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
	unsigned numeroVertices, numeroMaximoLinhas, numeroMaximoColunas;
	unsigned nArgumentos, indice, indiceAuxiliar, linha, coluna, numeroAleatorio;
	unsigned linhasVertices[NUMERO_MAXIMO_LINHAS], colunasVertices[NUMERO_MAXIMO_COLUNAS];
	useconds_t tempoEspera;
	char* verificacao;
	tipoErros codigoRetorno;


	/* TRATAMENTO DE EXCECAO */

	nArgumentos = 5 + (2 * strtoul (argv[4], &verificacao, 10));

	if (argc != nArgumentos)
	{
		printf ("Erro: Numero de argumentos invalido. \n");
		printf ("Uso: %s <Insira o numero de linhas e colunas do monitor, o tempo de congelamento, o numero de vertices e as coordenadas de cada vertice (linha e coluna)> \n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);    
  }

	for (indice = 1; indice < argc ; indice++) {
		if (argv[indice][0] == '-')
		{
			printf ("Erro: Caractere invalido: '-' \n");
			printf ("Uso: <Numero nao negativo> \n");
			exit (ARGUMENTO_INVALIDO);
		}
	}


	/* OBTENDO VALORES */

 	numeroMaximoLinhas = strtoul (argv[1],&verificacao,10);
	numeroMaximoColunas = strtoul (argv[2],&verificacao,10);
	tempoEspera = strtoul (argv[3],&verificacao,10);
	numeroVertices = strtoul (argv[4],&verificacao,10);
	

	/* TRATAMENTO DE EXCECAO */

	if (numeroMaximoLinhas > NUMERO_MAXIMO_LINHAS || numeroMaximoColunas > NUMERO_MAXIMO_COLUNAS)
	{
		printf ("Erro: Numero de linhas/colunas ultrapassa o limite permitido. \n");
		printf ("Uso: %s <Numero maximo de linhas e colunas respectivamente: 250 e 800> \n", argv [0]);
		exit (ARGUMENTO_INVALIDO);
	}

	if (numeroMaximoLinhas == 0 || numeroMaximoColunas == 0)
	{
		printf ("Erro: Numero de linhas/colunas eh nulo \n");
		exit (ARGUMENTO_INVALIDO);
	}

	if (*verificacao != END_OF_STRING)
	{
		printf ("\nArgumento contem caractere invalido.\n");
		exit (ARGUMENTO_INVALIDO);
	}


	/* OBTENDO VALORES */

	indiceAuxiliar = 0;
	for (indice = 5 ; indice < nArgumentos ; indice += 2)
	{
		linhasVertices[indiceAuxiliar] = (strtoul (argv[indice], &verificacao, 10));
		indiceAuxiliar += 1;
	}

	indiceAuxiliar = 0;
	for (indice = 6 ; indice < nArgumentos ; indice += 2)
	{
		colunasVertices[indiceAuxiliar] = (strtoul (argv[indice], &verificacao, 10));
		indiceAuxiliar += 1;
	}



	/* TESTE 1 - TODOS PIXELS APAGADOS */

	for (linha = 0; linha < numeroMaximoLinhas; linha++) {
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++) {
			monitor[linha][coluna] = apagado;
		}
	}
	
  codigoRetorno = MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);

  if (codigoRetorno != ok)
  {
    printf ("Funcao MostrarMonitor retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_MOSTRAR_MONITOR);
  }

  codigoRetorno = DesenharPoligono(monitor, numeroMaximoLinhas, numeroMaximoColunas, numeroVertices, linhasVertices, colunasVertices);

  if (codigoRetorno != ok)
  {
		if (codigoRetorno == pixelInvalido) {
			printf ("Erro: Pixel defeituoso, nao foi possivel completar o desenho. \n");
			exit (ERRO_FUNCAO_DESENHAR_POLIGONO);
		}
		else {
			printf ("Funcao DesenharPoligono retornou o erro: %i\n", codigoRetorno);
			exit (ERRO_FUNCAO_DESENHAR_POLIGONO);
		}
  }

  codigoRetorno = MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);

  if (codigoRetorno != ok)
  {
    printf ("Funcao MostrarMonitor retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_MOSTRAR_MONITOR);
  }


	/* TESTE 2 - TODOS PIXELS ACESOS */
/*
	for (linha = 0; linha < numeroMaximoLinhas; linha++) {
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++) {
			monitor[linha][coluna] = aceso;
		}
	}
	
  codigoRetorno = MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);

  if (codigoRetorno != ok)
  {
    printf ("Funcao MostrarMonitor retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_MOSTRAR_MONITOR);
  }

  codigoRetorno = DesenharPoligono(monitor, numeroMaximoLinhas, numeroMaximoColunas, numeroVertices, linhasVertices, colunasVertices);

  if (codigoRetorno != ok)
  {
		if (codigoRetorno == pixelInvalido) {
			printf ("Erro: Pixel defeituoso, nao foi possivel completar o desenho. \n");
			exit (ERRO_FUNCAO_DESENHAR_POLIGONO);
		}
		else {
			printf ("Funcao DesenharPoligono retornou o erro: %i\n", codigoRetorno);
			exit (ERRO_FUNCAO_DESENHAR_POLIGONO);
		}  
	}

  codigoRetorno = MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);

  if (codigoRetorno != ok)
  {
    printf ("Funcao MostrarMonitor retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_MOSTRAR_MONITOR);
  }
*/


	/* TESTE 3 - TODOS PIXELS COM DEFEITO */
/*
	for (linha = 0; linha < numeroMaximoLinhas; linha++) {
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++) {
			monitor[linha][coluna] = defeituoso;
		}
	}
	
  codigoRetorno = MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);

  if (codigoRetorno != ok)
  {
    printf ("Funcao MostrarMonitor retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_MOSTRAR_MONITOR);
  }

  codigoRetorno = DesenharPoligono(monitor, numeroMaximoLinhas, numeroMaximoColunas, numeroVertices, linhasVertices, colunasVertices);

  if (codigoRetorno != ok)
  {
		if (codigoRetorno == pixelInvalido) {
			printf ("Erro: Pixel defeituoso, nao foi possivel completar o desenho. \n");
			exit (ERRO_FUNCAO_DESENHAR_POLIGONO);
		}
		else {
			printf ("Funcao DesenharPoligono retornou o erro: %i\n", codigoRetorno);
			exit (ERRO_FUNCAO_DESENHAR_POLIGONO);
		}
	}

  codigoRetorno = MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);

  if (codigoRetorno != ok)
  {
    printf ("Funcao MostrarMonitor retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_MOSTRAR_MONITOR);
  }
*/


	/* TESTE 4 - PIXELS APAGADOS, ACESOS E COM DEFEITO */

	/*
		PORCENTAGEM:
			Defeituoso = 1%
			Aceso = 49%
			Apagado = 50%
	*/

	srand ((unsigned) time(NULL));
	for (linha = 0; linha < numeroMaximoLinhas; linha++) {
		for (coluna = 0; coluna < numeroMaximoColunas; coluna++) {
			numeroAleatorio = rand()%100;
			if (numeroAleatorio <= 1)
				monitor [linha][coluna] = defeituoso;
			else if (numeroAleatorio > 1 && numeroAleatorio <= 50)
				monitor [linha][coluna] = aceso;
			else
				monitor [linha][coluna] = apagado;
		}
	}
	
  codigoRetorno = MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);

  if (codigoRetorno != ok)
  {
    printf ("Funcao MostrarMonitor retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_MOSTRAR_MONITOR);
  }

  codigoRetorno = DesenharPoligono(monitor, numeroMaximoLinhas, numeroMaximoColunas, numeroVertices, linhasVertices, colunasVertices);

  if (codigoRetorno != ok)
  {
		if (codigoRetorno == pixelInvalido) {
			printf ("Erro: Pixel defeituoso, nao foi possivel completar o desenho. \n");
			exit (ERRO_FUNCAO_DESENHAR_POLIGONO);
		}
		else {
			printf ("Funcao DesenharPoligono retornou o erro: %i\n", codigoRetorno);
			exit (ERRO_FUNCAO_DESENHAR_POLIGONO);
		}
	}

  codigoRetorno = MostrarMonitor(monitor, numeroMaximoLinhas, numeroMaximoColunas, tempoEspera);

  if (codigoRetorno != ok)
  {
    printf ("Funcao MostrarMonitor retornou o erro: %i\n", codigoRetorno);
    exit (ERRO_FUNCAO_MOSTRAR_MONITOR);
  }


	return OK;
}

/* $RCSfile: aula0705.c,v $ */
