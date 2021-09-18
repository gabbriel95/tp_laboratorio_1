#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include "utn.h"

long int PedirEntero(char mensaje[]){
	long int numero;

	printf("%s", mensaje);
	scanf("%ld", &numero);
	numero = ValidarEntero(numero,INT_MIN, INT_MAX);

	return numero;
}

double PedirDecimal(char mensaje[]){
	double numero;

	printf("%s", mensaje);
	scanf("%lf", &numero);

	return numero;
}

long int ValidarEntero(long int numero, long int rangoMinimo, long int rangoMaximo){

	while(numero < rangoMinimo || numero > rangoMaximo){
		printf("%ld esta fuera de rango calculable, intente nuevamente entre[%ld/%ld]\n",numero, rangoMinimo,rangoMaximo);
		scanf("%ld", &numero);
	}

	return numero;
}

long int ValidarDecimal(double numero, double rangoMinimo, double rangoMaximo){

	while(numero < rangoMinimo || numero > rangoMaximo){
		printf("Fuera de rango, intente nuevamente[%lf/%lf]\n", rangoMinimo,rangoMaximo);
		scanf("%lf", &numero);
	}

	return numero;
}

void MostrarResultado(char mensaje[], long int valorIngresado,long int numeroUno, long int numeroDos){

	printf("%s %ld y %ld es: %ld\n", mensaje,numeroUno,numeroDos, valorIngresado);
}

long int Suma (long int numeroUno, long int numeroDos){

	long int resultado;
	resultado = numeroUno + numeroDos;

	return resultado;
}

long int Resta(long int numeroUno, long int numeroDos){
	long int resultado;
	resultado = numeroUno - numeroDos;

	return resultado;
}

long int Multiplicacion(long int numeroUno, long int numeroDos){
	long int resultado;
	resultado = numeroUno * numeroDos;

	return resultado;
}

double Division(long int numeroUno, long int numeroDos){
	double resultado;
	resultado = (float)numeroUno / numeroDos;

	return resultado;
}


void MostrarTexto(char mensaje[]){

	printf("%s", mensaje);
}


long int Factorial (long int numero){

	long int resultado2=0;
	if(numero == 0){
		resultado2 = 1;
	}
	else
	{
	resultado2 = numero*Factorial(numero-1);
	}

	return resultado2;
}

void MostrarFactorial(long int a)
{

    printf("\nEl Factorial de %ld es: %ld\n",a,Factorial(a));
}

long int ValidarFactorial(long int numero, long int rangoMinimo, long int rangoMaximo){

	char respuesta;
	int retorno = 1;
	while(numero < rangoMinimo || numero > rangoMaximo){
		printf("\n%ld esta fuera de rango calculable para un factorial, [%ld/%ld]\n",numero, rangoMinimo,rangoMaximo);
		printf("¿Desea continuar de todas formas? [S/N]\n");
		scanf("%s", &respuesta);
		respuesta = tolower(respuesta);
		if(respuesta == 'n')
		{
			printf("Por favor, ingrese un numero nuevo que este dentro del rango par calcular el factorial [%ld/%ld:]\n", rangoMinimo,rangoMaximo);
			scanf("%ld", &numero);
		}
		else
		{
			printf("El factorial de %ld, no sera calculado\n", numero);
			retorno = 0;
			break;
		}
	}
		return retorno;
}

void MostrarResultadoFlotante(float valorIngresado,long int numeroUno, long int numeroDos)
{

	if(numeroDos == 0)
    {
        printf("\nNo es posible dividir por cero. \n");

    }else {
    	printf("\nEl resultado de la división entre %ld y %ld es: %.2lf \n",numeroUno, numeroDos, valorIngresado);
    }
}








