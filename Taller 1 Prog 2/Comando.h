#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

#include "stringD.h"

typedef struct{
                stringD comand;
                int param;
            } Comando;

void devuelveNomCom (Comando com, stringD &s);
//devuelve en el string pasado por referencia el nombre de un comando

int devuelveCantParam (Comando com);
//devuelve la cantidad de parámetros que permite un comando

void levantarComArchivo (Comando &com, FILE *f);
//abre el archivo y carga el arreglo de comandos


#endif // COMANDO_H_INCLUDED
