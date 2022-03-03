#include <stdio.h>
#include "ABBSecuencias.h"
#include "Validaciones.h"

int main()
{
    int opcion;
    char c;
    stringD param1, param2, param3, textoCom, texto;
    ArregloPalabras arreP;
    Secuencia sec;
    ABBSecuencias arbol;
    ListaNum l;
    ArregloComandos arreC;
    levantarComandos(arreC, "arreCom.txt");
    CrearArbol(arbol);
    do
    {
        printf("\nIngrese comando: ");
        strcrear(texto);
        scan(texto);
        cargarArregloP(arreP, texto);
        strdestruir(texto);
        opcion = 9;
        if(devolverTope(arreP)==0)
            mensajeError(12);
        else if (cantParamInvalido(arreP))
            mensajeError(1);
        else
        {
            strcrear(textoCom);
            n_esimoPalabra(arreP, 0, textoCom);
            if (!existeComando(textoCom, arreC))
                mensajeError(0);
            else
                opcion = buscarComando(textoCom, arreC);
            strdestruir(textoCom);
        }
        switch (opcion)
        {
            case 5:     /// COMANDO CREATE
                if (!cantParamCorrecta(arreP, darComando(arreC, 5)))
                    mensajeError(1);
                else
                {
                    strcrear(param1);
                    n_esimoPalabra(arreP, 1, param1);
                    if (!esAlfabetico(param1))
                        mensajeError(2);
                    else
                    {
                        if(Pertenece(arbol, param1))
                            mensajeError(5);
                        else
                        {
                            cargarSecuencia(sec, param1);
                            insertarSecuencia(arbol, sec);
                            mostrarPrimerSecuencia(sec);
                        }
                    }
                    strdestruir(param1);
                }
                break;
            case 1:     /// COMANDO SHOW
                if (!cantParamCorrecta(arreP, darComando(arreC, 1)))
                    mensajeError(1);
                else
                {
                    if (esVacioABB(arbol))
                        mensajeError(9);
                    else
                    {
                        printf("Resultado:\n");  /// cambiar como se muestra
                        mostrarEnOrden(arbol);
                    }
                }
                break;
            case 8:     /// COMANDO INSBACK
                if (!cantParamCorrecta(arreP, darComando(arreC, 8)))
                    mensajeError(1);
                else
                {
                    strcrear(param1);
                    n_esimoPalabra(arreP, 1, param1);
                    if (!esAlfabetico(param1))
                        mensajeError(2);
                    else
                    {
                        if(!Pertenece(arbol, param1)) /// Controlo existencia
                            mensajeError(6);
                        else
                        {
                            strcrear(param2);
                            n_esimoPalabra(arreP, 2, param2);
                            if (!esNumerico(param2))
                                mensajeError(4);
                            else
                            {
                                modifSecArbol(arbol,param1,convertirString(param2));
                                //sec = devuelveSec(arbol, param1);
                                //modificarLista(sec, convertirString(param2));
                                //modificaArbol(arbol, sec);
                                //mostrarPrimerSecuencia(sec);
                            }
                            strdestruir(param2);
                        }
                    }
                    strdestruir(param1);
                }
                break;
            case 0:     /// COMANDO SUM
                if (!cantParamCorrecta(arreP, darComando(arreC, 0)))
                    mensajeError(1);
                else
                {
                    strcrear(param1);
                    n_esimoPalabra(arreP, 1, param1);
                    if (!esAlfabetico(param1))
                        mensajeError(2);
                    else
                    {
                        if(!Pertenece(arbol, param1))
                            mensajeError(6);
                        else
                        {
                            //sec = devuelveSec(arbol, param1);
                            printf("Resultado:\t %d\n", sumarValores(devuelveLista(devuelveSec(arbol, param1))));
                        }
                    }
                    strdestruir(param1);
                }
                break;
            case 6:     /// COMANDO CONCAT
                if (!cantParamCorrecta(arreP, darComando(arreC, 6)))
                    mensajeError(1);
                else
                {
                    strcrear(param1);
                    n_esimoPalabra(arreP, 1, param1);
                    if (!esAlfabetico(param1))
                        mensajeError(2);
                    else
                    {
                        if(!Pertenece(arbol, param1)) /// Controlo existencia
                            mensajeError(6);
                        else
                        {
                            strcrear(param2);
                            n_esimoPalabra(arreP, 2, param2);
                            if (!esAlfabetico(param2))
                                mensajeError(2);
                            else
                            {
                                if(!Pertenece(arbol, param2)) /// Controlo existencia
                                    mensajeError(6);
                                else
                                {
                                    strcrear(param3);
                                    n_esimoPalabra(arreP, 3, param3);
                                    if (!esAlfabetico(param3))
                                        mensajeError(2);
                                    else
                                    {
                                        if(Pertenece(arbol, param3)) /// Controlo existencia
                                            mensajeError(5);
                                        else
                                        {
                                            cargarSecuencia(sec, param3);
                                            //crearLista(l);
                                            //copiarLista(devuelveLista(devuelveSec(arbol, param1)), l);
                                            //copiarLista(devuelveLista(devuelveSec(arbol, param2)), l);
                                            copiarListaEnSec(devuelveLista(devuelveSec(arbol, param1)), sec);
                                            copiarListaEnSec(devuelveLista(devuelveSec(arbol, param2)), sec);
                                            //modificarSec(sec, l);
                                            insertarSecuencia(arbol, sec);
                                            mostrarPrimerSecuencia(sec);
                                            //destruirLista(l);
                                        }
                                    }
                                    strdestruir(param3);
                                }
                            }
                            strdestruir(param2);
                        }
                    }
                    strdestruir(param1);
                }
                break;
            case 7:     /// COMANDO REVERSE
                if (!cantParamCorrecta(arreP, darComando(arreC, 7)))
                    mensajeError(1);
                else
                {
                    strcrear(param1);
                    n_esimoPalabra(arreP, 1, param1);
                    if (!esAlfabetico(param1))
                        mensajeError(2);
                    else
                    {
                        if(!Pertenece(arbol, param1)) /// Controlo existencia
                            mensajeError(6);
                        else
                        {
                            strcrear(param2);
                            n_esimoPalabra(arreP, 2, param2);
                            if (!esAlfabetico(param2))
                                mensajeError(2);
                            else
                            {
                                if(Pertenece(arbol, param2)) /// Controlo existencia
                                    mensajeError(5);
                                else
                                {
                                    cargarSecuencia(sec, param2);
                                    //crearLista(l);
                                    //invertirLista(devuelveLista(devuelveSec(arbol, param1)), l);
                                    invertirListaEnSec(devuelveLista(devuelveSec(arbol, param1)), sec);
                                    //modificarSec(sec, l);
                                    insertarSecuencia(arbol, sec);
                                    mostrarPrimerSecuencia(sec);
                                    //destruirLista(l);
                                }
                            }
                            strdestruir(param2);
                        }
                    }
                    strdestruir(param1);
                }
                break;
            case 4:     /// COMANDO EXIT
                if (!cantParamCorrecta(arreP, darComando(arreC, 4)))
                    mensajeError(1);
                else
                {
                    destruirABB(arbol);
                    printf("Resultado:\t hasta la proxima\n");
                }
                break;
            case 2:     /// COMANDO SAVE
                if (!cantParamCorrecta(arreP, darComando(arreC, 2)))
                    mensajeError(1);
                else
                {
                    strcrear(param1);
                    n_esimoPalabra(arreP, 1, param1);
                    if (!esAlfabetico(param1))
                        mensajeError(2);
                    else
                    {
                        if(!Pertenece(arbol, param1)) /// Controlo existencia
                            mensajeError(6);
                        else
                        {
                            strcrear(param2);
                            n_esimoPalabra(arreP, 2, param2);
                            if (!esNomArchivo(param2))
                                mensajeError(3);
                            else
                            {
                                sec = devuelveSec(arbol, param1);
                                if (ListaVacia(devuelveLista(sec)))
                                    mensajeError(10);
                                else
                                {
                                    if (existeArchivo(param2))
                                    {
                                        do
                                        {
                                            printf ("Resultado:\t ");
                                            print(param2);
                                            printf(" ya existe en disco, ¿sobreescribe? (S/N)? ");
                                            fflush(stdin);
                                            scanf("%c", &c);
                                            if( c == 'S' || c == 's')
                                            {
                                                bajarLisArchivo(devuelveLista(sec),param2);
                                                printf ("Resultado:\t ");
                                                print(param1);
                                                printf(" almacenada correctamente en ");
                                                print(param2);
                                                printf ("\n");
                                            }
                                        }
                                        while (c != 'S' && c != 's' && c!= 'N' && c!= 'n');
                                    }
                                    else
                                    {
                                        bajarLisArchivo(devuelveLista(sec),param2);
                                        printf ("Resultado:\t ");
                                        print(param1);
                                        printf(" almacenada correctamente en ");
                                        print(param2);
                                        printf ("\n");
                                    }
                                }
                            }
                            strdestruir(param2);
                        }
                    }
                    strdestruir(param1);
                }
                break;
            case 3: /// COMANDO LOAD
                if (!cantParamCorrecta(arreP, darComando(arreC, 3)))
                    mensajeError(1);
                else
                {
                    strcrear(param1);
                    n_esimoPalabra(arreP, 1, param1);
                    if (!esNomArchivo(param1))
                        mensajeError(3);
                    else
                    {
                        if (!existeArchivo(param1))
                            mensajeError(11);
                        else
                        {
                            strcrear(param2);
                            n_esimoPalabra(arreP, 2, param2);
                            if (!esAlfabetico(param2))
                                mensajeError(2);
                            else
                            {
                                if(Pertenece(arbol, param2)) /// Controlo existencia
                                    mensajeError(5);
                                else
                                {
                                    //crearLista(l);
                                    //levantarLisArchivo(l,param1);
                                    cargarSecuencia(sec, param2);
                                    levantarLisArchivoEnSec(sec,param1);
                                    //modificarSec(sec, l);
                                    insertarSecuencia(arbol, sec);
                                    mostrarPrimerSecuencia(sec);
                                    //destruirLista(l);
                                }
                            }
                            strdestruir(param2);
                        }
                    }
                    strdestruir(param1);
                }
                break;
            default:
                break;
        }
    }while (opcion !=4);
    return 0;
}
