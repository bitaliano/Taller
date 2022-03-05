#include "ArregloComandos.h"

void levantarComandos (ArregloComandos &arreC, stringD fileName)

{
    FILE * f = fopen (fileName, "rb");
    int i = 0;
    levantarComArchivo(arreC[i], f);

    while (!feof(f) && i < N)
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

Comando darComando (ArregloComandos arre, int num)
{
    return arre[num];
}


void destruirComandos (ArregloComandos arre)
{
    //stringD s;
    //strcrear(s);
    for (int i = 0; i < N; i++)
    {
        //devuelveNomCom(arre[i],s);
        //strdestruir(s);
        destruircomando(arre[i]);
    }
}


void bajarComandos(ArregloComandos arreC, stringD fileName)
{
    FILE * f = fopen (fileName, "wb");
    int i = 0;
    bajarComArchivo(arreC[i], f);
    while (!feof(f) && i < N)
    {
        i++;
        bajarComArchivo(arreC[i], f);
    }
    fclose (f);
}
