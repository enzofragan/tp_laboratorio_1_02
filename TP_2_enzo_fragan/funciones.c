#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

int inicio(EPersona personas[],int lim)
{
    int retorno=-1;
    int i;
    if(lim>0)
    {
        retorno=0;
        for(i=0; i<lim; i++)
        {
            personas[i].estado=1;
            personas[i].dni=0;
            strcpy(personas[i].nombre,"");
            personas[i].edad=0;
        }
    }
    return retorno;
}

int obtenerEspacioLibre(EPersona lista[],int lim)
{
    for(int i=0; i<lim; i++)
    {
        if(lista[i].estado==1)
        {
            return i;
        }
    }
    return -1;
}

int buscarPorDni(EPersona lista[], int lim)
{
    int dni;
    int index=-1;
    int i;
    char auxDni[50];

    printf("ingrese el dni a buscar: ");
    fflush(stdin);
    gets(auxDni);///pide el numero com char
    while(numeroV(auxDni)==0)///valida si es numero o no
    {
        printf("ingrese un dni valido: ");
        fflush(stdin);
        gets(auxDni);
    }
    dni = atoi(auxDni);

    for (i=0;i<lim;i++)
    {
        if(dni==lista[i].dni)///si son iguales lo encontro
        {
            index=dni;///de vuelve el id encontrado
            break;
        }
        else
        {
            index=-2;
        }
    }
    return index;
}

int mostar(EPersona personas[],int lim)
{
    int retor = -1;
    int i;
    if(lim > 0 && personas != NULL)///si no obrepara el limite y halla algo en la lista
    {
        retor = 0;
        for(i=0; i<lim; i++)
        {
            if(personas[i].estado==0)///si esta coupado lo muestra
            {
                printf("\n%d---%s---%d\n",personas[i].dni,personas[i].nombre,personas[i].edad);
            }
        }
    }
    return retor;
}

int ordenarNombre(EPersona personas[],int lim)
{
    EPersona auxiliar;
    int i;
    int j;
    for (i=0;i<lim-1;i++)///mano amarilla
    {
        for(j=i+1;j<lim;j++)///mano celeste
        {
            if(strcmp(personas[i].nombre,personas[j].nombre)>0)///menor a mayor o criterio de ordenamiento
            {
                auxiliar=personas[i];
                personas[i]=personas[j];
                personas[j]=auxiliar;
            }
        }
    }
    mostar(personas,lim);
}

int alta(EPersona personas[],int lim)
{
    int retor=-1;
    int i;
    char aux[50];
    char auxE[50];
    int dni;
    int edad;

    i=obtenerEspacioLibre(personas,lim);///
    if(i>=0)
    {
        printf("ingrese el dni:");///
        fflush(stdin);
        gets(aux);
        while(numeroV(aux)==0)
        {
            printf("ingrese un dni valido:");///
            fflush(stdin);
            gets(aux);
        }
        dni=atoi(aux);
        personas[i].dni=dni;
        printf("ingrese el nombre: ");///
        fflush(stdin);
        gets(personas[i].nombre);
        while(letraV(personas[i].nombre)==0)///valida si es solo string
        {
            printf("ingrese un nombre valido: ");///
            fflush(stdin);
            gets(personas[i].nombre);
        }
        printf("ingrese su edad:");///
        fflush(stdin);
        gets(auxE);
        while(numeroV(auxE)==0)
        {
            printf("ingrese una edad valida: ");///
            fflush(stdin);
            gets(auxE);
        }
        edad=atoi(auxE);
        while(edadV(edad)==0)
        {
            printf("ingrese una edad real:");///
            fflush(stdin);
            scanf("%d",&edad);
        }

        personas[i].edad=edad;
        personas[i].estado=0;
        retor=0;
        mostar(personas,lim);
    }
    return retor;
}

int baja(EPersona personas[],int lim)
{
    int busqueda;
    char resp;
    int index=0;
    int i;

    busqueda=buscarPorDni(personas,lim);

    for(i=0;i<lim;i++)
    {
        if(busqueda>=0 && personas[i].dni==busqueda)
        {
            mostar(personas,lim);
            printf("desea darlo de baja? s/n: ");
            fflush(stdin);
            resp=getche();
            while(resp!='s' && resp!='n')///si no es ni si ni no
            {
                printf("\ningrese un valor valido s/n: ");
                fflush(stdin);
                resp=getche();
            }
            if(resp=='s')///si es si devuelve es valor al inicio
            {
                personas[i].estado=1;
                personas[i].dni=0;
                strcpy(personas[i].nombre,"");
                personas[i].edad=0;
            }
            else if(resp=='n')
            {
                index=-1;
            }
            mostar(personas,lim);
        }
    }
    return index;
}

int numeroV(char num[])
{
    int i=0;
    while(num[i] != '\0')
    {
        if(!(isdigit(num[i])))///si el char no es un digito
        {
            return 0;///es letra
        }
        i++;
    }
    return 1;
}

int letraV(char nom[])
{
    int i=0;
    while(nom[i] != '\0')///mientras no sea /0 osea alla algo
    {
        if((nom[i] != ' ') && (nom[i] < 'a' || nom[i] > 'z') && (nom[i] < 'A' || nom[i] > 'Z'))///si tiene espacio y no esta entre a y z
        {
            return 0;///es numero
        }
        i++;
    }
    return 1;
}
int edadV(int edades)
{
    if(edades>99 || edades<0)
    {
        return 0;
    }
    return 1;
}
