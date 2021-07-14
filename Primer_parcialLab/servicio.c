#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicio.h"


char descServicios[4][25]={
            "Limpieza",
            "Parche",
            "Centrado",
            "Cadena"
};

float precioServicios[4]={
            250,
            300,
            400,
            350
};
/** \brief imprime listado de servicios
 *
 * \param lista[] eServicio array de la lista de servicios
 * \param tamS int tmaño del array
 * \return int devuelve 0 si hubo un error y 1 si funciono bien
 *
 */
int listarServicios(eServicio lista[], int tamS)
{
    int isOk=0;

    if(lista != NULL && tamS>0)
    {

    printf("                        Lista de Servicios  \n");
    printf("----------------------------------------------------------------\n");
    printf("id\t  Descripcion    Precio\n");

    for(int i=0; i<tamS; i++)
    {
        mostrarServicio(lista[i], tamS);
    }
    isOk =1;
    }
    return isOk;
}
/** \brief imprime el detalle de un servicio
 *
 * \param unServicio eServicio array del servicio a imprimr
 * \param tamS int tamaño del array de servicios
 * \return int devuelve 0 si hubo un error y 1 si funciono bien
 *
 */
int mostrarServicio(eServicio unServicio, int tamS)
{
    int isOk = 0;

    if(tamS >0)
    {
    printf("%d     %10s     %.2f\n",unServicio.id, unServicio.descripcion, unServicio.precio);
    isOk=1;
    }
    return isOk;
}
/** \brief devuelve la descripcion del servicio
 *
 * \param idServicio int numero de id del servicio a cargar
 * \param servicios[] eServicio listado de servicios
 * \param tamS int tamaño del array
 * \param descripcion[] char variable donde se carga la descripcion
 * \param precioServicios float* puntero a la variable donde se carga el precio del servicio
 * \return int devuelve 0 si hubo un error y 1 si funciono bien
 *
 */
int cargarDescServ(int idServicio, eServicio servicios[], int tamS, char descripcion[], float* precioServicios)
{
    int todoOk=0;

    if(idServicio>=20000 && idServicio<=20003 && servicios!= NULL && tamS > 0 && descripcion != NULL)
    {

    for(int i=0;i<tamS;i++)
    {
        if(servicios[i].id == idServicio)
        {
            strcpy(descripcion, servicios[i].descripcion);
            *precioServicios = servicios[i].precio;
            todoOk = 1;
            break;
        }
    }
    }
    return todoOk;
}
int buscarServicio(eServicio lista[], int tamS, int idServicio)
{
    int indice=-1;

    for(int i=0;i<tamS;i++)
    {
        if(lista[i].id == idServicio)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
