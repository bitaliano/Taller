#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED

#include <stdio.h>

typedef enum {FALSE, TRUE} boolean;

void cargar (boolean &b); // devuelve la variable cargada
void mostrar (boolean b); // muestra en pantalla la varibale cargada

#endif // BOOLEAN_H_INCLUDED
