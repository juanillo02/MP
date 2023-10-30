#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include "cargar.h"
#include "tipos.h"
#include "usuario.h"
#include "menus.h"


//Su llamada es listarPerfil(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos)
///////////////////////////////////////LISTAR PERFIL////////////////////////////////////////
//Cabecera:void listarPerfil(char *, usuario **, int *, vehiculo **, int *, viajes **, int *, pasos **, int *)
//Precondición: La estructura vUsuarios y n se encuentran inicializados. Recibe la id con la cual se ha identificado el usuario
//Poscondición: Muestra los datos del perfil que accede al sistema
void listarPerfil(char *id, usuario **vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos **vPasos, int *nPasos)
{
	setlocale( LC_ALL, "spanish");
	int i;
	system("cls");
	puts("-	DATOS DEL PERFIL-");
	puts("ID-NOMBRE-LOCALIDAD-PERFIL-USUARIO-CONTRASEÑA");	
	for(i=0;i<(*nUsuarios);i++)							//Con este bucle nos mostrara la información del usuario que accede al sistema 
	{	
		if(strcmp((*vUsuarios)[i].id,id) == 0)				//Compara si el id del usuario.txt es el mismo que el del usuario. Si lo es, se visualizan sus datos
		{
			printf("%s-%s-%s-%s-%s-%s\n\n",(*vUsuarios)[i].id,(*vUsuarios)[i].nombre,(*vUsuarios)[i].localidad,(*vUsuarios)[i].perfil,(*vUsuarios)[i].login,(*vUsuarios)[i].pass);
	 	}
	}
	modificarPerfil(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
}

//Su llamada es modificarPerfil(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
///////////////////////////////////////MODIFICAR PERFIL////////////////////////////////////////
//Cabecera: void modificarUsuario(char *, usuario **, int *, vehiculo **, int *, viajes **, int *, pasos **, int *)
//Precondición: La estructura Usuario y el entero n deben estar inicializados
//Postcondición: Modifica su propio usuario
void modificarPerfil(char *id, usuario **vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos **vPasos, int *nPasos)
{
	setlocale(LC_ALL,"spanish");
	int i,e,opc,perfil=1,p;
	char s;
	puts("-MODIFICAR USUARIO-");
	for(i=0;i<(*nUsuarios);i++) //Recorremos todo el fichero
	{
		if(strcmp(id,(*vUsuarios)[i].id)==0) //Comparamos el id del usuario que ha iniciado sesion con el del fichero
		{
			printf("Desea modificar su usuario?\nEscribe S si asi lo desea\n");
			fflush(stdin); //Liberamos el buffer
			scanf("%s",&s);
			if(s=='S' || s=='s') //Si elegimos modificar el usuario se nos abrira un mensaje para elegir que parte del usuario queremos cambiar
			{
				puts("- OPCIONES -");
				puts("1. Modificar el nombre completo del usuario");
				puts("2. Modificar la localidad");
				puts("3. Modificar el nombre del usuario");
				puts("4. Modificar la contraseÃ±a");
				scanf("%i",&opc);
				switch(opc)
				{
		                	case 1: puts("Escriba su nuevo nombre completo:");
			                	fflush(stdin);
			                	gets((*vUsuarios)[i].nombre);
			                	break;
                			case 2: puts("Escriba su nueva localidad:");
			                	fflush(stdin);
			                	gets((*vUsuarios)[i].localidad);
			                	break;
                			case 3: puts("Escribe el nuevo nombre de usuario:");
			                	fflush(stdin);
			                	gets((*vUsuarios)[i].login);
			                	break;
                			case 4: puts("Escribe la nueva contraseña:");
			                	fflush(stdin);
			                	gets((*vUsuarios)[i].pass);
			                	fflush(stdin);
			                	break;
					default: puts("Opcion incorrecta"); break;
            			}
            			fflush(stdin);
        			system("pause");		//No va a la siguiente operación hasta que pulses una letra
				menuUsuario(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos); //Vuelve al menú inicio
        		}
        		else
        		{
        			fflush(stdin);
        			system("pause");		//No va a la siguiente operación hasta que pulses una letra
				menuUsuario(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos); //Vuelve al menú inicio
			}
			
    		}
    	}
}

//Su llamada es anadirVehiculoUsu(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
////////////////////////////////////////////AÑADIR VEHICULOS//////////////////////////////////////////////
//Cabecera: void anadirVehiculoUsu(char *, usuario *, int , vehiculo **, int *, viajes *, int , pasos *, int )
//Precondición: La estructura vehiculo y el entero n deben estar inicializados
//Postcondición: Añade vehiculos al archivo txt
void anadirVehiculoUsu(char *id, usuario *vUsuarios, int nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes *vViajes, int nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish");			//Para ajustar el idioma al español
    	char res = ' ';
	printf("%s",id);
    	puts("AÑADIR VEHÍCULOS");
    	do
	{
		fflush(stdin);
    		*vVehiculos=realloc((vehiculo *)(*vVehiculos),((*nVehiculos)+1)*sizeof(vehiculo));
		puts("Introduzca la matrícula de su vehículo (7 caracteres):");
    		fgets((*vVehiculos)[*nVehiculos].Id_mat,8,stdin);
    		fflush(stdin);
		strcpy((*vVehiculos)[*nVehiculos].Id_usuario,id); //el valor de la id enviada se copia en la estructura.
		puts("Introduzca el número de plazas de su vehículo");
	    	scanf("%i",&(*vVehiculos)[*nVehiculos].Num_plazas);
	    	fflush(stdin);
		puts("Introduzca la descripción del vehículo. Ejemplo: 'Peugeot 308 Azul'");
	    	gets((*vVehiculos)[*nVehiculos].Desc_veh);
	    	fflush(stdin);
		puts("¿Desea añadir otro vehículo? S/N");
	    	scanf("%c",&res);
	    	fflush(stdin);
		(*nVehiculos)++;
    	}while(res =='s'|| res =='S');
    	fflush(stdin);
	system("pause");
	menuVehiculos(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
}

//Su llamada es listarVehiculoUsu(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
////////////////////////////////////////////////// LISTAR VEHICULO /////////////////////////////////////////////////
//Cabecera: void listarVehiculoUsu (char *, usuario *, int , vehiculo **, int *, viajes *, int , pasos *, int )
//Precondición: La estructura vehiculo y el entero n deben estar inicializados
//Postcondición: Lista los vehiculos del archivo txt
void listarVehiculoUsu (char *id, usuario *vUsuarios, int nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes *vViajes, int nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish");
	int i;
	system("cls");
	printf("%s\n",(*vVehiculos)[0].Id_mat);
	printf("Vehículos del usuario %s:\n", id);
	for(i=0;i<*nVehiculos;i++)
	{
		if (strcmp((*vVehiculos)[i].Id_usuario, id)==0)
		{
			printf("%s-%s-%i-%s\n", (*vVehiculos)[i].Id_mat, (*vVehiculos)[i].Id_usuario, (*vVehiculos)[i].Num_plazas, (*vVehiculos)[i].Desc_veh);
		}
	}
	fflush(stdin);
	system("pause");
	menuVehiculos(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
}

//Su llamada es modificarVehiculoUsu(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
////////////////////////////////////////////////// MODIFICAR VEHICULO /////////////////////////////////////////////////
//Cabecera : void modificarVehiculoUsu(cchar *, usuario *, int , vehiculo **, int *, viajes *, int , pasos *, int )
//Precondicion : las estructura vehiculo debe estar inicializada, además del entero nVehiculo y el id.
//Postcondicion: Modificamos el vehiculo del usuario
void modificarVehiculoUsu(char *id, usuario *vUsuarios, int nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes *vViajes, int nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish");			//Para ajustar el idioma al español		
	system("cls");
	int i,opc;
	char s,n;
	char matricula[8];
	puts("-MODIFICAR VEHÍCULOS DEL USUARIO-");
	fflush(stdin);
	puts(" Escribe la matrícula del vehículo que desea modificar:");
	fgets(matricula,8,stdin);
	fflush(stdin);
	for(i=0; i< (*nVehiculos); i++)
	{
		if(strcmp(id, (*vVehiculos)[i].Id_usuario)==0)
	        {
	        	if(strcmp(matricula, (*vVehiculos)[i].Id_mat)==0)
	            	{
	                	printf("El vehículo seleccionado es %s-%s \nDesea modificarlo?\nEscribe S si asi lo desea\n", (*vVehiculos)[i].Id_mat, (*vVehiculos)[i].Desc_veh);
	                	fflush(stdin);	//Liberamos el buffer
				scanf("%s",&s);
				if(s=='S' || s=='s')
	                	{	//Si elegimos modificar el usuario se nos abrirÃ¡ un menÃº para elegir quÃ© parte del usuario queremos cambiar
	                    		do
	                    		{
	                    			puts("- OPCIONES -");
				                puts("1. Modificar la matrícula");
				                puts("2. Modificar el nuevo número de plazas");
				                puts("3. Modificar la nueva descripción del vehículo");
				                scanf("%i", &opc);
				                switch(opc)
	                    			{
	                        			case 1: puts("Escribe la nueva matrícula");
					                        scanf("%s", &(*vVehiculos)[i].Id_mat);
					                        fflush(stdin);
					                        break;
	                        			case 2: puts("Escribe el nuevo número de plazas");
					                        scanf("%i", &(*vVehiculos)[i].Num_plazas);
					                        fflush(stdin);
					                        break;
	                        			case 3: puts("Escribe la nueva descripción del vehículo");
					                        gets((*vVehiculos)[i].Desc_veh);
					                        fflush(stdin);
					                        break;
	                       		 		default: puts("Elección incorrecta");
	                    			}	
	                    			puts("Desea modificar algo mas?\nEscriba S si asi lo desea");
	                    			scanf("%c", &n);
	                    			fflush(stdin);
	                    		}while (n == 'S' || n == 's');
	                    		fflush(stdin);
					system("pause");
					menuVehiculos(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
	                	}
	            	}
            		else
			{
            			puts("Matrícula incorrecta");
            			fflush(stdin);
				system("pause");
				menuVehiculos(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
			}
        	}
    	}
}

//Su llamada es eliminarVehiculoUsu(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
////////////////////////////////////////////////// ELIMINAR VEHICULO /////////////////////////////////////////////////
//Cabecera : void eliminarVehiculoUsu(cchar *, usuario *, int , vehiculo **, int *, viajes *, int , pasos *, int )
//Precondicion : las estructura vehiculo debe estar inicializada, además del entero nVehiculo y el id.
//Postcondicion: Eliminamos el vehiculo del fichero usuario
void eliminarVehiculoUsu(char *id, usuario *vUsuarios, int nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes *vViajes, int nViajes, pasos *vPasos, int nPasos)
{
	system("cls");
	setlocale( LC_ALL, "spanish");			//Para ajustar el idioma al español	
    	int i,j;
    	char s;
    	char matricula[8];
   	fflush(stdin);
    	puts("-ELIMINAR VEHICULOS DEL USUARIO-");
    	puts(" Escribe la matricula del vehiculo que desea eliminar:");
    	fgets(matricula,8,stdin);
    	fflush(stdin);
    	for(i=0; i< (*nVehiculos); i++)
    	{
        	if(strcmp(id, (*vVehiculos)[i].Id_usuario)==0)
        	{
            		if(strcmp(matricula, (*vVehiculos)[i].Id_mat)==0)
            		{
                		printf("El vehículo seleccionado es %s-%s \nDesea eliminarlo?\nEscribe S si asi lo desea\n", (*vVehiculos)[i].Id_mat, (*vVehiculos)[i].Desc_veh);
                		fflush(stdin);	//Liberamos el buffer
				scanf("%s",&s);
				fflush(stdin);
				if(s=='S' || s=='s')
                		{
                    			for(j=0;j+1<(*nVehiculos);j++)
                    			{
            					strcpy((*vVehiculos)[j].Id_mat,(*vVehiculos)[j+1].Id_mat);
            					strcpy((*vVehiculos)[j].Id_usuario,(*vVehiculos)[j+1].Id_usuario);
                    				(*vVehiculos)[j].Num_plazas = (*vVehiculos)[j+1].Num_plazas;
                    				strcpy((*vVehiculos)[j].Desc_veh,(*vVehiculos)[j+1].Desc_veh);
        		    		}
        	    			(*nVehiculos)--;										//Se elimina una fila del total de vehiculos
       	 	    			*vVehiculos=realloc((vehiculo *)(*vVehiculos),(*nVehiculos)*sizeof(vehiculo));	//Cambiamos las dimensiones del vector 
                			puts("Vehiculo eliminado");
                			fflush(stdin);
					system("pause");
					menuVehiculos(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
                		}
            		}
            		else
            		{
            			puts("Matricula incorrecta");
                		fflush(stdin);
				system("pause");
				menuVehiculos(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
        		}
		}        
    	}
}

//Su llamada es publicarViajes(vVehiculos,nVehiculos,vViajes,nViajes,id)
////////////////////////////////////////////////////////////// PUBLICAR VIAJES /////////////////////////////////////////////////////////////////////
//Cabecera: int publicarViajes (vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, char *id)
//Precondición: La estructura Viajes y el entero n deben estar inicializados
//Postcondición: Añade los viajes seleccionado por el usuario

int publicarViajes (vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, char *id)
{
	setlocale( LC_ALL, "spanish");
	char mat[8];
	char estado[8] = "abierto";
	char str[7];
	int n = 1;
	int i, j, k, suma = 0, cadena, fecha = 0, matricula = 0; //Se inicializan las variables
	system("cls");
	for (i = 0; i < (*nVehiculos); i++) //Este vector recorre la estructura vehículos
	{
		if (strcmp((*vVehiculos)[i].Id_usuario, id) == 0) //Compara que la id del usuario y la id del usuario en el archivo usuario.txt sean el mismo
		{
			matricula = 1; 									//Si matricula=1, existe matricula
			puts ("Elige la matrícula con el coche que deseas realizar el viaje.");
			fflush(stdin);
			fgets(mat, 8, stdin);
			fflush(stdin);
			for(j = 0; j < (*nVehiculos); j++) 				//Recorre la estructura vehiculos
			{
				if (strcmp((*vVehiculos)[j].Id_mat, mat) == 0)  		//Compara si la matricula en el fichero vehiculos es igual a la matricula 
																		//introducida anteriormente
				{
    					strcpy(str, (*vViajes)[*nViajes-1].Id_viaje);		//Copia la id del viaje en la cadena str
    					cadena = atoi(str);									//Transforma la cadena str en un entero
    					cadena += 1;										//Se el suma uno al entero mencionado anteriormente 
    					sprintf((*vViajes)[*nViajes].Id_viaje, "%06d", cadena);      //En el id viajes coge la cadena con los ceros mencionados en el entrecomillado
					*vViajes=realloc((viajes *)(*vViajes),((*nViajes)+1)*sizeof(viajes));    //Se amplia el vector
					strcpy((*vViajes)[* nViajes].Id_mat,mat);			//Copia la matricula en la matricula del coche
					(*vViajes)[* nViajes].Plazas_libres = (*vVehiculos)[* nVehiculos].Num_plazas;  //Asigna a las plazas libre el numero de plazas
					strcpy((*vViajes)[* nViajes].Estado,estado);		//Copia el estado en el estado del viaje
					puts ("Introduce los datos del viaje a dar de alta:");
					puts("Escribe la fecha del viaje:");
					scanf("%s",(*vViajes)[* nViajes].F_inic);			
					fflush(stdin);
					puts("Escribe la hora de inicio del viaje:");
					scanf("%s",(*vViajes)[* nViajes].H_inic);
					fflush(stdin);
					puts("Escribe la hora de finalización del viaje:");
					scanf("%s",(*vViajes)[* nViajes].H_fin);
					fflush(stdin);
					puts("Escribe el importe del viaje:");
					scanf("%f", &(*vViajes)[* nViajes].importe);
					fflush(stdin);
					puts("Escribe si el viaje es de ida o de vuelta:");
					scanf("%s",(*vViajes)[* nViajes].viaje);
					fflush(stdin);
					fecha = comprobar_fecha((*vViajes)[* nViajes].F_inic, (*vViajes)[* nViajes].H_inic, (*vViajes)[* nViajes].H_fin);		//fecha llama a la funcion comprobar_fecha 																															//y si la fecha introducida es correcta la variable cambia a 1	
				}
				if(fecha == 0)		//Fecha introducida incorrecta
				{
					puts ("La matrícula  introducida no es correcta.");
				}
			}
		}
	}
	if(matricula == 0) 			//Si la matricula es iagual a 0 no tiene ningun vehiculo dado de alta
	{
		puts ("No tiene ningún vehículo dado de alta.");
	}
	return 0;
}

//Su llamada es comprobar_fecha((*vViajes)[* nViajes].F_inic, (*vViajes)[* nViajes].H_inic, (*vViajes)[* nViajes].H_fin)
////////////////////////////////////////////////////////////// COMPROBAR FECHA /////////////////////////////////////////////////////////////////////
//Cabecera: int comprobar_fecha (char *fecha, char *inicio, char *final)
//Precondición: Las cadenas deben estar inicializadas
//Postcondición: Comprueba que la fecha introducida para el viaje sea correcta
int comprobar_fecha (char *fecha, char *inicio, char *final)
{
	int dia, mes, ano, comprobar = 1;
	if(sscanf(fecha, "%d/%d/%d") == 3)		//Comprueba que la fecha introducida son tres variables diferentes
    	{
        	sscanf(fecha, "%d/%d/%d", &dia, &mes, &ano);		//Separa las variables de la fecha
        	if(ano<=0)
    		{
    			printf("Año incorrecto, debe ser mayor que cero\n");
		}
 		else
    		{
    			switch(mes)		//Depende del mes introducido los casos
    			{
     				case 1:case 3: case 5: case 7: case 8:case 10: case 12:		//Comprueban que los dias vayan del 1 al 31
                    			if(dia<0 ||dia>=31)
                    			{
                        			printf("día incorrecto, fecha no valida\n");
					}
                    			else
                    			{
                        			printf("fecha valida\n");
					}break;
     				case 4: case 6: case 9: case 11:		//Comprueban que los dias vayan del 1 al 30
                    			if(dia<0 ||dia>=30)
                    			{
                    				printf("día incorrecto, fecha no valida\n");
					}
                    			else
                    			{
                    				printf("fecha valida\n");
					}break;
     				case 2:
                    			if((ano % 4 == 0 && ano % 100 != 0)|| ano % 400 == 0)    	//Comprueban que los años sean bisiestos
                    			{
                    				if(dia<0 ||dia>=29)		//Comprueba que vaya del dia 1 al 29
                        			{
                        				printf("día incorrecto, fecha no valida\n");
						}
                        			else
                        			{
                        				printf("fecha valida\n");
						}
					}
                    			else
                    			{
                    				if(dia<0 ||dia>=28)		//Comprueba que vaya del dia 1 al 28
                        			{
                        				printf("día incorrecto, fecha no valida\n");
						}
                        			else
                        			{
                        				printf("fecha valida\n");
						}
					}break;
     				default: printf("mes incorrecto, fecha no valida\n");
    			}
		}
    	}
    	else
    	{
        	puts("La fecha introducida es incorrecta.");
        	comprobar = 1;		//La fecha es correcta y nos va a devolver 1
    	}
    	return comprobar;
}

// Su llamada es viajes_usuario(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos)
////////////////////////////////////////////////////////////// VIAJES USUARIO /////////////////////////////////////////////////////////////////////
//Cabecera: void viajes_usuario(char *id, usuario **vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos **vPasos, int *nPasos)
//Precondición: La estructura Viajes y el entero n deben estar inicializados
//Postcondición: permite al usuario realizar todas las cosas que pide el viaje usuarios
void viajes_usuario(char *id, usuario **vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos **vPasos, int *nPasos)
{
	setlocale(LC_ALL, "spanish");		//Configura el codigo para español
    	setlocale(LC_ALL, "es_ES");
    	SetConsoleCP(1252);
    	SetConsoleOutputCP(1252);			//Configura el codigo para poder mostrar 
	int i,j,k, sol = 0, numero;
	int e,opc,p,r;
	char s;
	char idviaje[7];
	char cad[8] = "abierto";
	char res = ' ';
	char mat[8];
	char estado[8] = "abierto";
	char str[7];
	int n = 1;
	int matricula=0;
	int coche=0;
	int suma = 0, cadena, fecha = 0;
	system("cls");
    	puts("-LISTAR DE VIAJES ABIERTOS EN ESTE MOMENTO-");
	if(*nViajes == 0)
	{														//La estructura if muestra si el fichero esta vacio ya que no hay nada para buscar
        	printf("No hay viajes.\n");
    	}
	else
	{
        	for(i=0;i<*nViajes;i++)
		{										
			if(strcmp((*vViajes)[i].Estado,cad) == 0) //Lista de los viajes abiertos en ese momento
			{
				printf("%s-%s-%s-%s-%s-%i-%s-%.2f%c-%s\n", (*vViajes)[i].Id_viaje, (*vViajes)[i].Id_mat, (*vViajes)[i].F_inic, (*vViajes)[i].H_inic, (*vViajes)[i].H_fin, (*vViajes)[i].Plazas_libres, (*vViajes)[i].viaje, (*vViajes)[i].importe,128, (*vViajes)[i].Estado );	//Se muestran los datos de todos los viajes que estén abiertos.
			}
		}
		do
		{			
			puts("¿Qué desea hacer?");
			puts("1.- Modificar viaje.");
			puts("2.- Publicar viaje.");
			puts("3.- Incorporarse a un viaje.");
			puts("4.- Volver");
			fflush(stdin);
			scanf("%i", &numero);
			switch(numero) 	
			{
				case 1: 
					for(i=0; i < *nVehiculos; i++)
					{
						if(strcmp(id,(*vVehiculos)[i].Id_usuario)==0)		//Compara la id de fichero vehiculos con la del usuario
						{
							for(k=0;k<*nViajes;k++)
							{
								if(strcmp((*vVehiculos)[i].Id_mat,(*vViajes)[k].Id_mat)==0)  //Compara la matricula del fichero vehiculos con la del fichero viajes
								{
									if((*vViajes)[k].Plazas_libres == (*vVehiculos)[i].Num_plazas) //No se ha incorporado nadie al viaje
									{
										matricula=1;
										sol = 1;
										strcpy(idviaje,(*vViajes)[i].Id_viaje); 	//Copia la id del viaje del fichero viajes en idviaje
										modificarViajeUsu(idviaje, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos);
									}
									else
									{
										printf("No ha sido posible realizar ninguna modificación\n");
										fflush(stdin);
										system("pause");
										menuUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
									}
								}
								if( sol == 0)
								{
									printf("Su usuario no ha publicado este viaje, así que no le será posible modificarlo\n");
									fflush(stdin);
									system("pause");
									menuUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
								}
							}
						}
					}
					if(matricula==0)
					{
						printf("Su usuario no tiene registrado ningun viaje para modificar\n");
						system("pause");
					}
					break;
				case 2: 
					for(i=0; i < *nVehiculos; i++)
					{
						if(strcmp(id,(*vVehiculos)[i].Id_usuario)==0)		//Compara la id de fichero vehiculos con la del usuario
						{
							coche=1;
							system("pause");
							publicarViajes(vVehiculos,nVehiculos,vViajes,nViajes,id);
						}
						else
						{
							printf("No tienes ningun vehiculo dado de alta\n");
							system("pause");
							viajes_usuario(id,vUsuarios, nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
						}
					} 
					if(coche==0)
					{
						printf("Su usuario no tiene registrado ningun coche para publicar un viaje\n");
						fflush(stdin);
						system("pause");
					}
					break;
				case 3: incorporarseaviaje(vPasos, nPasos, vViajes, nViajes, id, vUsuarios, nUsuarios, vVehiculos, nVehiculos); break;
				case 4: menuUsuario(id, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos); break;
				default: puts("Error.");
			}
		}while(numero != 4);
    	}
}

// Su llamada es modificarViajeUsu(idviaje, vUsuarios, nUsuarios, vVehiculos, nVehiculos, vViajes, nViajes, vPasos, nPasos)
////////////////////////////////////////////////////////////// MODIFICAR VIAJES /////////////////////////////////////////////////////////////////////
//Cabecera: void modificarViajesUsu(char *, usuario **, int *, vehiculo **, int *, viajes **, int *, pasos **, int *)
//Precondición: La estructura Viajes y el entero n deben estar inicializados
//Postcondición: Modifica viajes en el archivo txt
int modificarViajeUsu(char *idviaje, usuario **vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos **vPasos, int *nPasos)
{
	int i,e,opc,p,r;
	char s;
	fflush(stdin);
	system("cls");
	puts("-MODIFICAR VIAJE-");
	for(i=0;i<(*nViajes);i++)
	{						//Recorremos todo el fichero
		if(strcmp((*vViajes)[i].Id_viaje,idviaje)==0)			//Comparamos el id que hemos introducido con el del fichero 
		{	
			printf("El viaje seleccionado es: %s-%s \nDesea modificarlo?\nEscribe S si asi lo desea\n",(*vViajes)[i].Id_viaje,(*vViajes)[i].Id_mat);
			fflush(stdin);								//Liberamos el buffer
			scanf("%s",&s);
			fflush(stdin);
			if(s=='S' || s=='s')		//Si elegimos modificar el viaje se nos abrirÃ¡ un menÃº para elegir quÃ© parte del viaje queremos cambiar
			{						
				puts("- OPCIONES -");
				puts("1. Modificar la matricula del viaje:");
				puts("2. Modificar la fecha:");
				puts("3. Modificar la hora de inicio: ");
				puts("4. Modificar la hora de llegada:");
				puts("5. Modificar las plazas libres:");
				puts("6. Modificar el viaje:");
				puts("7. Modificar el importe:");
				puts("8. Modificar el estado del viaje:");
				scanf("%i",&opc);
				fflush(stdin);						
				switch(opc)
				{
					case 1: puts("Escribe la nueva matricula:");
						fflush(stdin);
						gets((*vViajes)[i].Id_mat);	//Elegimos gets para escribir cadenas mÃ¡s largas
						break;
					case 2: puts("Escribe la nueva fecha:");
						fflush(stdin);
						gets((*vViajes)[i].F_inic);	//Elegimos gets para escribir cadenas mÃ¡s largas
						break;				
					case 3: puts("Escribe la nueva hora de inicio:");
						fflush(stdin);
						gets((*vViajes)[i].H_inic);	//Elegimos gets para escribir cadenas mÃ¡s largas
						break;					
					case 4: puts("Escribe la nueva hora de fin:");
						fflush(stdin);
						gets((*vViajes)[i].H_fin);	//Elegimos gets para escribir cadenas mÃ¡s largas
						break;	
					case 5: puts("Escribe las nuevas plazas libres:");
						scanf("%i",&(*vViajes)[i].Plazas_libres);
						break;	
					case 6: puts("Escribe el tipo de viaje (Ida/Vuelta):");
						puts("0.- Ida");
						puts("1.- Vuelta");
						fflush(stdin);
        					scanf("%d",&p);
						switch(p)
						{
		        				case 0: strcpy((*vViajes)[i].viaje,"ida"); break;
		        				case 1: strcpy((*vViajes)[i].viaje,"vuelta"); break;
		        				default: puts("ERROR"); break;
		        			}
						break;	
					case 7: puts("Escribe el nuevo importe:");
						scanf("%f",&(*vViajes)[i].importe);
						break;	
					case 8: puts("Escribe el estado del viaje (Abierto/Cerrado/Iniciado/Finalizado/Anulado):");
						puts("0.- Abierto");
						puts("1.- Cerrado");
						puts("2.- Iniciado");
						puts("3.- Finalizado");
						puts("4.- Anulado");
						fflush(stdin);
		        			scanf("%d",&r);
						switch(r)
						{
		        				case 0: strcpy((*vViajes)[i].Estado,"abierto"); break;
		        				case 1: strcpy((*vViajes)[i].Estado,"cerrado");	break;
		        				case 2: strcpy((*vViajes)[i].Estado,"iniciado"); break;
		        				case 3: strcpy((*vViajes)[i].Estado,"finalizado"); break;
		        				case 4: strcpy((*vViajes)[i].Estado,"anulado"); break;
		        				default: puts("ERROR"); break;
		        			}
						break;
					default: puts("Opcion incorrecta"); break;
				}
				puts("Modificacion realizada");	
			}
			else puts("Se ha cancelado la operacion");
		}
	}
	return 0;
}
	
/// Su llamada es incorporarseaviaje(vPasos, nPasos, vViajes, nViajes, id, vUsuarios, nUsuarios, vVehiculos, nVehiculos)
////////////////////////////////////////////////////////////// INCORPORARSE A VIAJE /////////////////////////////////////////////////////////////////////
//Cabecera: int incorporarseaviaje(pasos **vPasos, int *nPasos,viajes **vViajes, int *nViajes,char *id,usuario **vUsuarios,int *nUsuarios,vehiculo **vVehiculos,int *nVehiculos)
//Precondición: Las estructuras y los n deben estar inicializados
//Postcondición: permite al usuario incorporarse a un viaje
int incorporarseaviaje(pasos **vPasos, int *nPasos,viajes **vViajes, int *nViajes,char *id,usuario **vUsuarios,int *nUsuarios,vehiculo **vVehiculos,int *nVehiculos)
{
	setlocale(LC_ALL, "spanish");	//Ajusta el idioma al español
    	setlocale(LC_ALL, "es_ES");
    	SetConsoleCP(1252);
    	SetConsoleOutputCP(1252);	//Muestra el símbolo 
	int i,j,k,m, solo = 0, acompa = 0, aux, aux1;
	char resp1,resp2,resp3,idviaj1[7],idviaj2[7],idviaj3[7];
	char estado[8] = "cerrado";
	int plazasocupadas;
	float importepersona;
	fflush(stdin);
	system("cls");
	puts("-	INCORPORARSE A UN VIAJE -");
	for(i=0;i<=*nUsuarios;i++)							//Este bucle nos mostrara la información del usuario que accede al sistema 
	{
		if(strcmp((*vUsuarios)[i].id,id)==0)	//Compara si el id del usuario.txt es el mismo que el del usuario. 
		{				   
			puts("A continuación se le mostrará los viajes que tengan previsto pasar por, o se inicien,o terminen en su población.");
			for(j=0;j<=*nPasos;j++)
			{	
				if(strcmp((*vPasos)[j].Poblacion,(*vUsuarios)[i].localidad)==0) //Compara que la poblacion del fichero pasos coincide con la localidad del fichero usuarios para saber si puede incorporarse
																				// el usuario en su ciudad
				{
					aux1 = j; //Guarda la posición para trabajar con esa linea más tarde
					acompa = 1; //Sirve para confirmar que ha entrado en el condicional
					for(k=0;k<*nViajes;k++)
					{
						if((strcmp((*vPasos)[j].Id_pasos,(*vViajes)[k].Id_viaje)==0) && ((*vViajes)[k].Estado!="anulado" && (*vViajes)[k].Estado!="cerrado" && (*vViajes)[k].Estado!="finalizado") && (*vViajes)[k].Plazas_libres!=0)
						{//Comprueba que el id de ambos ficheros sean el mismo, que los estados del viaje no sea ninguno de los mencionados y que existan plazas libres para poder incorporarse
							solo = 1; //Sirve para comprobar que ha entrado en el condicional
							for(m = 0; m < *nVehiculos; m++)
							{
								if(strcmp((*vVehiculos)[m].Id_mat, (*vViajes)[k].Id_mat) == 0) //Comprueba que las matriculas de los coches sean los mismos en ambos ficheros para ver que existe un viaje
																							   // con la matricula de ese vehículo
								{
									aux = k; //Guarda la posición para trabajar con esa linea más tarde
									plazasocupadas=(*vVehiculos)[m].Num_plazas -((*vViajes)[k].Plazas_libres-1); //se calculan las plazas ocupadas
									importepersona=((*vViajes)[k].importe/(float)plazasocupadas); //Se calcula el importe por persona dependiendo de las plazas ocupadas
									(*vViajes)[k].importe = importepersona; //Se guarda en la estructura de viajes
									printf("ID VIAJE-POBLACIÓN-FECHA VIAJE-HORA INICIO-HORA LLEGADA-PLAZAS LIBRES- TIPO VIAJE-IMPORTE-ESTADO\n");
									printf("%s-%s-%s-%s-%s-%i-%s-%.2f%c-%s\n", (*vViajes)[k].Id_viaje, (*vPasos)[j].Poblacion, (*vViajes)[k].F_inic, (*vViajes)[k].H_inic, (*vViajes)[k].H_fin,(*vViajes)[k].Plazas_libres, (*vViajes)[k].viaje, (*vViajes)[k].importe, 128, (*vViajes)[k].Estado );			
								}
							}
						}
					}
					if (solo == 0) //Si solo es 0 significa que no ha entrado en el condicional anterior y que no existen viajes para incorporarse
					{
						printf("No existen viajes para incorporarse\n");
					}
				}
			}
			printf("¿Quiere incorporarse a algún viaje?\n");
			printf("Si quiere incorporarse a un viaje pulse S\n");
			scanf("%c",&resp1);
			fflush(stdin);
			if(resp1=='S' || resp1=='s') //Si responde "S" o "s" empieza a incorporarse al viaje
			{
				printf("Introduzca el id del viaje al que quiere incorporarse\n");
				scanf("%s", &idviaj1);
				fflush(stdin); //Libera el buffer
				for(i = 0; i < *nViajes; i++)
				{
					if(strcmp((*vViajes)[i].Id_viaje,idviaj1)==0) //Si se cumple que el id escrito está en el fichero viajes entonces entra en el condicional
					{
						(*vViajes)[i].Plazas_libres=(*vViajes)[i].Plazas_libres-1; //Como el usuario se incorpora, se quita una plaza libre. Se actualizan las plazas libres.
						if((*vViajes)[i].Plazas_libres==0)
						{
							strcpy((*vViajes)[i].Estado,estado);//si no hay plazas libres, el estado del viaje se pone como cerrado
						}
						printf("Se ha incorporado al viaje con id %s\n",idviaj1);
					}
				}
			}
			printf("¿Desea anular algún viaje?\n");
			printf("Si desea anularlo pulse S\n");
			scanf("%c",&resp2);
			fflush(stdin);
			if(resp2=='S'|| resp2=='s') //Si el usuario decide anular el viaje entra en este condicional
			{
				printf("Introduzca el id del viaje que desea anular\n");
				scanf("%s", &idviaj2);
				fflush(stdin);
				if(strcmp((*vViajes)[aux].Id_viaje,idviaj2)==0) //Comprueba que el id introducido esté en la linea del viaje encontrado anteriormente coincidan
				{
					if((*vViajes)[aux].Estado=="abierto") //Comrpueba que el estado del viaje esté abierto
					{
						(*vViajes)[aux].Plazas_libres=(*vViajes)[aux].Plazas_libres+1;  //Como el usuario se va del viaje, se suma una plaza libre
						printf("Viaje con id %s anulado\n",idviaj2);
					}
				}
			}
			printf("¿Desea visualizar detalladamente algún viaje?\n");
			printf("Si desea viaualizarlo pulse S\n");
			scanf("%c",&resp3);
			fflush(stdin);
			if(resp3=='S' || resp3=='s') //Si responde "S" o "s" muestra detalladamente el viaje
			{
				printf("Introduzca el id del viaje que desea visualizar detalladamente\n");
				scanf("%s",&idviaj3);
				fflush(stdin);
				if(strcmp((*vViajes)[aux].Id_viaje,idviaj3)==0) //Comprueba que la id introducida coincida con el viaje que se encontro anteriormente
				{
					if(strcmp((*vPasos)[aux1].Id_pasos, (*vViajes)[aux].Id_viaje)==0) //Comprueba que ambos id sean iguales en sus respectivas posiciones en el fichero
					{
						printf("ID VIAJE- MATRÍCULA -FECHA VIAJE-HORA INICIO-HORA LLEGADA- PLAZAS LIBRES -TIPO VIAJE-IMPORTE-ESTADO-POBLACIONES\n");
						printf("%s-%s-%s-%s-%s-%i-%s-%.2f%c-%s\n", (*vViajes)[aux].Id_viaje, (*vViajes)[aux].Id_mat, (*vViajes)[aux].F_inic, (*vViajes)[aux].H_inic, (*vViajes)[aux].H_fin, (*vViajes)[aux].Plazas_libres, (*vViajes)[aux].viaje, (*vViajes)[aux].importe, 128, (*vViajes)[aux].Estado);			
					}
					printf("%s\n",(*vPasos)[aux1].Poblacion);
				}		
			}			
		}		
	}
	if(acompa == 0) //Si acompa es 0 significa que no ha entrado en el condicional anterior y que no existen viajes para incorporarse
	{
		printf("En su localidad no puede incorporarse a ningun viaje\n");
	}
	return 0;
}
