#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "cargar.h"
#include "admin.h"
#include "menus.h"
#include "tipos.h"
#include "guardar.h"

///////////////////////////////////////////////////////////////////// MENU INICIO /////////////////////////////////////////////////////////////////////////
void menuInicio(usuario **vUsuarios, int *nUsuarios, vehiculo *vVehiculos, int *nVehiculos, viajes *vViajes, int *nViajes, pasos *vPasos, int *nPasos)
{
	setlocale( LC_ALL, "spanish");
	int inicio;
	system("cls");
	puts("- BIENVENIDO A ESI-SHARE -");
	puts("1.- Registrarse.");
	puts("2.- Iniciar Sesión.");
	do
	{	
		scanf("%d", &inicio);
		fflush(stdin);
		switch(inicio)
		{
			case 1: anadirUsuarios(vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos); system("pause"); break; 
			case 2: registro(vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos); break;
			default: printf ("Error."); break;
		}
		menuInicio(vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos);
	}while (inicio != 2);
}

///////////////////////////////////////////////////////////////////// MENU USUARIO /////////////////////////////////////////////////////////////////////////
void menuUsuario(char *id, usuario **vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos **vPasos, int *nPasos)
{
	setlocale( LC_ALL, "spanish");
	int usuario, i, resp;
	system("cls");
	puts("- BIENVENIDO -");
	puts("Seleccione una opción:");
	puts("1.- Perfil");
	puts("2.- Vehículos");
	puts("3.- Viajes");
	puts("4.- Salir");
	do
	{	
		scanf("%d", &usuario);
		fflush(stdin);
		switch(usuario)
		{
			case 1: listarPerfil(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos); system("pause"); break; 
			case 2: 
				for	(i = 0; i < (*nVehiculos); i++)
					{
						if(strcmp((*vVehiculos)[i].Id_usuario, id) == 0)
						{
							menuVehiculos(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos); system("pause");
						}
					}
						puts ("No tiene ningún vehículo registrado.");
						puts ("¿Desea registrar un vehículo? (S o N)");
						fflush(stdin);
						scanf("%s", &resp);
						fflush(stdin);
						if('S' == resp || 's' == resp)
						{
							anadirVehiculoUsu(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos);
						}
						else
						{
							menuUsuario(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos);
						} break;
			case 3: viajes_usuario(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos); system("pause"); break;
			case 4: guardar(vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos);
			default: printf ("Error"); break;
		}
	}while (usuario != 4);
}

///////////////////////////////////////////////////////////////////// MENU ADMINISTRADOR /////////////////////////////////////////////////////////////////////////
void menuAdministrador(char *id, usuario **vUsuarios, int nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish");
	int administrador;
	system("cls");
	puts("- BIENVENIDO -");
	puts("Seleccione una opción:");
	puts("1.- Usuarios");
	puts("2.- Vehículos");
	puts("3.- Viajes.");
	puts("4.- Salir");
	do
	{	
		scanf("%d", &administrador);
		switch(administrador)
		{
			case 1: fflush(stdin);usuarios_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break; 
			case 2: fflush(stdin);vehiculos_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 3: fflush(stdin);viajes_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 4: guardar(vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos);
			default: printf ("Error"); break;
		}
	menuAdministrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
	}while (administrador != 4);
}

///////////////////////////////////////////////////////////////////// MENU VEHICULOS /////////////////////////////////////////////////////////////////////////
void menuVehiculos(char *id, usuario **vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos **vPasos, int *nPasos)
{
	setlocale( LC_ALL, "spanish");
	int veh;
	system("cls");
	puts("Seleccione una opción:");
	puts("1.- Listar");
	puts("2.- Añadir");
	puts("3.- Eliminar.");
	puts("4.- Modificar.");	
	puts("5.- Volver");	
	do
	{	
		scanf("%d", &veh);
		switch(veh)
		{
			case 1: fflush(stdin);listarVehiculoUsu(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break; 
			case 2: fflush(stdin);anadirVehiculoUsu(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 3: fflush(stdin);eliminarVehiculoUsu(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 4: fflush(stdin);modificarVehiculoUsu(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 5: fflush(stdin);menuUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			default: printf ("Error"); break;
		}
	}while (veh != 6);
}

///////////////////////////////////////////////////////////////////// MENU USUARIOS /////////////////////////////////////////////////////////////////////////
void usuarios_administrador(char *id, usuario **vUsuarios, int nUsuarios, vehiculo **vVehiculos, int nVehiculos, viajes **vViajes, int nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish");
	int usuarios;
	system("cls");
	puts("Seleccione una opción:");
	puts("1.- Listar");
	puts("2.- Añadir");
	puts("3.- Eliminar.");
	puts("4.- Modificar.");
	puts("5.- Volver");
	do
	{	
		scanf("%d", &usuarios);
		switch(usuarios)
		{
			case 1: fflush(stdin);listarUsuarios(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break; 
			case 2: fflush(stdin);anadirUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 3: fflush(stdin);eliminarUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 4: fflush(stdin);modificarUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 5: fflush(stdin);menuAdministrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			default: printf ("Error"); break;
		}
	usuarios_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
	}while (usuarios != 6);
}

///////////////////////////////////////////////////////////////////// MENU VEHICULOS ADMINISTRADOR /////////////////////////////////////////////////////////////////////////
void vehiculos_administrador(char *id, usuario *vUsuarios, int nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish");
	int vehiculoadmin;
	system("cls");
	puts("Seleccione una opción:");
	puts("1.- Listar");
	puts("2.- Añadir");
	puts("3.- Eliminar.");
	puts("4.- Modificar.");
	puts("5.- Volver.");
	do
	{	
		scanf("%d", &vehiculoadmin);
		switch(vehiculoadmin)
		{
			case 1: fflush(stdin);listarVehiculo(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break; 
			case 2: fflush(stdin);anadirVehiculo(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 3: fflush(stdin);eliminarVehiculo(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 4: fflush(stdin);modificarVehiculo(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 5: fflush(stdin);menuAdministrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);system("pause"); break;
			default: printf ("Error"); break;
		}
	}while (vehiculoadmin != 6);
}

///////////////////////////////////////////////////////////////////// MENU VIAJES ADMINISTRADOR /////////////////////////////////////////////////////////////////////////
void viajes_administrador(char *id, usuario *vUsuarios, int nUsuarios, vehiculo *vVehiculos, int nVehiculos, viajes **vViajes, int *nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish");
	int viajesadmin;
	system("cls");
	puts("Seleccione una opción:");
	puts("1.- Listar");
	puts("2.- Añadir");
	puts("3.- Eliminar.");
	puts("4.- Modificar.");
	puts("5.- Volver");		
	do
	{	
		scanf("%d", &viajesadmin);
		switch(viajesadmin)
		{
			case 1: fflush(stdin);listarViaje(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break; 
			case 2: fflush(stdin);anadirViaje(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 3: fflush(stdin);eliminarViaje(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 4: fflush(stdin);modificarViaje(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); system("pause"); break;
			case 5: fflush(stdin);menuAdministrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);system("pause"); break;
			default: printf ("Error"); break;
		}
	}while (viajesadmin != 6);
}
