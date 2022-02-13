#include "boolean.h"

void cargar (boolean &b) // devuelve la variable cargada
{
    int valor;
    printf("Ingrese 0 si es falso y 1 si es verdadero: \n");
    scanf("%d", &valor);
    if (valor==0)
        b = FALSE;
    else
        b = TRUE;
}

void mostrar (boolean b) // muestra en pantalla la varibale cargada
{
    if(b)
        printf("Verdadero\n");
    else
        printf("Falso\n");
}
