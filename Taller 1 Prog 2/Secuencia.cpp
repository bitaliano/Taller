#include "Secuencia.h"

stringD devuelveIdent (Secuencia sec)

{
	return sec.id;
}

ListaNum devuelveLista(Secuencia sec)

{
	return sec.numeros;
}

Secuencia cargarSecuencia (ListaNum l, stringD ident)

{
	Secuencia sec;
	sec.id = ident;
	sec.numeros = l;
	return sec;
}

void mostrarSecuencia (Secuencia sec)

{
printf ("\nNombre: ");
	print(sec.id);
	printf ("\nLista de numeros: ");
	mostrarLista(sec.numeros);
}
