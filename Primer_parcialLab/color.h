#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{
        int id;
        char nombreColor[20];
}eColor;


#endif // COLOR_H_INCLUDED

/**
* \brief Recorre el array colores y devuelve el nombre del id solicitado
* \ param int idColor numero de id del color que se quiere obtener el nombre
* \ param eColor colores array de colores
* \ param int tamC tamaño del array colores
* \ param string nombre puntero donde debe cargar el nombre del color
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int cargarDescColor(int idColor, eColor colores[], int tamC, char nombre[]);
/**
* \brief imprime listado de colores
* \ param eColor lista array que se quiere mostrar listado
* \ param int tamC tamaño del array colores
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int listarColores(eColor lista[], int tamC);
/**
* \brief imprime contenido del array color
* \ param eColor unColor array que se quiere mostrar
* \ param int tamC tamaño del array color
* \
* \return Retorna 1 si se obtuvo la descripcion y 0 si no
*/
int mostrarColor(eColor unColor, int tamC);
/**
* \brief busca un vector dentro del array Color y devuelve el indice
* \ param eColor lista array donde se realiza la busqueda
* \ param int tam tamaño del array lista
* \ param int idColor numero de id que se desea buscar
* \
* \return Retorna el indice del color solicitado o -1 si no encontro
*/
int buscarColor(eColor lista[], int tamC, int idColor);
