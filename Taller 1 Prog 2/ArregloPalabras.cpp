#include "ArregloPalabras.h"



void cargarArregloP (ArregloPalabras &arreP, stringD s){
    boolean lleno = FALSE;
    tope=0;
    if ((texto[i]!='\0') && (texto[i]!=' ')) {
        //Guardo puntero de comienzo palabra
        k=i;
    }
    while (texto[i]!='\0' && !lleno ) {
        if ((texto[i]==' ') && (texto[i+1]!=' ') && (texto[i+1]!='\0')) {
            //Guardo puntero de comienzo palabra
            if (tope=3){
                printf("El comando ingresado excede el limite de parametros ingresados");
                lleno = TRUE;
                resetearArregloP (arreP);
            }
		k=i+1;
        }
        else {
            if ((texto[i]!=' ') && ((texto[i+1]==' ') || (texto[i+1]=='\0'))){
                f=i;
                strcopPalabra(arreP[tope], s, k, f);
                tope++;
            }
        }
        i++;
    }
}
