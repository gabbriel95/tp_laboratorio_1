#include <stdio.h>
#include <stdlib.h>

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
		printf("Fuera de rango, intente nuevamente[%d/%d]\n", rangoMinimo,rangoMaximo);
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

void MostrarEntero(char mensaje[], int valorIngresado){

	printf("%s%d", mensaje, valorIngresado);
}

void MostrarDecimal(char mensaje[], float valorIngresado){
	printf("%s%f", mensaje, valorIngresado);
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

	resultado = 1;

	for(int i = 1; i <= numero; i++){
		resultado = resultado * numero;
	}


	return resultado;
}

void MostrarTexto(char mensaje[]){

	printf("%s", mensaje);
}

void MostrarDivision(float a, float b){

	if(b == 0)
    {
        printf("\nNo es posible dividir por cero. \n");

    }else {
    	printf("\nEl resultado de la división es: %.2f \n", Division(a, b));
	}

}
