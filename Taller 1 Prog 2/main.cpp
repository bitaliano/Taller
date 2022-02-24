#include <stdio.h>
#include "ABBSecuencias.h"
#include "Validaciones.h"

int main()
{
    int opcion =0, numero =0, i,j;
    stringD texto1, texto2, texto3, insertar, sumar;
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
        printf("Opcion 1 - Prueba separar palabras\n");
        printf("Opcion 2 - Prueba comando create\n");
        printf("Opcion 3 - Prueba comando show\n");
        printf("Opcion 4 - Prueba comando insback\n");
        printf("Opcion 5 - Prueba comando sum\n");
        printf("Opcion 6 - Prueba comando concat\n");
        printf("Opcion 7 - Prueba comando reverse\n");
        printf("Opcion 8 - Prueba comando exit\n");
        printf("Opcion 9 - Prueba comando save\n");
        printf("Opcion 10 - Prueba comando load\n");
        printf("Opcion 11 - Prueba bajar arreglo de comandos\n");
        printf("Opcion 12 - Prueba levantar arreglo de comandos\n");
        printf("Opcion 13 - Prueba control es alfabetico\n");
        printf("Opcion 14 - Prueba control es numerico\n");
        printf("Opcion 15 - Prueba control es nombre de archivo\n");
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
            case 5:   /// COMANDO SUM
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
            case 6:   /// COMANDO CONCAT
                strcrear(texto1);
                strcrear(texto2);
                strcrear(texto3);
                printf("\nInserte la primer secuencia:   ");
                scan(texto1);
                printf("\nInserte la segunda secuencia:   ");
                scan(texto2);
                printf("\nInserte la secuencia concatenada:   ");
                scan(texto3);
                cargarSecuencia(sec, texto3);
                crearLista(l);
                copiarLista(devuelveLista(devuelveSec(arbol, texto2)), l);
                copiarLista(devuelveLista(devuelveSec(arbol, texto1)), l);
                modificarSec(sec, l);
                insertarSecuencia(arbol, sec);
                strdestruir(texto1);
                strdestruir(texto2);
                strdestruir(texto3);
                break;
            case 7:   /// COMANDO REVERSE
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
            case 8:   /// COMANDO EXIT
                destruirABB(arbol);
                printf("\nEn el arbol hay:\n");
                mostrarEnOrden(arbol);
                break;
            case 9: /// COMANDO SAVE
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
            case 10: /// COMANDO LOAD
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
            case 11: ///CREAR y BAJAR ARREGLO DE COMANDOS
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
            case 12: ///LEVANTAR ARCHIVO COMANDOS
                strcrear(texto1);
                printf("\nInserte el nombre del archivo de COMANDOS:   ");
                scan(texto1);
                levantarComandos(arreC, texto1);
                ///MUESTRO EL ARREGLO PARA VER C�MO QUED�
                for(i=0; i<9; i++)
                {
                    printf("\nComando:  ");
                    print(arreC[i].comand);
                    printf("\nParametros permitidos:  %d", arreC[i].param);
                }
                break;
            case 13: ///Es alfabetico
                strcrear(texto1);
                n_esimoPalabra(arreP,0,texto1);
                if (esAlfabetico(texto1))
                    printf("*La primera palabra es alfabetica*");
                else
                    printf("La primera palabra NO es alfabetica");
                strdestruir(texto1);
                break;
            case 14: ///Es numerico
                strcrear(texto1);
                n_esimoPalabra(arreP,0,texto1);
                if (esNumerico(texto1))
                    printf("*La primera palabra es numerica*");
                else
                    printf("La primera palabra NO es numerica");
                strdestruir(texto1);
                break;
            case 15: ///Es nombre de archivo
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
    }while (opcion <16);
    return 0;
}
