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
//devuelve la cantidad de par�metros que permite un comando

void levantarComArchivo (Comando &com, FILE *f);
//recibe el archivo abierto y carga el un comando


#endif // COMANDO_H_INCLUDED
