#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
//Leer traer datos desde un archivo
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* auxEmpleado;
	int retorno = -1;
	int respuesta;
	char id[20];
	char nombre[20];
	char horasTrabajadas[20];
	char salario[20];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		//HASTA ACA FUNCIONA MEDIANAMENTE BIEN
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, nombre, horasTrabajadas, salario);
		retorno = 1;
		while(!feof(pFile))
		{

			respuesta = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, nombre, horasTrabajadas, salario);

			if(respuesta == 4 && auxEmpleado != NULL)
			{
				auxEmpleado = employee_newParametros(id, nombre, horasTrabajadas, salario);
				if(auxEmpleado != NULL)
				{
					ll_add(pArrayListEmployee, auxEmpleado);
				}
			}
		}

	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee empleado;
	Employee* pEmpleado;
	int cantidad;
	int retorno = -1;

	while(!feof(pFile))
	{
		cantidad = fread(&empleado, sizeof(Employee), 1, pFile);

		if(cantidad != 1)
		{
			if(feof(pFile))
			{
				break;
			}
		}
		pEmpleado = employee_new();
		employee_setNombre(pEmpleado, empleado.nombre);
		employee_setSueldo(pEmpleado, empleado.sueldo);
		employee_setId(pEmpleado, empleado.id);
		employee_setHorasTrabajadas(pEmpleado, empleado.horasTrabajadas);
		ll_add(pArrayListEmployee, pEmpleado);
	}


    return retorno;
}
