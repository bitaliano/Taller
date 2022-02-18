#include <stdio.h>
#include "ABBSecuencias.h"
#include "Validaciones.h"

int main()
{
    int opcion =0;
    stringD texto, texto1, texto2;
    strcrear(texto);
    strcrear(texto1);
    strcrear(texto2);
    ArregloPalabras arreP;
    Secuencia sec;
    ABBSecuencias arbol, a1, a2;
    CrearArbol(arbol);
    ///Prueba de construir arbol para luego insertar y comparar
    CrearArbol(a1);
    CrearArbol(a2);
    printf("Ingrese el nombre de la primer secuencia:\n");
    fflush(stdin);
    scan(texto);
    //print(texto);
    cargarSecuencia(sec, texto);
    arbol = constructABB(sec, a1, a2);
    printf("en el arbol hay:\n");
    mostrarEnOrden(arbol);
    ///Hasta aca va prueba de construir arbol
    do
    {
        printf("\n\nMenu Testeo\n");
        printf("Opcion 1 - Prueba palabras\n");
        printf("Opcion 2 - Prueba create\n");
        scanf("%d", &opcion);
        switch (opcion)
        {
            case 1:
                printf("Ingrese tres palabras separadas por espacios:\n");
                fflush(stdin);
                scan(texto1);
                print(texto1);
                cargarArregloP(arreP, texto1); // ANDA BARBARO PARA DOS, SE ROMPE PARA 3 O MAS
                printf("\nEl tope era %d\n", devolverTope(arreP));
                printf("El arreglo es:\n");
                mostrarArregloP(arreP);
                break;
            case 2:
                printf("Ingrese el nombre de la secuencia:\n");
                scan(texto1);
                cargarSecuencia(sec, texto1);
                fflush(stdin);
                insertarSecuencia(arbol, sec); //Borra nodos y copia varias veces la secuencia
                ///Prueba para ver como anda el streq y strmen con strings desde funciones
                if (streq(devuelveIdent(arbol->info), devuelveIdent(sec)))
                    printf("\nIGUALES");
                else
                {
                    if (strmen(devuelveIdent(arbol->info), devuelveIdent(sec)))
                        printf("\nTRUE");
                    else
                        printf("\nFALSE");
                }
                ///Aca termina la prueba de streq y strmen
                printf("\nEn el arbol hay:\n");
                mostrarEnOrden(arbol);
                break;
            default:
                printf("\nChau\n");
        }
    }while (opcion <3);
    return 0;
}
