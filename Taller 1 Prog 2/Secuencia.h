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
//dada una secuencia devuelve la lista de n�meros

void cargarSecuencia (Secuencia &sec, stringD nomSec);
//carga los valores identificador y n�merosen la secuencia

void mostrarSecuencia (Secuencia sec);
//despliega en pantalla los par�metros de sec



#endif // SECUENCIA_H_INCLUDED
