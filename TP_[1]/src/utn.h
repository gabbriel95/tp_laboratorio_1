#ifndef UTN_H_
#define UTN_H_

/// @brief Pide un numero entero
/// @param mensaje - Mensaje que solicita el numero
/// @return devuelve el numero ingresado
long int PedirEntero(char mensaje[]);

/// @brief Pide un numero decimal
/// @param mensaje - Mensaje que solicita el numero
/// @return devuelve el numero ingresado
double PedirDecimal(char mensaje[]);

/// @brief Muestra un mensaje
/// @param mensaje - Mensaje a ser mostrado
void mostrarTexto(char mensaje[]);

/// @brief  Valida un numero entero entre dos rangos
/// @param numero Numero a validar
/// @param rangoMinimo El rango minimo
/// @param rangoMaximo El rango maximo
/// @return
long int ValidarEntero(long int numero, long int rangoMinimo, long int rangoMaximo);

/// @brief Valida un numero decimal entre dos rangos
/// @param numero numero a validar
/// @param rangoMinimo rango minimo
/// @param rangoMaximo rango maximo
/// @return
long int ValidarDecimal(double numero, double rangoMinimo, double rangoMaximo);

/// @brief Muentra el resultado de una division, valida que el segundo numero no sea un cero
/// @param a  Dividendo
/// @param b Divisor
void MostrarDivision(long int a, long int b);

/// @brief Muentra el resultado del factorial de dos numeros
/// @param a Primer Numero
void MostrarFactorial(long int a);


/// @brief Muestra el resultado de una operacion entre dos numeros
/// @param mensaje - Mensaje que describe la operacion y el resultado
/// @param valorIngresado - Resultado de la operacion
/// @param numeroUno - Primer numero de la operacion
/// @param numeroDos - Segundo numero de la operacion
void MostrarResultado(char mensaje[], long int valorIngresado,long int numeroUno, long int numeroDos);


/// @brief Suma sus los dos parametros y devuelve el resultado de la suma
/// @param numeroUno
/// @param numeroDos
/// @return devuelve el resultado de la suma
long int Suma(long int numeroUno, long int numeroDos);

/// @brief Resta sus dos parametros y devuelve el resultado de la resta
/// @param numeroUno
/// @param numeroDos
/// @return devuelve el resultado de la resta
long int Resta(long int numeroUno, long int numeroDos);

/// @brief	Divide sus dos parametros y devuelve el resultado de la division
/// @param numeroUno
/// @param numeroDos
/// @return devuelve el resultado de la division
double Division(long int numeroUno, long int numeroDos);

/// @brief multiplica sus dos parametros y devuelve el resultado de la multiplicacion
/// @param numeroUno
/// @param numeroDos
/// @return devuelve el resultado de la multiplicacion
long int Multiplicacion(long int numeroUno, long int numeroDos);

/// @brief busca el factorial de un numero y devuelve el resultado de las multiplicaciones
/// @param numeroUno
/// @return devuelve el resultado del factorial
long int Factorial(long int numeroUno);

/// @brief Valida que el numero ingresado este dentro de los rangos calculabres para un factorial
/// 		Y si el usuario lo desea puede volver a reingresar un numero dentro del rango
/// @param numero		Numero a validar
/// @param rangoMinimo 	rango minimo para validar
/// @param rangoMaximo	rango maximo para validar
/// @return
long int ValidarFactorial(long int numero, long int rangoMinimo, long int rangoMaximo);

/// @brief	Muentras el resultado de la division entre dos numeros, tambien informa si no
/// 								se puede dividir por cero
/// @param valorIngresado	es el resultado de la division
/// @param numeroUno		es el dividendo
/// @param numeroDos		es el divisor
void MostrarResultadoFlotante(float valorIngresado,long int numeroUno, long int numeroDos);


#endif /* UTN_H_ */
