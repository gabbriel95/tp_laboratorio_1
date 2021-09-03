#include <stdio.h>
#include <stdlib.h>

#include "utn.h"


int main(void) {

	int a;
	int b;
	int resultado;

	printf("Bienvenido a Basic Calculator\n\n");


	int opcion;
	int opcion2;

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
				a = PedirEntero("\nIngrese el valor para A: ");

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
				scanf("%d", &opcion2);

				switch(opcion2)
				{
				case 1:
					resultado = Suma(a, b);
					MostrarEntero("\nEl resultado de la suma entre", resultado,a,b);
					break;
				case 2:
					resultado = Resta(a, b);
					MostrarEntero("\nEl resultado de la resta entre", resultado,a,b);
					break;
				case 3:
					resultado = Division(a, b);
					MostrarDivision(a, b);
					break;
				case 4:
					resultado = Multiplicacion(a, b);
					MostrarEntero("\nEl resultado de la multiplicacion entre", resultado,a,b);
					break;
				case 5:
					a =ValidarEntero(a, 0, 10);
					b =ValidarEntero(b,0,10);
					MostrarFactorial(a, b);
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
