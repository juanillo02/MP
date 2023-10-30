#ifndef _ADMIN_H_
#define _ADMIN_H_

#include "tipos.h"
#include "cargar.h"

//funciones dentro de administrador

//Gestionar usuarios
void listarUsuarios(char *, usuario **, int *, vehiculo *, int *, viajes *, int *, pasos *, int *);
void modificarUsuario(char *, usuario **, int *, vehiculo *, int , viajes *, int , pasos *, int );
void anadirUsuario(char *, usuario **, int *, vehiculo *, int *, viajes *, int *, pasos *, int *);
void eliminarUsuario(char *, usuario **, int *, vehiculo *, int *, viajes *, int *, pasos *, int *);

//gestionar vehiculos administrador:
void listarVehiculo(char *, usuario *, int *, vehiculo **, int *, viajes **, int *, pasos *, int *);
void modificarVehiculo(char *, usuario *, int , vehiculo **, int *, viajes *, int , pasos *, int );
void anadirVehiculo(char *, usuario *, int *, vehiculo **, int *, viajes *, int *, pasos *, int *);
void eliminarVehiculo(char *, usuario *, int *, vehiculo **, int *, viajes *, int *, pasos *, int *);

//gestionar viajes administrador:
void listarViaje(char *, usuario *, int , vehiculo *, int , viajes **, int *, pasos *, int );
void modificarViaje(char *, usuario *, int , vehiculo *, int , viajes **, int *, pasos *, int );
void anadirViaje(char *, usuario *, int , vehiculo *, int , viajes **, int *, pasos *, int );
void eliminarViaje(char *, usuario *, int , vehiculo *, int , viajes **, int *, pasos *, int );


#endif
