#include <stdio.h>
#include "ABBSecuencias.h"
#include "Validaciones.h"

int main()
{
    int opcion =0;
    stringD texto;
    ArregloPalabras arreP;
    printf("Testeo\n");
    printf("Opcion 1 - Prueba palabras\n");
    printf("Opcion 2 - Prueba create\n");
    scanf("%d", &opcion);
    switch (opcion)
    {
        case 1:
            printf("Ingrese tres palabras separadas por espacios:\n");
            fflush(stdin);
            scan(texto);
            cargarArregloP(arreP, texto); // SE ROMPE CON 3 PALABRAS
            printf("el tope era %d\n", devolverTope(arreP));
            printf("El arreglo es:\n");
            mostrarArregloP(arreP);
            //printf("\nchau\n");
            //print(texto);
            /*fflush(stdin);
            printf("El arreglo quedo cargado con las palabras ingresadas\n");
            ;*/
            break;
        default:
            printf("Hola");
            break;
    }
    return 0;
}
