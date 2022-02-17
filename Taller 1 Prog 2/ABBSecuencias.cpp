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
            devuelveSec (a->hder, ident);
        else
            devuelveSec (a->hizq, ident);
}

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
            insertarSecuencia(a->hder, sec);
        else
            insertarSecuencia(a->hizq, sec);
    }
}

boolean Pertenece (ABBSecuencias a, stringD ident)
{
    if (a == NULL)
        return FALSE;
    else
    {
        if(streq((devuelveIdent(a->info, s),ident)))
            return TRUE;
        else
        {
            if (strMayor(devuelveIdent(a->info, s), ident))
                return Pertenece(a->hder, ident);
            else
                return Pertenece (a->hizq, ident);
        }
    }
}






