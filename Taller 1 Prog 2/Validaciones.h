#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "ArregloPalabras.h"
#include "ArregloComandos.h"
#include "ABBSecuencias.h"



int buscarComando (stringD s, ArregloComandos arreC);
//busca un string en el arreglo y devuelve su posici�n

boolean esAlfabetico (stringD s);
//devuelve TRUE si el string es puramente alfab�tico

boolean cantParamCorrecta (ArregloPalabras arreP, Comando com);
/*devuelve TRUE si el arreglo de palabras tiene la cantidad correcta de par�metros definidos para el comando*/

boolean existeSecuencia (stringD ident, ABBSecuencias a);
/*devuelve TRUE si existe en el �rbol una secuencia que coincida con el identificador que se pasa como par�metro*/
//PRECONDICI�N: a !esVacioABB

void mensajeError (int codError);
//dado un c�digo de error, imprime en pantalla en mensaje a mostrar al usuario

boolean esNumerico (stringD s);
//devuelve TRUE si el string es num�rico

boolean esNomArchivo (stringD s);
//devuelve TRUE si el nombre es alfab�tico hasta el punto y termina en .txt

boolean existeArchivo (stringD nomArch);
//devuelve TRUE si existe un archivo con el nombre pasado por par�metro



#endif // VALIDACIONES_H_INCLUDED
