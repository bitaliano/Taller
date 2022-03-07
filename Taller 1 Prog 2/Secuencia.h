#ifndef SECUENCIA_H_INCLUDED
#define SECUENCIA_H_INCLUDED

#include "ListaNum.h"

typedef struct{ stringD id;
                ListaNum numeros;
                } Secuencia;


stringD devuelveIdent (Secuencia sec);
//dada una secuencia devuelve el identificador

ListaNum devuelveLista(Secuencia sec);
//dada una secuencia devuelve la lista de numeros

void cargarSecuencia (Secuencia &sec, stringD nomSec);
//carga los valores identificador y numeros en la secuencia

void mostrarPrimerSecuencia (Secuencia sec);
//muestra en pantalla la secuencia resultante de cada operacion

void mostrarSecuencia (Secuencia sec);
//despliega en pantalla los parametros de sec

void levantarLisArchivoEnSec (Secuencia &sec, stringD arch);
//guarda en la secuencia la lista que se lee desde el archivo

void copiarListaEnSec (ListaNum l, Secuencia &sec);
//copia la lista dada en una secuencia

void invertirListaEnSec (ListaNum l, Secuencia &sec);
//crea una copia invertida de la lista y la inserta en una secuencia

void modificarLista (Secuencia &sec, int num);
//inserta el numero pasado por parametro en la lista de una secuencia

#endif // SECUENCIA_H_INCLUDED
