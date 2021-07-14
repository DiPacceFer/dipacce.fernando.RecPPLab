#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menu.h"





char menu()
{
    char opcion;
        system("cls");
        printf("    *** ABM BICICLETAS ***\n\n");
        printf("A. Alta\n");
        printf("B. Modificar Bicicleta\n");
        printf("C. Baja Bicicleta\n");
        printf("D. Listar Bicicletas\n");
        printf("E. Listar tipos\n");
        printf("F. Listar Colores\n");
        printf("G. Listar Servicios\n");
        printf("H. Alta Trabajo\n");
        printf("I. Listar trabajos\n");
        printf("J. Informe bicicletas por color seleccionado\n");
        printf("K. Informe bicicletas por tipo seleccionado\n");
        printf("L. Informe de la/las bicicleta/s con el menor rodado\n");
        printf("M. Informe bicicletas segun tipo\n");
        printf("N. Informe cuantas bicicletas hay de un tipo y color seleccionado\n");
        printf("O. Informe del color más elegidos por los clientes\n");
        printf("P. Informe trabajos a una bicicleta seleccionada\n");
        printf("Q. Informe importe de servicios realizados a bicicleta seleccionada\n");
        printf("R. Informe de las bicicletas a las que se les realizo un servicio y la fecha.\n");
        printf("S. Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
        printf("T. Pedir una localidad y mostrar todos los trabajos realizados en la misma.\n");
        printf("U. Pedir una localidad y mostrar todos los clientes de la misma.\n");
        printf("V. Pedir un servicio y mostrar la localidad de los clientes que realizaron ese servicio.\n");
        printf("W. Pedir una fecha y mostrar todos los trabajos realizados en la misma.\n");
        printf("X. Informe de fecha de Ingreso de cada cliente\n");
        printf("Y. Salir\n");
        pedirChar(&opcion, "Ingrese opcion: ", "Error. ");
        opcion = toupper(opcion);
    return opcion;
}
