#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Utn.h"

void controller_listSingleEmployee(LinkedList* pArrayListEmployee,int id);
Employee* buscarEmpleadoPorId(LinkedList* this, int id);
int employee_GeneradorId(LinkedList* pArrayListEmployee);
int buscarMaximoId(LinkedList* pArrayListEmployee, int* maximoId);
int controller_findIndexEmployee(LinkedList* pArrayListEmployee, int id);
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* archivoDatos = fopen(path, "r+");

	if(archivoDatos != NULL && pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);
		parser_EmployeeFromText(archivoDatos, pArrayListEmployee);
		puts("\nModo texto cargado correctamente\n");

	}
	else
	{
		puts("\nNo se pudo realizar la carga\n");
	}

	fclose(archivoDatos);
    return 1;
}





/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* datosBinarios;

	datosBinarios = fopen(path, "rb");

	if(pArrayListEmployee != NULL)
	{
		ll_clear(pArrayListEmployee);
	}

	if(datosBinarios != NULL)
	{
		parser_EmployeeFromBinary(datosBinarios, pArrayListEmployee);
		puts("\n Datos cargados correctamente\n");
	}
	else
	{
		puts("\nError de carga de archivo binario");
	}

	fclose(datosBinarios);
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int id;
	int retorno = 1;
	int hsTrabajadas = 0;
	int salario = 0;
	char name[51];

	Employee* auxiliarEmpleado = employee_new();

	ll_sort(pArrayListEmployee, employee_CompareById, 1);

	if(pArrayListEmployee != NULL)
	{
		id = employee_GeneradorId(pArrayListEmployee);
		employee_setId(auxiliarEmpleado, id);
		employee_SolicitarNombre(name, auxiliarEmpleado);
		employee_SolicitarSalario(salario, auxiliarEmpleado);
		employee_SolicitarHorasTrabajadas(hsTrabajadas, auxiliarEmpleado);
		retorno = 0;
		ll_add(pArrayListEmployee, auxiliarEmpleado);
		//ll_sort(pArrayListEmployee, employee_CompareById, 1);
	}else
	{
		puts("\n Primero cargue una lista\n");
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int tamLista = ll_len(pArrayListEmployee);
	int idABuscar;
	int retorno = -1;

	Employee* auxEmpleado;

	if(pArrayListEmployee != NULL)
	{
		retorno = 0;
		if(Utn_GetNumero(&idABuscar, "\nIngrese el id del empleado a modificar: ", "\n Error, el no existe", 1, tamLista, 3) == 1)
		{
			retorno = 1;
			auxEmpleado  = ll_get(pArrayListEmployee, idABuscar);

			employee_SolicitarNombre(auxEmpleado->nombre, auxEmpleado);
			employee_SolicitarSalario(auxEmpleado->sueldo, auxEmpleado);
			employee_SolicitarHorasTrabajadas(auxEmpleado->horasTrabajadas, auxEmpleado);
		}


	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int id;
	int posicionEmpleado;
	int maximoId;
	int respuesta;

	Employee* auxEmpleado;

	if(pArrayListEmployee != NULL)
	{
		buscarMaximoId(pArrayListEmployee, &maximoId);
		Utn_GetNumero(&id, "\nIngrese el id del emplado que desea eliminar: ", "\nError, el id ingresado no existe en la base de datos", 1, maximoId, 3);
		auxEmpleado  = (Employee*)ll_get(pArrayListEmployee, id);
		controller_listSingleEmployee(pArrayListEmployee,auxEmpleado->id);
		posicionEmpleado = controller_findIndexEmployee(pArrayListEmployee, id);
		printf("%d",posicionEmpleado);

		do
		{
			if(Utn_GetNumero(&respuesta, "\nEsta seguro que desea eliminar al empleado? 1-SI / 2-NO ", "\nError, ingrese 1 para si, 2 para no", 1, 2, 3)==1)
			{
				if(respuesta == 1)
				{
					printf("\n El empleado con id %d a sido eliminado\n",id);
					ll_remove(pArrayListEmployee, posicionEmpleado);
				}
				else
				{
					break;
				}
			}
			else
			{
				puts("\nTe quedaste sin reintentos");
			}

		}
		while(respuesta != 1 && respuesta != 2);
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;

	if(pArrayListEmployee != NULL)
	{
		for(int i=0; i<ll_len(pArrayListEmployee); i++)
		{
			controller_listSingleEmployee(pArrayListEmployee,i);
			retorno = 1;
		}
	}
	else
	{
		puts("\n No hay ninguna lista para mostrar\n");
	}
    return retorno;
}

void controller_listSingleEmployee(LinkedList* pArrayListEmployee,int id)
{
	Employee* pEmpleado;
	int auxId = 0;
	int auxHs = 0;
	char auxName[51];
	int auxSalario = 0;

	if(pArrayListEmployee != NULL)
	{
		pEmpleado = ll_get(pArrayListEmployee, id);

		if(pEmpleado != NULL)
		{
			auxId = employee_getId(pEmpleado);
			employee_getHorasTrabajadas(pEmpleado, &auxHs);
			employee_getNombre(pEmpleado, auxName);
			employee_getSueldo(pEmpleado,&auxSalario);
			printf("%5d %20s %16d %25d\n", auxId, auxName, auxHs, auxSalario);
		}

	}
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int respuesta;

	if(pArrayListEmployee != NULL)
	{
		if(Utn_GetNumero(&respuesta, "\n¿Cómo desea ordenar?\n1-Por nombre\n2-Por ID\n Por favor, seleccione una opcion:", "\nOpcion no valida\n", 1, 2, 3)==1)
		{
			if(respuesta == 1)
			{
				if(Utn_GetNumero(&respuesta, "\n¿Cómo desea ordenar?\n1)A-Z\n2)Z-A\n Por favor, seleccione una opcion:", "\nOpcion no valida\n", 1, 2, 3)==1)
				{
					puts("\n Este proceso puede tardar bastante tiempo, por favor tenga paciencia\n");

					if(respuesta == 1)
					{
						ll_sort(pArrayListEmployee, employee_CompareByName, 1);
					}
					else if(respuesta == 2)
					{
						ll_sort(pArrayListEmployee, employee_CompareByName, 0);
					}
				}
			}
			else if (respuesta == 2)
			{
				if(Utn_GetNumero(&respuesta, "\n¿Cómo desea ordenar?\n1)1 a 100\n2)100 a 1\n Por favor, seleccione una opcion:", "\nOpcion no valida\n", 1, 2, 3)==1)
				{
					puts("\n Este proceso puede tardar bastante tiempo, por favor tenga paciencia\n");

					if(respuesta == 1)
					{
						ll_sort(pArrayListEmployee, employee_CompareById, 1);
					}
					else if(respuesta == 2)
					{
						ll_sort(pArrayListEmployee, employee_CompareById, 0);
					}
				}
			}
			puts("\nOrdenamiento completado");
		}

	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int id;
	int salario;
	int horas;
	char nombre[51];
	int tamLista = ll_len(pArrayListEmployee);
	Employee* auxEmpleado;
	pArchivo = fopen(path,"w");

	if(pArchivo != NULL)
	{
		for(int i=0; i<tamLista; i++)
		{
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

			if(auxEmpleado != NULL)
			{
				id = employee_getId(auxEmpleado);
				employee_getNombre(auxEmpleado, nombre);
				employee_getSueldo(auxEmpleado, &salario);
				employee_getHorasTrabajadas(auxEmpleado, &horas);
				fprintf(pArchivo, "%d,%s,%d,%d\n",id,nombre,horas,salario);
			}

		}
			ll_clear(pArrayListEmployee);
			puts("\n Exito al guardar en modo texto\n");
			fclose(pArchivo);
	}
	else
	{
		puts("\n No se pudo abrir el archivo\n");
	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	Employee* auxEmpleado;
	int retorno = -1;
	int tamanioLista = ll_len(pArrayListEmployee);
	printf("%d", tamanioLista);

	pArchivo = fopen(path,"wb");

	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		for(int i=0; i<tamanioLista; i++)
		{
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			if(auxEmpleado != NULL)
			{
				fwrite(auxEmpleado, sizeof(Employee),1,pArchivo);
			}
		}
		puts("\nDatos guardados correctamente en modo binario");
		retorno  = 1;
		ll_clear(pArrayListEmployee);
		fclose(pArchivo);
	}
	else
	{
		puts("\n No se pudo guardar\n");
	}

    return retorno;;
}

int employee_GeneradorId(LinkedList* pArrayListEmployee)//RARO
{
	int length = ll_len(pArrayListEmployee);//cuenta cuantos elementos hay en lista
	int id = length +1 ;

	Employee* auxEmpleado;

	for(int i=0; i<length; i++)
	{
		auxEmpleado = ll_get(pArrayListEmployee, length);//devuelve un elemento de la lista
		if(employee_getId(auxEmpleado) != i + 1)
		{
			id = length;
			break;
		}
	}

	return id;
}

Employee* buscarEmpleadoPorId(LinkedList* this, int id)
{
	Employee* empleado;
	int tamanio = ll_len(this);

	if(this != NULL && id > 0)
	{
		for(int i = 0; i<tamanio; i++)
		{
			empleado = ll_get(this,i);

			if(employee_getId(empleado) == id)
			{
				break;
			}
		}
	}

	return empleado;
}

int buscarMaximoId(LinkedList* pArrayListEmployee, int* maximoId)
{
	int retorno = -1;
	int idAux;
	int tamanioLista = ll_len(pArrayListEmployee);
	Employee* auxEmpleado;

	if(pArrayListEmployee != NULL)
	{
		retorno = 1;
		for(int i=0; i<tamanioLista; i++)
		{
			auxEmpleado = ll_get(pArrayListEmployee, i);
			if(i==0)
			{
				idAux = employee_getId(auxEmpleado);
			}
			else
			{
				if(employee_getId(auxEmpleado) > idAux)
				{
					idAux = employee_getId(auxEmpleado);
				}
			}

		}

		*maximoId =  idAux;
	}

	return retorno;
}

int controller_findIndexEmployee(LinkedList* pArrayListEmployee, int id)
{
	Employee* pEmployee;
	int retorno;
	int idAux;
	int tamanioLista = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL)
	{
		for(int i=0; i<tamanioLista; i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee,i);

			if(pEmployee != NULL)
			{
				idAux = employee_getId(pEmployee);
				if(id == idAux)
				{
					retorno = i;
					break;
				}
			}
		}
	}

	return retorno;
}
