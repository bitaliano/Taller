#include "Validaciones.h"

int buscarComando (stringD s, ArregloComandos arreC);
//busca un string en el arreglo y devuelve su posici�n

boolean esAlfabetico (stringD s);
//devuelve TRUE si el string es puramente alfab�tico

boolean cantParamCorrecta (ArregloPalabras arreP, Comando com);
/*devuelve TRUE si el arreglo de palabras tiene la cantidad correcta de par�metros definidos para el comando*/

boolean existeSecuencia (stringD ident, ABBSecuencias a);
/*devuelve TRUE si existe en el �rbol una secuencia que coincida con el identificador que se pasa como par�metro*/
//PRECONDICI�N: a !esVacioABB

void mensajeError (int codError)
{
    switch (codError)
    {
    case 1:
        printf("Se ha excedido el limite de parametros permitidos para el comando ingresado");
        break;
    
    case 2:
        printf("Los caracteres ingresados deben ser alfabeticos solamente");
        break;
    
    case 3:
        printf("El nombre del archivo debe finalizar en .txt");
        break;

    case 4:
        printf("El parametro debe ser numerico");
        break;
    
    case 5:
        printf("El identificador ingresado ya existe en memoria");
        break;

    case 6:
        printf("El identificador ingresado no existe en memoria");
        break;
    
    case 7: 
        printf("El archivo ingresado por parametro ya existe");
        break;

    case 8: 
        printf("El archivo ingresado por parametro no existe");
        break;

    default:
        break;
    }
}


boolean esNumerico (stringD s);
//devuelve TRUE si el string es num�rico

boolean esNomArchivo (stringD s);
//devuelve TRUE si el nombre es alfab�tico hasta el punto y termina en .txt

boolean existeArchivo (stringD nomArch);
//devuelve TRUE si existe un archivo con el nombre pasado por par�metro