#include "ListaNum.h"

void crearLista (ListaNum &l)
{
    l=NULL;
}

boolean ListaVacia(ListaNum l)
{
    if (l==NULL)
        return TRUE;
    else
        return FALSE;
}

void mostrarLista (ListaNum l)
{
    printf("[");
    while(l!=NULL)
    {
        printf("%d", l->info);
        l=l->sig;
        if (l!=NULL)
            printf(" ");
    }
    printf("]");
}

int sumarValores (ListaNum l)
{
    int suma = 0;
    while (l != NULL)
    {
        suma = suma + l -> info;
        l = l -> sig;
    }
    return suma;
}


void insertarAtras (ListaNum &l, int num)
{
    if (l==NULL)
    {
        l=new nodoLista;
        l->info=num;
        l->sig=NULL;
    }
    else
        insertarAtras(l->sig,num);
}


void bajarLisArchivo (ListaNum l, stringD arch)
{
    FILE * f = fopen (arch, "wb");
    while (l != NULL)
    {
        fwrite (&l->info, sizeof(int), 1, f);
        l = l->sig;
    }
    fclose (f);
}

void levantarLisArchivo (ListaNum &l, stringD arch)
{
    FILE * f = fopen (arch, "rb");
    int buffer;
    //crearLista (l);
    fread(&buffer, sizeof(int), 1, f);
    while (!feof(f))
    {
        insertarAtras (l, buffer);
        fread(&buffer, sizeof(int), 1, f);
    }
    fclose (f);
}

void destruirLista (ListaNum &l)
{
    if (l != NULL)
    {
        ListaNum aux = l;
        l = l -> sig;
        //mostrarLista(l);
        delete aux;
        destruirLista (l);
    }
}


void copiarLista (ListaNum lOrigen, ListaNum &lCopia)
{
    while (lOrigen != NULL)
    {
        insertarAtras(lCopia,lOrigen->info);
        lOrigen = lOrigen->sig;
    }
}

void invertirLista (ListaNum listOrigen, ListaNum &listInvert)
{
    if (listOrigen != NULL)
    {
        invertirLista(listOrigen->sig, listInvert);
        insertarAtras(listInvert,listOrigen->info);
    }
}
