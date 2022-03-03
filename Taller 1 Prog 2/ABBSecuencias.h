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
//devuelve TRUE si el arbol esta vacio

Secuencia DarRaiz (ABBSecuencias a); ///Pre condicion: ABB no vacio
//devuelve el estructurado del nodo raiz del arbol pasado como parametro

Secuencia devuelveSec (ABBSecuencias a, stringD ident); /// Pre condicion: existeSecuencia ident en el arbol a
//dado un identificador devuelve la secuencia correspondiente cargado en el arbol

void modifSecArbol (ABBSecuencias &a, stringD ident, int n);

ABBSecuencias HijoIzq (ABBSecuencias a); ///Pre condicion: ABB no vacio
//devuelve el hijo izq del arbol pasado como parametro

ABBSecuencias HijoDer (ABBSecuencias a); ///Pre condicion: ABB no vacio
//devuelve el hijo der del arbol pasado como parametro

void insertarSecuencia (ABBSecuencias &a, Secuencia sec); /// Pre condicion: La secuencia no existe en el arbol
//inserta una secuencia en el arbol ordenada alfabeticamente segun su identificador

boolean Pertenece (ABBSecuencias a, stringD ident);
//Devueluve TRUE si una secuencia pertenece al arbol

void modificaArbol (ABBSecuencias &a, Secuencia sec);
//modifica la secuencia pasada por parámetro en el ABB

void mostrarEnOrden (ABBSecuencias a); ///Pre condicion: ABB no vacio
//recorre el arbol de la forma: izq-raiz-der y muestra en pantalla las secuencias en ese orden

ABBSecuencias constructABB (Secuencia raiz, ABBSecuencias i, ABBSecuencias  d);
//dada una secuencia raiz, construye el ABB.

void destruirABB (ABBSecuencias &a);
// libera la memoria ocupada por el arbol y lo deja nulo






#endif // ABBSECUENCIAS_H_INCLUDED
