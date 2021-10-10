#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>


#include "Employees.h"
#include "Utn.h"

#define CANTIDAD_EMPLEADOS 1
#define CANTIDAD_CARACTERES 51


static int cargarNombre(char name[], int len);
static int cargarApellido(char lastName[], int len);

static int modificarNombreEmpleado(Employee* list, int len, int id);
static int modificarApellidoEmpleado(Employee* list, int len, int id);
static int modificarSectorEmpleado(Employee* list, int len, int id);
static int modificarSalarioEmpleado(Employee* list, int len, int id);

static int contarEmpleados(Employee* list, int len, int* contadorEmpleados);
static int acumularSueldos(Employee* list, int len, float* acumuladorSueldos);
static void promedioSueldosEmpleados(Employee* list, int len, int contadorEmpleados, float acumuladorSueldos, float* promedio);
static int contarSueldosMayoresPromedio(Employee* list, int len, int* contadorSueldosMayoresPromedio, float promedioSueldos);



int initEmployees(Employee* list, int len)
{
	int i;
	int retorno = 0;

	for(i=0; i < len; i++)
	{
		list[i].isEmpty = 1;
		retorno = 1;
	}

	return retorno;
}


int verificarVacio(Employee* list, int len)
{
	int retorno = 1;//LA POSICION ESTA VACIA
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				retorno = 0; // AL MENOS UNO ESTA LLENO
				break;
			}

		}

	}

	return retorno;
}

int verificarLleno(Employee* list, int len)//verifica que este completo el array
{
	int retorno = 1;
	int i;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				retorno = 0;
			}
		}
	}



	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno = 0;
	int i;

	for(i=0;i<len;i++)
	{

		if(list[i].isEmpty == 1)
		{
			strncpy(list[i].name, name, 50);
			strncpy(list[i].lastName, lastName, 50);
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty = 0;
			list[i].id = id;
			break;
		}
	}


	return retorno;
}

int cargarUnEmpleado(int len, char name[], char lastName[], float* salary, int* sector)
{
	int retorno = 0;

	if(name != NULL && lastName != NULL && salary != NULL && sector != NULL && len > 0)
	{
		retorno = 1;

		if( cargarNombre(name, len) == 0 || cargarApellido(lastName, len) == 0 || Utn_GetNumeroFlotante(salary, "\nSalario del empleado: ", "\nError", 0, INT_MAX, 3) == 0 || Utn_GetNumero(sector, "\nIngrese sector del empleado", "\nError, el sector ingresaro no existe",  1, 5, 3) == 0)
		{
			retorno = 0;
		}

	}

	return retorno;
}

static int cargarNombre(char name[], int len)
{
	int retorno=0;
	char nameAux[50];

	if(name != NULL && len > 0)
	{
		if(PedirCadenaChars(nameAux, len, "\nNombre del empleado: ", "\nError, supero la cantidad de caracateres", 3)==1)
		{
			Tolower(nameAux, len);
			PrimerLetraToUpper(nameAux, len);
			strncpy(name, nameAux, len);
			retorno = 1;
		}
	}

	return retorno;
}

static int cargarApellido(char lastName[], int len)
{
	int retorno =0;
	char lastNameAux[50];
	if(lastName != NULL && len > 0)
	{
		if(PedirCadenaChars(lastNameAux, len, "\nApellido del empleado: ", "\nError, supero la cantidad de caracateres", 3)==1)
		{
			Tolower(lastNameAux, len);
			PrimerLetraToUpper(lastNameAux, len);
			strncpy(lastName, lastNameAux, len);
			retorno = 1;
		}
	}

	return retorno;
}


int printfEmployees(Employee* list, int lenght)
{
	int retorno = 0;
	int i;

	for(i=0; i<lenght; i++)
	{
		if(list[i].isEmpty == 0)
		{
			printf("\n %4d %10s %10s %5.2f %10d\n", list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector);
		}
	}

	return retorno;
}


int findEmployeeById(Employee* list, int len, int id)
{
	int retorno = 0;
	int i ;

	for(i=0; i<len; i++)
	{
		if(id == list[i].id)
		{
			retorno = 1;
			break;
		}

	}


	return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno = 0;
	int i;

	if(findEmployeeById(list, len, id) == 1)
	{
		for(i=0;i<len;i++)
		{
			if(id == list[i].id && list[i].isEmpty == 0)
			{
				list[i].isEmpty = 1;
				printf("\nEl empleado a sido removido.");
				retorno = 1;
				break;
			}
		}
	}
	else
	{
		printf("El id ingresado no existe");
	}


	return retorno;
}

int modificarEmpleado(Employee* list, int len, int id)
{
	int retorno = 0;
	int opcion;

	if(findEmployeeById(list, len, id) == 1)
	{
		printf("Que desea modificar: \n"
				"\n1. Modificar nombre"
				"\n2. Modificar apellido"
				"\n3. Modificar sector"
				"\n4. Modificar salario"
				"\n5. Modificar todo"
				"\n6. Atras");
		if(Utn_GetNumero(&opcion, "\nSelecione una opcion: ", "\nA selecionado una opcion no valida, intente nuevamente",1, 6, 3)==1)
		{

			switch(opcion)
			{
			case 1:
				if(modificarNombreEmpleado(list, len, id)==0)
				{
					printf("ERROR, el dato no a sido modificado. Vuelva a intentarlo la proxima vez");
					break;
				}
				break;
			case 2:
				if(modificarApellidoEmpleado(list, len, id)==0)
				{
					printf("ERROR, el dato no a sido modificado. Vuelva a intentarlo la proxima vez");
					break;
				}

				break;
			case 3:
				modificarSectorEmpleado(list, len, id);
				break;
			case 4:
				modificarSalarioEmpleado(list, len, id);
				break;
			case 5:
				if(modificarNombreEmpleado(list, len, id)==0)
				{
					printf("\nERROR, el dato no a sido modificado. Vuelva a intentarlo la proxima vez");
					break;
				}
				if(modificarApellidoEmpleado(list, len, id)==0)
				{
					printf("\nERROR, Algunos datos no han podido modificarse. Vuelva a intentarlo la proxima vez");
					break;
				}

				if(modificarSectorEmpleado(list, len, id)==0)
				{
					printf("\nERROR, Algunos datos no han podido modificarse. Vuelva a intentarlo la proxima vez");
					break;
				}

				if(modificarSalarioEmpleado(list, len, id)==0)
				{
					printf("\nERROR, Algunos datos no han podido modificarse. Vuelva a intentarlo la proxima vez");
					break;
				}

				break;
			case 6:
				break;
			default:
				printf("\nOpcion no valida");
			}
		}
		else
		{
			printf("Opcion no valida");
		}


	}
	else
	{
		printf("\nEl id ingresado no existe");
	}


	return retorno;

}

static int modificarNombreEmpleado(Employee* list, int len, int id)
{
	int retorno = 0;
	char nombreAux [CANTIDAD_CARACTERES];

	//printfEmployees(list, len);
	mostrarUnEmpleadoPorId(list, len, id);
	for(int i = 0; i<len; i++)
	{
		if(list[i].isEmpty == 0 && id == list[i].id)
		{
			if(PedirCadenaChars(nombreAux, CANTIDAD_CARACTERES, "\nIngrese el nuevo nombre: ", "\nError, sobrepasaste el limite de caracteres", 3)==1)
			{
				Tolower(nombreAux, len);
				PrimerLetraToUpper(nombreAux, len);
				strncpy(list[i].name, nombreAux,CANTIDAD_CARACTERES);
				retorno = 1;
			}


			break;
		}

	}

	return retorno;
}

static int modificarApellidoEmpleado(Employee* list, int len, int id)
{
	int retorno = 0;
	char apellidoAux[50];

	//printfEmployees(list, len);
	mostrarUnEmpleadoPorId(list, len, id);

	for(int i = 0; i<len; i++)
	{
		if(list[i].isEmpty == 0 && id == list[i].id)
		{
			if(PedirCadenaChars(apellidoAux, CANTIDAD_CARACTERES, "\nIngrese el nuevo apellido: ", "\nError, sobrepasaste el limite de caracteres", 3) == 1)
			{
				Tolower(apellidoAux, len);
				PrimerLetraToUpper(apellidoAux, len);
				strncpy(list[i].lastName, apellidoAux,CANTIDAD_CARACTERES);
				retorno = 1;

			}

			break;
		}

	}

	return retorno;
}

static int modificarSectorEmpleado(Employee* list, int len, int id)
{
	int retorno = 0;
	//printfEmployees(list, len);
	mostrarUnEmpleadoPorId(list, len, id);
	for(int i = 0; i<len; i++)
	{
		if(list[i].isEmpty == 0 && id == list[i].id)
		{
			if(Utn_GetNumero(&list[i].sector, "\nIngrese el nuevo sector", "\nSector no valido", 1, 5, 3)==1)
			{
				retorno = 1;
			}

			break;
		}

	}

	return retorno;
}

static int modificarSalarioEmpleado(Employee* list, int len, int id)
{
	int retorno = 0;
	//printfEmployees(list, len);
	mostrarUnEmpleadoPorId(list, len, id);

	for(int i = 0; i<len; i++)
	{
		if(list[i].isEmpty == 0 && id == list[i].id)
		{
			if(Utn_GetNumeroFlotante(&list[i].salary, "\nIngrese el nuevo salario: ", "\nRango invalido", 0, INT_MAX, 3)==1)
			{
				retorno = 1;
			}

			break;
		}

	}

	return retorno;
}


int sortEmployees(Employee* list, int len, int order)
{
	int retorno=0;
	Employee auxiliarEmpleado;
	int i;
	int flagOrdenado = 1;

	if(order == 1)
	{
		while(flagOrdenado == 1)
		{
			flagOrdenado = 0;
			for(i=1; i<len; i++)
			{
				if(strncmp(list[i].lastName,list[i-1].lastName,CANTIDAD_CARACTERES) < 0)
				{
					auxiliarEmpleado = list[i];
					list[i] = list[i-1];
					list[i-1] = auxiliarEmpleado;

					flagOrdenado = 1;
					retorno = 1;
				}
				else
				{
					if(strncmp(list[i].lastName,list[i-1].lastName,CANTIDAD_CARACTERES) == 0)
					{
						if(list[i].sector < list[i-1].sector)
						{
							auxiliarEmpleado = list[i];
							list[i] = list[i-1];
							list[i-1] = auxiliarEmpleado;

							flagOrdenado = 1;
							retorno = 1;
						}
					}
				}
			}
		}

	}
	else
	{
		while(flagOrdenado == 1)
			{
				flagOrdenado = 0;
				for(i=1; i<len; i++)
				{
					if(strncmp(list[i].lastName,list[i-1].lastName,CANTIDAD_CARACTERES) > 0)
					{
						auxiliarEmpleado = list[i];
						list[i] = list[i-1];
						list[i-1] = auxiliarEmpleado;

						flagOrdenado = 1;
						retorno = 1;
					}
					else
					{
						if(strncmp(list[i].lastName,list[i-1].lastName,CANTIDAD_CARACTERES) == 0)
						{
							if(list[i].sector > list[i-1].sector)
							{
								auxiliarEmpleado = list[i];
								list[i] = list[i-1];
								list[i-1] = auxiliarEmpleado;

								flagOrdenado = 1;
								retorno = 1;
							}
						}

					}
				}
			}

	}

	return retorno;
}


static int acumularSueldos(Employee* list, int len, float* acumuladorSueldos)
{
	int retorno = 0;
	int i;
	float acumuladorSueldosAux = 0;

	if(list != NULL)
	{
		for(i=0; i<len; i++)
		{
			acumuladorSueldosAux += list[i].salary;
			retorno = 1;
		}

		*acumuladorSueldos = acumuladorSueldosAux;
	}


	return retorno;
}

static int contarEmpleados(Employee* list, int len, int* contadorEmpleados)
{
	int retorno = 0;
	int contadorEmpleadosAux=0;

	if(list!=NULL && contadorEmpleados != NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				contadorEmpleadosAux++;
				retorno = 1;
			}

		}

		*contadorEmpleados = contadorEmpleadosAux;
	}

	return retorno;
}

static void promedioSueldosEmpleados(Employee* list, int len, int contadorEmpleados, float acumuladorSueldos, float* promedio)
{

	*promedio = acumuladorSueldos/contadorEmpleados;

}


static int contarSueldosMayoresPromedio(Employee* list, int len, int* contadorSueldosMayoresPromedio, float promedioSueldos)
{
	int retorno = 0;
	int AuxContadorSueldosMayoresPromedio=0;

	if(list != NULL && contadorSueldosMayoresPromedio != NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > promedioSueldos)
			{
				AuxContadorSueldosMayoresPromedio++;
			}

		}

		*contadorSueldosMayoresPromedio = AuxContadorSueldosMayoresPromedio;
	}

	return retorno;
}


int informarDatosDeEmpleados(Employee* list, int len)
{
	int retorno = 0;
	float promedioSueldos;
	int contadorEmpleados=0;
	float acumuladorSueldos=0;
	int contadorSueldosMayoresPromedio = 0;


	if(list != NULL && len > 0)
	{

		contarEmpleados(list, len, &contadorEmpleados);
		acumularSueldos(list, len, &acumuladorSueldos);
		promedioSueldosEmpleados(list, len, contadorEmpleados, acumuladorSueldos, &promedioSueldos);
		contarSueldosMayoresPromedio(list, len, &contadorSueldosMayoresPromedio, promedioSueldos);


		printf("La suma total de los sueldos es %.2f\n", acumuladorSueldos);
		printf("El promedio de los sueldos es %.2f\n", promedioSueldos);
		printf("La cantidad de empleados que supera el sueldo promedio es %d\n", contadorSueldosMayoresPromedio);

		retorno = 1;

	}

	return retorno;
}

int mostrarUnEmpleadoPorId(Employee* list, int lenght, int id)
{
	int retorno = 0;
	int i;

	for(i=0; i<lenght; i++)
	{
		if(list[i].isEmpty == 0 && list[i].id == id)
		{
			printf("\n %4d %10s %10s %5.2f %10d\n", list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector);
		}
	}

	return retorno;
}
