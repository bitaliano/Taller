#include <stdio.h>
#include "ABBSecuencias.h"
#include "Validaciones.h"

int main()
{
    int opcion =0, numero =0;
    stringD texto1, texto2, insertar, sumar;
    strcrear(insertar);
    ArregloPalabras arreP;
    Secuencia sec, sec2, secSum;
    ABBSecuencias arbol;
    CrearArbol(arbol);
    do
    {
        printf("\n\n-----Menu Testeo-----\n\n");
        printf("Opcion 1 - Prueba separar palabras\n");
        printf("Opcion 2 - Prueba comando create\n");
        printf("Opcion 3 - Prueba comando show\n");
        printf("Opcion 4 - Prueba comando insback\n");
        printf("Opcion 5 - Prueba comando sum\n");
        printf("\nSu opcion:   ");
        scanf("%d", &opcion);
        printf("\n");
        switch (opcion)
        {
            case 1:   /// SEPARAR PALABRAS
                strcrear(texto1);
                printf("Ingrese palabras (maximo 4 palabras), para finalizar pulse ENTER:\n");
                scan(texto1);
                cargarArregloP(arreP, texto1);
                mostrarArregloP(arreP);
                strdestruir(texto1);
                break;
            case 2:   /// COMANDO CREATE
                strcrear(texto2);
                printf("Ingrese el nombre de la secuencia a crear:\n");
                scan(texto2);
                if(Pertenece(arbol, texto2)) /// Controlo existencia
                    printf("\nLa secuencia pertenece al arbol, debe crear una nueva");
                else
                {
                    cargarSecuencia(sec, texto2);
                    insertarSecuencia(arbol, sec);
                }
                strdestruir(texto2);
                break;
            case 3:   /// COMANDO SHOW
                printf("\nEn el arbol hay:\n");
                mostrarEnOrden(arbol);
                break;
            case 4:   /// COMANDO INSBACK
                strcrear(insertar);
                printf("\nIngrese la secuencia a la que le quiere insertar un entero:\n");
                scan(insertar);
                if(Pertenece(arbol, insertar)) /// Controlo existencia
                {
                    printf("\nIngrese el numero entero que desea insertar:  ");
                    scanf("%d", &numero);
                    sec2 = devuelveSec(arbol, insertar);
                    modificarLista(sec2, numero);
                    modificaArbol(arbol, sec2);
                }
                else
                    printf("\nLa secuencia no pertenece al arbol, debe crearla primero");
                strdestruir(insertar);
                break;
            case 5:
                strcrear(sumar);
                printf("\nInserte la secuencia que quiere sumar:  ");
                scan(sumar);
                if(Pertenece(arbol, insertar)) /// Controlo existencia
                {
                    secSum = devuelveSec(arbol, sumar);
                    printf("\nLa suma de los valores de la secuencia es: %d", sumarValores(devuelveLista(secSum)));
                }
                else
                    printf("\nLa secuencia no se encuentra en el arbol");
                strdestruir(sumar);
                break;
            default:
                printf("\nChau\n");
        }
    }while (opcion <7);
    return 0;
}
