#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utn.h"
#include <limits.h>

#define TCADENA 50

/// @brief Verifica si la cadena ingresada es numerica
///
/// @param cadena Cadena de caracteres a ser analizada
/// @return retorna 1(verdadero) si la cadena es numerica, y 0  (error) si no
static int EsNumerica(char* cadena);

/// @brief
/// @param pResultado
/// @return retorno(0) if error, (1) if ok
static int GetFloat(float* pResultado);

/// @brief verifica que la cadena ingresada sea un numero flotante
/// @param cadena array de caracteres
/// @return retorno(0) if error, (1) if ok
static int EsFlotante(char* cadena);

int PedirCadenaChars(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos)
{
	char auxiliar[1000];
	int retorno = 1;


	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			MyGets(auxiliar, 1000);


			if(EsChar(auxiliar) == 0)
			{
				printf("Error, usted ingresado números.\n");
				reintentos --;
				retorno = 0;
			}
			else
			{

				if(strlen(auxiliar) > tam-1)
				{
					printf("%s\n",mensajeError);
					reintentos --;
					retorno = 0;
				}
				else
				{
					strncpy(cadena, auxiliar, TCADENA-1);
					retorno = 1;
					break;
				}

			}

			strncpy(cadena, auxiliar, TCADENA-1);

		}while(reintentos >= 0);

		if(reintentos < 0)
		{
			puts("Se quedo sin reintentos");
		}

	}

	return retorno;
}

int EsChar(char* cadena)
{
	int i=0;
	int retorno = 1;// es letra
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
		{
			if((cadena[i] < 'A' || cadena[i] > 'z') && cadena[i] != 32) // no es una letra
			{
				retorno = 0;// no es letra
				break;
			}
			i++;
		}

	}
	return retorno;
}


int MyGets(char* cadena, int longitud)
{
	int retorno = 0;
	if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin)==cadena)
	{
		__fpurge(stdin);
		if(cadena[strlen(cadena)-1] == '\n')
		{
			cadena[strlen(cadena)-1] = '\0';
		}
		retorno = 1;
	}
	return retorno;
}

int Utn_GetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = 0;
	int bufferInt;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo &&reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);

			if(GetInt(&bufferInt) == 0 && bufferInt <= maximo && bufferInt >= minimo)
			{
				*pResultado = bufferInt;
				retorno = 1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);
	}
	if(reintentos < 0)
	{
		printf("\nTe quedaste sin reintentos.\n\n");
	}

	return retorno;
}

int GetInt(int* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(MyGets(buffer, sizeof(buffer))==1 && EsNumerica(buffer))
	{
		*pResultado = atoi(buffer);
		retorno = 0;
	}

	return retorno;
}


static int EsNumerica(char* cadena)
{
	int i=0;
	int retorno = 1;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}

		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			i++;
		}

	}
	return retorno;
}




int Tolower(char nombreAPasar[], int tamArray)
{
	int retorno = 1;
	int i;
	char aux[51];

	strncpy(aux,nombreAPasar,tamArray);

	for(i=0; i<tamArray; i++)
	{
		aux[i] = tolower(aux[i]);
	}

	strncpy(nombreAPasar,aux,tamArray);

	return retorno;
}

int PrimerLetraToUpper(char nombreAPasar[], int tamArray)
{
	int retorno = 1;
	char aux[51];

	strncpy(aux,nombreAPasar,tamArray);

	aux[0] = toupper(aux[0]);

	strncpy(nombreAPasar,aux,tamArray);

	return retorno;
}



int Utn_GetNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = 0;
	float bufferFloat;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo &&reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);

			if(GetFloat(&bufferFloat) == 0 && bufferFloat <= maximo && bufferFloat >= minimo)
			{
				*pResultado = bufferFloat;
				retorno = 1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}

		}while(reintentos >= 0);
	}

	return retorno;
}

static int EsFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		if(cadena[0] == '-')
		{
			i = 1;
		}

		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
			i++;
		}

	}
	return retorno;
}

static int GetFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];

	if(MyGets(buffer, sizeof(buffer))==1 && EsFlotante(buffer))
	{
		*pResultado = atof(buffer);
		retorno = 0;
	}

	return retorno;
}


