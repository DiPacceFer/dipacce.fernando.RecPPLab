#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "color.h"


char colores[5][20]={
        "Gris",
        "Negro",
        "Blanco",
        "Azul",
        "Rojo"
};

/** \brief carga la descripcion del color en lugar del id
 *
 * \param idColor int numero que identifica el color
 * \param colores[] eColor listado de colores
 * \param tamC int tamaño del array
 * \param nombre[] char variable donde se guarda la descripcion
 * \return int devuelve 0 si hubo un error y 1 si funciono bien
 *
 */
int cargarDescColor(int idColor, eColor colores[], int tamC, char nombre[])
{
    int todoOk=0;
    if(idColor>=5000 && idColor<=5004 && colores != NULL && tamC > 0 && nombre != NULL)
    {

    for(int i=0;i<tamC;i++)
    {
        if(colores[i].id == idColor)
        {
            strcpy(nombre, colores[i].nombreColor);
            todoOk = 1;
            break;
        }
    }
    }
    return todoOk;
}
/** \brief imprime listado de colores
 *
 * \param lista[] eColor array de colores
 * \param tamC int tamaño del array
 * \return int devuelve 0 si hubo un error y 1 si funciono bien
 *
 */
int listarColores(eColor lista[], int tamC)
{
    int isOk=0;

    if(lista != NULL && tamC>0)
    {

    printf("               Lista de Colores  \n");
    printf("----------------------------------------------\n");
    printf("id\t  Nombre de Color\n");

    for(int i=0; i<tamC; i++)
    {
        mostrarColor(lista[i], tamC);
    }
    isOk =1;
    }
    return isOk;
}
/** \brief imprime el detalle de un solo color
 *
 * \param unColor eColor array de un color
 * \param tamC int tamaño del array
 * \return int devuelve 0 si hubo un error y 1 si funciono bien
 *
 */
int mostrarColor(eColor unColor, int tamC)
{
    int isOk = 0;

    if(tamC >0)
    {
    printf("%d  %10s\n",unColor.id, unColor.nombreColor);
    isOk=1;
    }
    return isOk;
}
/** \brief devuelve el indice de un color
 *
 * \param lista[] eColor lista de colores
 * \param tamC int tamaño del array
 * \param idColor int numero de id del color a buscar
 * \return int devuelve 0 si hubo un error y 1 si funciono bien
 *
 */
int buscarColor(eColor lista[], int tamC, int idColor)
{
    int indice=-1;

    for(int i=0;i<tamC;i++)
    {
        if(lista[i].id == idColor)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
