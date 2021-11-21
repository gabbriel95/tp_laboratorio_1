#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Utn.h"



Employee* employee_new()
{
	Employee* this = (Employee*) malloc(sizeof(Employee));

	if(this != NULL)
	{
		return this;
	}
	else
	{
		puts("\n No se pudo asignar espacio en memoria");
		exit(0);
	}


}


int employee_setId(Employee* this, int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int employee_getId(Employee* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->id;
	}

	return retorno;

}

int employee_setSueldo(Employee* this, int sueldo)
{
	int setea = -1;

	if(this != NULL)
	{
		this->sueldo = sueldo;
		setea = 0;
	}

	return setea;
}

int employee_getSueldo(Employee* this, int* sueldo) // PREGUNTAR PORQUE ESTO NO FUNCIONA!!!!
{
	int retorno = -1;
	if(this != NULL)
	{
		*sueldo = this->sueldo;
		retorno  = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int setea = -1;
	if(this != NULL)
	{
		setea = 0;
		this->horasTrabajadas = horasTrabajadas;
	}

	return setea;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno  = 0;
	}
	return retorno;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salaryStr)
{
	int id;
	int sueldo;
	int horasTrabajadas;
	Employee* auxEmpleado;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && salaryStr != NULL)
	{
		id = atoi(idStr);
		sueldo = atoi(salaryStr);
		horasTrabajadas = atoi(horasTrabajadasStr);

		auxEmpleado = employee_new();

		if(auxEmpleado != NULL)
		{
			employee_setId(auxEmpleado, id);
			employee_setNombre(auxEmpleado, nombreStr);
			employee_setSueldo(auxEmpleado, sueldo);
			employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas);
		}


	}

	return auxEmpleado;
}



int employee_CompareByName(void* pEmpleadoA, void* pEmpleadoB)
{
	int retorno = 0;
	Employee* e1;
	Employee* e2;

	e1 =(Employee*) pEmpleadoA;
	e2 =(Employee*) pEmpleadoB;

	if(strcmp(e1->nombre, e2->nombre) >0)
	{
		retorno =  1;
	}
	else
	{
		if(strcmp(e1->nombre, e2->nombre) < 0)
		{
			retorno = -1;
		}
	}

	return retorno;
}

int employee_CompareById(void* pEmpleadoA, void* pEmpleadoB)
{
	int retorno = 0;

	Employee* e1;
	Employee* e2;

	e1 =(Employee*) pEmpleadoA;
	e2 =(Employee*) pEmpleadoB;

	if(e1->id > e2->id)
	{
		retorno = 1;
	}
	else
	{
		if(e1->id < e2->id)
		{
			retorno = -1;
		}
	}

	return retorno;
}

int employee_SolicitarNombre(char* name, Employee* empleado)
{
	int retorno = -1;

	if(name != NULL && empleado != NULL)
	{
		if(PedirCadenaChars(name, 51, "\nIngrese el nombre: ", "\nError\n", 3) == 1)
		{
			employee_setNombre(empleado, name);
			retorno = 1;
		}
	}

	return retorno;
}

int employee_SolicitarSalario(int salario, Employee* empleado)
{
	int retorno = -1;

	if(empleado != NULL)
	{
		if(Utn_GetNumero(&salario, "\nIngrese el sueldo: ", "Error",  0, 200000, 3) == 1)
		{
			employee_setSueldo(empleado, salario);
			retorno = 1;
		}
	}

	return retorno;
}

int employee_SolicitarHorasTrabajadas(int horas, Employee* empleado)
{
	int retorno = -1;

	if(empleado != NULL)
	{
		if(Utn_GetNumero(&horas, "\nIngrese horas trabajadas:", "Error",  12, 72, 3) == 1)
		{
			employee_setHorasTrabajadas(empleado, horas);
			retorno = 1;
		}
	}

	return retorno;
}


