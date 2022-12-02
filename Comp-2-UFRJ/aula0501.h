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
 * $Date: 2021/08/27 18:37:58 $
 * $Log: aula0501.h,v $
 * Revision 1.4  2021/08/27 18:37:58  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao do prototipo da funcao ValidarCpf.
 *
 * Revision 1.3  2021/08/27 14:43:37  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao do comprimento do CPF.
 *
 * Revision 1.2  2021/08/27 14:28:26  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Acrescimo no comprimento do CPF em virtude da adicao de simbolos.
 *
 * Revision 1.1  2021/08/25 18:37:37  rafael.jesus
 * Initial revision
 *
 */

#ifndef _AULA0501_
#define _AULA0501_				 "@(#)aula0501.h $Revision: 1.4 $"

#define COMPRIMENTO_CPF			11

typedef enum
{
	ok,
	argumentoInvalido,
	comprimentoArgumentoInvalido,
	caractereInvalido
} tipoErros;

typedef unsigned char byte;

tipoErros
GerarDigitosVerificadoresCpf (byte [COMPRIMENTO_CPF - 2]);

tipoErros
ValidarCpf (byte [COMPRIMENTO_CPF]); 

#endif

/* $RCSfile: aula0501.h,v $ */
