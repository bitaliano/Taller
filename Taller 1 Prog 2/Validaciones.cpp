#include "Validaciones.h"


void cantParamTotal (ArregloPalabras arreP)
{
    if (devolverTope(arreP) == 5)
    {
        resetearArregloP(arreP);
        mensajeError(1);
    }
}

boolean existeComando (stringD s, ArregloComandos arreC)
{
    boolean existe = FALSE;
	int	i = 0;
    stringD com;
    strcrear(com);
    while (!existe && i <9)
    {
		n_esimoComando(arreC,i,com);
        if (streq(com, s))
			existe = TRUE;
		i++;
    }
    strdestruir(com);
    return existe;
}

int buscarComando (stringD s, ArregloComandos arreC)
{
    int i = 0;
    stringD com;
    strcrear(com);
    n_esimoComando(arreC,0,com);
    while (!streq(s, com)){
        i++;
        n_esimoComando(arreC,i,com);
    }
    strdestruir(com);
    return i;
}

boolean esAlfabetico (stringD s)
{
    boolean esalfa=TRUE;
    int i=0;
    while((esalfa)&&(s[i]!='\0'))
    {
        if( s[i]<'A' || (s[i]>'Z' && s[i]<'a') || s[i]>'z' )
            esalfa =FALSE;
        i++;
    }
    return esalfa;
}

boolean cantParamCorrecta (ArregloPalabras arreP, Comando com)
{
    boolean correcto=TRUE;
    if (devolverTope(arreP)!=devuelveCantParam(com))
        correcto=FALSE;
    return correcto;
}
/*devuelve TRUE si el arreglo de palabras tiene la cantidad correcta de par�metros definidos para el comando*/

boolean existeSecuencia (stringD ident, ABBSecuencias a)
{
    return Pertenece(a,ident);
}


void mensajeError (int codError)
{
    switch (codError)
    {
    case 0:
        printf("\n Error: El comando ingresado no existe\n");
        break;
    case 1:
        printf("\n Error: El numero de parametros ingresados excede el limite de parametros permitidos\n");
        break;
    case 2:
        printf("\n Error: Los caracteres ingresados deben ser alfabeticos solamente\n");
        break;

    case 3:
        printf("\n Error: El nombre del archivo debe finalizar en .txt\n");
        break;

    case 4:
        printf("\n Error: El segundo parametro debe ser numerico\n");
        break;

    case 5:
        printf("\n Error: El identificador ingresado ya existe en memoria\n");
        break;

    case 6:
        printf("\n Error: El identificador ingresado no existe en memoria\n");
        break;

    case 7:
        printf("\n Error: El archivo ingresado por parametro ya existe\n");
        break;

    case 8:
        printf("\n Error: El archivo ingresado por parametro no existe\n");
        break;

    default:
        break;
    }
}


boolean esNumerico (stringD s)
{
    boolean esnum=TRUE;
    int i=0;
    while((esnum)&&(s[i]!='\0'))
    {
        if(s[i]<'0' || s[i]>'9')
            esnum =FALSE;
        i++;
    }
    return esnum;
}
//devuelve TRUE si el string es num�rico

boolean esNomArchivo (stringD s)
{
    boolean esarch=TRUE;
    int i=0;
    while( (esarch) && (s[i]!='\0') && (s[i]!='.'))
    {
        if( ((s[i]<'A') && (s[i]>'Z')) && ((s[i]<'a') && (s[i]>'z')) )
            esarch =FALSE;
        i++;
    }
    if(s[i]=='\0' || !esarch)
        esarch =FALSE;
    else
    {
        i++;
        if (s[i]!='t')
            esarch =FALSE;
        else if (s[i+1]!='x')
            esarch =FALSE;
        else if (s[i+2]!='t')
            esarch =FALSE;
        else if (s[i+3]!='\0')
            esarch =FALSE;
    }
    return esarch;
}


boolean existeArchivo (stringD nomArch)
{
    boolean existeArchivo = TRUE;
    FILE * f = fopen (nomArch, "rb");
    if (f == NULL)
        existeArchivo = FALSE;
    else
        fclose (f);
    return existeArchivo;
}
