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
 * $Date: 2021/10/02 08:35:13 $
 * $Log: aula0801.h,v $
 * Revision 1.4  2021/10/02 08:35:13  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Incremento do prototipo da funcao DecodificarBase64.
 *
 * Revision 1.3  2021/10/01 17:19:23  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao do prototipo da funcao CodificarBase64.
 *
 * Revision 1.2  2021/09/30 03:21:41  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Incremento do prototipo da funcao DecodificarBase16.
 *
 * Revision 1.1  2021/09/29 21:45:36  rafael.jesus
 * Initial revision
 *
 */

#ifndef _AULA0801_
#define _AULA0801_				"@(#)aula0708.h $Revision: 1.4 $"

#define BASE_16						"0123456789ABCDEF"
#define BASE_64						"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

#define TAMANHO_MAX_LINHA_64	76
#define END_OF_STRING					'\0'

typedef unsigned char byte;

typedef enum
{
	ok,
	argumentoInvalido,
	caractereInvalido,
	nulo
} tipoErros;

typedef enum
{
	desabilitado,
	habilitado
} tipoFinalLinha;


tipoErros
CodificarBase16 (byte * /* (E) */,
								unsigned long long /* (E) */,
								char * /* (S) */);


tipoErros
DecodificarBase16 (char * /* (E) */,
									byte * /* (S) */,
									unsigned long long * /*  (S) */);


tipoErros
CodificarBase64 (byte * /* (E) */,
								unsigned long long /*  (E) */,
								tipoFinalLinha /* (E) */,
								char * /* (S) */);


tipoErros
DecodificarBase64 (char * /* (E) */,
									tipoFinalLinha /* (E) */,
									byte * /* (S) */,
									unsigned long long * /* (S) */);


#endif

/* $RCSfile: aula0801.h,v $ */
