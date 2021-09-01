#ifndef UTN_H_
#define UTN_H_

/// @brief Pide un numero entero a traves del mensaje
/// @param mensaje
/// @return devuelve el numero pedido
int PedirEntero(char mensaje[]);

int ValidarEntero(int numero, int rangoMinimo, int rangoMaximo);

void MostrarEntero(char mensaje[], int valorIngresado);

/// @brief Suma sus los dos parametros y devuelve el resultado de la suma
/// @param numeroUno
/// @param numeroDos
/// @return devuelve el resultado de la suma
int Suma(int numeroUno, int numeroDos);

/// @brief Resta sus dos parametros y devuelve el resultado de la resta
/// @param numeroUno
/// @param numeroDos
/// @return devuelve el resultado de la resta
int Resta(int numeroUno, int numeroDos);

/// @brief	Divide sus dos parametros y devuelve el resultado de la division
/// @param numeroUno
/// @param numeroDos
/// @return devuelve el resultado de la division
int Division(int numeroUno, int numeroDos);

/// @brief multiplica sus dos parametros y devuelve el resultado de la multiplicacion
/// @param numeroUno
/// @param numeroDos
/// @return devuelve el resultado de la multiplicacion
int Multiplicacion(int numeroUno, int numeroDos);

/// @brief busca el factorial de un numero y devuelve el resultado de las multiplicaciones
/// @param numeroUno
/// @return devuelve el resultado del factorial
int Factorial(int numeroUno);

#endif /* UTN_H_ */
