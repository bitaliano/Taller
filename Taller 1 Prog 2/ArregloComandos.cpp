#include "ArregloComandos.h"

void levantarComandos (ArregloComandos &arreC, stringD fileName)

{
    FILE * f = fopen (fileName, "rb");
    int i = 0;
    levantarComArchivo(arreC[i], f);

    while (!feof(f) && i < 9)
    {
        i++;
        levantarComArchivo(arreC[i], f);
    }
    fclose (f);
}



void n_esimoComando (ArregloComandos arre, int num, stringD &s)
{
    devuelveNomCom(arre[num],s);
}


boolean existeComando (ArregloComandos arre, stringD s)
{
    boolean existe = FALSE;
    int i = 0;
    stringD nombre;
    strcrear(nombre);
    while (!existe && i < 9)
    {
        n_esimoComando(arre, i, nombre);
        if (streq(s, nombre))
        {
            existe = TRUE;
        }
    }
    return existe;
}


void destruirComandos (ArregloComandos arre)
{
    stringD s;
    strcrear(s);
    for (int i = 0; i < 9; i++)
    {
        devuelveNomCom(arre[i],s);
        strdestruir(s);
    }

}


void bajarComandos(ArregloComandos arreC, stringD fileName)
{
    FILE * f = fopen (fileName, "wb");
    int i = 0;
    bajarComArchivo(arreC[i], f);
    while (!feof(f) && i < 9)
    {
        i++;
        bajarComArchivo(arreC[i], f);
    }
    fclose (f);
}