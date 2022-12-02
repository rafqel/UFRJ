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
 * $Date: 2021/10/12 04:49:47 $
 * $Log: aula0901.c,v $
 * Revision 1.5  2021/10/12 04:49:47  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao da funcao ConverterArquivoFormatoDosParaFormatoUnix.
 *
 * Revision 1.4  2021/10/12 04:20:42  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Implementacao da funcao ConverterArquivoFormatoUnixParaFormatoDos.
 *
 * Revision 1.3  2021/10/12 02:03:05  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1
 * Correcao de erros no Linux.
 *
 * Revision 1.2  2021/10/12 00:39:02  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Update da funcao ExibirConteudoArquivo.
 *
 * Revision 1.1  2021/10/10 19:51:53  rafael.jesus
 * Initial revision
 *
 */

#include "aula0901.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define COMPRIMENTO_COLUNA											17

tipoErros
ExibirConteudoArquivo (char *nomeArquivo /* (E) */)
{
	FILE *arquivo;
	byte bytes[COMPRIMENTO_COLUNA], tamanhoBytes;
	char caractere='\0', *conteudo, *saidaHex;
	unsigned indice, indiceAuxiliar;


	/* \/ TRATAMENTO DE EXCECAO \/ ----------------------------------------------- */	


	if (!nomeArquivo)
		return nulo;


	/* \/ ABRINDO ARQUIVO \/ ----------------------------------------------------- */	


	arquivo = fopen (nomeArquivo, "r");
	if (arquivo == NULL)
	{
		printf ("Nao foi possivel abrir o arquivo \"%s\"\n", nomeArquivo);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		return erroAbrindoArquivo;
	}


	/* \/ ALOCANDO MEMORIA \/ ---------------------------------------------------- */


	fseek (arquivo, 0L, SEEK_END);
	tamanhoBytes = ftell (arquivo);

	conteudo = (char *) malloc (tamanhoBytes * sizeof(char));
	if (conteudo == NULL){
		fclose (arquivo);
		printf ("Memoria Insuficiente. \n");
		return memoriaInsuficiente;
	}

	saidaHex = (char *) malloc (((1 + (2 * tamanhoBytes)) * sizeof(char)));
	if (saidaHex == NULL){
		fclose(arquivo);
		free (conteudo);	
		printf ("Nao foi possivel alocar memoria!\n");
		return memoriaInsuficiente;
	}


	/* \/ LENDO ARQUIVO \/ -------------------------------------------------------- */


	fseek (arquivo, 0, SEEK_SET);	

	indice = 0;
	while (caractere != EOF)
	{	
		caractere = fgetc (arquivo);
		conteudo[indice] = caractere;
		indice += 1;
	}
	conteudo[indice] = EOS;	


	/* \/ CONVERTENDO PARA NUMERO HEXADECIMAL \/ --------------------------------- */


	for (indiceAuxiliar = indice = 0 ; indiceAuxiliar < tamanhoBytes * 2; indiceAuxiliar++)
	{
		saidaHex[indice] = BASE_16 [ (conteudo[indiceAuxiliar] >> 4) & 0X0F ];
		saidaHex[indice + 1] = BASE_16 [ conteudo[indiceAuxiliar] & 0X0F ]; 
		indice += 2;
	}
	saidaHex[indice] = EOS;


	/* \/ PRINTANDO HEXDUMP \/ --------------------------------------------------- */


	for (indice = indiceAuxiliar = 0 ; indice < tamanhoBytes ; indice++)
	{	
		if ((indice % 16) == 0){

			if (indice != 0)
				printf ("| %s\n", bytes);

			printf ("%08x | ", indice);
		}

		printf ("%c%c ", saidaHex[indiceAuxiliar], saidaHex[indiceAuxiliar + 1]);
		indiceAuxiliar += 2;

		if ((conteudo[indice] < 0x20) || (conteudo[indice] > 0x7F))
			bytes[indice % 16] = '.';
		else
			bytes[indice % 16] = conteudo[indice];
		
		bytes[(indice % 16) + 1] = '\0';
	}

	indiceAuxiliar = indice;
	while ((indice % 16) != 0) {
		printf ("   ");
		indice++;
	}
	printf ("| %s\n", bytes);
	printf ("%08x\n", indiceAuxiliar);


	/* \/ FECHANDO ARQUIVO E LIBERANDO MEMORIA \/ --------------------------------- */

	memset (saidaHex, 0x00, 2*tamanhoBytes+1);
	memset (conteudo, 0x00, tamanhoBytes+1);

	fclose(arquivo);

	return ok;
}



tipoErros
ConverterArquivoFormatoUnixParaFormatoDos (char *original, char *convertido)
{
	FILE *arquivo, *arquivoConvertido;
	char caractere, nomeBackup[COMPRIMENTO_MAX_NOME_ARQUIVO],\
	nomeTemporario[COMPRIMENTO_MAX_NOME_ARQUIVO];
	time_t horaAtual; struct tm *informacao;
	int verificacao, ehTemporario=0;


	/* \/ TRATAMENTO DE EXCECAO \/ ----------------------------------------------- */	


	if (!original)
		return nulo;


	/* \/ ABRINDO ARQUIVO PARA LEITURA \/ ----------------------------------------- */	


	arquivo = fopen (original, "r");
	if (arquivo == NULL)
	{
		printf ("Nao foi possivel abrir o arquivo \"%s\"\n", original);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		return erroAbrindoArquivo;
	}	

	
	/* \/ ABRINDO ARQUIVO PARA ESCRITA \/ ----------------------------------------- */	


	if (!convertido)
	{
		strcpy (nomeTemporario, original);
		strcat (nomeTemporario, ".XXXXXX");
		verificacao = mkstemp(nomeTemporario);
		if (verificacao == -1){
			printf ("Erro ao gerar arquivo temporario.\n");
			return nulo;
		}	
		
		arquivoConvertido = fdopen (verificacao,"w");
		if (arquivoConvertido == NULL)
		{
			fclose (arquivo);
			printf ("Nao foi possivel abrir o arquivo \"%s\"\n", convertido);
			printf ("Erro (#%i) - %s\n", errno, strerror (errno));
			return erroAbrindoArquivo;
		}

		ehTemporario += 1; /* TRUE */
	}

	else {
		arquivoConvertido = fopen (convertido, "w");
		if (arquivoConvertido == NULL)
		{
			fclose (arquivo);
			printf ("Nao foi possivel abrir o arquivo \"%s\"\n", convertido);
			printf ("Erro (#%i) - %s\n", errno, strerror (errno));
			return erroAbrindoArquivo;
		}
	}


	/* \/ COPIANDO CONTEUDO \/ ---------------------------------------------------- */

	fseek (arquivo, 0, SEEK_SET);	

	while (!feof(arquivo))
	{	
		caractere = fgetc (arquivo);
		if (caractere != EOF){
			if (caractere == '\n'){
				fputc ('\r', arquivoConvertido);
				fputc ('\n', arquivoConvertido);
			}
			else
				fputc (caractere, arquivoConvertido);
		}
	}

	/* /\ RENOMEANDO /\ ----------------------------------------------------------- */


	fclose (arquivo);
	fclose (arquivoConvertido);

	horaAtual = time(NULL);
	informacao = localtime (&horaAtual);

	snprintf (nomeBackup, 100, "%s.backup-%04d%02d%02d_%02d%02d%02d", original,\
						informacao->tm_year + 1900, informacao->tm_mon + 1, informacao->tm_mday,\
						informacao->tm_hour, informacao->tm_min, informacao->tm_sec);


	if (ehTemporario == 1){
		rename (original, nomeBackup);
		rename (convertido, original);
	}

	else {
		rename (original, nomeBackup);
		rename (original, convertido);
	}

	return ok;
}


tipoErros
ConverterArquivoFormatoDosParaFormatoUnix (char *original, char *convertido)
{
	FILE *arquivo, *arquivoConvertido;
	char caractere, nomeBackup[COMPRIMENTO_MAX_NOME_ARQUIVO],\
	nomeTemporario[COMPRIMENTO_MAX_NOME_ARQUIVO];
	time_t horaAtual; struct tm *informacao;
	int verificacao, ehTemporario=0;


	/* \/ TRATAMENTO DE EXCECAO \/ ----------------------------------------------- */	


	if (!original)
		return nulo;


	/* \/ ABRINDO ARQUIVO PARA LEITURA \/ ----------------------------------------- */	


	arquivo = fopen (original, "r");
	if (arquivo == NULL)
	{
		printf ("Nao foi possivel abrir o arquivo \"%s\"\n", original);
		printf ("Erro (#%i) - %s\n", errno, strerror (errno));
		return erroAbrindoArquivo;
	}	

	
	/* \/ ABRINDO ARQUIVO PARA ESCRITA \/ ----------------------------------------- */	


	if (!convertido)
	{
		strcpy (nomeTemporario, original);
		strcat (nomeTemporario, ".XXXXXX");
		verificacao = mkstemp(nomeTemporario);
		if (verificacao == -1){
			printf ("Erro ao gerar arquivo temporario.\n");
			return nulo;
		}	
		
		arquivoConvertido = fdopen (verificacao,"w");
		if (arquivoConvertido == NULL)
		{
			fclose (arquivo);
			printf ("Nao foi possivel abrir o arquivo \"%s\"\n", convertido);
			printf ("Erro (#%i) - %s\n", errno, strerror (errno));
			return erroAbrindoArquivo;
		}

		ehTemporario += 1; /* TRUE */
	}

	else {
		arquivoConvertido = fopen (convertido, "w");
		if (arquivoConvertido == NULL)
		{
			fclose (arquivo);
			printf ("Nao foi possivel abrir o arquivo \"%s\"\n", convertido);
			printf ("Erro (#%i) - %s\n", errno, strerror (errno));
			return erroAbrindoArquivo;
		}
	}

	/* \/ COPIANDO CONTEUDO \/ --------------------------------------------------- */

	fseek (arquivo, 0, SEEK_SET);	

	while (!feof(arquivo))
	{	
		caractere = fgetc (arquivo);

		if (caractere != EOF){
			if (caractere == '\r')
				continue;
				
			else
				fputc (caractere, arquivoConvertido);
		}
	}

	/* /\ RENOMEANDO /\ ----------------------------------------------------------- */


	fclose (arquivo);
	fclose (arquivoConvertido);

	horaAtual = time(NULL);
	informacao = localtime (&horaAtual);

	snprintf (nomeBackup, 100, "%s.backup-%04d%02d%02d_%02d%02d%02d", original,\
						informacao->tm_year + 1900, informacao->tm_mon + 1, informacao->tm_mday,\
						informacao->tm_hour, informacao->tm_min, informacao->tm_sec);


	if (ehTemporario == 1){
		rename (original, nomeBackup);
		rename (convertido, original);
	}

	else {
		rename (original, nomeBackup);
		rename (original, convertido);
	}

	return ok;
}


/* $RCSfile: aula0901.c,v $ */
