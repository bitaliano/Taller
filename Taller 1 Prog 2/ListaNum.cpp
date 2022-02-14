#include "ListaNum.h"

void crearLista (ListaNum &l){
    l=NULL;
}

boolean ListaVacia(ListaNum l){
    if (l==NULL)
        return TRUE;
    else
        return FALSE;
}

void mostrarLista (ListaNum l){
    printf("[ ");
    while(l!=NULL){
        printf("%d ", info);
        l=l->sig;
    }
    printf("]");
}

int sumarValores (ListaNum l){
    int suma = 0;
    while (l != NULL)
    {
        suma = suma + l -> info;
        l = l -> sig;
    }
    return suma;
}


void insertarAtras (ListaNum &l, int num){
    if (l==NULL)
    {
        l=new nodoLista;
        l->info=num;
        l->sig=NULL;
    }
    else
        insertarAtras(l->sig,num);
}


void bajarLisArchivo (ListaNum l, stringD arch){
    FILE * f = fopen (arch, "wb");
    while (l != NULL)
    {
        fwrite (l->info, sizeof(int), 1, f);
        l = l->sig;
    }
    fclose (f);
}

void levantarLisArchivo (ListaNum l, stringD arch){
    FILE * f = fopen (arch, "rb");
    int buffer;
    crearLista (L);
    fread(buffer, sizeof(int), 1, f);
    while (!feof(f))
    {
        insertarAtras (l, buffer);
        fread(buffer, sizeof(int), 1, f);
    }
    fclose (f);
}

void destruirLista (ListaNum &l){

}

void copiarLista (ListaNum listOrigen; ListaNum &listCopia){

}

void invertirLista (ListaNum listOrigen; ListaNum &listInvert){

}
