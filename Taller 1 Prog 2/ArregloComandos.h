#ifndef ARREGLOCOMANDOS_H_INCLUDED
#define ARREGLOCOMANDOS_H_INCLUDED

#include "Comando.h"

const int N = 9;
typedef Comando ArregloComandos [N];

void levantarComandos (ArregloComandos &arreC, stringD fileName);
//abre el archivo y carga el arreglo con los comandos levantados del archivo

void n_esimoComando (ArregloComandos arre, int num, stringD &s);
//devuelve el string cargado en la posici�n num del arreglo

boolean existeComando (ArregloComandos arre, stringD s);
//devuelve TRUE si el string pasado por par�metro es un comando existente en el arreglo

void destruirComandos (ArregloComandos arre);
//recorre el arreglo y destruye los strings

#endif // ARREGLOCOMANDOS_H_INCLUDED
