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

void modificarLista (Secuencia &sec, int num)
{
    insertarAtras(sec.numeros, num);
}

void bajarLista (Secuencia sec, stringD param2)
{
    bajarLisArchivo(sec.numeros,param2);
}

boolean secuenciaVacia (Secuencia sec)
{
    boolean vacia = FALSE;
    if (ListaVacia (sec.numeros))
        vacia = TRUE;
    return vacia;
}

