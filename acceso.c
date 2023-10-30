#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>
#include <time.h>
#include "tipos.h"
#include "cargar.h"
#include "guardar.h"

//Cabecera: void registro(usuario **vUsuarios, int *nUsuarios, vehiculo *vVehiculos, int *nVehiculos, viajes *vViajes, int *nViajes, pasos *vPasos, int *nPasos)
//Precondicion: el vector vUsuarios y nUsuarios estan inicializados
//Postcondicion: Si introduces administrador te lleva al menu admin y si introduces usuario te lleva al menu usuario
void registro(usuario **vUsuarios, int *nUsuarios, vehiculo *vVehiculos, int *nVehiculos, viajes *vViajes, int *nViajes, pasos *vPasos, int *nPasos)
{
	setlocale( LC_ALL, "spanish"); //Ajusta al idioma espanol
	int i, aux = 0;
	char us[6];
	char ct[9];
	char *id;
	fflush(stdin);
	system("cls");
	puts("Introduce tu usuario:"); //Introduce tu usuario.
	fgets(us, 6, stdin); 			//Usamos fgets para evitar que el usuario introduzca caracteres de mas
	fflush(stdin);
	puts("Introduce tu contrase�a:"); //Introduce tu contrasena.
	fgets(ct, 9, stdin);
	fflush(stdin);
	for(i=0;i<(*nUsuarios);i++)
	{
        if(strcmp((*vUsuarios)[i].login,us)==0) //Si el apodo usuario introducido coincide con algun usuario del fichero, entra en el condicional
		{	
            if(strcmp((*vUsuarios)[i].pass,ct)==0) //Si la contrasena que el usuario ha introducido coincide con alguna contrasena del fichero, entra en el condicional
			{	
				aux = 1; //Sirve para comprobar que ha entrado en el condicional
				id = (*vUsuarios)[i].id; 
                if(strcmp((*vUsuarios)[i].perfil,"administrador")==0) //Comrprueba que el perfil del fichero coincida con "administrador" para saber si entra en el menu de administrador o entra en el menu de los usuarios
				{
                    menuAdministrador(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos); 
                }
				else
				{
					menuUsuario(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos); 
                }
            }

    	}
	}

    if(aux == 0)	//Si el usuario es incorrecto, aux no cambia de valor, por lo que entra en este condicional
	{
        puts("ERROR: Usuario o contraseña no existe.");
        system("pause");
        menuInicio(vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos);
    }
}


///////////////////////////////////////////////////////////////////// ANADIR USUARIOS /////////////////////////////////////////////////////////////////////////
//Cabecera: void anadirUsuarios(usuario **vUsuarios, int *nUsuarios, vehiculo *vVehiculos, int *nVehiculos, viajes *vViajes, int *nViajes, pasos *vPasos, int *nPasos)
//Precondici�n: La estructura Usuario y el entero n deben estar inicializados
//Postcondici�n: Anade usuarios al archivo txt
void anadirUsuarios(usuario **vUsuarios, int *nUsuarios, vehiculo *vVehiculos, int *nVehiculos, viajes *vViajes, int *nViajes, pasos *vPasos, int *nPasos)
{
	int p, cadena;
	char str[5];
	char usu[5];
	char con[8];
	setlocale( LC_ALL, "spanish");
	system("cls");
	puts("-A�ADIR USUARIO-");
	*vUsuarios=realloc((usuario *)(*vUsuarios),((*nUsuarios)+1)*sizeof(usuario));		//Aumentamos la dimension del vector para ampliar el espacio
	strcpy(str, (*vUsuarios)[*nUsuarios-1].id);
    cadena = atoi(str);
    cadena += 1;
    sprintf((*vUsuarios)[*nUsuarios].id, "%04d", cadena);
	puts("Escriba el nombre del nuevo usuario:");
	gets((*vUsuarios)[*nUsuarios].nombre);	
	fflush(stdin);																	//Liberamos el buffer
	puts("Escriba la localidad del nuevo usuario:");
	gets((*vUsuarios)[*nUsuarios].localidad);										//Usamos gets para que copie una cadena con espacios
																					//Para el perfil, hemos decidido que el usuario elija una opcion en lugar de escribirlo ya que sera mas facil de comprobar despues 
	system("cls");																				      	
	puts("Elige el perfil del nuevo usuario:");
	puts("0.- Usuario");
	puts("1.- Admin");
	fflush(stdin);																				
    do
	{
		fflush(stdin);
        scanf("%d",&p);
		switch(p)
		{
			case 0: strcpy((*vUsuarios)[*nUsuarios].perfil,"usuario"); break;								//Copia la palabra "usuario" en la zona del perfil
        	case 1: strcpy((*vUsuarios)[*nUsuarios].perfil,"administrador"); break;						//Copia la palabra "administrador" en la zona del perfil
        	default: puts("ERROR: no ha escogido 1 o 0\nElige el perfil del nuevo usuario:"); break;
        }	
    }while(p!=1 && p!=0);
    fflush(stdin);
    do
	{
    	system("cls");
		puts("Escriba el apodo del nuevo usuario (5 car�cteres):");
		scanf("%s",&usu);
		fflush(stdin);
	}while(strlen(usu)!=5);
	strcpy((*vUsuarios)[*nUsuarios].login,usu);
	do
	{
		system("cls");
		puts("Escriba la contrase�a del nuevo usuario (8 car�cteres):");
		scanf("%s",&con);
		fflush(stdin);	
	}while(strlen(con)!=8);
	strcpy((*vUsuarios)[*nUsuarios].pass,con);
	(*nUsuarios)++;																//Aumentamos el numero total de usuarios
	guardarUsuarios(vUsuarios, nUsuarios);
	system("pause");															//No va a la siguiente operacion hasta que pulses una letra
	menuInicio(vUsuarios,nUsuarios,vVehiculos,nVehiculos, vViajes,nViajes,vPasos,nPasos);					//Una vez registrado, vuelve al menu inicio para iniciar sesion
}

// Su llamada es cambiar_estado (&vViajes, &nViajes);
////////////////////////////////////////////////////////////// CAMBIAR ESTADO /////////////////////////////////////////////////////////////////////
//Cabecera: void cambiar_estado (viajes **vViajes, int *nViajes)
//Precondici�n: La estructura Viajes y el entero n deben estar inicializados
//Postcondici�n: Se cambia el estado del viaje una vez haya pasado una hora de que el estado haya finalizado

void cambiar_estado (viajes **vViajes, int *nViajes)
{
	int chora, cmin, cdia, cmes, cano, hora, minutos, dia, mes, ano, k;
	time_t now;		//Se obtiene la hora actual
	time (&now);
	struct tm *local = localtime (&now); //Crea la estructura del tiempo
	hora = local -> tm_hour;		//Se pasa la hora actual a las variables definidas
	minutos = local -> tm_min;
	dia = local -> tm_mday;
	mes = local -> tm_mon + 1;
	ano = local -> tm_year + 1900;
	for(k = 0; k < *nViajes; k++)
	{
		sscanf((* vViajes)[k].H_fin, "%d:%d", &chora, &cmin);		//Separa el hora (y abajo el dia) en variables distintas
		sscanf((* vViajes)[k].F_inic, "%d/%d/%d", &cdia, &cmes, &cano);
		if (1 + hora == 1 + chora && cmin >= minutos && dia == cdia && mes == cmes && ano == cano) //Cuando pase 1 hora despu�s de la finalizaci�n entra en el condicional para cambiar el estado
		{
			strcpy((*vViajes)[k].Estado, "finalizado");
		}
	}
}

