#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bicicleta.h"
#include "validaciones.h"
#include "tipo.h"
#include "color.h"


int altaBicicleta(eBicicleta nuevaBicicleta[], int tam, int* idBicicleta, eCliente clientes[], int tamCl, eColor colores[], int tamC, eTipo tipos[], int tamT)
{
     int todoOk=0;
    eBicicleta auxAlta;
    int indice;


    printf("   Alta Bicicleta\n\n");
    printf("Codigo Bicicleta: %d\n", *idBicicleta);
    if(nuevaBicicleta != NULL && tam>0 && idBicicleta!= NULL)
    {
        indice = siguienteBicicleta(nuevaBicicleta, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
            system("pause");
        }
        else
        {

            pedirCadena(auxAlta.marca, 20, "Ingrese marca de bicicleta: ", "Error. ");
            /*printf("Ingrese marca de bicicleta: ");
            fflush(stdin);
            gets(auxAlta.marca);*/

            pedirFlotante(&auxAlta.rodado, "Ingrese rodado 20/26/27.5/29: ", "Error. ");
            while(auxAlta.rodado != 20 && auxAlta.rodado != 26 && auxAlta.rodado != 27.5 && auxAlta.rodado != 29)
            {
                printf("Rodado no valido.");
                pedirFlotante(&auxAlta.rodado, "Ingrese rodado 20/26/27.5/29: ", "Error. ");
            }
            listarColores(colores, tamC);
            pedirEntero(&auxAlta.idColor, "Ingrese id Color 5000 a 5004:", "Error. ");
            while(auxAlta.idColor < 5000 || auxAlta.idColor > 5004)
            {
                printf("Id color no valido.");
                pedirEntero(&auxAlta.idColor, "Ingrese id Color 5000 a 5004:", "Error. ");
            }
            listarTipos(tipos, tamT);
            pedirEntero(&auxAlta.idTipo, "Ingrese id Tipo 1000 a 1003: ", "Error.");
            while(auxAlta.idTipo <1000 || auxAlta.idTipo >1003)
            {
                printf("Id tipo no valido.");
                pedirEntero(&auxAlta.idTipo, "Ingrese id Tipo 1000 a 1003: ", "Error.");
            }
            listarClientes(clientes, tamCl);
            pedirEntero(&auxAlta.idCliente, "Ingrese id Cliente 7000 a 7004: ", "Error.");

        auxAlta.id = *idBicicleta;
        (*idBicicleta)++;
        auxAlta.isEmpty = 0;
        nuevaBicicleta[indice]=auxAlta;
        todoOk=1;
        }
    }
    return todoOk;
}
int siguienteBicicleta(eBicicleta nuevaBicicleta[],int  tam)
{
    int libre=-1;
    for(int i=0;i<tam;i++)
    {
        if(nuevaBicicleta[i].isEmpty)
        {
            libre=i;
            break;
        }
    }
    return libre;
}
void inicializarBicicletas(eBicicleta lista[],int tam)
{
    for(int i=0; i<tam; i++)
    {
        lista[i].isEmpty = 1;
    }
}
int listarBicicletas(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int isOk=0;
    int flag = 1;

    if(lista != NULL && tam>0 && tipos !=NULL && tamT > 0 && colores !=NULL && tamC > 0)
    {

    printf("                        Lista de Bicicletas  \n");
    printf("----------------------------------------------------------------\n");
    printf("id\t     Marca        Tipo         Color     Rodado    Cliente   Localidad\n");

    for(int i=0; i<tam; i++)
    {
        if(!lista[i].isEmpty)
        {
            mostrarBicicleta(lista[i], tam, tipos, tamT, colores, tamC, clientes, tamCl);
            flag = 0;
        }
    }
    if(flag)
    {
        printf("       No hay bicicletas que mostrar\n");
    }
    isOk =1;
    }
    return isOk;
}
int mostrarBicicleta(eBicicleta unaBicicleta, int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    char descripcion[20];
    char nombreColor[51];
    char nombreCliente[30];
    char localidad[30];
    int isOk = 0;

    if(tipos != NULL && tamT >0 && colores != NULL && tamC >0)
    {
    if(
    cargarDescripcionTipo(unaBicicleta.idTipo, tipos, tamT, descripcion) &&
        cargarDescColor(unaBicicleta.idColor, colores, tamC, nombreColor)
        && cargarNombreCliente(unaBicicleta.idCliente, clientes, tamCl, nombreCliente)
       && cargarLocalidadCliente(unaBicicleta.idCliente, clientes, tamCl, localidad)
        )
    {

    printf("%d    %10s    %10s   %10s      %.2f    %s   %15s\n"
           ,unaBicicleta.id
           , unaBicicleta.marca
           , descripcion
           , nombreColor
           ,unaBicicleta.rodado
           ,nombreCliente
           ,localidad
           );
    }
    isOk=1;
    }
    return isOk;
}
int modificarBicicleta(eBicicleta lista[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int todoOk=0;
    int idBici;
    int indice;

    printf("    MODIFICACION DE DATOS DE BICICLETA\n\n");
    listarBicicletas(lista, tamB, tipos, tamT, colores, tamC,clientes, tamCl );
    printf("\n\n");
    pedirEntero(&idBici, "Ingrese numero de id: ", "Error. ");
    indice = buscarBicicleta(lista, tamB, idBici);
    system("cls");
    if(indice == -1)
    {
        printf("No se encontro id de Bicicleta\n");
    }
    else
    {
        printf("id\t    Marca          Tipo        Color     Rodado    Cliente\n");
        mostrarBicicleta(lista[indice], tamB, tipos, tamT, colores, tamC, clientes, tamCl);
        printf("\n\n");
        switch(subMenuModificar())
        {
            case 1:
                listarTipos(tipos, tamT);
                pedirEntero(&lista[indice].idTipo, "Ingrese id del tipo: ", "Error. ");
                break;
            case 2:
                pedirFlotante(&lista[indice].rodado, "Ingrese nuevo rodado 20/26/27.5/29: ", "Error. ");
                break;
            default:
                printf("No es un opcion valida\n");
                system("pause");
                break;
        }
            todoOk=1;
    }
    return todoOk;
}
int subMenuModificar()
{
    int opcion;
        printf("1. Modificar tipo\n");
        printf("2. Modificar rodado\n");
        pedirEntero(&opcion, "Ingrese opcion: ", "Error. ");
    return opcion;
}
int buscarBicicleta(eBicicleta lista[], int tamB, int idBicicleta)
{
    int indice=-1;

    for(int i=0;i<tamB;i++)
    {
        if(lista[i].id == idBicicleta && !lista[i].isEmpty)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int bajarBicicleta(eBicicleta lista[], int tamB, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl)
{
    int todoOk=0;
    int id;
    int indice;
    char confirmacion;

    system("cls");
    printf("              BAJA DE BICICLETA\n\n");
    listarBicicletas(lista, tamB, tipos, tamT, colores, tamC, clientes, tamCl);
    pedirEntero(&id, "Ingrese id Bicicleta: ", "Error. ");

    indice = buscarBicicleta(lista, tamB, id);
    if(indice == -1)
    {
        printf("No se encontro bicicleta\n");
    }
    else
    {
        printf("id\t    Marca          Tipo        Color    Rodado\n\n");
        mostrarBicicleta(lista[indice], tamB, tipos, tamT, colores, tamC, clientes, tamCl);
        pedirChar(&confirmacion, "Confirma baja? s/n:  ", "Error. ");

        if(confirmacion == 's')
        {
            lista[indice].isEmpty = 1;
            todoOk=1;
        }
        else if(confirmacion == 'n')
        {
            printf("Baja cancelada por el usuario\n");
            system("pause");
        }
        else
        {
            printf("Error. Ingrese s/n:");
            system("pause");
        }
    }
    return todoOk;
}
void ordenarBicicletas(eBicicleta lista[], int tam)
{
    eBicicleta auxBici;
    for(int i=0;i<tam-1;i++)
    {
        for(int j=i+1;j<tam;j++)
        {
            if(lista[i].idTipo > lista[j].idTipo ||
            (lista[i].idTipo == lista[j].idTipo &&
             lista[i].rodado > lista[j].rodado))
            {
                auxBici=lista[i];
                lista[i]=lista[j];
                lista[j]=auxBici;

            }
        }
    }
}
