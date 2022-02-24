#include <stdio.h>
#include "ABBSecuencias.h"
#include "Validaciones.h"

int main()
{
    int opcion =0, numero =0, i,j;
    stringD texto1, texto2, textoCon, insertar, sumar;
    strcrear(insertar);
    ArregloPalabras arreP;
    Secuencia sec, sec2, secSum;
    ABBSecuencias arbol;
    ListaNum l;
    ArregloComandos arreC;
    CrearArbol(arbol);
    do
    {
        printf("\n\n-----Menu Testeo-----\n\n");
        printf("Opcion 1 - Prueba comando create\n");
        printf("Opcion 2 - Prueba comando show\n");
        printf("Opcion 3 - Prueba comando insback\n");
        printf("Opcion 4 - Prueba comando sum\n");
        printf("Opcion 5 - Prueba comando concat\n");
        printf("Opcion 6 - Prueba comando reverse\n");
        printf("Opcion 7 - Prueba comando exit\n");
        printf("Opcion 8 - Prueba comando save\n");
        printf("Opcion 9 - Prueba comando load\n");
        printf("Opcion 10 - Prueba bajar arreglo de comandos\n");
        printf("Opcion 11 - Prueba levantar arreglo de comandos\n");
        printf("Opcion 12 - Prueba control es alfabetico\n");
        printf("Opcion 13 - Prueba control es numerico\n");
        printf("Opcion 14 - Prueba control es nombre de archivo\n");
        printf("\nSu opcion:   ");
        scanf("%d", &opcion);
        printf("\n");
        switch (opcion)
        {
            case 1:   /// COMANDO CREATE
                strcrear(texto2);
                printf("Ingrese el comando: ");
                scan(texto2);
                cargarArregloP(arreP, texto2);
                if(Pertenece(arbol, arreP.arre[1]))
                    mensajeError(5);
                else
                {
                    cargarSecuencia(sec, arreP.arre[1]);
                    insertarSecuencia(arbol, sec);
                }
                strdestruir(texto2);
                break;
            case 2:   /// COMANDO SHOW
                strcrear(texto2);
                printf("Ingrese el comando: ");
                scan(texto2);
                cargarArregloP(arreP, texto2);
                printf("\nEn el arbol hay:\n");
                mostrarEnOrden(arbol);
                break;
            case 3:   /// COMANDO INSBACK
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
            case 4:   /// COMANDO SUM
                strcrear(sumar);
                printf("Ingrese el comando: ");
                scan(sumar);
                cargarArregloP(arreP, sumar);
                if (!esAlfabetico(arreP.arre[1]))
                {
                    mensajeError(2);
                }
                else
                {
                    if(!Pertenece(arbol, arreP.arre[1]))
                        mensajeError(6);
                    else
                    {
                        secSum = devuelveSec(arbol, arreP.arre[1]);
                        printf("\nLa suma de los valores de la secuencia es: %d", sumarValores(devuelveLista(secSum)));
                    }
                }
                strdestruir(sumar);
                break;
            case 5:   /// COMANDO CONCAT
                strcrear(textoCon);
                printf("Ingrese el comando: ");
                scan(textoCon);
                cargarArregloP(arreP, textoCon);
                cargarSecuencia(sec, arreP.arre[3]);
                crearLista(l);
                copiarLista(devuelveLista(devuelveSec(arbol, arreP.arre[2])), l);
                copiarLista(devuelveLista(devuelveSec(arbol, arreP.arre[1])), l);
                modificarSec(sec, l);
                insertarSecuencia(arbol, sec);
                strdestruir(textoCon);
                break;
            case 6:   /// COMANDO REVERSE
                strcrear(texto1);
                strcrear(texto2);
                printf("\nInserte la primer secuencia:   ");
                scan(texto1);
                printf("\nInserte la segunda secuencia:   ");
                scan(texto2);
                cargarSecuencia(sec, texto2);
                crearLista(l);
                invertirLista(devuelveLista(devuelveSec(arbol, texto1)), l);
                modificarSec(sec, l);
                insertarSecuencia(arbol, sec);
                strdestruir(texto1);
                strdestruir(texto2);
                break;
            case 7:   /// COMANDO EXIT
                destruirABB(arbol);
                printf("\nEn el arbol hay:\n");
                mostrarEnOrden(arbol);
                break;
            case 8: /// COMANDO SAVE
                strcrear(texto1);
                printf("\nInserte el nombre de la secuencia:   ");
                scan(texto1);
                strcrear(texto2);
                printf("\nInserte el nombre del archivo:   ");
                scan(texto2);
                sec = devuelveSec(arbol, texto1);
                bajarLisArchivo(devuelveLista(sec),texto2);
                strdestruir(texto1);
                strdestruir(texto2);
                break;
            case 9: /// COMANDO LOAD
                strcrear(texto2);
                printf("\nInserte el nombre del archivo:   ");
                scan(texto2);
                crearLista(l);
                levantarLisArchivo(l,texto2);
                strcrear(texto1);
                printf("\nInserte el nombre de la secuencia:   ");
                scan(texto1);
                cargarSecuencia(sec, texto1);
                modificarSec(sec, l);
                insertarSecuencia(arbol, sec);
                strdestruir(texto1);
                strdestruir(texto2);
                break;
            case 10: ///CREAR y BAJAR ARREGLO DE COMANDOS
                strcrear(texto1);
                strcrear(texto2);
                printf("\nInserte el nombre del archivo de COMANDOS:   ");
                scan(texto2);
                i = 0;
                while (i<N)
                {
                    fflush(stdin);
                    printf("\nInserte el nombre del COMANDO:   ");
                    scan(texto1);
                    printf("\nInserte la cantidad de parametros admitida por el comando:    ");
                    scanf("%d",&j);
                    cargarComando(arreC[i], texto1, j);
                    i++;
                }
                bajarComandos(arreC, texto2);
                strdestruir(texto1);
                strdestruir(texto2);
                break;
            case 11: ///LEVANTAR ARCHIVO COMANDOS
                strcrear(texto1);
                printf("\nInserte el nombre del archivo de COMANDOS:   ");
                scan(texto1);
                levantarComandos(arreC, texto1);
                ///MUESTRO EL ARREGLO PARA VER CÓMO QUEDÓ
                for(i=0; i<9; i++)
                {
                    printf("\nComando:  ");
                    print(arreC[i].comand);
                    printf("\nParametros permitidos:  %d", arreC[i].param);
                }
                break;
            case 12: ///Es alfabetico
                strcrear(texto1);
                n_esimoPalabra(arreP,0,texto1);
                if (esAlfabetico(texto1))
                    printf("*La primera palabra es alfabetica*");
                else
                    printf("La primera palabra NO es alfabetica");
                strdestruir(texto1);
                break;
            case 13: ///Es numerico
                strcrear(texto1);
                n_esimoPalabra(arreP,0,texto1);
                if (esNumerico(texto1))
                    printf("*La primera palabra es numerica*");
                else
                    printf("La primera palabra NO es numerica");
                strdestruir(texto1);
                break;
            case 14: ///Es nombre de archivo
                strcrear(texto1);
                n_esimoPalabra(arreP,0,texto1);
                if (esNomArchivo(texto1))
                    printf("*La primera palabra es un nombre de archivo valido*");
                else
                    printf("La primera palabra NO es un nombre de archivo valido");
                strdestruir(texto1);
                break;
            default:
                printf("\nChau\n");
        }
    }while (opcion <15);
    return 0;
}
