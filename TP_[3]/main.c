#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Utn.h"

/****************************************************
 * Alumno: Mendez Juan Gabriel
 * Division:1F
    Menu:
ok     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
ok     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
ok     3. Alta de empleado
ok     4. Modificar datos de empleado
ok     5. Baja de empleado
ok     6. Listar empleados
ok    7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	int opcion;
	LinkedList* listaEmpleados = ll_newLinkedList();

	do
	    {
		printf( "\n1. Cargar datos desde archivo modo texto\n"
				"2. Cargar datos desde archivo modo binario\n"
				"3. Alta de empleados\n"
				"4. Modificar datos de empleado\n"
				"5. Baja de empleado\n"
				"6. Listar empleados\n"
				"7. Ordenar empleados\n"
				"8. Guardar modo texto\n"
				"9. Guardar modo binario\n"
				"10. Salir\n");

			Utn_GetNumero(&opcion, "\nSeleccione una opcion\n", "\n Error, opcion no valida", 1, 10, 3);

			switch(opcion)
	        {
	        case 1:
	        	controller_loadFromText("data.csv", listaEmpleados);
	            break;

	        case 2:
	        	controller_loadFromBinary("data.bin", listaEmpleados);
	            break;

	        case 3:
	        	controller_addEmployee(listaEmpleados);
	            break;

	        case 4:
	        	controller_editEmployee(listaEmpleados);
	            break;

	        case 5:
	        	controller_removeEmployee(listaEmpleados);
	            break;

	        case 6:
	        	controller_ListEmployee(listaEmpleados);
	            break;

	        case 7:
	        	controller_sortEmployee(listaEmpleados);
	            break;

	        case 8:
	        	controller_saveAsText("data.csv", listaEmpleados);
	            break;

	        case 9:
	        	controller_saveAsBinary("data.bin", listaEmpleados);
	            break;

	        case 10:

	            break;
	        }

	    }
	    while(opcion != 10);


    return 0;
}

