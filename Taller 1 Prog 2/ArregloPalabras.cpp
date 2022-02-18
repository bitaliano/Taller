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
    while (texto[i]!='\0' && !lleno )
    {
        if ((texto[i]==' ') && (texto[i+1]!=' ') && (texto[i+1]!='\0'))
        {
            //Guardo indice de comienzo palabra
            if (arreP.tope==4)
            {
                printf("El comando ingresado excede el limite de parametros permitidos"); //se debe modificar por la funcion con codigo de error
                lleno = TRUE;
                resetearArregloP (arreP);
            }
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
}

void resetearArregloP (ArregloPalabras &arreP)
{
    for (int i = 0; i < TAM; i++)
    {
        strdestruir(arreP.arre[i]);
    }
    arreP.tope = 0;
}

void n_esimoPalabra (ArregloPalabras arreP, int num, stringD &s)
{
    strcop(s, arreP.arre[num]);
}


int devolverTope (ArregloPalabras arreP)
{
    return arreP.tope;
}


boolean esVacioArreP (ArregloPalabras arreP)
{
    int i = devolverTope(arreP);
    boolean iguales = FALSE;
    if (i == 0)
        iguales = TRUE;
    return iguales;
}
