#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo.h"


char descripcion[4][20]={
            "Rutera",
            "Carrera",
            "Mountain",
            "BMX"
};

/**
* \brief Recorre el array tipos y devuelve la descripcion del id solicitado
* \ param int idTipo numero de id del tipo que se quiere obtener la descripcion
* \ param eTipo tipos array de tipos
* \ param int tamT tamaño del array tipos
* \ param char desc puntero donde debe cargar la descripcion del tipo
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int cargarDescripcionTipo(int idTipo, eTipo tipos[], int tamT, char desc[])
{
    int todoOk=0;
    if(idTipo>=1000 && idTipo<=1003 && tipos != NULL && tamT > 0 && desc != NULL)
    {

    for(int i=0;i<tamT;i++)
    {
        if(tipos[i].id == idTipo)
        {
            strcpy(desc, tipos[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    }
    return todoOk;
}
/**
* \brief imprime listado de tipos
* \ param eTipo lista array que se quiere mostrar listado
* \ param int tamT tamaño del array tipos
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int listarTipos(eTipo lista[], int tamT)
{
    int isOk=0;

    if(lista != NULL && tamT>0)
    {

    printf("          Lista de Tipos  \n");
    printf("-----------------------------------\n");
    printf("id\t  Descripcion\n");

    for(int i=0; i<tamT; i++)
    {
        mostrarTipo(lista[i], tamT);
    }
    isOk =1;
    }
    return isOk;
}
/**
* \brief imprime un tipo
* \ param eTipo unTipo array que se quiere mostrar
* \ param int tamT tamaño del array tipos
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int mostrarTipo(eTipo unTipo, int tamT)
{
    int isOk = 0;

    if(tamT >0)
    {
    printf("%d     %10s\n",unTipo.id, unTipo.descripcion);
    isOk=1;
    }
    return isOk;
}
/**
* \brief busca un vector dentro del array tipo y devuelve el indice
* \ param eTipo lista array donde se realiza la busqueda
* \ param int tam tamaño del array lista
* \ param int idTipo numero de id que se desea buscar
* \
* \return Retorna el indice del tipo solicitado o -1 si no encontro
*/
int buscarTipo(eTipo lista[], int tamT, int idTipo)
{
     int indice=-1;

    for(int i=0;i<tamT;i++)
    {
        if(lista[i].id == idTipo)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
