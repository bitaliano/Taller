#ifndef ABBSECUENCIAS_H_INCLUDED
#define ABBSECUENCIAS_H_INCLUDED

#include "Secuencia.h"

typedef struct nodoA {
                    Secuencia info;
                    nodoA * hizq;
                    nodoA * hder;
                    } nodoSecuencia;

typedef nodoSecuencia * ABBSecuencias;



Secuencia DarRaiz (ABBSecuencias a);
//devuelve el estructurado del nodo raiz del �rbol pasado como par�metro

ABBSecuencias HijoIzq (ABBSecuencias a);
//devuelve el hijo izq del�rbol pasado como par�metro

ABBSecuencias HijoDer (ABBSecuencias a);
//devuelve el hijo der del �rbol pasado como par�metro

boolean esVacioABB (ABBSecuencias a);
//devuelve TRUE si el �rbol est� vac�o

ABBSecuencias constructABB (Secuencia raiz, ABBSecuencias i, ABBSecuencias  d);
//dada una secuencia raiz, construye el ABB.

void mostrarEnOrden (ABBSecuencias a);
//recorre el �rbol de la forma: izq-ra�z-der y muestra en pantalla las secuencias en ese orden
//PRECONDICI�N: a !esVacioABB

void insertarSecuencia (ABBSecuencias &a, Secuencia sec);
/*inserta una secuencia en el �rbol ordenada alfab�ticamente seg�n su identificador*/

void destruirABB (ABBSecuencias &a);
// libera la memoria ocupada por el �rbol y lo deja nulo

Secuencia devuelveSec (ABBSecuencias a, stringD ident);
//dado un identificador devuelve la secuencia correspondiente cargado en el �rbol
//PRECONDICI�N: existeSecuencia ident en el �rbol a



#endif // ABBSECUENCIAS_H_INCLUDED
