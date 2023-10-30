#ifndef _GUARDAR_H_
#define _GUARDAR_H_

#include "tipos.h"
#include "cargar.h"

//precond: un vector usuario existente y un tam de vector
//prostcond : guarda en el fichero los datos de los usuarios

void guardar(usuario **, int *, vehiculo **, int *, viajes **, int *, pasos **, int *);
void guardarUsuarios(usuario **,int *);
void guardarVehiculos(vehiculo **,int *);
void guardarViajes(viajes **,int *);
void guardarPasos(pasos **,int *);

#endif // _GUARDAR_H_

