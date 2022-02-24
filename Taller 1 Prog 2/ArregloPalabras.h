#ifndef ARREGLOPALABRAS_H_INCLUDED
#define ARREGLOPALABRAS_H_INCLUDED

#include "stringD.h"

const int TAM=4;
typedef struct{ stringD arre [TAM];
                int tope;
              }ArregloPalabras;


void cargarArregloP (ArregloPalabras &arreP, stringD texto);
//dado un arreglo y un string, carga las diferentes palabras del string en cada posicion del arreglo, hasta un maximo de 4 palabras

void mostrarArregloP (ArregloPalabras arreP);
//muestra por pantalla los strings cargados en el arreglo

void resetearArregloP (ArregloPalabras &arreP);
//destruye los strings y setea el tope a 0

void n_esimoPalabra (ArregloPalabras arreP, int num, stringD &s);
//devuelve el string cargado en la posicion num del arreglo

int devolverTope (ArregloPalabras arreP);
//devuelve el valor del tope del arreglo

boolean esVacioArreP (ArregloPalabras arreP);
//devuelve TRUE si el tope = 0

#endif // ARREGLOPALABRAS_H_INCLUDED
