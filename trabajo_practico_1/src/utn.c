#include <stdio.h>
#include <stdlib.h>

int PedirEntero(char mensaje[]){
	int numero;

	printf("%s", mensaje);
	scanf("%d", &numero);

	return numero;
}

int ValidarEntero(int numero, int rangoMinimo, int rangoMaximo){

	while(numero < rangoMinimo || numero > rangoMaximo){
		printf("Fuera de rango, intente nuevamente[%d/%d]\n", rangoMinimo,rangoMaximo);
		scanf("%d", &numero);
	}

	return numero;
}

void MostrarEntero(char mensaje[], int valorIngresado){

	printf("%s%d", mensaje, valorIngresado);
}

int Suma (int numeroUno, int numeroDos){

	int resultado;
	resultado = numeroUno + numeroDos;

	return resultado;
}

int Resta(int numeroUno, int numeroDos){
	int resultado;
	resultado = numeroUno + numeroDos;

	return resultado;
}

int Multiplicacion(int numeroUno, int numeroDos){
	int resultado;
	resultado = numeroUno * numeroDos;

	return resultado;
}

int division(int numeroUno, int numeroDos){
	int resultado;
	resultado = numeroUno / numeroDos;

	return resultado;
}

int Factorial (int numeroUno){

	int resultado;
	if(numeroUno == 0){
		resultado = 1;
	}
	else
	{
	resultado = numeroUno*Factorial(numeroUno-1);
	}

	return resultado;
}
