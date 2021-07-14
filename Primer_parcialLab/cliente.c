#include "cliente.h"

int cargarNombreCliente(int idCliente, eCliente clientes[], int tamCl, char nombre[])
{
    int todoOk=0;
    if(idCliente>=7000 && idCliente<=7006 && clientes != NULL && tamCl > 0 && nombre != NULL)
    {

    for(int i=0;i<tamCl;i++)
    {
        if(clientes[i].id == idCliente)
        {
            strcpy(nombre, clientes[i].nombre);
            todoOk = 1;
            break;
        }
    }
    }
    return todoOk;
}
int listarClientes(eCliente lista[], int tam)
{
    int isOk=0;

    if(lista != NULL && tam>0)
    {

    printf("               Lista de Clientes  \n");
    printf("----------------------------------------------\n");
    printf("id\t  Nombre Cliente   Sexo  Localidad\n");

    for(int i=0; i<tam; i++)
    {
        mostrarCliente(lista[i], tam);
    }
    isOk =1;
    }
    return isOk;
}

int mostrarCliente(eCliente unCliente, int tam)
{
    int isOk = 0;

    if(tam >0)
    {
    printf("%d     %10s           %c     %15s\n",unCliente.id, unCliente.nombre, unCliente.sexo, unCliente.localidad);
    isOk=1;
    }
    return isOk;
}
int altaCliente(eCliente nuevoCliente[], int tam, int* idCliente)
{
     int todoOk=0;
    eCliente auxAlta;
    int indice;


    printf("   Alta Cliente\n\n");
    printf("Codigo Cliente: %d\n", *idCliente);
    if(nuevoCliente != NULL && tam>0 && idCliente != NULL)
    {
        indice = siguienteCliente(nuevoCliente, tam);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
            system("pause");
        }
        else
        {

            printf("Ingrese nombre de cliente: ");
            fflush(stdin);
            gets(auxAlta.nombre);

            pedirChar(&auxAlta.sexo, "Ingrese sexo de cliente f/m: ", "Error. ");

        auxAlta.id = *idCliente;
        (*idCliente)++;
        auxAlta.isEmpty = 0;
        nuevoCliente[indice]=auxAlta;
        todoOk=1;
        }
    }
    return todoOk;
}
int siguienteCliente(eCliente nuevoCliente[],int  tam)
{
    int libre=-1;
    for(int i=0;i<tam;i++)
    {
        if(nuevoCliente[i].isEmpty)
        {
            libre=i;
            break;
        }
    }
    return libre;
}
int cargarLocalidadCliente(int idCliente, eCliente clientes[], int tamCl, char localidad[])
{
    int todoOk=0;
    if(idCliente>=7000 && idCliente<=7006 && clientes != NULL && tamCl > 0 && localidad != NULL)
    {

    for(int i=0;i<tamCl;i++)
    {
        if(clientes[i].id == idCliente)
        {
            strcpy(localidad, clientes[i].localidad);
            todoOk = 1;
            break;
        }
    }
    }
    return todoOk;
}
