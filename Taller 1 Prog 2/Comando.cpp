#include "Comando.h"

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
