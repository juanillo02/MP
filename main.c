#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "menus.h"
#include "cargar.h"
#include "guardar.h"
#include "admin.h"
#include "tipos.h"
#include "acceso.h"
#include "usuario.h"

int main()
{
	int nUsuarios;		//Numero de usuarios en usuarios.txt//
	int nVehiculos;		//Numero de vehiculos en vehiculos.txt//
	int nViajes;		//Numero de viajes en viajes.txt//
	int nPasos;			//Numero de pasos en pasos.txt//
	usuario *vUsuarios;				//Puntero con la direccion de inicio de un vector de usuario//
	vUsuarios = (usuario *)malloc(sizeof(usuario));
	cargarUsuarios(&vUsuarios, &nUsuarios);
	vehiculo *vVehiculos;			//Puntero con la direccion de inicio de un vector de vehiculos//
	vVehiculos = (vehiculo *)malloc(sizeof(vehiculo));
	cargarVehiculos(&vVehiculos, &nVehiculos);
	viajes *vViajes;				//Puntero con la direccion de inicio de un vector de viaje//
	vViajes = (viajes *)malloc(sizeof(viajes));
	cargarViajes(&vViajes, &nViajes);
	pasos *vPasos;					//Puntero con la direccion de inicio de un vector de paso//
	vPasos = (pasos *)malloc(sizeof(pasos));
	cargarPasos(&vPasos, &nPasos);
	cambiar_estado (&vViajes, &nViajes);
    	menuInicio(&vUsuarios, &nUsuarios, &vVehiculos, &nVehiculos, &vViajes, &nViajes, &vPasos, &nPasos);
	return 0;
}
