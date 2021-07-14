#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
}eTipo;


#endif // TIPO_H_INCLUDED


int cargarDescripcionTipo(int idTipo, eTipo tipos[], int tamT, char desc[]);

int mostrarTipo(eTipo unTipo, int tamT);

int listarTipos(eTipo lista[], int tamT);

int buscarTipo(eTipo lista[], int tamT, int idTipo);
