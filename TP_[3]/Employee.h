#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
//1
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salaryStr);


void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

//Crear una funcion que compare a dos empleados x nombre
int employee_CompareByName(void*, void*);
int employee_CompareById(void* pEmpleadoA, void* pEmpleadoB);


void employee_SolicitarNombre(char* name, Employee* empleado);
void employee_SolicitarSalario(int salario, Employee* empleado);
void employee_SolicitarHorasTrabajadas(int horas, Employee* empleado);



#endif // employee_H_INCLUDED
