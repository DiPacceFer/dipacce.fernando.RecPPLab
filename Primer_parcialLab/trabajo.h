#include "fecha.h"
#include "validaciones.h"
#include "servicio.h"
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "cliente.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{
        int id;
        int idBicicleta;
        int idServicio;
        eFecha fecha;
        int isEmpty;
}eTrabajo;


#endif // TRABAJO_H_INCLUDED
/**
* \brief Solicita al usuario toda la informacion para agragar un nuevo trabajo
* \ param eTrabajo nuevoTrabajo array que se quiere agragar
* \ param int tam tamaño del array nuevoTrabajo
* \ param int* idTrabajo puntero del id autoincremental
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int altaTrabajo(eTrabajo nuevoTrabajo[], int tam, int* idTrabajo, eBicicleta bicicletas[], int tamB,
                 eServicio servicios[], int tamS, eTipo tipos[], int tamT,
                  eColor colores[], int tamC, eCliente clientes[], int tamCl);

void inicializarTrabajo(eTrabajo lista[],int tamT);
/**
* \brief busca una posicion libre dentro del array trabajo y devuelve el indice
* \ param eTrabajo nuevoTrabajo array donde se realiza la busqueda
* \ param int tam tamaño del array nuevoTrabajo
* \
* \return Retorna el indice del espacio libre o -1 si no encontro
*/
int siguienteTrabajo(eTrabajo nuevoTrabajo[],int  tam);
/**
* \brief imprime contenido de un trabajo con precio y descripcion del servicio realizado en el trabajo
* \ param eTrabajo unTrabajo array que se quiere mostrar
* \ param int tam tamaño del array trabajo
* \ param eServicio servicios array de donde se obtiene precio y descripcion de servicios
* \ param int tamS tamaño del array servicios
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int mostrarTrabajo(eTrabajo unTrabajo, int tam, eServicio servicios[], int tamS);
/**
* \brief imprime listado de trabajos y servicios en cada trabajo
* \ param eTrabajo lista array que se quiere mostrar listado
* \ param int tam tamaño del array trabajos
* \ param eServicio servicios donde se obtiene los serivcios realizados en cada trabajo
* \ param int tamS tamaño del array servicios
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int listarTrabajos(eTrabajo lista[], int tam, eServicio servicios[], int tamS);
