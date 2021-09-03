#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int PedirEntero(char mensaje[]){
	int numero;

	printf("%s", mensaje);
	scanf("%d", &numero);

	return numero;
}

float PedirDecimal(char mensaje[]){
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);

	return numero;
}

int ValidarEntero(int numero, int rangoMinimo, int rangoMaximo){

	while(numero < rangoMinimo || numero > rangoMaximo){
		printf("%d esta fuera de rango calculable, intente nuevamente entre[%d/%d]\n",numero, rangoMinimo,rangoMaximo);
		scanf("%d", &numero);
	}

	return numero;
}

int ValidarDecimal(float numero, float rangoMinimo, float rangoMaximo){

	while(numero < rangoMinimo || numero > rangoMaximo){
		printf("Fuera de rango, intente nuevamente[%f/%f]\n", rangoMinimo,rangoMaximo);
		scanf("%f", &numero);
	}

	return numero;
}

void MostrarResultado(char mensaje[], int valorIngresado,int numeroUno, int numeroDos){

	printf("%s %i y %i es: %d\n", mensaje,numeroUno,numeroDos, valorIngresado);
}

int Suma (int numeroUno, int numeroDos){

	int resultado;
	resultado = numeroUno + numeroDos;

	return resultado;
}

int Resta(int numeroUno, int numeroDos){
	int resultado;
	resultado = numeroUno - numeroDos;

	return resultado;
}

int Multiplicacion(int numeroUno, int numeroDos){
	int resultado;
	resultado = numeroUno * numeroDos;

	return resultado;
}

float Division(int numeroUno, int numeroDos){
	float resultado;
	resultado = (float)numeroUno / numeroDos;

	return resultado;
}

int Factorial (int numero){

	int resultado;
	if(numero == 0){
		resultado = 1;
	}
	else
	{
	resultado = numero*Factorial(numero-1);
	}

	return resultado;
}

void MostrarTexto(char mensaje[]){

	printf("%s", mensaje);
}

void MostrarDivision(int a, int b){


	if(b == 0)
    {
        printf("\nNo es posible dividir por cero. \n");

    }else {
    	printf("\nEl resultado de la división entre %d y %d es: %.2f \n",a, b, Division(a, b));
	}

}


void MostrarFactorial(int a, int b)
{

    printf("\nEl Factorial de %d es: %d   \nEl Factorial de %d es: %d \n",a,Factorial(a),b, Factorial(b));
}

