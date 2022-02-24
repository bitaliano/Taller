#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "ArregloPalabras.h"
#include "ArregloComandos.h"
#include "ABBSecuencias.h"


boolean existeComando (stringD s, ArregloComandos arreC);
//devuelve TRUE si existe en el arreglo de comandos un comando que coincida con el nombre pasado por parámetro

int buscarComando (stringD s, ArregloComandos arreC);
//busca un string en el arreglo y devuelve su posición
//PRECONDICIÓN: s existeComando

boolean esAlfabetico (stringD s);
//devuelve TRUE si el string es puramente alfabético

boolean cantParamCorrecta (ArregloPalabras arreP, Comando com);
/*devuelve TRUE si el arreglo de palabras tiene la cantidad correcta de parámetros definidos para el comando*/

boolean existeSecuencia (stringD ident, ABBSecuencias a);
/*devuelve TRUE si existe en el árbol una secuencia que coincida con el identificador que se pasa como parámetro*/
//PRECONDICIÓN: a !esVacioABB

void mensajeError (int codError);
//dado un código de error, imprime en pantalla en mensaje a mostrar al usuario

boolean esNumerico (stringD s);
//devuelve TRUE si el string es numérico

boolean esNomArchivo (stringD s);
//devuelve TRUE si el nombre es alfabético hasta el punto y termina en .txt

boolean existeArchivo (stringD nomArch);
//devuelve TRUE si existe un archivo con el nombre pasado por parámetro



#endif // VALIDACIONES_H_INCLUDED
