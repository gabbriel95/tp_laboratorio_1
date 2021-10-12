#ifndef UTN_H_
#define UTN_H_

int PedirCadenaChars(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos);

/// @brief Recorre la cadena para verificar si los caracteres del array son letras o no
/// @param cadena array de caracteres
/// @return		return (0) no es letra   (1) es letra
int EsChar(char* cadena);

/// @brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo
/// 		de longitud -1 caracteres
/// @param cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
/// @param longitud Define el tamaño de la cadena
/// @return Retorna 1 (exito) si se obtiene una cadena y 0(error) si no
int MyGets(char* cadena, int longitud);


/// @brief Obtener un numero entero desde la terminal
///
/// @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
/// @return Retorna 0 (exito) si se obtiene un entero y -1 (error)
///
int GetInt(int* pResultado);

/// @brief Solicita el ingreso de un entero por mensaje y lo retorna por puntero pResultado
/// @param pResultado  Numero a retoronar
/// @param mensaje		Mensaje
/// @param mensajeError Mensaje Error
/// @param minimo		Rango minimo de numeros que puede ingresar
/// @param maximo		Rango maximo de numeros que puede ingresar
/// @param reintentos   Cantidad de reintentos
/// @return   return (1) If ok,   (0) Error, se quedo sin reintentos
int Utn_GetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @brief  Solicita el ingreso de un numero decimal por mensaje y retorna por puntero pResultado
/// @param pResultado  puntero numero a retornar
/// @param mensaje		mensaje
/// @param mensajeError	mensaje error
/// @param minimo		rango minimo de numeros que puede ingresar
/// @param maximo		rango maximo de numeros que puede ingresar
/// @param reintentos   cantidad de reintentos
/// @return  return (1) If ok,   (0) Error, se quedo sin reintentos
int Utn_GetNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/// @brief tranforma el array de caracteres tdo a minuscula
/// @param nombreAPasar array de caracteres a convertir
/// @param tamArray		tam array
/// @return retorno(0) if error, (1) if ok
int Tolower(char nombreAPasar[], int tamArray);

/// @brief transforma la primera letra del array en mayuscula
/// @param nombreAPasar  array a convertir
/// @param tamArray			tamaño array
/// @return retorno(0) if error, (1) if ok
int PrimerLetraToUpper(char nombreAPasar[], int tamArray);
#endif
