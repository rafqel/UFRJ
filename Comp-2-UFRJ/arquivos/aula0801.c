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
 * $Log: aula0801.c,v $
 * Revision 1.6  2021/10/02 08:35:13  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Incremento da funcao DecodificarBase64.
 *
 * Revision 1.5  2021/10/02 06:40:18  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao de condicional na funcao CodificarBase64.
 *
 * Revision 1.4  2021/10/02 04:55:49  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Correcao da funcao CodificarBase64.
 *
 * Revision 1.3  2021/10/01 17:19:23  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Inclusao da funcao CodificarBase64.
 *
 * Revision 1.2  2021/09/30 03:21:41  rafael.jesus
 * EEL270 - Computacao II - Turma 2021/1.
 * Incremento da funcao DecodificarBase16.
 *
 * Revision 1.1  2021/09/29 21:45:36  rafael.jesus
 * Initial revision
 *
 */

#include "aula0801.h"
#include <string.h>
#include <stdio.h>

tipoErros
CodificarBase16 (byte *conjuntoBytes /* (E) */,
								unsigned long long numBytes /* (E) */,
								char *string /* (S) */)
{
	unsigned indice;
	byte indiceAuxiliar;


	if (!conjuntoBytes)
		return nulo; 

	for (indiceAuxiliar = indice = 0 ; indiceAuxiliar < numBytes ; indiceAuxiliar++)
	{
		string[indice] = (conjuntoBytes[indiceAuxiliar] >> 4) & (0X0F);
		string[indice + 1] = (conjuntoBytes[indiceAuxiliar]) & (0X0F); 
		indice += 2;
	}
	
	string[indice] = END_OF_STRING;
	
	return ok;
}


tipoErros
DecodificarBase16 (char *string /* (E) */,
									byte *conjuntoBytes /* (S) */,
									unsigned long long *numBytes /*  (S) */)
{
	unsigned indice1,indice2,indiceHex,indiceAuxiliar;
	byte indice;

	if (!string)
		return nulo;	

	for (indice = indiceAuxiliar = 0 ; indice < numBytes[0] ; indice++)
	{
		for (indiceHex = 0 ; indiceHex < 16 ; indiceHex++)
		{
			if (BASE_16[indiceHex] == string[indiceAuxiliar])
				indice1 = indiceHex;
			if (BASE_16[indiceHex] == string[indiceAuxiliar+1])
				indice2 = indiceHex;
		}
		conjuntoBytes[indice] =  indice1 * 16 + indice2;
		indiceAuxiliar +=2;
	}


	return ok;
}


tipoErros
CodificarBase64 (byte *conjuntoBytes /* (E) */,
								unsigned long long numBytes /*  (E) */,
								tipoFinalLinha indicador /* (E) */,
								char *string /* (S) */)
{
	unsigned indice, indiceAuxiliar, numConjunto;
	byte contador;

	if (!conjuntoBytes)
		return nulo; 

	numConjunto = (numBytes / 3);
	if ((numBytes % 3) != 0)
		numConjunto += 1; 

	for (indice = indiceAuxiliar = contador = 0 ; contador < numConjunto ; contador++)
	{
		/* CARACTERE 1 */
		string[indice] = (char) BASE_64 [ (conjuntoBytes[indiceAuxiliar] >> 2) ];

		/* CARACTERE 2 */
		string[indice + 1] = (char) BASE_64 [ ((conjuntoBytes[indiceAuxiliar] & 0x03) << 4) |\
																	((conjuntoBytes[indiceAuxiliar + 1] & 0xf0) >> 4) ];
		/* CARACTERE 3 */
		string[indice + 2] = (char) BASE_64 [ ((conjuntoBytes[indiceAuxiliar + 1] & 0x0f) << 2) |\
																		((conjuntoBytes[indiceAuxiliar + 2] & 0xc0) >> 6) ];
		/* CARACTERE 4*/
		string[indice + 3] = (char) BASE_64 [ (conjuntoBytes[indiceAuxiliar + 2] & 0X3F) ];

		/* \/ PADDING '=' \/ ---------------------------------------------------------------- */

		if (contador == numConjunto - 1) {
			if (numBytes % 3 == 1) {
				conjuntoBytes[indiceAuxiliar + 1] = 0x00;
				string[indice + 2] = '=';
				string[indice + 3] = '=';
			}
		}

		else if (((contador == numConjunto - 1) && (numBytes % 3 != 1)) ||\
	  (contador != numConjunto - 1)){
			if ((numBytes % 3) == 2)
				string[indice + 3] = '=';
		}

		/* /\ PADDING '=' /\ ---------------------------------------------------------------- */

		indice += 4;
		indiceAuxiliar += 3;
	}

	string[indice + 1] = END_OF_STRING;

	return ok;
}


tipoErros
DecodificarBase64 (char *string /* (E) */,
									tipoFinalLinha indicador /* (E) */,
									byte *conjuntoBytes /* (S) */,
									unsigned long long *numBytes /* (S) */)
{
	unsigned indiceEntrada, indiceSaida, contador;

	if (!string)
		return nulo; 

	for (indiceEntrada = indiceSaida = contador = 0 ; contador < numBytes[0]; contador++){

		conjuntoBytes[indiceSaida] = (string [indiceEntrada] << 2 |\
																	string [indiceEntrada + 1] >> 4);

		conjuntoBytes[indiceSaida + 1] = (string [indiceEntrada + 1] << 4 |\
																			string [indiceEntrada + 2] >> 2);

		conjuntoBytes[indiceSaida + 2] =	(((string [indiceEntrada + 2] << 6) & 0xc0) |\
																				string [indiceEntrada + 3]);

		indiceEntrada += 4;
		indiceSaida += 3;
	}

	return ok;
}


/* $RCSfile: aula0801.c,v $ */
