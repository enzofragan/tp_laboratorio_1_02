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
                valorAlta=alta(listaDePersonas,Tam);
                if(valorAlta>=0)
                {
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
                    printf("\nbaja completada\n");
                }
                else
                {
                    printf("\naccion completada\n");
                }
                break;
            case 3:
                ordenarNombre(listaDePersonas,Tam);
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
