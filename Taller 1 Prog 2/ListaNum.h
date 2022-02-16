#ifndef LISTANUM_H_INCLUDED
#define LISTANUM_H_INCLUDED

#include "boolean.h"
#include "stringD.h"

typedef struct nodoL{
                int info;
                nodoL *sig;
                }nodoLista;
typedef nodoLista *ListaNum;


void crearLista (ListaNum &l);
//crea una lista vac�a

boolean ListaVacia(ListaNum l);

void mostrarLista (ListaNum l);
//despliega la lista en pantalla en el orden que fueron ingresados los n�meros

int sumarValores (ListaNum l);
//suma los valores de la lista

void insertarAtras (ListaNum &l, int num);
//dada una lista y un valor, ingresa el valor al final de la lista.

void bajarLisArchivo (ListaNum l, stringD arch);
//abre el archivo, baja la lista al archivo y cierrael archivo

void levantarLisArchivo (ListaNum l, stringD arch);
//abre el archivo y crea la lista con los n�meros del archivo
//PRECONDICI�N: el archivo debe existir

void destruirLista (ListaNum &l);
/* liberala memoria ocupada por la lista y deja el puntero nulo*/

void copiarLista (ListaNum listOrigen, ListaNum &listCopia);
//copia una lista origen a una lista copia

void invertirLista (ListaNum listOrigen, ListaNum &listInvert);
//invierte los valores de una lista origen en una lista invertida


#endif // LISTANUM_H_INCLUDED