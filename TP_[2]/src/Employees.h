#ifndef EMPLOYEES_H_
#define EMPLOYEES_H_

typedef struct
{
	int id;
	char lastName[51];
	char name[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);


int cargarUnEmpleado(int len, char name[], char lastName[], float* salary, int* sector);
int printfEmployees(Employee* list, int lenght);
int mostrarUnEmpleadoPorId(Employee* list, int lenght, int id);

int removeEmployee(Employee* list, int len, int id);

int modificarEmpleado(Employee* list, int len, int id);


int verificarVacio(Employee* list, int len);
int verificarLleno(Employee* list, int len);


int sortEmployees(Employee* list, int len, int order);




int informarDatosDeEmpleados(Employee* list, int len);



#endif
