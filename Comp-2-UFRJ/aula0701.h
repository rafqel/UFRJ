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
 * $Log: aula0701.h,v $
 * Revision 1.6  2021/09/21 03:31:22  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Incremento do prototipo da funcao PreencherPoligono.
 *
 * Revision 1.5  2021/09/20 05:33:41  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao do prototipo da funcao DesenharPoligono.
 *
 * Revision 1.4  2021/09/19 22:44:29  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao do prototipo da funcao DesenharReta.
 *
 * Revision 1.3  2021/09/18 20:55:52  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao do cabecalho com o intento de rodar no Linux.
 *
 * Revision 1.2  2021/09/18 08:01:52  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Incremento do prototipo da funcao LimparMonitor.
 *
 * Revision 1.1  2021/09/18 00:16:47  rafael.jesus
 * Initial revision
 *
 */

#ifdef __linux__
#define _BSD_SOURCE || _XOPEN_SOURCE >= 500 || _XOPEN_SOURCE && _XOPEN_SOURCE_EXTENDED
#endif

#include <time.h>
#include <unistd.h>

#ifdef __linux__
typedef __useconds_t useconds_t;
#endif

#ifndef _AULA0701_
#define _AULA0701_												"@(#)aula0701.h $Revision: 1.6 $"

#define NUMERO_MAXIMO_LINHAS							250
#define NUMERO_MAXIMO_COLUNAS							800

#define APAGADO														'-'
#define ACESO															'+'
#define DEFEITUOSO												'X'

typedef enum
{
	ok,
	linhaInvalida,
	colunaInvalida,
	pixelInvalido,
	argumentoInvalido,
	matrizNula,
	dimensaoInvalida,
	caractereInvalido
} tipoErros;

typedef enum
{
	apagado,
	aceso,
	defeituoso
}	tipoPixel;


tipoErros
MostrarMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS] [NUMERO_MAXIMO_COLUNAS], 
								unsigned numeroMaximoLinhas, 
								unsigned numeroMaximoColunas, 
								useconds_t tempoEspera);


tipoErros
LimparMonitor (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
							unsigned numeroMaximoLinhas,
							unsigned numeroMaximoColunas);


tipoErros
DesenharReta (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
							unsigned numeroMaximoLinhas,
							unsigned numeroMaximoColunas,
							unsigned linhaA, unsigned colunaA,
							unsigned linhaB, unsigned colunaB);


tipoErros
DesenharPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
									unsigned numeroMaximoLinhas,
									unsigned numeroMaximoColunas, 
									unsigned numeroVertices,
									unsigned linhasVertices [NUMERO_MAXIMO_LINHAS],
									unsigned colunasVertices [NUMERO_MAXIMO_COLUNAS]);


tipoErros
PreencherPoligono (tipoPixel monitor [NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
									unsigned numeroMaximoLinhas,
									unsigned numeroMaximoColunas,
									unsigned linha, unsigned coluna,
									useconds_t tempoEspera);


#endif

/* $RCSfile: aula0701.h,v $ */
