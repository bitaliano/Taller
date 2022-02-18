#ifndef STRINGD_H_INCLUDED
#define STRINGD_H_INCLUDED

#include "boolean.h"

const int MAX=80;
typedef char *stringD;

void strcrear (stringD &s);
//crea un string vac�o (solo con el car�cter �\0�)

void strdestruir (stringD &s);
// libera la memoria ocupada por el string y lo deja nulo.

int strlar (stringD s);
// devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes del car�cter nulo.

//strcop
void strcop(stringD &s1,stringD s2);
// recibe dos strings y copia el  segundo en el primero.

void strcopPalabra(stringD &s1, stringD s2, int desde, int hasta);
//copia el segmento del segundo string limitado por los �ndices [desde] y [hasta] en el primero.*/

void scan (stringD &s);
// lee un string desde el teclado. Se tomar�n en cuenta los primeros 79 caracteres  significativos en caso de que el largo del string sea mayor o igual a 80. Un string finaliza cuando se lea un car�cter �nueva l�nea� el cual se sustituir� por uno nulo.

void strcon(stringD &s1,stringD s2);
// recibe dos strings y concatena el segundo string al final del primero, la concatenaci�n deber� quedar sobre el primero de los dos. En caso de que el largo de los strings exceda los 79 caracteres, no se tomar�n los caracteres excedentes del segundo string.

void strswp (stringD &s1,stringD &s2);
// recibe dos strings y devuelve el primero en el segundo y viceversa.

void print (stringD s);
// despliega un string por pantalla.

boolean strmen (stringD s1,stringD s2);
// recibe dos strings y devuelve TRUE si el primero de ellos es menor (en orden alfab�tico) que el segundo, o FALSE en caso contrario.

boolean streq (stringD s1,stringD s2);
//streq 	reciba dos strings y devuelve TRUE si ambos strings son iguales o FALSE en caso contrario.


//ARCHIVO

void Bajar_String (stringD s, FILE * f);
// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondici�n: El archivo viene abierto para escritura.

void Levantar_String (stringD &s, FILE * f);
// Lee desde el archivo los caracteres del string s.
// Precondici�n: El archivo viene abierto



#endif // STRINGD_H_INCLUDED
