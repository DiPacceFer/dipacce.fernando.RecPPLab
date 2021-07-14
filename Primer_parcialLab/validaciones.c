#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"

int pedirEntero(int* numero, char* mensaje, char* mensajeError)
{
    int isOk= -1;
    int num;
    int reintentos=100;

    if(numero != NULL && mensaje != NULL && mensajeError != NULL)
    {
        while(reintentos > 0)
        {
            printf("%s", mensaje);
            if(scanf("%d", &num) == 1)
            {
                break;
            }
            fflush(stdin);
            reintentos--;
            printf("%s", mensajeError);
        }
        if(reintentos == 0)
        {
            isOk=-1;
        }
        else
        {
            *numero = num;
            isOk=0;
        }
    }
    return isOk;
}
int pedirCadena(char* cadena, int tam, char* mensaje, char* mensajeError)
{
    int isOk;
    char chain[51];
    int reintentos=100;
    int error;
    if(cadena != NULL && mensaje != NULL && mensajeError != NULL && tam>0)
    {
        while(reintentos > 0)
        {
            error = 0;
            printf("%s", mensaje);
            fflush(stdin);
            gets(chain);
            if(strlen(chain) <= tam)
            {
                for(int i=0; i<strlen(chain); i++)
                {
                    if(!isalpha(chain[i]))
                    {
                        error++;
                    }
                }
                if(error == 0)
                {
                    break;
                }
            }
            fflush(stdin);
            reintentos--;
            printf("%s", mensajeError);
        }
        if(reintentos == 0)
        {
            isOk=-1;
        }
        else
        {
            strcpy(cadena, chain);
            isOk=0;
        }
    }
    return isOk;

}
int pedirFlotante(float* numero, char* mensaje, char* mensajeError)
{
    int isOk= -1;
    float num;
    int reintentos=100;
    if(numero != NULL && mensaje != NULL && mensajeError != NULL)
    {
        while(reintentos > 0)
        {
            printf("%s", mensaje);
            if(scanf("%f", &num) == 1)
            {
                break;
            }
            fflush(stdin);
            reintentos--;
            printf("%s", mensajeError);
        }
        if(reintentos == 0)
        {
            isOk=-1;
        }
        else
        {
            *numero = num;
            isOk=0;
        }
    }
    return isOk;
}
int pedirChar(char* Uncaracter, char* mensaje,char* mensajeError)
{
    int isOk;
    char caracter;
    int reintentos=100;
    int error;

    if(mensaje != NULL && mensajeError != NULL)
    {
        while(reintentos > 0)
        {
            error = 0;
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%c", &caracter);
            if(!isalpha(caracter))
            {
                error++;
            }
            if(error == 0)
            {
                break;
            }
            fflush(stdin);
            reintentos--;
            printf("%s", mensajeError);
            printf("%d", reintentos);
        }
        if(reintentos == 0)
        {
            isOk=-1;
        }
        else
        {
            *Uncaracter = caracter;
            isOk=0;
        }
    }
    return isOk;
}

int pedirFecha(eFecha* unaFecha, char* mensaje, char* mensajeError)
{
    int isOk=0;
    eFecha auxFecha;
    int reintentos=100;
    int error;
    if(unaFecha != NULL && mensaje != NULL && mensajeError != NULL)
    {
        while(reintentos > 0)
        {
            error=0;
            printf("%s", mensaje);
            pedirEntero(&auxFecha.dia, "dia: ", "Error. ");
            pedirEntero(&auxFecha.mes, "mes: ", "Error. ");
            pedirEntero(&auxFecha.anio, "anio: ", "Error. ");
            if(!validarFecha(auxFecha.dia, auxFecha.mes, auxFecha.anio))
            {
                error++;
            }
            if(error == 0)
            {
                break;
            }
            fflush(stdin);
            reintentos--;
            printf("%s", mensajeError);
        }
        if(reintentos == 0)
        {
            isOk=-1;
        }
        else
        {
            *unaFecha = auxFecha;
            isOk=0;
        }
    }
    return isOk;
}

int validarFecha(int dia, int mes, int anio)
{
    int todoOk = 0;

    if( mes >= 1 && mes <= 12 )
    {
        switch(mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if(dia >= 1 && dia <= 31)
            {
                todoOk = 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if(dia >= 1 && dia <= 30)
            {
                todoOk = 1;
            }
            break;
        case 2:
            if((anio%4 == 0 && anio%100 != 0) || anio%400 == 0)
            {
                if(dia >= 1 && dia <= 29)
                {
                    todoOk = 1;
                }
            }
            else
            {
                if(dia >= 1 && dia <= 28)
                {
                    todoOk = 1;
                }
            }
            break;
        }
    }
    return todoOk;
}

