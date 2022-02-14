#include "Comando.h"

void devuelveNomCom (Comando com, stringD &s);
{
	strcop(s, com.comand);
}

int devuelveCantParam (Comando com);
{
	return com.param;
}

//DE ESTE PROC HAY QUE CAMBIAR EL COMENTARIO, Y TAMBIEN EN EL MÓDULO ARREGLOCOMANDOS
//HAY QUE CAMBIAR EL PROC levantarComandos PARA QUE QUEDE ASÍ:
//void levantarComandos(ArregloComandos &arreC, stringD f);
//abre el archivo y arma el arreglo de comandos

void levantarComArchivo (Comando &com, FILE *f);
{
    strcrear (com.id);
    Levantar_String (com.id, f);
	fread(&com.param, sizeof(int), 1, f);
}
