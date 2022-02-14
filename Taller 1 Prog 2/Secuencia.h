#ifndef SECUENCIA_H_INCLUDED
#define SECUENCIA_H_INCLUDED

#include "ListaNum.h"
#include "stringD.h"

typedef struct{
                stringD id;
                ListaNum numeros;
                } Secuencia;


void devuelveIdent (Secuencia sec, stringD &s);
/*dada una secuencia devuelve el identificador*/

ListaNum devuelveLista(Secuencia sec);
/*dada una secuencia devuelve la lista de números*/

Secuencia cargarSecuencia (ListaNum l, stringD ident);
/*carga los valores identificador y númerosen la secuencia*/

void mostrarSecuencia (Secuencia sec);
//despliega en pantalla los parámetros de sec



#endif // SECUENCIA_H_INCLUDED
