#include "color.h"
#include "tipo.h"
#include "cliente.h"
#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct{
        int id;
        char marca[20];
        int idTipo;
        int idColor;
        float rodado;
        int isEmpty;
        int idCliente;
}eBicicleta;


#endif // BICICLETA_H_INCLUDED
/**
* \brief Solicita al usuario toda la informacion para agregar una nueva bicicleta
* \ param eBicicleta nuevaBicicleta array que se quiere agregar
* \ param int tam tamaño del array nuevaBicicleta
* \ param int* idBicicleta puntero del id autoincremental
* \ param eCliente clientes array para mostrar en la lista
* \ param int tamCl tamaño del array clientes
* \ param eColores colores array para mostrar en la lista
* \ param int tamC tamaño del array colores
* \ param eTipo tipos array para mostrar en la lista
* \ param int tamT tamaño del array tipos
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int altaBicicleta(eBicicleta nuevaBicicleta[], int tam, int* idBicicleta, eCliente clientes[], int tamCl,
                   eColor colores[], int tamC, eTipo tipos[], int tamT);
/**
* \brief busca una posicion libre dentro del array bicicleta y devuelve el indice
* \ param eBicicleta nuevaBicicleta array donde se realiza la busqueda
* \ param int tam tamaño del array nuevaBicicleta
* \
* \return Retorna el indice del espacio libre o -1 si no encontro
*/
int siguienteBicicleta(eBicicleta nuevaBicicleta[],int  tam);

void inicializarBicicletas(eBicicleta lista[],int tam);
/**
* \brief imprime listado de bicicletas con el color, servicio, cliente y tipo
* \ param eBicicleta lista array de bicicletas que se quiere mostrar listado
* \ param int tam tamaño del array bicicletas
* \ param eTipo tipos array de los tipos de bicicletas
* \ param int tamT tamaño del array tipos
* \ param eColor colores array de colores
* \ param int tamC tamaño del array colores
* \ param eCliente clientes array de clientes
* \ param int tamCl tamaño del array clientes
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int listarBicicletas(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/**
* \brief imprime contenidos de una bicicleta
* \ param eBicicleta unaBicicleta array que se quiere mostrar
* \ param int tam tamaño del array unaBicicleta
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int mostrarBicicleta(eBicicleta unaBicicleta, int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);
/**
* \brief busca un vector dentro del array bicicleta y devuelve el indice
* \ param eBicicleta lista array donde se realiza la busqueda
* \ param int tam tamaño del array lista
* \ param int idBicicleta numero de id que se desea buscar
* \
* \return Retorna el indice de la bicicleta solicitada o -1 si no encontro
*/
int buscarBicicleta(eBicicleta lista[], int tamB, int idBicicleta);
/**
* \brief imprime listado de opciones para modificar y toma la elegida por el usuario
* \
* \return Retorna la opcion elegida por el usuario
*/
int subMenuModificar();

int modificarBicicleta(eBicicleta lista[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);

int bajarBicicleta(eBicicleta lista[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);

void ordenarBicicletas(eBicicleta lista[], int tam);
