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

}

void insFrontLista(ListaNum &l, int num){
    ListaNum aux;
    aux=new nodoLista;
    aux->info=num;
    aux->sig=l;
    l=aux;
}

void insertarAtras (ListaNum &l, int num){
    ListaNum aux=l;
    ListaNum aux2;
    if(ListaVacia(l))
        insFrontLista(l,num);
    else{
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux2=new nodoLista;
        aux2->info=num;
        aux2->sig=NULL;
        aux->sig=aux2;
    }
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
