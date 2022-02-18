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
            return devuelveSec (a->hizq, ident);
        else
            return devuelveSec (a->hder, ident);
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
            insertarSecuencia(a->hizq , sec);
        else
            insertarSecuencia(a->hder, sec);
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
            return Pertenece(a->hizq, ident);
        else
            return Pertenece(a->hder, ident);
    }
}

void mostrarEnOrden (ABBSecuencias a)
{

    if (a->hizq != NULL)
        mostrarEnOrden(a->hizq);

    print(devuelveIdent(a->info));

    if (a->hder != NULL)
        mostrarEnOrden(a->hder);
}

ABBSecuencias constructABB (Secuencia raiz, ABBSecuencias i, ABBSecuencias  d)
{
ABBSecuencias a = new nodoSecuencia;
a -> info = raiz;
a -> hizq = i;
a -> hder = d;
return a;
}

void destruirABB (ABBSecuencias &a)
{

if(a!=NULL){
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






