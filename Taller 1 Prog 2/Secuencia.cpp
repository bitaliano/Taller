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

void mostrarPrimerSecuencia (Secuencia sec)

{
    printf ("Resultado:\t ");
	print(sec.id);
	printf (" = ");
	mostrarLista(sec.numeros);
	printf("\n");
}

void mostrarSecuencia (Secuencia sec)

{
    printf ("\t\t ");
	print(sec.id);
	printf (" = ");
	mostrarLista(sec.numeros);
	printf("\n");
}

void levantarLisArchivoEnSec (Secuencia &sec, stringD arch)
{
    levantarLisArchivo(sec.numeros,arch);
}

void copiarListaEnSec (ListaNum l, Secuencia &sec)
{
    copiarLista(l,sec.numeros);
}

void invertirListaEnSec (ListaNum l, Secuencia &sec)
{
    invertirLista(l,sec.numeros);
}

void modificarSec (Secuencia &sec, ListaNum l)
{
    sec.numeros = l;
}

void modificarLista (Secuencia &sec, int num)
{
    insertarAtras(sec.numeros, num);
}
