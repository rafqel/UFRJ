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
 * $Log: aula0101.c,v $
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


int main(int argc, char *argv[])
{
	int indice;
	char nome[78]="", espaco[2]=" ";
  for (indice=1; indice<argc; indice++)
  {
		if (argc-1==indice)
    {
			strcat(nome,argv[indice]);
    }
    else
    {
      strcat(nome,argv[indice]);
			strcat(nome,espaco);
    }
  }
	
	int tamanho;
	tamanho = strlen(nome);
	if (tamanho>50)
	{
		printf ("Tamanho deve ter no maximo 50 caracteres.\n");
		exit (TAMANHO_INVALIDO);
	}

  ExibirSeparador();
	int len, metade, i;
	len = strlen(nome)+2;
  metade = (80-len)/2;
  for (i=0;i<metade;i++)
  {
		printf (" ");
  }

  printf ("\"%s\"\n",nome);
  ExibirSeparador();

  return OK; /* Sucesso */
}

/* $RCSfile: aula0101.c,v $ */
