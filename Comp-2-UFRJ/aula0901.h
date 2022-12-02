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
 * $Date: 2021/10/12 04:20:42 $
 * $Log: aula0901.h,v $
 * Revision 1.4  2021/10/12 04:20:42  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1
 * Implementacao do prototipo da funcao ConverterArquivoFormatoUnixParaFormatoDos.
 *
 * Revision 1.3  2021/10/12 02:03:05  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1
 * Correcao de erros no Linux.
 *
 * Revision 1.2  2021/10/12 00:40:06  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Update de macros.
 *
 * Revision 1.1  2021/10/10 19:51:53  rafael.jesus
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

#ifndef _AULA0901_
#define _AULA0901_				"@(#)aula0901.h $Revision: 1.4 $"

#define BASE_16						"0123456789ABCDEF"
#define COMPRIMENTO_MAX_NOME_ARQUIVO						257
#define ENTER							'\n'
#define EOS								'\0'

typedef unsigned char byte;

typedef enum
{
	ok,
	nulo,
	memoriaInsuficiente,
	erroAbrindoArquivo,
	argumentoInvalido
} tipoErros;


tipoErros
ExibirConteudoArquivo (char * /* (E) */);

tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *original, char *convertido);

tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *original, char *convertido);


#endif

/* $RCSfile: aula0901.h,v $ */
