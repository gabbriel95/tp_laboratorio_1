#include <stdio.h>
#include <stdlib.h>

#include "utn.h"


int main(void) {

	int a;
	int b;
	int resultado;
	int resultadoB;

	printf("Bienvenido a Basic Calculator\n\n");


	int opcion;

	do
	{
		printf("\n1.Ingresar 1er operando");
		printf("\n2.Ingresar 2do operando");
		printf("\n3.Seleccione operador");
		printf("\n4.Salir\n");
		printf("\nIngrese una opcion:");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				a = PedirEntero("Ingrese el valor para A: ");

				break;
			case 2:
				b = PedirEntero("\nIngrese el valor para B: ");

				break;
			case 3:
				printf("\n1.Suma\n");
				printf("2.Resta\n");
				printf("3.Division\n");
				printf("4.Multiplicacion\n");
				printf("5.Factorial\n");
				printf("6.Atras\n");
				printf("Ingrese una opcion: ");
				scanf("%d", &opcion);

				switch(opcion)
				{
				case 1:
					resultado = Suma(a, b);
					MostrarEntero("\nEl resultado de la suma es: ", resultado);
					break;
				case 2:
					resultado = Resta(a, b);
					MostrarEntero("\nEl resultado de la resta es: ", resultado);
					break;
				case 3:
					resultado = Division(a, b);
					MostrarDivision(a, b);
					break;
				case 4:
					resultado =Multiplicacion(a, b);
					MostrarEntero("\nEl resultado de la multiplicacion es: ", resultado);
					break;
				case 5:
					resultado = Factorial(a);
					resultadoB = Factorial(b);
					MostrarEntero("\nEl resultado de es: \n", resultado);
					break;
				case 6:
					break;
				}

				break;
			case 4:
				printf("Gracias por usar Basic Calculator");
				break;
		}

	}while(opcion != 4);


	return EXIT_SUCCESS;
}
