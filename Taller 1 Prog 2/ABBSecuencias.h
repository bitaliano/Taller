#ifndef ABBSECUENCIAS_H_INCLUDED
#define ABBSECUENCIAS_H_INCLUDED

#include "Secuencia.h"

typedef struct nodoA {
                    Secuencia info;
                    nodoA * hizq;
                    nodoA * hder;
                    } nodoSecuencia;

typedef nodoSecuencia * ABBSecuencias;


void CrearArbol (ABBSecuencias &a);
// Crea arbol vacio

boolean esVacioABB (ABBSecuencias a);
//devuelve TRUE si el �rbol est� vac�o

Secuencia DarRaiz (ABBSecuencias a); ///Pre condicion: ABB no vacio
//devuelve el estructurado del nodo raiz del �rbol pasado como par�metro

Secuencia devuelveSec (ABBSecuencias a, stringD ident, stringD &s); /// Pre condicion: existeSecuencia ident en el �rbol a
//dado un identificador devuelve la secuencia correspondiente cargado en el �rbol

ABBSecuencias HijoIzq (ABBSecuencias a); ///Pre condicion: ABB no vacio
//devuelve el hijo izq del�rbol pasado como par�metro

ABBSecuencias HijoDer (ABBSecuencias a); ///Pre condicion: ABB no vacio
//devuelve el hijo der del �rbol pasado como par�metro

void insertarSecuencia (ABBSecuencias &a, Secuencia sec); /// Pre condicion: La secuencia no existe en el arbol
//inserta una secuencia en el �rbol ordenada alfab�ticamente seg�n su identificador

boolean Pertenece (ABBSecuencias a, stringD ident);
//Devueluve TRUE si una secuencia pertenece al arbol

void mostrarEnOrden (ABBSecuencias a); ///Pre condicion: ABB no vacio
//recorre el �rbol de la forma: izq-ra�z-der y muestra en pantalla las secuencias en ese orden

ABBSecuencias constructABB (Secuencia raiz, ABBSecuencias i, ABBSecuencias  d);
//dada una secuencia raiz, construye el ABB.

void destruirABB (ABBSecuencias &a);
// libera la memoria ocupada por el �rbol y lo deja nulo


//PRECONDICI�N:



#endif // ABBSECUENCIAS_H_INCLUDED
