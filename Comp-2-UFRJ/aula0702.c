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
 * $Date: 2021/09/20 05:13:05 $
 * $Log: aula0702.c,v $
 * Revision 1.2  2021/09/20 05:13:05  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao da funcao rand.
 *
 * Revision 1.1  2021/09/18 00:16:47  rafael.jesus
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
#define ERRO_FUNCAO_MOSTRAR_MONITOR							2
#define NUMERO_ARGUMENTOS_INVALIDO							3
#define NUMERO_ARGUMENTOS												4
#define END_OF_STRING														'\0'

int
main (int argc, char *argv [])
{
	tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];
	unsigned numeroMaximoLinhas, numeroMaximoColunas, numeroAleatorio;
	unsigned short linha, coluna;
	useconds_t tempoEspera;
	tipoErros codigoRetorno;
	char* verificacao;


	if (argc != NUMERO_ARGUMENTOS)
	{
		printf ("Erro: Numero de argumentos invalido. \n");
		printf ("Uso: %s <Insira o numero de linhas, colunas e o tempo de espera> \n", argv [0]);
    exit (NUMERO_ARGUMENTOS_INVALIDO);    
  }

	if (argv[1][0] == '-' || argv[2][0] == '-' || argv[3][0] == '-')
	{
		printf ("Erro: Caractere invalido: '-' \n");
		printf ("Uso: <Numero nao negativo> \n");
		exit (ARGUMENTO_INVALIDO);
	}


 	numeroMaximoLinhas = strtoul (argv[1],&verificacao,10);
	numeroMaximoColunas = strtoul (argv[2],&verificacao,10);
	tempoEspera = strtoul (argv[3],&verificacao,10);


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


	/* TESTE 2 - TODOS PIXELS ACESOS */

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


	/* TESTE 3 - TODOS PIXELS COM DEFEITO */

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


	return OK;
}

/* $RCSfile: aula0702.c,v $ */
