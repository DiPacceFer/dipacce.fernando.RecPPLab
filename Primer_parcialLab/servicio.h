#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{
        int id;
        char descripcion[25];
        float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED
/**
* \brief imprime listado de servicios
* \ param eServicio lista array que se quiere mostrar listado
* \ param int tamS tamaño del array servicios
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int listarServicios(eServicio lista[], int tamS);
/**
* \brief imprime un servicio
* \ param eServicio unServicio array que se quiere mostrar
* \ param int tamS tamaño del array servicios
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int mostrarServicio(eServicio unServicio, int tamS);
/**
* \brief Recorre el array servicios y devuelve la descripcion y precio del id solicitado
* \ param int idServicio numero de id del servicio que se quiere obtener la descripcion y el precio
* \ param eServicios servicios array de servicios
* \ param int tamS tamaño del array servicios
* \ param char desc puntero donde debe cargar la descripcion del servicio
* \ param float precioServicios puntero donde debe cargar el precio del servicio
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int cargarDescServ(int idServicio, eServicio servicios[], int tamS, char descripcion[], float* precioServicios);

int buscarServicio(eServicio lista[], int tamS, int idServicio);
