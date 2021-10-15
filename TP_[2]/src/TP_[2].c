/*
 * Alumno : Mendez Juan Gabriel
 * Division: 1F
 * */
#include <stdio_ext.h>
#include <stdlib.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "Utn.h"

#define CANTIDAD_EMPLEADOS 3
#define CANTIDAD_CARACTERES 21

int main(void) {

	setbuf(stdout,NULL);
	Employee listaEmpleados[CANTIDAD_EMPLEADOS];
	int opcion;
	char respuesta;

	int id = 0;
	char name[CANTIDAD_CARACTERES];
	char lastName[CANTIDAD_CARACTERES];
	float salary;
	int sector;

	int idParaBuscar;
	int orden;




	if(initEmployees(listaEmpleados, CANTIDAD_EMPLEADOS)==0)
	{
		printf("Error, al inicializar lista");
	}
	else
	{

		do
		{
			printf( "\n1. Alta de empleado\n"
					"2. Modificar empleado\n"
					"3. Baja de empleado\n"
					"4. Informar\n"
					"5. Salir\n");
			if(Utn_GetNumero(&opcion, "\nSeleccione una opcion:", "\nError, a seleccionado una opcion no valida.\n", 1, 5, 3)==1)
			{

				switch(opcion)
				{

				case 1:
						respuesta = 'S';
						while(respuesta == 'S')
						{
							if(verificarLleno(listaEmpleados, CANTIDAD_EMPLEADOS) == 0)
							{
								if(cargarUnEmpleado(CANTIDAD_CARACTERES, name, lastName, &salary, &sector)== 1)
								{
									id++;
									addEmployee(listaEmpleados, CANTIDAD_EMPLEADOS, id, name, lastName, salary, sector);

								}
								else
								{
									printf("No se cargo el empleado devido a errores en la carga\n");
								}

								printf("Desea dar de alta a otro empleado?: [S/N]");
								scanf("%c", &respuesta);
								respuesta = toupper(respuesta);
								__fpurge(stdin);

							}
							else
							{
								printf("La base de datos esta completa. Para ingresar un nuevo empleado debe eliminar a uno\n");
								break;
							}

						}



					break;
				case 2:
					if(verificarVacio(listaEmpleados, CANTIDAD_EMPLEADOS)==0)
					{
						printfEmployees(listaEmpleados, CANTIDAD_EMPLEADOS);
						Utn_GetNumero(&idParaBuscar, "\nIngrese el numero de ID del empleado a modificar\n", "Error, id no encontrado\n", 0, 1000, 3);
						modificarEmpleado(listaEmpleados, CANTIDAD_EMPLEADOS, idParaBuscar);
						mostrarUnEmpleadoPorId(listaEmpleados, CANTIDAD_EMPLEADOS, idParaBuscar);
					}
					else
					{
						printf("\n Aun no hay empleados ingresados \n");
					}
					break;
				case 3:
					if(verificarVacio(listaEmpleados, CANTIDAD_EMPLEADOS)==0)
					{
						printfEmployees(listaEmpleados, CANTIDAD_EMPLEADOS);
						Utn_GetNumero(&idParaBuscar, "\nIngrese el numero de ID del empleado a eliminar\n", "Error, id no encontrado", 0, 1000, 3);
						removeEmployee(listaEmpleados, CANTIDAD_EMPLEADOS, idParaBuscar);
						printfEmployees(listaEmpleados, CANTIDAD_EMPLEADOS);
					}
					else
					{
						printf("\n Aun no hay empleados ingresados \n");
					}
					break;
				case 4:

							if(verificarVacio(listaEmpleados, CANTIDAD_EMPLEADOS)==0)
							{
								printf( "\n1. Listar Empleados por apellido y sector"
										"\n2. Total de salarios, promedio de salarios y cantidad de empleados que superar el salario promedio"

										"\n3. Atras");


								Utn_GetNumero(&opcion, "\nSeleccione una opcion:", "\nError, a seleccionado una opcion no valida.\n", 1, 3, 3);

								switch(opcion)
								{
								case 1:
									Utn_GetNumero(&orden, "Como desea que se muestre la lista [1-UP/ 2-DOWN]: ", "Error, opcion invalida", 1, 2, 3);
									sortEmployees(listaEmpleados, CANTIDAD_EMPLEADOS, orden);
									printfEmployees(listaEmpleados, CANTIDAD_EMPLEADOS);
									break;
								case 2:
									informarDatosDeEmpleados(listaEmpleados, CANTIDAD_EMPLEADOS);
									break;
								case 3:
									break;
								default:
									printf("A ingresado una opcion invalidad, vuelva a intentarlo\n");
								}

							}
							else
							{
								printf("\n Aun no hay empleados ingresados \n");
							}

							break;

				case 5:
					printf("Gracias, vuelva pronto..");
					break;
				default:
					printf("A ingresado una opcion invalidad, vuelva a intentarlo");

				}
			}
			else
			{
				break;
			}
		}while(opcion != 5);
	}




	return EXIT_SUCCESS;
}
