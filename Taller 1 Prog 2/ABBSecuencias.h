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
//devuelve TRUE si el árbol está vacío

Secuencia DarRaiz (ABBSecuencias a); ///Pre condicion: ABB no vacio
//devuelve el estructurado del nodo raiz del árbol pasado como parámetro

Secuencia devuelveSec (ABBSecuencias a, stringD ident); /// Pre condicion: existeSecuencia ident en el árbol a
//dado un identificador devuelve la secuencia correspondiente cargado en el árbol

ABBSecuencias HijoIzq (ABBSecuencias a); ///Pre condicion: ABB no vacio
//devuelve el hijo izq delárbol pasado como parámetro

ABBSecuencias HijoDer (ABBSecuencias a); ///Pre condicion: ABB no vacio
//devuelve el hijo der del árbol pasado como parámetro

void insertarSecuencia (ABBSecuencias &a, Secuencia sec); /// Pre condicion: La secuencia no existe en el arbol
//inserta una secuencia en el árbol ordenada alfabéticamente según su identificador

boolean Pertenece (ABBSecuencias a, stringD ident);
//Devueluve TRUE si una secuencia pertenece al arbol

void mostrarEnOrden (ABBSecuencias a); ///Pre condicion: ABB no vacio
//recorre el árbol de la forma: izq-raíz-der y muestra en pantalla las secuencias en ese orden

ABBSecuencias constructABB (Secuencia raiz, ABBSecuencias i, ABBSecuencias  d);
//dada una secuencia raiz, construye el ABB.

void Bajar_ABB (ABBSecuencias a, stringD nomArch);
// Abre el archivo para escritura y escribe los datos de todos los productos que están almacenados en el árbol

void destruirABB (ABBSecuencias &a);
// libera la memoria ocupada por el árbol y lo deja nulo


//PRECONDICIÓN:



#endif // ABBSECUENCIAS_H_INCLUDED
