#include "Comando.h"

void cargarComando (Comando &com, stringD s, int cant)
{
	strcrear (com.comand);
	strcop(com.comand, s);
	com.param = cant;
}

void devuelveNomCom (Comando com, stringD &s)
{
	strcop(s, com.comand);
}

int devuelveCantParam (Comando com)
{
	return com.param;
}


void levantarComArchivo (Comando &com, FILE *f)
{
    strcrear (com.comand);
    Levantar_String (com.comand, f);
	fread(&com.param, sizeof(int), 1, f);
}

void bajarComArchivo (Comando &com, FILE *f)
{
    Bajar_String (com.comand, f);
	fwrite(&com.param, sizeof(int), 1, f);
}
