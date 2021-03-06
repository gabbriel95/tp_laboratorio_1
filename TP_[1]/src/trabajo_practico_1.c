#include <stdio_ext.h>
#include <stdlib.h>
#include <limits.h>

#include "utn.h"


int main(void) {

	long int a;
	long int b;
	long int resultadoSuma;
	long int resultadoResta;
	long int resultadoMultiplicacion;
	float resultadoDivision;

	int flagIngresoNumeroUno = 0;
	int flagIngresoNumeroDos = 0;
	int flagCalculoResultados = 0;
	int flagFactorialA = 0;
	int flagFactorialB = 0;

	printf("Bienvenido a Basic Calculator\n\n");


	int opcion;
	do
	{
		printf("---------------------------------------------------------------------------------------------------\n");
		printf("\n1.Ingresar 1er operando");
		printf("\n2.Ingresar 2do operando");
		printf("\n3.Calcular todas las operaciones");
		printf("\n4.Informar Resultados");
		printf("\n5.Salir\n");
		printf("\nIngrese una opcion:");
		scanf("%d", &opcion);
		__fpurge(stdin);
		printf("---------------------------------------------------------------------------------------------------\n");


		switch(opcion)
		{
			case 1:
				a = PedirEntero("\nIngrese el valor para A: ");
				flagIngresoNumeroUno = 1;

				break;
			case 2:
				b = PedirEntero("\nIngrese el valor para B: ");
				flagIngresoNumeroDos = 1;

				break;
			case 3:
				if(flagIngresoNumeroUno == 1 && flagIngresoNumeroDos == 1)
				{
				flagCalculoResultados = 1;
				resultadoSuma = Suma(a, b);
				resultadoResta = Resta(a, b);
				resultadoDivision = Division(a, b);
				resultadoMultiplicacion = Multiplicacion(a, b);
				flagFactorialA=ValidarFactorial(a, 0,22);
				flagFactorialB=ValidarFactorial(b,0, 22);

				printf("\nLos operaciones han sido calculadas correctamente\n");

				}
				else
				{
					printf("Primero debe ingresaron los valores de A y B en las opciones 1 y 2 respectivamente\n");
				}
				break;
			case 4:

				if(flagCalculoResultados == 1)
				{


					MostrarResultado("\nEl resultado de la suma entre", resultadoSuma,a,b);

					MostrarResultado("\nEl resultado de la resta entre", resultadoResta,a,b);

					MostrarResultadoFlotante(resultadoDivision, a, b);

					MostrarResultado("\nEl resultado de la multiplicacion entre", resultadoMultiplicacion,a,b);

					if(flagFactorialA == 1)
					{
						MostrarFactorial(a);
					}
					if(flagFactorialB == 1)
					{
						MostrarFactorial(b);
					}


				}
				else
				{
					printf("Primero debe calcular las operaciones en la opcion 3, previamente haber ingresado los numeros en las opciones 1 y 2\n");
				}

				break;
			case 5:
				printf("Gracias por usar Basic Calculator");
				break;
			default: printf("Error, opcion invalida\n");
		}

	}while(opcion != 5);


	return EXIT_SUCCESS;
}
