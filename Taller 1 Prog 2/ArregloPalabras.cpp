#include "ArregloPalabras.h"

void cargarArregloP (ArregloPalabras &arreP, stringD texto)
{
    int k=0,f=0,i=0;
    boolean lleno = FALSE;
    arreP.tope=0;

    if ((texto[i]!='\0') && (texto[i]!=' '))
    {
        //Guardo indice de comienzo palabra
        k=i;
    }
    while (texto[i]!='\0' && !lleno)
    {
        if ((texto[i]==' ') && (texto[i+1]!=' ') && (texto[i+1]!='\0'))
        {
            //Guardo indice de comienzo palabra si no llegue al maximo de parametros permitidos
            if (arreP.tope==4)
                lleno = TRUE;
            else
                k=i+1;
        }
        else
        {
            if ((texto[i]!=' ') && ((texto[i+1]==' ') || (texto[i+1]=='\0')))
            {
                //Guardo indice de final de palabra
                f=i;
                strcopPalabra(arreP.arre[arreP.tope], texto, k, f);
                arreP.tope++;
            }
        }
        i++;
    }
    if (texto[i]!='\0')
        arreP.tope ++;
}

void mostrarArregloP (ArregloPalabras arreP)
{
    for (int i=0; i<arreP.tope; i++)
    {
        print(arreP.arre[i]);
        printf("\n");
    }
}

void resetearArregloP (ArregloPalabras &arreP)
{
    for (int i = 0; i < arreP.tope; i++)
        strdestruir(arreP.arre[i]);
    arreP.tope = 0;
}

void n_esimoPalabra (ArregloPalabras arreP, int num, stringD &s)
{
    strcop (s, arreP.arre[num]);
}

int devolverTope (ArregloPalabras arreP)
{
    return arreP.tope;
}


boolean esVacioArreP (ArregloPalabras arreP)
{
    boolean vacio = FALSE;
    if (devolverTope(arreP) == 0)
        vacio = TRUE;
    return vacio;
}
