#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{
        int id;
        char nombre[30];
        char sexo;
        char localidad[30];
        int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED

/**
* \brief Recorre el array Clientes y devuelve el nombre del id solicitado
* \ param int idCliente numero de id del cliente que se quiere obtener el nombre
* \ param eCliente clientes array de clientes
* \ param int tamCl tamaño del array clientes
* \ param string nombre puntero donde debe cargar el nombre del cliente
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int cargarNombreCliente(int idCliente, eCliente clientes[], int tamCl, char nombre[]);
/**
* \brief imprime listado de clientes
* \ param eCliente lista array que se quiere mostrar listado
* \ param int tam tamaño del array clientes
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int listarClientes(eCliente lista[], int tam);
/**
* \brief imprime un tipo
* \ param eCliente unCliente array que se quiere mostrar
* \ param int tam tamaño del array
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int mostrarCliente(eCliente unCliente, int tam);
/**
* \brief Solicita al usuario toda la informacion para agragar un nuevo cliente
* \ param eCliente nuevoCliente array que se quiere agragar
* \ param int tam tamaño del array nuevoCliente
* \ param int* idCliente puntero del id autoincremental
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int altaCliente(eCliente nuevoCliente[], int tam, int* idCliente);
/**
* \brief busca una posicion libre dentro del array Clientes y devuelve el indice
* \ param eCliente nuevoCliente array donde se realiza la busqueda
* \ param int tam tamaño del array nuevoCliente
* \
* \return Retorna el indice del espacio libre o -1 si no encontro
*/
int siguienteCliente(eCliente nuevoCliente[],int  tam);

int cargarLocalidadCliente(int idCliente, eCliente clientes[], int tamCl, char localidad[]);
