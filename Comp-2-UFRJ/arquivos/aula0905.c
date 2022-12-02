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
 * $Date: 2021/10/13 00:59:30 $
 * $Log: aula0905.c,v $
 * Revision 1.3  2021/10/13 00:59:30  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao de macros erradas.
 *
 * Revision 1.2  2021/10/13 00:31:24  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao de erros.
 *
 * Revision 1.1  2021/10/12 18:35:12  rafael.jesus
 * Initial revision
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
#define ERRO_FUNCAO_EXIBIR_CONTEUDO_ARQUIVO															3
#define ERRO_FUNCAO_CONVERTER_ARQUIVO_FORMATO_UNIX_PARA_FORMATO_DOS			4
#define ERRO_FUNCAO_CONVERTER_ARQUIVO_FORMATO_DOS_PARA_FORMATO_UNIX			5
#define NUMERO_ARGUMENTOS_INVALIDO                                      6

#define NUMERO_MAXIMO_ARGUMENTOS																				4

int
main (int argc, char *argv [ ])
{
	const char *opcoesCurtas = "sSdDuUhH";
	int opcaoCurta;
	char entrada [COMPRIMENTO_MAX_NOME_ARQUIVO + 1];
	char saida [COMPRIMENTO_MAX_NOME_ARQUIVO + 1];
	tipoErros codigoRetorno;

	opterr = 0;

	if (argc > NUMERO_MAXIMO_ARGUMENTOS)				
	{
    printf ("Erro: Passando muitos argumentos atraves da linha de comando. \n");
    printf ("- Para mais informacoes de como usar o programa, use o comando:\n");
		printf ("./aula0905 -h | -H\n\n");
		exit (NUMERO_ARGUMENTOS_INVALIDO);
  }
	

	memset (entrada, 0x00, COMPRIMENTO_MAX_NOME_ARQUIVO + 1);
	memset (saida, 0x00, COMPRIMENTO_MAX_NOME_ARQUIVO + 1);

	while((opcaoCurta = getopt (argc, argv, opcoesCurtas)) != -1){
		switch (opcaoCurta)
    {
      case 's':
      case 'S':
        printf ("Opcao EXIBIR CONTEUDO DO ARQUIVO selecionada\n");

				if (argc > (NUMERO_MAXIMO_ARGUMENTOS - 1))
				{
          printf ("Erro: Passando muitos argumentos atraves da linha de comando.\n");
					printf ("- Para mais informacoes de como usar o programa, use o comando:\n");
					printf ("./aula0905 -h | -H\n\n");
					exit (NUMERO_ARGUMENTOS_INVALIDO);
        }
	
				if (argv[optind] == NULL)
					break;

				if (strlen (argv[optind]) > COMPRIMENTO_MAX_NOME_ARQUIVO)
				{
          printf ("Comprimento maximo entrada foi excedido\n");
					exit (COMPRIMENTO_MAX_ENTRADA_EXCEDIDO);
        }
				strcpy (entrada, argv[optind]);				


				codigoRetorno = ExibirConteudoArquivo (entrada);
				if (codigoRetorno != ok)
				{
					printf ("Funcao ExibirConteudoArquivo retornou o erro: %i \n", codigoRetorno);
					exit (ERRO_FUNCAO_EXIBIR_CONTEUDO_ARQUIVO);
				}		
      break; /* case 's' | 'S' */


      case 'd':
      case 'D':
        printf ("Opcao DOS selecionada\n");
	
				if (argv[optind] == NULL)
					break;
				
				if (strlen (argv[optind]) > COMPRIMENTO_MAX_NOME_ARQUIVO)
				{
          printf ("Comprimento maximo entrada foi excedido\n");
					exit (COMPRIMENTO_MAX_ENTRADA_EXCEDIDO);
        }	
				strcpy (entrada, argv[optind]);				

				
				if (argv[optind + 1] == NULL)
				{
					codigoRetorno = ConverterArquivoFormatoUnixParaFormatoDos (entrada, NULL);
					if (codigoRetorno != ok)
					{
					printf ("Funcao ConverterArquivoFormatoUnixParaFormatoDos retornou o erro: %i \n", codigoRetorno);
					exit (ERRO_FUNCAO_CONVERTER_ARQUIVO_FORMATO_UNIX_PARA_FORMATO_DOS);
					}				  
				}

				else
				{
					if (strlen (argv[optind + 1]) > COMPRIMENTO_MAX_NOME_ARQUIVO)
					{
						printf ("Comprimento maximo saida foi excedido\n");
						exit (COMPRIMENTO_MAX_SAIDA_EXCEDIDO);
					}
					strcpy (saida, argv[optind + 1]);


					codigoRetorno = ConverterArquivoFormatoUnixParaFormatoDos (entrada, saida);
					if (codigoRetorno != ok)
					{
						printf ("Funcao ConverterArquivoFormatoUnixParaFormatoDos retornou o erro: %i \n", codigoRetorno);
						exit (ERRO_FUNCAO_CONVERTER_ARQUIVO_FORMATO_UNIX_PARA_FORMATO_DOS);
					}
				}				 
      break; /* case 'd' | 'D' */


      case 'u':
      case 'U':
        printf ("Opcao UNIX selecionada\n");

				if (argv[optind] == NULL)
					break;

				if (strlen (argv[optind]) > COMPRIMENTO_MAX_NOME_ARQUIVO)
				{
          printf ("Comprimento maximo entrada foi excedido\n");
					exit (COMPRIMENTO_MAX_ENTRADA_EXCEDIDO);
        }
				strcpy (entrada, argv[optind]);				


				if (argv[optind + 1] == NULL)
				{
					codigoRetorno = ConverterArquivoFormatoDosParaFormatoUnix (entrada, NULL);
					if (codigoRetorno != ok)
					{
					printf ("Funcao ConverterArquivoFormatoDosParaFormatoUnix retornou o erro: %i \n", codigoRetorno);
					exit (ERRO_FUNCAO_CONVERTER_ARQUIVO_FORMATO_DOS_PARA_FORMATO_UNIX);
					}				  
				}

				else
				{
					if (strlen (argv[optind + 1]) > COMPRIMENTO_MAX_NOME_ARQUIVO)
					{
						printf ("Comprimento maximo saida foi excedido\n");
						exit (COMPRIMENTO_MAX_SAIDA_EXCEDIDO);
					}
					strcpy (saida, argv[optind + 1]);


					codigoRetorno = ConverterArquivoFormatoDosParaFormatoUnix (entrada, saida);
					if (codigoRetorno != ok)
					{
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
				printf ("./aula0905 -s | -S <nome-arquivo>\n\n");

        printf ("- Para converter um arquivo de texto formato Linux (Unix)"); 
				printf (" para o formato Microsoft (DOS):\n");
				printf ("./aula0905 -d | -D <nome-arquivo>");
				printf (" <nome-gerado-desejado(opcional)>\n\n");

        printf ("- Para converter um arquivo de texto do formato Microsoft (DOS)");
				printf (" para o formato Linux (Unix):\n");
				printf ("./aula0905 -u | -U <nome-arquivo>");
				printf (" <nome-gerado-desejado(opcional)>\n\n");

        printf ("- Para exibir informacoes de como usar o programa:\n");
				printf ("./aula0905 -h | -H\n\n");
      break; /* case 'h' | 'H' */


      default:
        printf ("Opcao invalida foi escolhida\n");
				printf ("Para mais informações, use o comando:\n");
				printf ("./aula0905 -h | -H\n\n");
    }     
	}

	return OK;
}

/* $RCSfile: aula0905.c,v $ */
