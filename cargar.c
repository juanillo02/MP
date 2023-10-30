#include "cargar.h"

//////////////////////////////////////////////////CARGAR USUARIOS////////////////////////////////////////////////
//Cabecera: int cargarUsuarios(usuario **vUsuarios,int *n){
//Precondición: La estructura usuario y el entero n deben estar inicializados
//Postcondición: Carga el fichero de la estructura usuario
int cargarUsuarios(usuario **vUsuarios,int *n){
	FILE *f;
    	char *token;
    	char linea[350];		//Creamos una variable que controle las lineas del fichero 
    	(*vUsuarios)=NULL;	//Asignamos al vector de usuarios el valor NULL para que cada vez que se abra el programa se cargue su contenido de nuevo
  	*n = 0;
	f=fopen("usuarios.txt","r");			//Abrimos el fichero Usuarios.txt para leerlo
    	if (f==NULL)
    	{
    		puts("Error al abrir el fichero");
	}
    	else
	{
	    	do
		{
  			fgets(linea,350,f);				//Recogemos 350 caracteres de la linea (son 350 porque elige desde el principio hasta el final de una cadena)
            		if (strcmp(linea,"\0"))			//Comparamos la linea con el final de cadena \0 para asegurarnos que la linea ha acabado
			{	
	           		(*vUsuarios)=realloc((usuario *)(*vUsuarios),((*n)+1)*sizeof(usuario));	//Aumentamos la dimension del vector usuario
	          		token=strtok(linea,"-");
		                if(token==NULL) break;
		            	strcpy((*vUsuarios)[*n].id,token);
		                token=strtok(NULL,"-");
		                if(token==NULL) break;
		            	strcpy((*vUsuarios)[*n].nombre,token);
				token=strtok(NULL,"-");
		                if(token==NULL) break;
		            	strcpy((*vUsuarios)[*n].localidad,token);
		                token=strtok(NULL,"-");
		                if(token==NULL) break;
		            	strcpy((*vUsuarios)[*n].perfil,token);
		                token=strtok(NULL,"-");
		                if(token==NULL) break;
		            	strcpy((*vUsuarios)[*n].login,token);
		                token=strtok(NULL,"\n");
		                if(token==NULL) break;
		            	strcpy((*vUsuarios)[*n].pass,token);
		                (*n)++; //Aumentamos la linea para que haga lo mismo con las siguientes
		            }
        	}while(!feof(f)); //Repetimos el bucle hasta que terminemos el fichero
    	}
    	fclose(f); //Cerramos el fichero
    	return 0;
}

////////////////////////////////////////////////// CARGAR VEHICULO /////////////////////////////////////////////////
//Cabecera: int cargarVehiculos(vehiculos **vVehiculos,int *n)
//Precondición: La estructura vehiculos y el entero n deben estar inicializados
//Postcondición: Carga el fichero de la estructura vehiculos
int cargarVehiculos(vehiculo **vVehiculos, int *n){
	FILE *fichero;
	char linea[200];  // Guardar cada linea que leamos del fichero.
	char *token;
	int i;
	int guarda_val;
    	*vVehiculos=NULL; //Asignamos al vector de vehículos el valor NULL para que cada vez que se abra el programa se cargue su contenido de nuevo
    	*n=0;
	fichero=fopen("vehiculos.txt","r"); //Abrimos el fichero
	if (fichero==NULL)	//El condicional muestra si se ha podido abrir o no el fichero
	{ 
		puts("Error al abrir el fichero vehiculos.txt");
	}
	else
	{
		do
		{ 
            		if ((fgets(linea,200,fichero) ) != NULL) 	//Recogemos 200 caracteres de la linea (son 200 porque elige desde el principio hasta el final de una cadena)
            		{ 
            			*vVehiculos=realloc((vehiculo *)(*vVehiculos),((*n)+1)*sizeof(vehiculo)); //Aumentamos la dimension del vector vehiculos
				token=strtok(linea,"-");		//Usamos el comando strtok encargado de separar una cadena en tokens. En este caso, separa la linea desde al principio hasta el primer -
		                if(token==NULL) break;
		                strcpy((*vVehiculos)[*n].Id_mat,token);
		                token=strtok(NULL,"-");
		                if(token==NULL) break;
		                strcpy((*vVehiculos)[*n].Id_usuario,token);
				token=strtok(NULL,"-");
		                if (token==NULL) break;
		                guarda_val=atoi(token);
		                (*vVehiculos)[*n].Num_plazas=guarda_val;
				token=strtok(NULL,"\n");
		                if(token==NULL) break;
		                strcpy((*vVehiculos)[*n].Desc_veh,token);
				(*n)++; 	//Aumentamos la linea para que haga lo mismo con las siguientes
			}
		}while(!feof(fichero)); //Se repite hasta que recorra el fichero entero
    	}
	fclose(fichero); //Cerramos el fichero
	return 0;
}

////////////////////////////////////////////////// CARGAR PASOS /////////////////////////////////////////////////
//Cabecera: int cargarPasos(pasos **,int *n)
//Precondición: La estructura Pasos y el entero n deben estar inicializados
//Postcondición: Carga el fichero de la estructura Pasos
int cargarPasos(pasos **vPasos,int *n){
    	FILE *f;
    	char *token;
    	char linea[250];		//Creamos una variable que controle las lineas del fichero 
    	*vPasos=NULL;	//Asignamos al vector de pasos el valor NULL para que cada vez que se abra el programa se cargue su contenido de nuevo
    	*n=0;
	f=fopen("pasos.txt","r");			//Abrimos el fichero pasos.txt para leerlo
    	if (f==NULL)
    	{
    		puts("Error al abrir el fichero");
	} 
    	else
	{
        	do
		{
		        fgets(linea,250,f);				//Recogemos 250 caracteres de la linea (son 250 porque elige desde el principio hasta el final de una cadena)
		        if (strcmp(linea,"\0"))	//Comparamos la linea con el final de cadena \0 para asegurarnos que la linea ha acabado
			{	
                		*vPasos=realloc((pasos *)(*vPasos),((*n)+1)*sizeof(pasos));	//Aumentamos la dimension del vector usuario
				token=strtok(linea,"-");//Usamos el comando strtok encargado de separar una cadena en tokens. En este caso, separa la linea desde al principio hasta el primer -
		                if(token==NULL) break;
		                strcpy((*vPasos)[*n].Id_pasos,token);
				token=strtok(NULL,"\n");
		                if(token==NULL) break;
		                strcpy((*vPasos)[*n].Poblacion,token);
				(*n)++; //Aumentamos la linea para que haga lo mismo con las siguientes
            		}
        	}while(!feof(f)); //Repetimos el bucle hasta que terminemos el fichero
    	}
    	fclose(f); //Cerramos el fichero
    	return 0;
}

////////////////////////////////////////////////// CARGAR VIAJES /////////////////////////////////////////////////
//Cabecera: int cargarViajes(viajes **vViajes,int *n){
//Precondición: La estructura Viajes y el entero n deben estar inicializados
//Postcondición: Carga el fichero de la estructura Viajes
int cargarViajes(viajes **vViajes,int *n){
    	FILE *f;
    	char *token;
    	char linea[300];		//Creamos una variable que controle las lineas del fichero 
    	*vViajes=NULL;	//Asignamos al vector de viajes el valor NULL para que cada vez que se abra el programa se cargue su contenido de nuevo
    	*n=0;
    	int value;
    	float value2;
	f=fopen("viajes.txt","r");			//Abrimos el fichero viajes.txt para leerlo
    	if (f==NULL)
    	{
    		puts("Error al abrir el fichero");
	}   
    	else
	{
        	do
		{
            	fgets(linea,300,f);				//Recogemos 300 caracteres de la linea (son 300 porque elige desde el principio hasta el final de una cadena)
            	if (strcmp(linea,"\0"))			//Comparamos la linea con el final de cadena \0 para asegurarnos que la linea ha acabado
			{	
		                *vViajes=realloc((viajes *)(*vViajes),((*n)+1)*sizeof(viajes));	//Aumentamos la dimension del vector viajes
		                token=strtok(linea,"-");
		                if(token==NULL) break;
		            	strcpy((*vViajes)[*n].Id_viaje,token);
				token=strtok(NULL,"-");
		                if(token==NULL) break;
		            	strcpy((*vViajes)[*n].Id_mat,token);
				token=strtok(NULL,"-");
		                if(token==NULL) break;
		            	strcpy((*vViajes)[*n].F_inic,token);
				token=strtok(NULL,"-");
		                if(token==NULL) break;
		            	strcpy((*vViajes)[*n].H_inic,token);
				token=strtok(NULL,"-");
		                if(token==NULL) break;
		            	strcpy((*vViajes)[*n].H_fin,token);
				token=strtok(NULL,"-");
		                if(token==NULL) break;
		                value = atoi(token);
		                ((*vViajes)[*n].Plazas_libres) = value;
				token=strtok(NULL,"-");
		                if(token==NULL) break;
		            	strcpy((*vViajes)[*n].viaje,token);
				token=strtok(NULL,"-");
		                if(token==NULL) break;
		                value2 = atoi(token);
		            	(*vViajes)[*n].importe = value2;
				token=strtok(NULL,"\n");
		                if(token==NULL) break;
		            	strcpy((*vViajes)[*n].Estado,token);
				(*n)++; //Aumentamos la linea para que haga lo mismo con las siguientes
            		}
		}while(!feof(f)); //Repetimos el bucle hasta que terminemos el fichero
    	}
    	fclose(f); //Cerramos el fichero
    	return 0;
}
