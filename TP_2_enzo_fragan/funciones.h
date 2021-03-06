#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
///int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
///int buscarPorDni(EPersona lista[], int dni);

#endif // FUNCIONES_H_INCLUDED
int inicio(EPersona [],int);
int obtenerEspacioLibre(EPersona lista[],int);
int buscarPorDni(EPersona lista[], int lim);
int alta(EPersona [], int,int);
int baja(EPersona [],int);
int mostar(EPersona [],int);
int ordenarNombre(EPersona [],int);
int repeticion(EPersona [],int,int);
int letraV(char []);
int numeroV(char []);
int edadV(int );
void graficoBarras(int ,int ,int );
