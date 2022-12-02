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
 * $Date: 2021/08/03 23:31:54 $
 * $Log: aula0105.c,v $
 * Revision 1.1  2021/08/03 23:31:54  rafael.jesus
 * Initial revision
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK															0

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
	char titulo[50]="Tamanhos dos Tipos Basicos:";
 
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
	
	char titulo2[50]="Tamanhos dos Modificadores de Sinal:";
	
	ExibirSeparador();
	printf ("\"%s\"\n\n",titulo2);
	printf("signed");
  Coluna("signed");
  printf("%lu %s\n", sizeof(signed), sizeof(signed)==1?"byte":"bytes");
  printf("unsigned");
  Coluna("unsigned");
  printf("%lu %s\n", sizeof(unsigned), sizeof(unsigned)==1?"byte":"bytes");
  ExibirSeparador();

	char titulo3[50]="Tamanhos dos Modificadores de Largura:";
	
	ExibirSeparador();
	printf ("\"%s\"\n\n",titulo3);
	printf("short");
  Coluna("short");
  printf("%lu %s\n", sizeof(short), sizeof(short)==1?"byte":"bytes");
  printf("long");
  Coluna("long");
  printf("%lu %s\n", sizeof(long), sizeof(long)==1?"byte":"bytes");
	printf("long long");
  Coluna("long long");
  printf("%lu %s\n", sizeof(long long), sizeof(long long)==1?"byte":"bytes");
  ExibirSeparador();

	char titulo4[80]="Tamanhos dos Modificadores de Sinal combinados com os Modificadores\n de Largura:";
 
	ExibirSeparador();
  printf ("\"%s\"\n\n",titulo4);
	printf("short signed");
  Coluna("short signed");
  printf("%lu %s\n", sizeof(short signed), sizeof(short signed)==1?"byte":"bytes");
  printf("short unsigned");
  Coluna("short unsigned");
  printf("%lu %s\n", sizeof(short unsigned), sizeof(short unsigned)==1?"byte":"bytes");
  printf("long signed");
  Coluna("long signed");
  printf("%lu %s\n", sizeof(long signed), sizeof(long signed)==1?"byte":"bytes");
  printf("long unsigned");
  Coluna("long unsigned");
  printf("%lu %s\n", sizeof(long unsigned), sizeof(long unsigned)==1?"byte":"bytes");
	printf("long long signed");
  Coluna("long long signed");
  printf("%lu %s\n", sizeof(long long signed), sizeof(long long signed)==1?"byte":"bytes");
  printf("long long unsigned");
  Coluna("long long unsigned");
  printf("%lu %s\n", sizeof(long long unsigned), sizeof(long long unsigned)==1?"byte":"bytes");
	ExibirSeparador();
  
	char titulo5[80]="Tamanhos dos Tipos Básicos combinados com Modificadores de Sinal:";
	
	ExibirSeparador();
	printf ("\"%s\"\n\n",titulo5);
	printf("signed char");
  Coluna("signed char");
  printf("%lu %s\n", sizeof(signed char), sizeof(signed char)==1?"byte":"bytes");
  printf("unsigned char");
  Coluna("unsigned char");
  printf("%lu %s\n", sizeof(unsigned char), sizeof(unsigned char)==1?"byte":"bytes");
	printf("signed int");
  Coluna("signed int");
  printf("%lu %s\n", sizeof(signed int), sizeof(signed int)==1?"byte":"bytes");
  printf("unsigned int");
  Coluna("unsigned int");
  printf("%lu %s\n", sizeof(unsigned int), sizeof(unsigned int)==1?"byte":"bytes");
  ExibirSeparador();

	char titulo6[80]="Tamanhos dos Tipos Básicos combinados com Modificadores de Largura:";
	
	ExibirSeparador();
	printf ("\"%s\"\n\n",titulo6);
	printf("short int");
  Coluna("short int");
  printf("%lu %s\n", sizeof(short int), sizeof(short int)==1?"byte":"bytes");
  printf("long int");
  Coluna("long int");
  printf("%lu %s\n", sizeof(long int), sizeof(long int)==1?"byte":"bytes");
	printf("long long int");
  Coluna("long long int");
  printf("%lu %s\n", sizeof(long long int), sizeof(long long int)==1?"byte":"bytes");
  printf("long double");
  Coluna("long double");
  printf("%lu %s\n", sizeof(long double), sizeof(long double)==1?"byte":"bytes");
	ExibirSeparador();

	char titulo7[78]="Tamanhos dos Tipos Básicos combinados com Modificadres\n";
	char titulo8[78]="de sinal e com Modificadores de Largura:";
 
	ExibirSeparador();
	strcat(titulo7,titulo8);
  printf ("\"%s\"\n\n",titulo7);
	printf("short signed int");
  Coluna("short signed int");
  printf("%lu %s\n", sizeof(short signed int), sizeof(short signed int)==1?"byte":"bytes");
  printf("short unsigned int");
  Coluna("short unsigned int");
  printf("%lu %s\n", sizeof(short unsigned int), sizeof(short unsigned int)==1?"byte":"bytes");
  printf("long signed int");
  Coluna("long signed int");
  printf("%lu %s\n", sizeof(long signed int), sizeof(long signed int)==1?"byte":"bytes");
  printf("long unsigned int");
  Coluna("long unsigned int");
  printf("%lu %s\n", sizeof(long unsigned int), sizeof(long unsigned int)==1?"byte":"bytes");
	printf("long long signed int");
  Coluna("long long signed int");
  printf("%lu %s\n", sizeof(long long signed int), sizeof(long long signed int)==1?"byte":"bytes");
  printf("long long unsigned int");
  Coluna("long long unsigned int");
  printf("%lu %s\n", sizeof(long long unsigned int), sizeof(long long unsigned int)==1?"byte":"bytes");
	ExibirSeparador();
  
	return OK; /* Sucesso */
}

/* $RCSfile: aula0105.c,v $ */
