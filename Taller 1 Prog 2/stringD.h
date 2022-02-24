#ifndef STRINGD_H_INCLUDED
#define STRINGD_H_INCLUDED

#include "boolean.h"

const int MAX=80;
typedef char *stringD;

void strcrear (stringD &s);
//crea un string vacío (solo con el carácter ‘\0’)

void strdestruir (stringD &s);
// libera la memoria ocupada por el string y lo deja nulo.

int strlar (stringD s);
// devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes del carácter nulo.

void strcop(stringD &s1,stringD s2);
// recibe dos strings y copia el  segundo en el primero.

void strcopPalabra(stringD &s1, stringD s2, int desde, int hasta);
//copia el segmento del segundo string limitado por los índices [desde] y [hasta] en el primero.*/

void scan (stringD &s);
// lee un string desde el teclado. Se tomarán en cuenta los primeros 79 caracteres  significativos en caso de que el largo del string sea mayor o igual a 80. Un string finaliza cuando se lea un carácter ‘nueva línea’ el cual se sustituirá por uno nulo.

void strcon(stringD &s1,stringD s2);
// recibe dos strings y concatena el segundo string al final del primero, la concatenación deberá quedar sobre el primero de los dos. En caso de que el largo de los strings exceda los 79 caracteres, no se tomarán los caracteres excedentes del segundo string.

void strswp (stringD &s1,stringD &s2);
// recibe dos strings y devuelve el primero en el segundo y viceversa.

void print (stringD s);
// despliega un string por pantalla.

boolean strmen (stringD s1,stringD s2);
// recibe dos strings y devuelve TRUE si el primero de ellos es menor (en orden alfabético) que el segundo, o FALSE en caso contrario.

boolean streq (stringD s1,stringD s2);
// recibe dos strings y devuelve TRUE si ambos strings son iguales o FALSE en caso contrario.


int convertirString (stringD s);  
//convierte strings numéricos en números enteros 
//PRECONDICIÓN: s esNumerico 


void Bajar_String (stringD s, FILE * f);
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondición: El archivo viene abierto para escritura.

void Levantar_String (stringD &s, FILE * f);
// Lee desde el archivo los caracteres del string s.
// Precondición: El archivo viene abierto



#endif // STRINGD_H_INCLUDED
