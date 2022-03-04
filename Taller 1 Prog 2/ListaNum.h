#ifndef LISTANUM_H_INCLUDED
#define LISTANUM_H_INCLUDED

#include "boolean.h"
#include "stringD.h"

typedef struct nodoL{
                int info;
                nodoL *sig;
                }nodoLista;
typedef nodoLista * ListaNum;


void crearLista (ListaNum &l);
//crea una lista vacia

boolean ListaVacia(ListaNum l);
//devuelve TRUE si la lista está vacía

void mostrarLista (ListaNum l);
//despliega la lista en pantalla en el orden que fueron ingresados los numeros

int sumarValores (ListaNum l);
//suma los valores de la lista

void insertarAtras (ListaNum &l, int num);
//dada una lista y un valor, ingresa el valor al final de la lista.

void bajarLisArchivo (ListaNum l, stringD arch); /// Pre condicion: lista no vacia
//abre el archivo, baja la lista al archivo y cierra el archivo

void levantarLisArchivo (ListaNum &l, stringD arch); /// Pre condicion: el archivo debe existir
//abre el archivo y crea la lista con los numeros del archivo

void destruirLista (ListaNum &l);
// liberala memoria ocupada por la lista y deja el puntero nulo

void copiarLista (ListaNum lOrigen, ListaNum &lCopia);
//copia una lista origen al final de otra lista

void invertirLista (ListaNum listOrigen, ListaNum &listInvert);
//invierte los valores de una lista origen en una lista invertida


#endif // LISTANUM_H_INCLUDED
