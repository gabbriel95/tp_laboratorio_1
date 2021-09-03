#ifndef UTN_H_
#define UTN_H_

/// @brief Pide un numero entero
/// @param mensaje - Mensaje que solicita el numero
/// @return devuelve el numero ingresado
int PedirEntero(char mensaje[]);

/// @brief Pide un numero decimal
/// @param mensaje - Mensaje que solicita el numero
/// @return devuelve el numero ingresado
float PedirDecimal(char mensaje[]);

/// @brief Muestra un mensaje
/// @param mensaje - Mensaje a ser mostrado
void mostrarTexto(char mensaje[]);

/// @brief  Valida un numero entero entre dos rangos
/// @param numero Numero a validar
/// @param rangoMinimo El rango minimo
/// @param rangoMaximo El rango maximo
/// @return
int ValidarEntero(int numero, int rangoMinimo, int rangoMaximo);

/// @brief Valida un numero decimal entre dos rangos
/// @param numero numero a validar
/// @param rangoMinimo rango minimo
/// @param rangoMaximo rango maximo
/// @return
int ValidarDecimal(float numero, float rangoMinimo, float rangoMaximo);

/// @brief Muentra el resultado de una division, valida que el segundo numero no sea un cero
/// @param a  Dividendo
/// @param b Divisor
void MostrarDivision(int a, int b);

/// @brief Muentra el resultado del factorial de dos numeros
/// @param a Primer Numero
/// @param b Segundo Numero
void MostrarFactorial(int a, int b);


/// @brief Muestra el resultado de una operacion entre dos numeros
/// @param mensaje - Mensaje que describe la operacion y el resultado
/// @param valorIngresado - Resultado de la operacion
/// @param numeroUno - Primer numero de la operacion
/// @param numeroDos - Segundo numero de la operacion
void MostrarResultado(char mensaje[], int valorIngresado,int numeroUno, int numeroDos);


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
float Division(int numeroUno, int numeroDos);

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
