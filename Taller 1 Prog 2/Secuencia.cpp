#include "Secuencia.h"

void devuelveIdent (Secuencia sec, stringD &s);
/*dada una secuencia devuelve el identificador*/
{
	return Secuencia.id;
}

ListaNum devuelveLista(Secuencia sec);
/*dada una secuencia devuelve la lista de números*/
{
	return Secuencia.numeros;
}

Secuencia cargarSecuencia (ListaNum l, stringD ident);
/*carga los valores identificador y númerosen la secuencia*/
{
	Secuencia.id = ident;
	Secuencia.numeros = l;
	return Secuencia;
}

void mostrarSecuencia (Secuencia sec);
//despliega en pantalla los parámetros de sec
{
printf ("\nNombre: ");
	print(sec.id);
	printf ("\nLista de numeros: ");
	mostrarLista(sec.numeros);
}
