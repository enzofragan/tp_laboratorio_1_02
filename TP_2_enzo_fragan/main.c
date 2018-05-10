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
                valorAlta=alta(listaDePersonas,edad,Tam);
                if(valorAlta>=0)
                {
                    if (edad<19)
                    {
                        menor++;
                    }
                    if(edad>18 && edad<=35)
                    {
                        adulto++;
                    }
                    if(edad>35)
                    {
                        mayor++;
                    }
                    mostar(listaDePersonas,Tam);
                    printf("\ncompleto\n");
                }
                else
                {
                    printf("\ninvalidado\n");
                }
                break;
            case 2:
                valorBaja=baja(listaDePersonas,Tam);
                if(valorBaja>=0)
                {
                    listaDePersonas[valorBaja].dni=0;
                    strcpy(listaDePersonas[valorBaja].nombre,"");
                    if (listaDePersonas[valorBaja].edad<19)
                    {
                        menor--;
                    }
                    if(listaDePersonas[valorBaja].edad>18 && listaDePersonas[valorBaja].edad<35)
                    {
                        adulto--;
                    }
                    if(listaDePersonas[valorBaja].edad>35)
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
                ordenarNombre(listaDePersonas,Tam);
                break;
            case 4:
                if(menor==0 && adulto==0 && mayor==0)
                {
                    printf("no se puede realizar el grafico");
                    break;
                }
                else
                {
                    graficoBarras(menor,adulto,mayor);
                }
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
