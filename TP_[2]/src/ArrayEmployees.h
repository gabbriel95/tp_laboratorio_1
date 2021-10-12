#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char lastName[51];
	char name[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

/// @brief Recorre el array e inicializa sus posiciones en 1 (vacio)
/// @param list Array
/// @param len Tamaño Array
/// @return return(1) ok --- return(0) Error, no pudo inicializar las posiciones
int initEmployees(Employee* list, int len);

/// @brief Da de alta a un empleado con los valores recibidos por parametros
/// @param list Array de empleados
/// @param len Tamaño array
/// @param id Identificador de empleado
/// @param name Nombre del empleado
/// @param lastName Apellido del empleado
/// @param salary Salario del empleado
/// @param sector Sector donde trabaja el empleado
/// @return retorno (0) Ocurrio un error, no hay posiciones vacias ---- (1) Dio de alta los datos
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/// @brief Solicita la informacion de un empleado y las devuelve a traves de punteros
/// @param len Cantidad de caracteres de nombre y apellido
/// @param name puntero a Nombre del empleado
/// @param lastName puntero a Apellido del empleado
/// @param salary puntero a Salario del empleado
/// @param sector puntero a Sector donde trabaja el empleado
/// @return retorno (0) ocurrio un error en la carga de datos   (1) Datos cargados satisfactoriamente
int cargarUnEmpleado(int len, char name[], char lastName[], float* salary, int* sector);

/// @brief Imprime la lista de empleados
/// @param list Array empleados
/// @param lenght tamaño array
/// @return retorno(0) No pudo imprimir por pantalla (1) Datos mostrados satisfactoriamente
int printfEmployees(Employee* list, int lenght);

/// @brief Muenstra los datos del empleado, usando al ID como referencia
/// @param list Listas de empleados
/// @param lenght tamaño de array
/// @param id ID del empleado
/// @return retorno (0) Error, no pudo encontrar el empleado   (1) exito, mostro el empleado por consola
int mostrarUnEmpleadoPorId(Employee* list, int lenght, int id);

/// @brief Remueve un empleado usando el ID como referencia
/// @param list Lista de empleados
/// @param len Tamaño del array
/// @param id ID del empleado
/// @return retorno (0) El id ingresado no existe, (1) exito, empleado removido
int removeEmployee(Employee* list, int len, int id);


/// @brief  Modifica un empleado usando el ID como referencia
/// @param list array de empleados
/// @param len tamaño array
/// @param id Id del empleado a modificar
/// @return
int modificarEmpleado(Employee* list, int len, int id);

/// @brief Verifica que las posiciones del array de empleados se encuentren vacias,
/// 			al encontrar una rompe y deja de recorrer el array
/// @param list array de empleados
/// @param len tamaño array
/// @return retorno (1) la posicion esta vacia, (0) la posicion esta llena
int verificarVacio(Employee* list, int len);

/// @brief verifica que TODA las posiciones del array de empleados esten llenas
/// @param list lista de empleados
/// @param len  tamaño array
/// @return retorno (1) esta lleno, (0) quedan espacios
int verificarLleno(Employee* list, int len);

/// @brief Ordena el array de empleados por apellido y sector de manera ascendente o descendente
/// @param list array de empleados
/// @param len tam array
/// @param order orden en el que seran ordenados los apellidos [1] up [0] down
/// @return retorno (0) error invalid lenght or null    (1) If ok
int sortEmployees(Employee* list, int len, int order);



/// @brief informa los datos de los empleados (promedio de salarios, total de salarios y cantidad
/// @param list
/// @param len
/// @return retorno (0) error invalid lenght or null    (1) If ok
int informarDatosDeEmpleados(Employee* list, int len);

/// @brief Ordena el array de apellidos de A a Z
/// @param list  array de empleados
/// @param len tam array empleados
/// @return retorno(0) if error, (1) if ok
int ordenarApellidoAscendente(Employee* list, int len);

/// @brief Ordena el array de empleados por apellidos de Z a A
/// @param list array de empleados
/// @param len tam array empleados
/// @return retorno(0) if error, (1) if ok
int ordenarApellidoDescendente(Employee* list, int len);

/// @brief ordena el array  de empleados por sector comenzando desde el primer sector
/// @param list  array de empleados
/// @param len  tam array empleados
/// @return  retorno(0) if error, (1) if ok
int ordenarSectorAscendente(Employee* list, int len);

/// @brief ordena el array de empleados por sector comenzando desde el ultimo sector
/// @param list  array de empleados
/// @param len tam array empleados
/// @return retorno(0) if error, (1) if ok
int ordenarSectorDescendente(Employee* list, int len);

#endif
