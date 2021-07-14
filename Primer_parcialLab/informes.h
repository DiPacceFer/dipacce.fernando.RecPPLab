#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "color.h"
#include "bicicleta.h"
#include "tipo.h"
#include "cliente.h"
#include "validaciones.h"
#include "trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

int listarBicicletasColor(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eCliente clientes[], int tamCl);

int mostrarBiciPorTipo(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl);

int mostrarTrabajosBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamTr,
                               eServicio servicios[], int tamS);

int mostrarMenorRodado(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC,
                        eCliente clientes[], int tamCl);

int listarBiciSegunTipo(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl);

int mostrarBiciTipoYColor(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl);

int mostrarColorMasElegido(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC,
                           eCliente clientes[], int tamCl);

int mostrarImportesBici(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamTr,
                               eServicio servicios[], int tamS);

int mostrarServiciosBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamTr,
                              eServicio servicios[], int tamS);

int mostrarServiciosFecha(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamTr,
                              eServicio servicios[], int tamS);

int mostrarTrabajosLocalidad(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamTr,
                              eServicio servicios[], int tamS);

int mostrarClientesLocalidad(eCliente clientes[], int tamCl);

int mostrarLocalidadServicios(eTrabajo trabajos[], int tamTr, eServicio servicios[], int tamS,
                               eCliente clientes[], int tamCl, eBicicleta lista[], int tam);

int mostrarTrabajoFecha(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamTr,
                              eServicio servicios[], int tamS);

int mostrarNuevoCliente(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[],
                              int tamC, eCliente clientes[], int tamCl, eTrabajo trabajos[], int tamTr,
                              eServicio servicios[], int tamS);
