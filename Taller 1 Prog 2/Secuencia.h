#ifndef SECUENCIA_H_INCLUDED
#define SECUENCIA_H_INCLUDED

#include "ListaNum.h"
#include "stringD.h"

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

void mostrarSecuencia (Secuencia sec);
//despliega en pantalla los parametros de sec

void modificarLista (Secuencia &sec, int num);
//inserta el numero pasado por parametro en la lista de una secuencia

void modificarSec (Secuencia &sec, ListaNum l);
//carga una lista pasada por parametro en la secuencia

#endif // SECUENCIA_H_INCLUDED
