#ifndef STRINGD_H_INCLUDED
#define STRINGD_H_INCLUDED

#include "boolean.h"

const int MAX=80;
typedef char *stringD;

//strcrear  	crea un string vac�o (solo con el car�cter �\0�)
void strcrear (stringD &s);

//strdestruir  libera la memoria ocupada por el string y lo deja nulo.

void strdestruir (stringD &s);

//strlar  devuelve el largo de un string. Se entiende por largo, la cantidad de caracteres antes del car�cter nulo.


int strlar (stringD s);


//strcop  	recibe dos strings y copia el  segundo en el primero.
void strcop(stringD &s1,stringD s2);

/*copia el segmento del segundo string limitado por los �ndices [desde] y [hasta] en el primero.*/
void strcopPalabra(stringD &s1, stringD s2, int desde, int hasta);

//scan  lee un string desde el teclado. Se tomar�n en cuenta los primeros 79 caracteres  significativos en caso de que el largo del string sea mayor o igual a 80. Un string finaliza cuando se lea un car�cter �nueva l�nea� el cual se sustituir� por uno nulo.
void scan (stringD &s);


//strcon  recibe dos strings y concatena el segundo string al final del primero, la concatenaci�n deber� quedar sobre el primero de los dos. En caso de que el largo de los strings exceda los 79 caracteres, no se tomar�n los caracteres excedentes del segundo string.
void strcon(stringD &s1,stringD s2);

//strswp  	recibe dos strings y devuelve el primero en el segundo y viceversa.
void strswp (stringD &s1,stringD &s2);

//print 	despliega un string por pantalla.
void print (stringD s);

//strmen  recibe dos strings y devuelve TRUE si el primero de ellos es menor (en orden alfab�tico) que el segundo, o FALSE en caso contrario.
boolean strmen (stringD s1,stringD s2);

//streq 	reciba dos strings y devuelve TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq (stringD s1,stringD s2);

//ARCHIVO

// Escribe en el archivo los caracteres del string s (incluido '\0')
// Precondici�n: El archivo viene abierto para escritura.
void Bajar_String (stringD s, FILE * f);


// Lee desde el archivo los caracteres del string s.
// Precondici�n: El archivo viene abierto
void Levantar_String (stringD &s, FILE * f);


#endif // STRINGD_H_INCLUDED
