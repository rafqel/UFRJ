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
 * $Date: 2021/08/03 20:26:08 $
 * $Log: aula0102.c,v $
 * Revision 1.1  2021/08/03 20:26:08  rafael.jesus
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK															0
#define TAMANHO_INVALIDO								1

void ExibirSeparador (void) 
{
	int contador;
	printf ("\n");
	for (contador=1;contador<=80;contador++)
	{
		printf ("-");
	}
	printf ("\n\n");
	return;
}

char Coluna(char nome[10])
{
	int len, espacos, i;
  len = strlen(nome);
  espacos = 61-len;
  for (i=0; i<espacos; i++)
		printf (" ");
  return OK;
}

int main()
{
	char titulo[78]="Tamanhos dos Tipos Basicos:";
 
	ExibirSeparador();
  printf ("\"%s\"\n\n",titulo);
	printf("char");
  Coluna("char");
  printf("%lu %s\n", sizeof(char), sizeof(char)==1?"byte":"bytes");
  printf("int");
  Coluna("int");
  printf("%lu %s\n", sizeof(int), sizeof(int)==1?"byte":"bytes");
  printf("float");
  Coluna("float");
  printf("%lu %s\n", sizeof(float), sizeof(float)==1?"byte":"bytes");
  printf("void");
  Coluna("void");
  printf("%lu %s\n", sizeof(void), sizeof(void)==1?"byte":"bytes");
  printf("double");
  Coluna("double");
  printf("%lu %s\n", sizeof(double), sizeof(double)==1?"byte":"bytes");
  ExibirSeparador();

  return OK; /* Sucesso */
}

/* $RCSfile: aula0102.c,v $ */
