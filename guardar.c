#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guardar.h"

void guardar(usuario **vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos **vPasos, int *nPasos)
{
	guardarUsuarios(vUsuarios, nUsuarios);
	guardarVehiculos(vVehiculos, nVehiculos);
	guardarViajes(vViajes, nViajes);
	guardarPasos(vPasos, nPasos);
	system("pause");
	exit(0);
}

/////////////GUARDAR USUARIO////////////////
//Llamada a funcion: guardarUsuario(vUsuario, nUsuarios)
//Cabecera: void guardarUsuario(usuario *vUsuarios, int nUsuarios)
//Precondicion: Vector Usuario y tama?o del vector iniciado 
//Postcondicion:Escribe en el fichero los nuevos cambios

void guardarUsuarios(usuario **vUsuarios, int *nUsuarios)
{
    	FILE *f;
    	int i = 0;
    	int us;
    	// Escribir todos los usuarios, incluyendo el nuevo, en el archivo
    	f = fopen("Usuarios.txt", "w+");
    	if (f == NULL)
	{
        	puts("Error al abrir el fichero");
    	}
	else
	{
        	for (i = 0; i < (*nUsuarios)-1; i++)
		{
            		fprintf(f, "%s-%s-%s-%s-%s-%s\n", (*vUsuarios)[i].id, (*vUsuarios)[i].nombre, (*vUsuarios)[i].localidad, (*vUsuarios)[i].perfil, (*vUsuarios)[i].login, (*vUsuarios)[i].pass);
        	}
       	 	us = ((*nUsuarios)-1);
        	fprintf(f, "%s-%s-%s-%s-%s-%s", (*vUsuarios)[us].id, (*vUsuarios)[us].nombre, (*vUsuarios)[us].localidad, (*vUsuarios)[us].perfil, (*vUsuarios)[us].login, (*vUsuarios)[us].pass);
        	fclose(f); // Cerrar el archivo
    	}
}

/////////////GUARDAR VEHICULOS////////////////
//Llamada a funcion: guardarVehiculos(vMatriculos, nVehiculos)
//Cabecera: void guardarVehiculos(usuario *vMatriculas, int nVehiculos)
//Precondicion: Vector Vehiculos y tama�o del vector iniciado 
//Postcondicion:Escribe en el fichero los nuevos cambios
void guardarVehiculos(vehiculo **vVehiculos, int *nVehiculos){
    	FILE *f;
	int i = 0;							//Creamos una variable encargada de realizar el bucle
	int veh;
	f=fopen("Vehiculos.txt","w+");	//Abrimos el fichero Vehiculos.txt para escribir en el
	if (f==NULL)
	{
    		puts("Error al abrir el fichero");
	}
    	else
    	{
    		for(i=0;i< (*nVehiculos)-1;i++)	//Hacemos el bucle para todas las lineas excepto la ultima                               
            	{
                	fprintf(f,"%s-%s-%i-%s\n", (*vVehiculos)[i].Id_mat, (*vVehiculos)[i].Id_usuario, (*vVehiculos)[i].Num_plazas, (*vVehiculos)[i].Desc_veh ); //Escribimos en el fichero todas las variables      
            	}
        	veh = ((*nVehiculos)-1);
        	fprintf(f,"%s-%s-%i-%s", (*vVehiculos)[veh].Id_mat, (*vVehiculos)[veh].Id_usuario, (*vVehiculos)[veh].Num_plazas, (*vVehiculos)[veh].Desc_veh );
	}       
	fclose(f);
}

/////////////GUARDAR VIAJES////////////////
//Llamada a funcion: guardarViajes(vViajes, nViajes)
//Cabecera: void guardarViajes(viajes *vViajes, int nViajes)
//Precondicion: Vector Viajes y tama�o del vector iniciado 
//Postcondicion:Escribe en el fichero los nuevos cambios
void guardarViajes(viajes **vViajes, int *nViajes){
    	FILE *f;
    	int i = 0;							//Creamos una variable encargada de realizar el bucle
    	int viaje;
    	f=fopen("Viajes.txt","w+");			//Abrimos el fichero usuarios.txt para escribir en el
    	if (f==NULL)
    	{
    		puts("Error al abrir el fichero");
	}  
    	else
    	{
    		for(i=0;i<(*nViajes)-1;i++)	                               
            	{
                	fprintf(f,"%s-%s-%s-%s-%s-%i-%s-%.2f-%s\n", (*vViajes)[i].Id_viaje, (*vViajes)[i].Id_mat, (*vViajes)[i].F_inic, (*vViajes)[i].H_inic, (*vViajes)[i].H_fin, (*vViajes)[i].Plazas_libres, (*vViajes)[i].viaje, (*vViajes)[i].importe, (*vViajes)[i].Estado ); //Escribimos en el fichero todas las variables     
            	}
        	viaje = ((*nViajes)-1);
        	fprintf(f,"%s-%s-%s-%s-%s-%i-%s-%.2f-%s", (*vViajes)[viaje].Id_viaje, (*vViajes)[viaje].Id_mat, (*vViajes)[viaje].F_inic, (*vViajes)[viaje].H_inic, (*vViajes)[viaje].H_fin, (*vViajes)[viaje].Plazas_libres, (*vViajes)[viaje].viaje, (*vViajes)[viaje].importe, (*vViajes)[viaje].Estado);
	}
    	fclose(f);
}

/////////////GUARDAR PASOS////////////////
//Llamada a funcion: guardarPasos(vPasos, nPasos)
//Cabecera: void guardaPasos(pasos *vPasos, int nPasos)
//Precondicion: Vector Pasos y tama�o del vector iniciado 
//Postcondicion:Escribe en el fichero los nuevos cambios
void guardarPasos(pasos **vPasos, int *nPasos){
    	FILE *f;
    	int i = 0;							//Creamos una variable encargada de realizar el bucle
    	int paso;
    	f=fopen("Pasos.txt","w+");	//Abrimos el fichero usuarios.txt para escribir en el
    	if (f==NULL)
    	{
    		puts("Error al abrir el fichero");
	}  
    	else
    	{
    		for(i=0;i<(*nPasos)-1;i++)                               
            	{
                	fprintf(f,"%s-%s\n", (*vPasos)[i].Id_pasos, (*vPasos)[i].Poblacion ); //Escribimos en el fichero todas las variables        
            	}
        	paso = ((*nPasos) - 1);
        	fprintf(f,"%s-%s", (*vPasos)[paso].Id_pasos, (*vPasos)[paso].Poblacion );
	}      
    	fclose(f);
}
