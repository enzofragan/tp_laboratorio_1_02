#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"
#define Tam 20


int main()
{
    char seguir='s';
    int opcion=0;
    int valorAlta;
    int valorBaja;
    int valorGrafico;
    char auxE[50];
    int edad;
    int menor = 0;
    int adulto = 0;
    int mayor = 0;

    EPersona listaDePersonas[Tam];
    inicio(listaDePersonas,Tam);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("ingrese su edad:");///se pide la edad fuera de la funcion ara contarlo
                fflush(stdin);
                gets(auxE);
                while(numeroV(auxE)==0)
                {
                    printf("ingrese una edad valida: ");///valida
                    fflush(stdin);
                    gets(auxE);
                }
                edad=atoi(auxE);
                while(edadV(edad)==0)
                {
                    printf("ingrese una edad real:");///valida si es real
                    fflush(stdin);
                    scanf("%d",&edad);
                }
                valorAlta=alta(listaDePersonas,edad,Tam);///uedo llama a la funcion y pasa la lista y edad
                if(valorAlta>=0)
                {
                    if (edad<18)///si todo sale bien cuenta
                    {
                        menor++;
                    }
                    if(edad>19 && edad<=35)
                    {
                        adulto++;
                    }
                    if(edad>36)
                    {
                        mayor++;
                    }
                    mostar(listaDePersonas,Tam);///y lo muestra
                    printf("\ncompleto\n");
                }
                else
                {
                    printf("\ninvalidado\n");
                }
                break;
            case 2:
                valorBaja=baja(listaDePersonas,Tam);///llama a la baja
                if(valorBaja>=0)///si todo sale bien devuelve los parametros originales y descuenta antes de baja la edad
                {
                    listaDePersonas[valorBaja].dni=0;
                    strcpy(listaDePersonas[valorBaja].nombre,"");
                    if (listaDePersonas[valorBaja].edad<18)
                    {
                        menor--;
                    }
                    if(listaDePersonas[valorBaja].edad>19 && listaDePersonas[valorBaja].edad<35)
                    {
                        adulto--;
                    }
                    if(listaDePersonas[valorBaja].edad>36)
                    {
                        mayor--;
                    }
                    listaDePersonas[valorBaja].edad=0;
                    mostar(listaDePersonas,Tam);
                    printf("\nbaja completada\n");
                }
                else
                {
                    printf("\naccion cancelada\n");
                }
                break;
            case 3:
                ordenarNombre(listaDePersonas,Tam);///ordena toda la lista por nombre
                break;
            case 4:
                if(menor==0 && adulto==0 && mayor==0)///valida si enrealidad hay algo en los contadores
                {
                    printf("no se puede realizar el grafico");
                    break;
                }
                else
                {
                    graficoBarras(menor,adulto,mayor);///si hay imprime el grafico
                }
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
