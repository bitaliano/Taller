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

Secuencia devuelveSec (ABBSecuencias a, stringD ident, stringD &s)
{
    devuelveIdent(a->info, s);
    if (streq(s, ident))
        return a->info;
    else
    {
        if (strMayor(s, ident))
            return devuelveSec (a->hizq, ident,s);
        else
            return devuelveSec (a->hder, ident,s);
    }
}


ABBSecuencias HijoIzq (ABBSecuencias a)
{
    return a -> hizq;
}

ABBSecuencias HijoDer (ABBSecuencias a)
{
    return a -> hder;
}

void insertarSecuencia (ABBSecuencias &a, Secuencia sec, stringD &s)
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
        stringD t;
        strcrear(t);
        devuelveIdent(a->info, s);
        devuelveIdent(sec, t);
        if (strMayor(s, t))
            insertarSecuencia(a->hizq , sec);
        else
            insertarSecuencia(a->hder, sec);
    }
}

boolean Pertenece (ABBSecuencias a, stringD ident)
{
    if (a==NULL)
        return FALSE;
    else if streq(devuelveIdent(a->info), ident)
        return TRUE;
    else
    {
        if strMayor(devuelveIdent(a->info), ident);
            return Pertenece(a->hizq, ident);
        else
            return Pertenece(a->hder, ident);
    }
}







