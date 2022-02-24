#include "stringD.h"

void strcrear (stringD &s)
{
    s=new char[1];
    s[0]='\0';
}


void strdestruir (stringD &s)
{
    delete[]s;
    s=NULL;
}


 int strlar (stringD s)
 {
    int i=0;
    while(s[i]!='\0')
        i++;
    return i;
 }


void strcop(stringD &s1,stringD s2)
{
    int largo, i=0;
    strdestruir(s1);
    largo=strlar(s2);
    s1=new char[largo+1];
    while (s2[i]!='\0')
    {
        s1[i]=s2[i];
        i++;
    }
    s1[i]='\0';
}


void strcopPalabra(stringD &s1, stringD s2, int desde, int hasta)
{
    int largo = hasta-desde, i=desde, j=0;
    s1 = new char[largo+1];
    while (i != hasta+1)
    {
        s1[j] = s2[i];
        i++;
        j++;
    }
    s1[j] = '\0';
}


 void scan (stringD &s)
 {
    stringD aux=new char[MAX];
    int i=0;
    char c;
    fflush(stdin);
    scanf("%c",&c);
    while((c!='\n') && (i<MAX-1))
    {
        aux[i]=c;
        i++;
        scanf("%c",&c);
    }
    aux[i]='\0';
    strcop(s,aux);
    strdestruir(aux);
 }


void strcon(stringD &s1,stringD s2)
{
    int largoT,i,j=0;
    largoT=strlar(s1)+strlar(s2)+1;
    if (largoT>MAX)
        largoT=MAX;
    stringD aux=new char[largoT];
    strcop(aux,s1);
    i=strlar(s1)+1;
    while(i<largoT)
    {
        aux[i]=s2[j];
        i++;
        j++;
    }
}


void strswp (stringD &s1,stringD &s2)
{
    stringD aux;
    aux=s1;
    s1=s2;
    s2=aux;
}


void print (stringD s)
{
    int i=0;
    while (s[i]!='\0')
    {
       printf("%c",s[i]);
       i++;
    }
}


boolean strmen (stringD s1,stringD s2)
{
    int i=0;
    boolean distintos = FALSE;
    boolean menor = FALSE;
    while ((s1[i] != '\0' && s2[i] != '\0') && !(distintos))
    {
        if(s1[i] != s2[i])
            distintos = TRUE;
        if(s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if(!(distintos) && s2[i] != '\0')
        menor = TRUE;
    return menor;
}


boolean streq (stringD s1,stringD s2)
{
    boolean igual=TRUE;
    int i=0;
    while((igual)&&(s1[i]!='\0')&&(s2[i]!='\0'))
    {
        if(s1[i]!=s2[i])
            igual =FALSE;
        i++;
    }
    if (s2[i]!='\0'|| s1[i]!='\0')
        igual=FALSE;
    return igual;
}


int convertirString (stringD s);  
//convierte strings numéricos en números enteros 
//PRECONDICIÓN: s esNumerico 


void Bajar_String (stringD s, FILE * f)
{
     int i=0;
     while (s[i] != '\0')
     {
         fwrite (&s[i], sizeof(char), 1, f);
         i++;
     }
     fwrite (&s[i], sizeof(char), 1, f);
}
void Levantar_String (stringD &s, FILE * f)
{
     int i=0;
     stringD aux;
     aux = new char[MAX];
     fread (&aux[i], sizeof(char), 1, f);
     while (!feof(f) && (aux[i] != '\0'))
     {
         i++;
         fread (&aux[i], sizeof(char), 1, f);
     }
     strcop (s, aux);
     delete [] aux;
}
