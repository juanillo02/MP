#ifndef _MENUS_H_
#define _MENUS_H_
#include "tipos.h"



void menuInicio(usuario **, int *,vehiculo *, int *, viajes *, int *, pasos *, int *);
void menuUsuario(char *, usuario **, int *, vehiculo **, int *, viajes **, int *, pasos **, int *);
void menuAdministrador(char *, usuario **, int , vehiculo **, int *, viajes **, int *, pasos *, int);
void menuVehiculos(char *, usuario **, int *, vehiculo **, int *, viajes **, int *, pasos **, int *);
void usuarios_administrador(char *, usuario **, int , vehiculo **, int , viajes **, int , pasos *, int);
void vehiculos_administrador(char *, usuario *, int , vehiculo **, int *, viajes **, int *, pasos *, int );
void viajes_administrador(char *, usuario *, int , vehiculo *, int , viajes **, int *, pasos *, int );



#endif
