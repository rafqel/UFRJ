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
 * $Date: 2021/08/28 02:47:25 $
 * $Log: aula0504.h,v $
 * Revision 1.2  2021/08/28 02:47:25  rafael.jesus
 * Incremento da funcao ValidarCpf.
 *
 * Revision 1.1  2021/08/28 02:00:06  rafael.jesus
 * Initial revision
 *
 */

#ifndef _AULA0504_
#define _AULA0504_								"@(#)aula0504.h $Revision: 1.2 $"

#define COMPRIMENTO_CPF						11
#define ARGUMENTO_IGUAL_A_NULL		-1	

typedef enum
{
	ok,
	argumentoInvalido,
	comprimentoArgumentoInvalido,
	caractereInvalido
} tipoErros;


tipoErros
GerarDigitosVerificadoresCpf (char * , char * , char *); 

tipoErros
ValidarCpf (char *); 

#endif

/* $RCSfile: aula0504.h,v $ */
