#include "ArregloPalabras.h"



void cargarArregloP (ArregloPalabras &arreP, stringD s){
    boolean lleno = FALSE;
    arreP.tope=0;
    if ((texto[i]!='\0') && (texto[i]!=' ')) {
        //Guardo indice de comienzo palabra
        k=i;
    }
    while (texto[i]!='\0' && !lleno ) {
        if ((texto[i]==' ') && (texto[i+1]!=' ') && (texto[i+1]!='\0')) {
            //Guardo indice de comienzo palabra
            if (arreP.tope=4){
                printf("El comando ingresado excede el limite de parametros ingresados"); //se debe modificar por la funcion con codigo de error
                lleno = TRUE;
                resetearArregloP (arreP);
            }
		k=i+1;
        }
        else {
            if ((texto[i]!=' ') && ((texto[i+1]==' ') || (texto[i+1]=='\0'))){
                f=i;
                strcopPalabra(arreP[arreP.tope], s, k, f);
                arreP.tope++;
            }
        }
        i++;
    }
}
