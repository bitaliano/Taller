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
	strcop(sec.id, nomSec);
}

void mostrarSecuencia (Secuencia sec)

{
printf ("\nNombre: ");
	print(sec.id);
	printf ("\nLista de numeros: ");
	mostrarLista(sec.numeros);
}

void modificarSec (Secuencia &sec, ListaNum l)
{
    sec.numeros = l;
}

void modificarLista (Secuencia &sec, int num)
{
    insertarAtras(sec.numeros, num);
}
