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
//devuelve el estructurado del nodo raiz del árbol pasado como parámetro

ABBSecuencias HijoIzq (ABBSecuencias a);
//devuelve el hijo izq delárbol pasado como parámetro

ABBSecuencias HijoDer (ABBSecuencias a);
//devuelve el hijo der del árbol pasado como parámetro

boolean esVacioABB (ABBSecuencias a);
//devuelve TRUE si el árbol está vacío

ABBSecuencias constructABB (Secuencia raiz, ABBSecuencias i, ABBSecuencias  d);
//dada una secuencia raiz, construye el ABB.

void mostrarEnOrden (ABBSecuencias a);
//recorre el árbol de la forma: izq-raíz-der y muestra en pantalla las secuencias en ese orden
//PRECONDICIÓN: a !esVacioABB

void insertarSecuencia (ABBSecuencias &a, Secuencia sec);
/*inserta una secuencia en el árbol ordenada alfabéticamente según su identificador*/

void destruirABB (ABBSecuencias &a);
// libera la memoria ocupada por el árbol y lo deja nulo

Secuencia devuelveSec (ABBSecuencias a, stringD ident);
//dado un identificador devuelve la secuencia correspondiente cargado en el árbol
//PRECONDICIÓN: existeSecuencia ident en el árbol a



#endif // ABBSECUENCIAS_H_INCLUDED
