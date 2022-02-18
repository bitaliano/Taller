#include "Secuencia.h"

stringD devuelveIdent (Secuencia sec)

{
	return sec.id;
}

ListaNum devuelveLista(Secuencia sec)

{
	return sec.numeros;
}

void cargarSecuencia (Secuencia &sec, stringD nomSec)

{
	crearLista (sec.numeros);
	strcrear (sec.id);
	sec.id = nomSec;
}

void mostrarSecuencia (Secuencia sec)

{
printf ("\nNombre: ");
	print(sec.id);
	printf ("\nLista de numeros: ");
	mostrarLista(sec.numeros);
}
