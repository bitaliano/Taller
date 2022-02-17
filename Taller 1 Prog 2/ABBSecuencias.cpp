#include "ABBSecuencias.h"

void CrearArbol (ABBSecuencias &a)
{
    a = NULL;
}

boolean esVacioABB (ABBSecuencias a)
{
    return (boolean) (a == NULL);
}

Secuencia DarRaiz (ABBSecuencias a)
{
    return a -> info;
}

Secuencia devuelveSec (ABBSecuencias a, stringD ident)
{
    if (streq(devuelveIdent(a->info, s), ident))
        return a->info;
    else
        if (strMayor(devuelveIdent(a->info, s), ident))
            return devuelveSec (a->hizq, ident);
        else
            return devuelveSec (a->hder, ident);
}
   /* {
        if (strMayor(devuelveIdent(a->info, s), ident))
            devuelveSec (a->hizq, ident);
        else
            devuelveSec (a->hder, ident);
    }

}*/

ABBSecuencias HijoIzq (ABBSecuencias a)
{
    return a -> hizq;
}

ABBSecuencias HijoDer (ABBSecuencias a)
{
    return a -> hder;
}

void insertarSecuencia (ABBSecuencias &a, Secuencia sec)
{
    if (a == NULL)
    {
        a = new nodoSecuencia;
        a->info = sec;
        a -> hizq = NULL;
        a -> hder = NULL;
    }
    else
    {
        if (strMayor(devuelveIdent(a->info, s), devuelveIdent(sec, t)))
            insertarSecuencia(a->hizq , sec);
        else
            insertarSecuencia(a->hder, sec);
    }
}

boolean Pertenece (ABBSecuencias a, stringD ident)
{
    if (a==NULL)
        return FALSE;
    else
        if streq(devuelveIdent(a->info, ident))
            return TRUE;
    else
    {
        if strMayor(devuelveIdent(a->info, ident);
            return Pertenece(a->hizq, ident);
        else
            return Pertenece(a->hder, ident);
    }
}







