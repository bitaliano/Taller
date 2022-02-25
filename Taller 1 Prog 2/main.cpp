#include <stdio.h>
#include "ABBSecuencias.h"
#include "Validaciones.h"

int main()
{
    int opcion, i=0, j;
    char c;
    stringD texto1, texto2, textoCon, textoInt, textoCom, textoArch;
    ArregloPalabras arreP;
    Secuencia sec, sec2, secSum;
    ABBSecuencias arbol;
    ListaNum l;
    ArregloComandos arreC;
    levantarComandos(arreC, "arreCom.txt");
    /*for(i=0; i<9; i++)
    {
        printf("\nComando:  ");
        print(arreC[i].comand);
        printf("\nParametros permitidos:  %d", arreC[i].param);
    }*/
    CrearArbol(arbol);
    do
    {
        printf("\nIngrese comando> ");
        strcrear(texto2);
        scan(texto2);
        cargarArregloP(arreP, texto2);
        cantParamTotal(arreP);
        strcrear(textoCom);
        n_esimoPalabra(arreP, 0, textoCom);
        opcion = 9;
        if (!existeComando(textoCom, arreC))
            mensajeError(0);
        else
            opcion = buscarComando(textoCom, arreC);
        strdestruir(textoCom);
        switch (opcion)
        {
            case 5:     /// COMANDO CREATE
                strcrear(textoCom);
                n_esimoPalabra(arreP, 1, textoCom);
                if (!cantParamCorrecta(arreP, darComando(arreC, 5)))
                    mensajeError(1);
                else
                {
                    if (!esAlfabetico(textoCom))
                        mensajeError(2);
                    else
                    {
                        if(Pertenece(arbol, textoCom))
                            mensajeError(5);
                        else
                        {
                            cargarSecuencia(sec, textoCom);
                            insertarSecuencia(arbol, sec);
                        }
                    }
                }
                strdestruir(textoCom);
                break;
            case 1:     /// COMANDO SHOW
                if (!cantParamCorrecta(arreP, darComando(arreC, 1)))
                    mensajeError(1);
                else
                {
                    if (esVacioABB(arbol))
                        printf("El arbol es vacio"); /// agregar mensaje de error
                    else
                    {
                        printf("\nResultado:\n");  /// cambiar como se muestra
                        mostrarEnOrden(arbol);
                    }
                }
                break;
            case 8:     /// COMANDO INSBACK
                strcrear(textoCom);
                strcrear(textoInt);
                n_esimoPalabra(arreP, 1, textoCom);
                n_esimoPalabra(arreP, 2, textoInt);
                if (!cantParamCorrecta(arreP, darComando(arreC, 8)))
                    mensajeError(1);
                else
                {
                    if (!esAlfabetico(textoCom))
                        mensajeError(2);
                    else
                    {
                        if(!Pertenece(arbol, textoCom)) /// Controlo existencia
                            mensajeError(6);
                        else
                        {
                            if (!esNumerico(textoInt))
                                mensajeError(4);
                            else
                            {
                                sec2 = devuelveSec(arbol, textoCom);
                                modificarLista(sec2, convertirString(textoInt));
                                modificaArbol(arbol, sec2);
                            }
                        }
                    }
                }
                strdestruir(textoCom);
                strdestruir(textoInt);
                break;
            case 0:     /// COMANDO SUM
                strcrear(textoCom);
                n_esimoPalabra(arreP, 1, textoCom);
                if (!esAlfabetico(textoCom))
                {
                    mensajeError(2);
                }
                else
                {
                    if(!Pertenece(arbol, textoCom))
                        mensajeError(6);
                    else
                    {
                        secSum = devuelveSec(arbol, textoCom);
                        printf("\nLa suma de los valores de la secuencia es: %d", sumarValores(devuelveLista(secSum)));
                    }
                }
                strdestruir(textoCom);
                break;
            case 6:     /// COMANDO CONCAT
                strcrear(textoCon);
                printf("Ingrese el comando: ");
                scan(textoCon);
                cargarArregloP(arreP, textoCon);
                cargarSecuencia(sec, arreP.arre[3]);
                crearLista(l);
                copiarLista(devuelveLista(devuelveSec(arbol, arreP.arre[1])), l);
                copiarLista(devuelveLista(devuelveSec(arbol, arreP.arre[2])), l);
                modificarSec(sec, l);
                insertarSecuencia(arbol, sec);
                strdestruir(textoCon);
                break;
            case 7:     /// COMANDO REVERSE
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
            case 4:     /// COMANDO EXIT
                destruirABB(arbol);
                printf("\nEn el arbol hay:\n");
                mostrarEnOrden(arbol);
                break;
            case 2:     /// COMANDO SAVE
                strcrear(textoCom);
                strcrear(textoArch);
                n_esimoPalabra(arreP, 1, textoCom);
                n_esimoPalabra(arreP, 2, textoArch);
                if (!esAlfabetico(textoCom))
                {
                    mensajeError(2);
                }
                else
                {
                    if(!Pertenece(arbol, textoCom)) /// Controlo existencia
                        mensajeError(6);
                    else
                    {
                        if (!esNomArchivo(textoArch))
                            mensajeError(3);
                        else
                        {
                            sec = devuelveSec(arbol, textoCom);
                            mostrarSecuencia (sec);
                            if (ListaVacia(devuelveLista(sec)))
                                printf("Error"); /// agregar mensaje de error
                            else
                            {
                                if (existeArchivo(textoArch))
                                {
                                    printf("\n¿Desea sobreescribir el archivo?   S/N\n");
                                    scanf("%c", &c);
                                    while (c != 'S' || c != 's' || c!= 'N' || c!= 'n')
                                    {
                                        fflush(stdin);
                                        if( c != 'S' || c != 's')
                                            bajarLisArchivo(devuelveLista(sec),textoArch);
                                    }
                                }
                                else
                                    bajarLisArchivo(devuelveLista(sec),textoArch);
                            }
                        }
                    }
                }
                strdestruir(textoCom);
                strdestruir(textoArch);
                break;
            case 3: /// COMANDO LOAD
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
            /*
            case 14: ///Es nombre de archivo
                strcrear(texto1);
                n_esimoPalabra(arreP,0,texto1);
                if (esNomArchivo(texto1))
                    printf("*La primera palabra es un nombre de archivo valido*");
                else
                    printf("La primera palabra NO es un nombre de archivo valido");
                strdestruir(texto1);
                break;*/
            default:
                break;
        }
    }while (opcion !=4);
    return 0;
}
