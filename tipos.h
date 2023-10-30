#ifndef _TIPOS_H_
#define _TIPOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura para usuarios.txt: Almacena informacion de los usuarios del sistema.

typedef struct{
 char id[5];
 char nombre[21];
 char localidad[23];
 char perfil[14];
 char login[6];
 char pass[9];
}usuario;

//Estructura para vehiculos.txt: Almacena informacion de los vehiculos.

typedef struct{
 char Id_mat[8];
 char Id_usuario[5];
 int Num_plazas;
 char Desc_veh[51];
}vehiculo;

//Estructura para viajes.txt: Almacena informacion de los viajes.

typedef struct{
 char Id_viaje[7];
 char Id_mat[8];
 char F_inic[11];
 char H_inic[6];
 char H_fin[6];
 int Plazas_libres;
 char viaje[7];
 float importe;
 char Estado[20];
}viajes;

//Estructura para pasos.txt: Almancena informacion de los pasos.

typedef struct{
 char Id_pasos[7];
 char Poblacion[22];
}pasos;

#endif

