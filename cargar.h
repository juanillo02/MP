#ifndef _CARGAR_H_
#define _CARGAR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"
    

int cargarUsuarios(usuario **,int *);   //usuario ** significa que apunta al interior del inicio de un vector, y la posicion del vector sera la que nos da con el int * para llegar al usuario correspondiente almacenado en dicha posicion del vector//
int cargarVehiculos(vehiculo **,int *);
int cargarViajes(viajes **,int *);
int cargarPasos(pasos **,int *);
void registro(usuario **, int *, vehiculo *, int *, viajes *, int *, pasos *, int *);
void anadirUsuarios(usuario **, int *, vehiculo *, int *, viajes *, int *, pasos *, int *);
#endif
