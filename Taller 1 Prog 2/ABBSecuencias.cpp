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
    if (streq(devuelveIdent(a->info), ident))
        return a->info;
    else
    {
        if (strmen(devuelveIdent(a->info), ident))
            return devuelveSec (a->hder, ident);
        else
            return devuelveSec (a->hizq, ident);
    }
}

void modifSecArbol (ABBSecuencias &a, stringD ident, int n)
{
    if (streq(devuelveIdent(a->info), ident))
    {
        modificarLista(a->info,n);
        mostrarPrimerSecuencia(a->info);
    }
    else
    {
        if (strmen(devuelveIdent(a->info), ident))
            modifSecArbol (a->hder, ident, n);
        else
            modifSecArbol (a->hizq, ident, n);
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
        if (strmen(devuelveIdent(a->info), devuelveIdent(sec)))
            insertarSecuencia(a->hder , sec);
        else
            insertarSecuencia(a->hizq, sec);
    }
}

boolean Pertenece (ABBSecuencias a, stringD ident)
{
    if (a==NULL)
        return FALSE;
    else if (streq(devuelveIdent(a->info), ident))
        return TRUE;
    else
    {
        if (strmen(devuelveIdent(a->info), ident))
            return Pertenece(a->hder, ident);
        else
            return Pertenece(a->hizq, ident);
    }
}

/*void modificaArbol (ABBSecuencias &a, Secuencia sec)
{
    if(streq(devuelveIdent(a->info), devuelveIdent(sec)))
        a->info = sec;
    else
    {
        if (strmen(devuelveIdent(a->info), devuelveIdent(sec)))
            modificaArbol(a->hder, sec);
        else
            modificaArbol(a->hizq, sec);
    }
}*/

void mostrarEnOrden (ABBSecuencias a)
{
    if (a != NULL)
    {
        mostrarEnOrden(a ->hizq);
        mostrarSecuencia(a->info);
        mostrarEnOrden(a->hder);
    }
}

/*ABBSecuencias constructABB (Secuencia raiz, ABBSecuencias i, ABBSecuencias  d)
{
    ABBSecuencias a = new nodoSecuencia;
    a -> info = raiz;
    a -> hizq = i;
    a -> hder = d;
    return a;
}*/


void destruirABB (ABBSecuencias &a)
{
    if(a!=NULL)
    {
        destruirABB(a->hizq);
        destruirABB(a->hder);
        ListaNum l = devuelveLista(a->info);
        destruirLista(l);
        stringD s = devuelveIdent(a->info);
        strdestruir(s);
        delete(a);
        a=NULL ;
    }
}



