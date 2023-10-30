#ifndef _USUARIOS_H_
#define _USUARIOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

void listarPerfil (char *, usuario **, int *, vehiculo **, int *, viajes **, int *, pasos **, int *);
void modificarPerfil(char *, usuario **, int *, vehiculo **, int *, viajes **, int *, pasos **, int *);
void anadirVehiculoUsu (char *, usuario *, int , vehiculo **, int *, viajes *, int , pasos *, int );
void eliminarVehiculoUsu(char *, usuario *, int , vehiculo **, int *, viajes *, int , pasos *, int );
void listarVehiculoUsu (char *, usuario *, int , vehiculo **, int *, viajes *, int , pasos *, int );
void modificarVehiculoUsu (char *, usuario *, int , vehiculo **, int *, viajes *, int , pasos *, int );
int incorporarseaviaje (pasos **, int *, viajes **, int *, char *, usuario **, int *, vehiculo **, int *);
int publicarViajes (vehiculo **, int *, viajes **, int *, char *);
int comprobar_fecha (char *, char *, char *);
void viajes_usuario(char *, usuario **, int *, vehiculo **, int *, viajes **, int *, pasos **, int *);
int modificarViajeUsu(char *, usuario **, int *, vehiculo **, int *, viajes **, int *, pasos **, int *);

#endif

