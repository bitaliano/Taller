#ifndef ARREGLOPALABRAS_H_INCLUDED
#define ARREGLOPALABRAS_H_INCLUDED

#include "stringD.h"

const int TAM=4;
typedef struct{
                stringD arre [TAM];
                int tope;
            }ArregloPalabras;

void resetearArregloP (ArregloPalabras &arreP);
//destruye los strings y setea el tope a 0

void cargarArregloP (ArregloPalabras &arreP, stringD s);
/*dado un arreglo y un string, carga las diferentes palabras del string en cada posición del arreglo, hasta un máximo de 4 palabras*/

void n_esimoPalabra (ArregloPalabras arre, int num, stringD &s);
//devuelve el string cargado en la posición num del arreglo

int devolverTope (ArregloPalabras arre);
//devuelve el valor del tope del arreglo

boolean esVacioArreP (ArregloPalabras arre)
//devuelve TRUE si el tope = 0

#endif // ARREGLOPALABRAS_H_INCLUDED
