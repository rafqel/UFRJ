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
 * $Date: 2021/10/12 20:17:56 $
 * $Log: aula0907.c,v $
 * Revision 1.1  2021/10/12 20:17:56  rafael.jesus
 * Initial revision
 *
 *
 */

#include "aula0901.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#define OK																															0
#define COMPRIMENTO_MAX_ENTRADA_EXCEDIDO																1
#define COMPRIMENTO_MAX_SAIDA_EXCEDIDO																	2
#define ARGUMENTO_REPETIDO																							3
#define ERRO_FUNCAO_EXIBIR_CONTEUDO_ARQUIVO															4
#define ERRO_FUNCAO_CONVERTER_ARQUIVO_FORMATO_UNIX_PARA_FORMATO_DOS			5
#define ERRO_FUNCAO_CONVERTER_ARQUIVO_FORMATO_DOS_PARA_FORMATO_UNIX			6
#define VALOR_ARGUMENTO_INEXISTENTE																			7

typedef enum
{
	argumentoEntrada,
	argumentoSaida
} indicesArgumentos;

int
main (int argc, char *argv [ ])
{
	const char *opcoesCurtas = "sSdDuUhH";
	struct option opcoesLongas [5] =
	{
		{"show", 0, NULL, 's'},
		{"dos", 0, NULL, 'd'},
		{"unix", 0, NULL, 'u'},
		{"help", 0, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};

	char *nomesArgumentos[3] =
	{
		"input",
		"output",
		NULL
	};

	int opcaoCurta;
	int opcaoLonga;
	int indiceArgumento;
	char *argumentos, *valorArgumento;
	char entrada [COMPRIMENTO_MAX_NOME_ARQUIVO + 1];
	char saida [COMPRIMENTO_MAX_NOME_ARQUIVO + 1];
	tipoErros codigoRetorno;

	opterr = 0;

	memset (entrada, 0x00, COMPRIMENTO_MAX_NOME_ARQUIVO + 1);
	memset (saida, 0x00, COMPRIMENTO_MAX_NOME_ARQUIVO + 1);

	while((opcaoCurta = getopt_long (argc,
																	argv,
																	opcoesCurtas,
																	opcoesLongas,
																	&opcaoLonga)) != -1){
		switch (opcaoCurta)
    {
      case 's':
      case 'S':
        printf ("Opcao EXIBIR CONTEUDO DO ARQUIVO selecionada\n");
				while (optind < argc){
					argumentos = argv [optind];	
					indiceArgumento = getsubopt (&argumentos, nomesArgumentos, &valorArgumento);
					switch (indiceArgumento)
					{
						case argumentoEntrada:
							if (strlen (entrada) > 0)
              {
								printf ("Tipo de argumento repetido\n");
								printf ("Valor ja obtido: %s\n", entrada);
								exit (ARGUMENTO_REPETIDO);
              }

							if (!valorArgumento)
              {
                printf ("Argumentos devem ser sempre no formato input=valor\n");
                exit (VALOR_ARGUMENTO_INEXISTENTE);
              }
							
              if (strlen (valorArgumento) > COMPRIMENTO_MAX_NOME_ARQUIVO)
              {
                printf ("Comprimento maximo input foi excedido\n");
                exit (COMPRIMENTO_MAX_ENTRADA_EXCEDIDO);
              }
              strcpy (entrada, valorArgumento);

              #ifdef __FreeBSD__
              if (strlen (argumentos) > 0)
              {
                if ((strlen (entrada) + 1 + strlen (argumentos))\
											> COMPRIMENTO_MAX_NOME_ARQUIVO)
                {
                  printf ("Comprimento maximo input foi excedido\n");
                  exit (COMPRIMENTO_MAX_ENTRADA_EXCEDIDO);
                }

                strcat (entrada, " ");
                strcat (entrada, argumentos);
              }
              #endif
						break; /*case argumentoEntrada */

						default:
							printf ("Erro: Argumento Invalido.\n");
							printf ("Uso: ./aula0905 -s | -S | --show input=<nome-arquivo>\n\n");

					} /* switch (indiceArgumento) */
					optind++;
				} /* while (optind) */
				
				if(strlen(entrada) > 0)
				{
					codigoRetorno = ExibirConteudoArquivo (entrada);
					if (codigoRetorno != ok){
						printf ("Funcao ExibirConteudoArquivo retornou o erro: %i \n", codigoRetorno);
						exit (ERRO_FUNCAO_EXIBIR_CONTEUDO_ARQUIVO);
					}
				}		

      break; /* case 's' | 'S' */

      case 'd':
      case 'D':
        printf ("Opcao DOS selecionada\n");
				while (optind < argc)
				{
					argumentos = argv [optind];	
					indiceArgumento = getsubopt (&argumentos, nomesArgumentos, &valorArgumento);
					switch (indiceArgumento)
					{
						case argumentoEntrada:
							if (strlen (entrada) > 0)
              {
								printf ("Tipo de argumento repetido\n");
								printf ("Valor ja obtido: %s\n", entrada);
								exit (ARGUMENTO_REPETIDO);
              }

							if (!valorArgumento)
              {
                printf ("Argumentos devem ser sempre no formato input=valor\n");
                exit (VALOR_ARGUMENTO_INEXISTENTE);
              }
							
              if (strlen (valorArgumento) > COMPRIMENTO_MAX_NOME_ARQUIVO)
              {
                printf ("Comprimento maximo input foi excedido\n");
                exit (COMPRIMENTO_MAX_ENTRADA_EXCEDIDO);
              }
              strcpy (entrada, valorArgumento);

              #ifdef __FreeBSD__
              if (strlen (argumentos) > 0)
              {
                if ((strlen (entrada) + 1 + strlen (argumentos))\
											> COMPRIMENTO_MAX_NOME_ARQUIVO)
                {
                  printf ("Comprimento maximo input foi excedido\n");
                  exit (COMPRIMENTO_MAX_ENTRADA_EXCEDIDO);
                }

                strcat (entrada, " ");
                strcat (entrada, argumentos);
              }
              #endif
						break; /*case argumentoEntrada */

						case argumentoSaida:
							if (strlen (saida) > 0)
              {
								printf ("Tipo de argumento repetido\n");
								printf ("Valor ja obtido: %s\n", saida);
								exit (ARGUMENTO_REPETIDO);
              }

              if (!valorArgumento)
              {
                printf ("Argumentos devem ser sempre no formato output=valor\n");
                exit (VALOR_ARGUMENTO_INEXISTENTE);
              }

              if (strlen (valorArgumento) > COMPRIMENTO_MAX_NOME_ARQUIVO)
              {
                printf ("Comprimento maximo output foi excedido\n");
                exit (COMPRIMENTO_MAX_SAIDA_EXCEDIDO);
              }
              strcpy (saida, valorArgumento);

              #ifdef __FreeBSD__
              if (strlen (argumentos) > 0)
              {
                if ((strlen (saida) + 1 + strlen (argumentos)) > COMPRIMENTO_MAX_NOME_ARQUIVO)
                {
                  printf ("Comprimento maximo output foi excedido\n");
                  exit (COMPRIMENTO_MAX_SAIDA_EXCEDIDO);
                }

                strcat (saida, " ");
                strcat (saida, argumentos);
              } 
              #endif
						break; /*case argumentoSaida */
					
						default:
							printf ("Erro: Argumento Invalido.\n");
							printf ("Uso: ./aula0905 -d | -D | --dos input=<nome-arquivo>");
							printf (" output=<nome-gerado-desejado(opcional)>\n\n");
					} /* switch (indiceArgumento) */
					optind++;
				} /* while (optind) */
				
				if(strlen(entrada) > 0)
				{
					codigoRetorno = ConverterArquivoFormatoUnixParaFormatoDos (entrada, saida);
					if (codigoRetorno != ok){
						printf ("Funcao ConverterArquivoFormatoUnixParaFormatoDos retornou o erro: %i \n", codigoRetorno);
						exit (ERRO_FUNCAO_CONVERTER_ARQUIVO_FORMATO_UNIX_PARA_FORMATO_DOS);
					}
				}				 
      break; /* case 'd' | 'D' */

      case 'u':
      case 'U':
        printf ("Opcao UNIX selecionada\n");
				while (optind < argc)
				{
					argumentos = argv [optind];	
					indiceArgumento = getsubopt (&argumentos, nomesArgumentos, &valorArgumento);
					switch (indiceArgumento)
					{
						case argumentoEntrada:
							if (strlen (entrada) > 0)
              {
								printf ("Tipo de argumento repetido\n");
								printf ("Valor ja obtido: %s\n", entrada);
								exit (ARGUMENTO_REPETIDO);
              }

							if (!valorArgumento)
              {
                printf ("Argumentos devem ser sempre no formato input=valor\n");
                exit (VALOR_ARGUMENTO_INEXISTENTE);
              }
							
              if (strlen (valorArgumento) > COMPRIMENTO_MAX_NOME_ARQUIVO)
              {
                printf ("Comprimento maximo input foi excedido\n");
                exit (COMPRIMENTO_MAX_ENTRADA_EXCEDIDO);
              }
              strcpy (entrada, valorArgumento);

              #ifdef __FreeBSD__
              if (strlen (argumentos) > 0)
              {
                if ((strlen (entrada) + 1 + strlen (argumentos))\
											> COMPRIMENTO_MAX_NOME_ARQUIVO)
                {
                  printf ("Comprimento maximo input foi excedido\n");
                  exit (COMPRIMENTO_MAX_ENTRADA_EXCEDIDO);
                }

                strcat (entrada, " ");
                strcat (entrada, argumentos);
              }
              #endif
						break; /*case argumentoEntrada */

						case argumentoSaida:
							if (strlen (saida) > 0)
              {
								printf ("Tipo de argumento repetido\n");
								printf ("Valor ja obtido: %s\n", saida);
								exit (ARGUMENTO_REPETIDO);
              }

              if (!valorArgumento)
              {
                printf ("Argumentos devem ser sempre no formato output=valor\n");
                exit (VALOR_ARGUMENTO_INEXISTENTE);
              }

              if (strlen (valorArgumento) > COMPRIMENTO_MAX_NOME_ARQUIVO)
              {
                printf ("Comprimento maximo output foi excedido\n");
                exit (COMPRIMENTO_MAX_SAIDA_EXCEDIDO);
              }
              strcpy (saida, valorArgumento);

              #ifdef __FreeBSD__
              if (strlen (argumentos) > 0)
              {
                if ((strlen (saida) + 1 + strlen (argumentos)) > COMPRIMENTO_MAX_NOME_ARQUIVO)
                {
                  printf ("Comprimento maximo output foi excedido\n");
                  exit (COMPRIMENTO_MAX_SAIDA_EXCEDIDO);
                }

                strcat (saida, " ");
                strcat (saida, argumentos);
              } 
              #endif
						break; /*case argumentoSaida */
					
						default:
							printf ("Argumento invalido.\n");
							printf ("./aula0905 -u | -U | --unix input=<nome-arquivo>");
							printf (" output=<nome-gerado-desejado(opcional)>\n\n");

					} /* switch (indiceArgumento) */
					optind++;
				} /* while (optind) */
				
				if(strlen(entrada) > 0)
				{
					codigoRetorno = ConverterArquivoFormatoDosParaFormatoUnix (entrada, saida);
					if (codigoRetorno != ok){
						printf ("Funcao ConverterArquivoFormatoDosParaFormatoUnix retornou o erro: %i \n", codigoRetorno);
						exit (ERRO_FUNCAO_CONVERTER_ARQUIVO_FORMATO_DOS_PARA_FORMATO_UNIX);
					}
				}				 
      break; /* case 'u' | 'U' */


      case 'h':
      case 'H':
        printf ("\nOpcao AJUDA selecionada\n");
        printf ("COMANDOS DO PROGRAMA:\n\n");

        printf ("- Para exibir conteúdo do arquvo em HexDump:\n");
				printf ("./aula0905 -s | -S | --show input=<nome-arquivo>\n\n");

        printf ("- Para converter um arquivo de texto formato Linux (Unix)"); 
				printf (" para o formato Microsoft (DOS):\n");
				printf ("./aula0905 -d | -D | --dos input=<nome-arquivo>");
				printf (" output=<nome-gerado-desejado(opcional)>\n\n");

        printf ("- Para converter um arquivo de texto do formato Microsoft (DOS)");
				printf (" para o formato Linux (Unix):\n");
				printf ("./aula0905 -u | -U | --unix input=<nome-arquivo>");
				printf (" output=<nome-gerado-desejado(opcional)>\n\n");

        printf ("- Para exibir informacoes de como usar o programa:\n");
				printf ("./aula0905 -h | -H | --help \n\n");
      break; /* case 'h' | 'H' */

      default:
        printf ("Opcao invalida foi escolhida\n");
				printf ("Para mais informações, use o comando:\n");
				printf ("./aula0905 -h | -H | --help \n\n");
    }     
	}

	return OK;
}

/* $RCSfile: aula0907.c,v $ */
