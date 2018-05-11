#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

int inicio(EPersona personas[],int lim)///inicia los datos
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

int obtenerEspacioLibre(EPersona lista[],int lim)///busca un espacio libre
{
    for(int i=0; i<lim; i++)
    {
        if(lista[i].estado==1)///mientras este libre
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
    for (i=0;i<lim-1;i++)///se posiciona en un lugar menor al limite
    {
        for(j=i+1;j<lim;j++)///lo corre hasta llegar al final y compara
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

int alta(EPersona personas[], int edad,int lim)
{
    int retor=-1;
    int i;
    char aux[50];
    int dni;

    i=obtenerEspacioLibre(personas,lim);///si hay lugar libre
    if(i>=0)
    {
        printf("ingrese el dni:");///pide el dni
        fflush(stdin);
        gets(aux);
        while(numeroV(aux)==0)
        {
            printf("ingrese un dni valido:");///valida
            fflush(stdin);
            gets(aux);
        }
        dni=atoi(aux);
        while(repeticion(personas,dni,lim)==0)
        {
            printf("ingrese un dni no repetido:");///valida que el dni no este repetido
            fflush(stdin);
            scanf("%d",&dni);
        }
        personas[i].dni=dni;
        printf("ingrese el nombre: ");///pide el nombre
        fflush(stdin);
        gets(personas[i].nombre);
        while(letraV(personas[i].nombre)==0)///valida si es solo string
        {
            printf("ingrese un nombre valido: ");///valida si es nombre
            fflush(stdin);
            gets(personas[i].nombre);
        }
        personas[i].edad=edad;///asigna el valor del auxiliar de edad y se la para al a estructura
        personas[i].estado=0;///cambia ese estado a ocupado
        retor=0;
    }
    return retor;
}

int baja(EPersona personas[],int lim)
{
    int busqueda;
    char resp;
    int index=0;
    int i;

    busqueda=buscarPorDni(personas,lim);///busca el dni a borra

    for(i=0;i<lim;i++)
    {
        if(busqueda>=0 && personas[i].dni==busqueda)///si lo encontro
        {
            mostar(personas,lim);///lo muestra
            printf("desea darlo de baja? s/n: ");///pregunta si lo dara de baja
            fflush(stdin);
            resp=getche();
            while(resp!='s' && resp!='n')///si no es ni si ni no
            {
                printf("\ningrese un valor valido s/n: ");///valida la respuesta
                fflush(stdin);
                resp=getche();
            }
            if(resp=='s')///si es si devuelve es valor al inicio
            {
                personas[i].estado=1;///cambia su estado a libre
            }
            else if(resp=='n')
            {
                index=-1;///si no lo cancela
            }
        }
    }
    return index;
}

int numeroV(char num[])
{
    int i=0;
    while(num[i] != '\0')///mientrar haya algo
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
int repeticion(EPersona persona[],int dni,int lim)///valida la repeticion
{
    int i;
    for(i=0;i<lim;i++)///recorre todo
    {
        if (persona[i].dni==dni)///si el dni de es posicion es igual al que se pasa
        {
            return 0;///se esta repitiendo
        }
        i++;
    }

    return 1;
}
void graficoBarras(int menor,int adulto,int mayor)///grafica con los contadores
{
    int maxTodo;

    if(menor >= adulto && menor >= mayor)///verifica cual es el valor mas alto
    {
        maxTodo = menor;
    }
    else if(adulto >= menor && adulto >= mayor)
    {
        maxTodo = adulto;
    }
    else
    {
        maxTodo = mayor;
    }

for(int i=maxTodo;i>0; i--)///recorre en decenso todo el i definido por el valor maximo
{
    if(i<= menor)
    {
        printf("\n%c",42);///si es de el contador de 18 menor a el maximo escribe un * (219)
    }
    if(i<=adulto)
    {
        printf("\n\t\t%c",42);///si es de el contador de 18 y 35 menor a el maximo escribe un * (219)

    }
    if(i<= mayor)
    {
        printf("\n\t\t\t\t%c",42);///si es de 35 menor a el maximo escribe un * (219)
    }
}
printf("\n<18            19-35            >35\n");///impreme los contadores
}
