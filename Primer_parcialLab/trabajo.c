#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajo.h"

int altaTrabajo(eTrabajo nuevoTrabajo[], int tam, int* idTrabajo, eBicicleta bicicletas[], int tamB, eServicio servicios[],
                 int tamS, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
     int todoOk=0;
    eTrabajo auxAlta;
    int indice;


    printf("   Alta Trabajo\n\n");
    printf("Codigo Trabajo: %d\n", *idTrabajo);
    if(nuevoTrabajo != NULL && tam>0 && idTrabajo!= NULL)
    {
        indice = siguienteTrabajo(nuevoTrabajo, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
            system("pause");
        }
        else
        {
            listarBicicletas(bicicletas, tamB, tipos, tamT, colores, tamC, clientes, tamCl);
            pedirEntero(&auxAlta.idBicicleta, "Ingrese ID bicicleta: ", "Error. ");
            /*while(auxAlta.idBicicleta < 100 || auxAlta.idBicicleta > 104)
            {
                printf("Id Bicicleta no valido.");
                pedirEntero(&auxAlta.idBicicleta, "Ingrese ID bicicleta 100 a 104: ", "Error. ");
            }*/
            listarServicios(servicios, tamS);
            pedirEntero(&auxAlta.idServicio, "Ingrese id Servicio 20000 a 20003: ", "Error. ");
            while(auxAlta.idServicio < 20000 || auxAlta.idServicio > 20003)
            {
                printf("Id servicio no valido.");
                pedirEntero(&auxAlta.idServicio, "Ingrese id Servicio 20000 a 20003: ", "Error. ");
            }
            pedirFecha(&auxAlta.fecha, "Ingrese fecha trabajo: ", "Error. ");
        auxAlta.id = *idTrabajo;
        (*idTrabajo)++;
        auxAlta.isEmpty = 0;
        nuevoTrabajo[indice]=auxAlta;
        todoOk=1;
        }
    }
    return todoOk;
}
void inicializarTrabajo(eTrabajo lista[],int tamT)
{
    for(int i=0; i<tamT; i++)
    {
        lista[i].isEmpty = 1;
    }
}
int siguienteTrabajo(eTrabajo nuevoTrabajo[],int  tam)
{
    int libre=-1;
    for(int i=0;i<tam;i++)
    {
        if(nuevoTrabajo[i].isEmpty)
        {
            libre=i;
            break;
        }
    }
    return libre;
}
int listarTrabajos(eTrabajo lista[], int tam, eServicio servicios[], int tamS)
{
    int isOk=0;
    int flag = 1;

    if(lista != NULL && tam>0)
    {

    printf("                        Lista de Trabajos  \n");
    printf("----------------------------------------------------------------\n");
    printf("id   ID Bicicleta    ID Servicio    Fecha de trabajo    Precio  \n");

    for(int i=0; i<tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarTrabajo(lista[i], tam, servicios, tamS);
            flag = 0;
        }
    }
    if(flag)
    {
        printf("       No hay trabajos que mostrar\n");
    }
    isOk =1;
    }
    return isOk;
}
int mostrarTrabajo(eTrabajo unTrabajo, int tam, eServicio servicios[], int tamS)
{
    int isOk = 0;
    char servicio[30];
    float precio;
    if(tam >0)
    {
        if(cargarDescServ(unTrabajo.idServicio, servicios, tamS, servicio, &precio))
        {
    printf("%d     %d            %10s         %02d/%02d/%d     %3.2f\n"
           ,unTrabajo.id
           , unTrabajo.idBicicleta
           , servicio
           , unTrabajo.fecha.dia
           , unTrabajo.fecha.mes
           , unTrabajo.fecha.anio
           , precio
           );

        }
    isOk=1;
    }
    return isOk;
}
