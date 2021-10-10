#ifndef UTN_H_
#define UTN_H_

int PedirCadenaChars(char cadena[], int tam, char mensaje[], char mensajeError[], int reintentos);
int EsChar(char* cadena);
int MyGets(char* cadena, int longitud);
int Utn_GetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int Utn_GetNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int Utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);



int Tolower(char nombreAPasar[], int tamArray);
int PrimerLetraToUpper(char nombreAPasar[], int tamArray);
#endif
