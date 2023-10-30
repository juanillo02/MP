#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "admin.h"
#include "cargar.h"
#include "tipos.h"

//Su llamada es listarUsuarios(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
///////////////////////////////////////////////////////////////////// LISTAR USUARIOS /////////////////////////////////////////////////////////////////////////
//Cabecera: void listarUsuarios(char *, usuario **, int *, vehiculo *, int *, viajes *, int *, pasos *, int *)
//Precondición: La estructura Usuario y el entero n deben estar inicializados
//Postcondición: Lista todos los usuarios del archivo txt

void listarUsuarios(char *id, usuario **vUsuarios, int *nUsuarios, vehiculo *vVehiculos, int *nVehiculos, viajes *vViajes, int *nViajes, pasos *vPasos, int *nPasos)
{
	int i;
	setlocale( LC_ALL, "spanish"); //Para poder escribir y leer en español
	system("cls"); //Limpia la pantalla
	puts("-LISTA DE USUARIOS-");
	puts("ID-NOMBRE-LOCALIDAD-PERFIL-USUARIO-CONTRASENA");
	for(i=0;i<(*nUsuarios);i++)		//Con este bucle nos mostrara toda la informacion de cada usuario
	{							
	 printf("%s-%s-%s-%s-%s-%s\n",(*vUsuarios)[i].id,(*vUsuarios)[i].nombre,(*vUsuarios)[i].localidad,(*vUsuarios)[i].perfil,(*vUsuarios)[i].login,(*vUsuarios)[i].pass);
	}
	system("pause"); //No va a la siguiente operación hasta que pulses una letra
	fflush(stdin);
	usuarios_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Vuelve al menu usuarios
}



//Su llamada es modificarUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
///////////////////////////////////////////////////////////////////// MODIFICAR USUARIOS /////////////////////////////////////////////////////////////////////////
//Cabecera: void modificarUsuario(char *, usuario **, int *, vehiculo *, int *, viajes *, int *, pasos *, int *)
//Precondición: La estructura Usuario y el entero n deben estar inicializados
//Postcondición: Modifica usuarios en el archivo txt 

void modificarUsuario(char *id, usuario **vUsuarios, int *nUsuarios, vehiculo *vVehiculos, int nVehiculos, viajes *vViajes, int nViajes, pasos *vPasos, int nPasos)
{
	char id_nuevo[4];	//Creamos una variable cadena para comparar con el id del fichero
	int i,e,opc,perfil=1,p,aux = 0;
	char s, n, res;
	setlocale( LC_ALL, "spanish"); //Para poder escribir y leer en español
	system("cls"); //Limpia la pantalla
	for(i=0;i<(*nUsuarios);i++)		//Con este bucle nos mostrara toda la informacion de cada usuario
	{							
		printf("%s-%s-%s-%s-%s-%s\n",(*vUsuarios)[i].id,(*vUsuarios)[i].nombre,(*vUsuarios)[i].localidad,(*vUsuarios)[i].perfil,(*vUsuarios)[i].login,(*vUsuarios)[i].pass);
	}
	puts("-MODIFICAR USUARIO-");
	puts("Introduzca el id que desea modificar:"); //El usuario introduce una id para comprobar
	scanf("%s",&id_nuevo);
	fflush(stdin);
	for(i=0;i<(*nUsuarios);i++)		//Recorremos todo el fichero
	{	
		if(strcmp(id_nuevo,(*vUsuarios)[i].id)==0)	//Comparamos el id que hemos introducido exista en el fichero 
		{		
			aux = 1; //aux pasa a ser 1 para confirmar que la id seleccionada existe
			printf("El usuario seleccionado es: %s-%s \nDesea modificarlo?\nEscribe S si asi lo desea\n",(*vUsuarios)[i].id,(*vUsuarios)[i].nombre);
			fflush(stdin);	//Liberamos el buffer
			scanf("%s",&s);
			if(s=='S' || s=='s')
			{	//Si elegimos modificar el usuario se nos abrirá un menú para elegir qué parte del usuario queremos cambiar
				do
				{	
					system("cls");
					puts("- OPCIONES -");
					puts("1. Modificar el id del usuario");
					puts("2. Modificar el nombre completo del usuario");
					puts("3. Modificar la localidad");
					puts("4. Modificar el perfil del usuario: ");
					puts("5. Modificar el nombre del usuario:");
					puts("6. Modificar la contraseña:");
					scanf("%i",&opc);						
					switch(opc)
					{
						case 1: puts("Escribe el nuevo id del usuario:");
						fflush(stdin);
						scanf("%s",&(*vUsuarios)[i].id);
						break;
						
						case 2: puts("Escribe el nuevo nombre completo del usuario:");
						fflush(stdin);
						gets((*vUsuarios)[i].nombre);	//Elegimos gets para escribir cadenas más largas
						break;
						
						case 3: puts("Escribe la nueva localidad:");
						fflush(stdin);
						gets((*vUsuarios)[i].localidad);	//Elegimos gets para escribir cadenas más largas
						break;
						
						case 4: 
							system("cls");	//Limpia la pantalla					
							puts("Elige el perfil del nuevo usuario:");
							puts("0.- Usuario");
							puts("1.- Admin");
							fflush(stdin);
        					scanf("%d",&p);
        					fflush(stdin);
							switch(p)
							{
        						case 1: strcpy((*vUsuarios)[i].perfil,"administrador");	//Copia la palabra "administrador" en la zona del perfil
        						break;
        						case 0: strcpy((*vUsuarios)[i].perfil,"usuario");		//Copia la palabra "usuario" en la zona del perfil
        						break;
        						default:
        						puts("ERROR");
        					}
						break;
						
						case 5: puts("Escribe el nuevo nombre del usuario:");
						scanf("%s",&(*vUsuarios)[i].login);
						fflush(stdin);
						break;
						
						case 6: puts("Escribe la nueva contraseña:");
						scanf("%s",&(*vUsuarios)[i].pass);
						fflush(stdin);
						break;
						
						
						default: puts("Opcion incorrecta"); break;		
					}
					fflush(stdin);
					puts("Desea modificar algo mas?\nEscriba S si asi lo desea");
                    scanf("%c", &n);
                    fflush(stdin);
                }while (n == 'S' || n == 's'); // Si respondes "S" o "s" se repite el bucle
                system("pause"); //No va a la siguiente operación hasta que pulses una letra
				fflush(stdin);
				usuarios_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Vuelve al menu usuarios.
			}
			else	//Si eliges no modificar el usuario se cancela la operación
			{ 
				puts("Se ha cancelado la operacion");
				system("pause"); //No va a la siguiente operación hasta que pulses una letra
				fflush(stdin);
				usuarios_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Vuelve al menu usuarios
			}	
		}
	}
	if (aux == 0)	//Si la id que ha escrito no existe aux no cambia a 1 y entra en este if
	{ 
		puts("La ID seleccionada no existe\n¿Quiere seleccionar otra?");
        scanf("%c",&res);
        fflush(stdin);
        if(res == 's' || res == 'S') //Si responde "S" o "s" vuelve al principio de la función para poder seleccionar otra id
        {
        	modificarUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
		}   
		else // Si responde no u otra cosa vuelve al menu usuarios
		{
			usuarios_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
		}	
	}	
}

//Su llamada es anadirUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
///////////////////////////////////////////////////////////////////// AÑADIR USUARIOS /////////////////////////////////////////////////////////////////////////
//Cabecera: void anadirUsuarios(char *, usuario **, int *, vehiculo *, int *, viajes *, int *, pasos *, int *)
//Precondición: La estructura Usuario y el entero n deben estar inicializados
//Postcondición: Añade usuarios al archivo txt

void anadirUsuario(char *id, usuario **vUsuarios, int *nUsuarios, vehiculo *vVehiculos, int *nVehiculos, viajes *vViajes, int *nViajes, pasos *vPasos, int *nPasos)
{
	int p;
	char res = ' ';
	int suma = 0, cadena, n = 1;
	char str[5];
	setlocale( LC_ALL, "spanish"); //Para poder escribir y leer en español
	fflush(stdin);
	system("cls"); //Limpia la pantalla
	puts("-AÑADIR USUARIO-");
	(*vUsuarios) = realloc((usuario *)(*vUsuarios),((*nUsuarios)+1)*sizeof(usuario));		//Aumentamos la dimensión del vector para ampliar el espacio
	strcpy(str, (*vUsuarios)[*nUsuarios-1].id);									//Sirve para hacer que la id del usuario se ponga de forma automática y ordenada, sin
    cadena = atoi(str);															//necesidad que el usuario tenga que escribirla y evitar que haya mas de una id igual
    cadena += 1;
    sprintf((*vUsuarios)[*nUsuarios].id, "%04d", cadena);
	puts("Escriba el nombre del nuevo usuario:");
	gets((*vUsuarios)[*nUsuarios].nombre);	
	fflush(stdin);																	//Liberamos el buffer
	puts("Escriba la localidad del nuevo usuario:");
	gets((*vUsuarios)[*nUsuarios].localidad);										//Usamos gets para que copie una cadena con espacios
	system("cls"); //Limpia la pantalla																		
	puts("Elige el perfil del nuevo usuario:");
	puts("0.- Usuario");
	puts("1.- Admin");
	fflush(stdin);
    scanf("%d",&p);
    fflush(stdin);
	switch(p)
	{
        case 1: strcpy((*vUsuarios)[*nUsuarios].perfil,"administrador"); break;						//Copia la palabra "administrador" en la zona del perfil
        case 0: strcpy((*vUsuarios)[*nUsuarios].perfil,"usuario"); break;							//Copia la palabra "usuario" en la zona del perfil
    	default: puts("ERROR"); break;
    }
	puts("Escriba el apodo del nuevo usuario (5 carácteres):");
	scanf("%s",(*vUsuarios)[*nUsuarios].login);
	fflush(stdin);
	puts("Escriba la contraseña del nuevo usuario (8 carácteres):");
	scanf("%s",(*vUsuarios)[*nUsuarios].pass);
	fflush(stdin);
	(*nUsuarios)++;																//Aumentamos el numero total de usuarios
	system("pause"); //No va a la siguiente operación hasta que pulses una letra
	fflush(stdin);
	usuarios_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Vuelve al menu usuarios
}

//Su llamada es eliminarUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
///////////////////////////////////////////////////////////////////// ELIMINAR USUARIOS /////////////////////////////////////////////////////////////////////////
//Cabecera: void eliminarUsuario(char *, usuario **, int *, vehiculo *, int *, viajes *, int *, pasos *, int *)
//Precondición: La estructura Usuario y el entero n deben estar inicializados
//Postcondición: Elimina usuarios al archivo txt

void eliminarUsuario(char *id, usuario **vUsuarios, int *nUsuarios, vehiculo *vVehiculos, int *nVehiculos, viajes *vViajes, int *nViajes, pasos *vPasos, int *nPasos)
{
	char id_nuevo[4];												//Variable con la que vamos a buscar el id
	int i, j, aux=0;
	setlocale( LC_ALL, "spanish"); //Para poder escribir y leer en español
	char s,res;
	system("cls"); //Limpia la pantalla
	fflush(stdin);
	for(i=0;i<(*nUsuarios);i++)		//Con este bucle nos mostrara toda la informacion de cada usuario
	{							
		printf("%s-%s-%s-%s-%s-%s\n",(*vUsuarios)[i].id,(*vUsuarios)[i].nombre,(*vUsuarios)[i].localidad,(*vUsuarios)[i].perfil,(*vUsuarios)[i].login,(*vUsuarios)[i].pass);
	}
	puts("-ELIMINAR USUARIO-");
	puts("Introduzca el id que desea eliminar:"); 										
	scanf("%s",&id_nuevo); 									//Escribimos el id que estamos buscando dentro del fichero
	fflush(stdin);
	for(i=0;i<(*nUsuarios);i++)		//Hacemos un bucle que busque el id anterior en el fichero
	{								
		if(strcmp(id_nuevo,(*vUsuarios)[i].id)==0)	//Comparamos las cadenas (id) para encontrarlo
		{				
			aux=1; 												//aux pasa a ser 1 para confirmar que la id seleccionada existe
			printf("El usuario seleccionado es: %s-%s \nDesea eliminarlo? Escribe S si asi lo deseas\n",(*vUsuarios)[i].id,(*vUsuarios)[i].nombre);
			fflush(stdin);
			scanf("%c",&s);
			if(s=='S' || s=='s')		//En este bucle copiamos el contenido de la fila siguiente a la que 
			{							//vamos a borrar consiguiendo el numero total de usuarios							
				for(j = i; j + 1 < (*nUsuarios); j++)
				{
            		strcpy((*vUsuarios)[j].id,(*vUsuarios)[j+1].id);
            		strcpy((*vUsuarios)[j].nombre,(*vUsuarios)[j+1].nombre);
            		strcpy((*vUsuarios)[j].localidad,(*vUsuarios)[j+1].localidad);
            		strcpy((*vUsuarios)[j].perfil,(*vUsuarios)[j+1].perfil);
            		strcpy((*vUsuarios)[j].login,(*vUsuarios)[j+1].login);
            		strcpy((*vUsuarios)[j].pass,(*vUsuarios)[j+1].pass);
        		}
        	(*nUsuarios)--;										//Se elimina una fila del total de usuarios
       		*vUsuarios=realloc((usuario *)(*vUsuarios),(*nUsuarios)*sizeof(usuario));	//Cambiamos las dimensiones del vector 
       	 	puts("La eliminación se ha completado con éxito.");
       	 	system("pause"); //No va a la siguiente operación hasta que pulses una letra
       	 	fflush(stdin);
			usuarios_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
			}
			else	//Si eliges no eliminar el usuario se cancela la operación
			{ 
				puts("Eliminación del usuario cancelada.");
				system("pause"); //No va a la siguiente operación hasta que pulses una letra
				fflush(stdin);
				usuarios_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Vuelve al menu usuarios
			}	
		}	
	}
	if (aux == 0)	//Si la id que ha escrito no existe aux no cambia a 1 y entra en este if
	{ 
		puts("La ID seleccionada no existe\n¿Quiere seleccionar otra?");
        scanf("%c",&res);
        fflush(stdin);
        if(res == 's' || res == 'S') //Si responde "S" o "s" vuelve al principio de la función para poder seleccionar otra id
        {
        	eliminarUsuario(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); 
		}
		else // Si responde no u otra cosa vuelve al menu usuarios
		{
			usuarios_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
		}
	}
}

//Su llamada es anadirVehiculo(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
///////////////////////////////////////////AÑADIR VEHICULOS ADMIN//////////////////////////////////////////////
//Cabecera: void anadirVehiculoAdmin(char *, usuario *, int *, vehiculo **, int *, viajes *, int *, pasos *, int *)
//Precondición: La estructura vehiculo y el entero n deben estar inicializados
//Postcondición: Añade vehiculos al archivo txt

void anadirVehiculo(char *id, usuario *vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes *vViajes, int *nViajes, pasos *vPasos, int *nPasos)
{
	setlocale( LC_ALL, "spanish"); //Para poder escribir y leer en español
    char res = ' ';
	fflush(stdin);
	system("cls"); //Limpia la pantalla
    puts("AÑADIR VEHÍCULOS");
    do
	{
    	(*vVehiculos) = realloc((vehiculo *)(*vVehiculos),((*nVehiculos)+1)*sizeof(vehiculo)); //aumenta el vector vehiculos una posición
    	puts("Introduzca la matrícula de su vehículo:"); //Añade cada elemento de la estructura vehículos
    	fgets((*vVehiculos)[*nVehiculos].Id_mat,8,stdin); //Usamos fgets para asegurarnos que no escribe carácteres de más
    	fflush(stdin); //Liberamos el buffer
    	puts("Introduzca el id del usuario al que añadir matrícula (5 carácteres)");
    	fgets((*vVehiculos)[*nVehiculos].Id_usuario, 5, stdin);
    	fflush(stdin);
    	puts("Introduzca el número de plazas de su vehículo");
    	scanf("%i",&(*vVehiculos)[*nVehiculos].Num_plazas); //Al ser un entero se usa scanf
    	fflush(stdin);
    	puts("Introduzca el vehículo que tengas mas el color. Ejemplo: 'Peugeot 308 Azul'");
    	gets((*vVehiculos)[*nVehiculos].Desc_veh); //Usamos gets para cadenas largas
    	fflush(stdin);
    	puts("¿Desea anñdir otro vehículo? S/N");
    	scanf("%c",&res);
    	fflush(stdin);
		(*nVehiculos)++;
    }while(res =='s'|| res =='S'); //Si responde "S" o "s" se repite el bucle para seguir añadiendo vehículos
    system("pause"); //No va a la siguiente operación hasta que pulses una letra
    fflush(stdin);
    vehiculos_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Vuelve al menu vehículos
}

//Su llamada es listarVehiculo(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
////////////////////////////////////////////LISTAR VEHICULOS ADMIN//////////////////////////////////////////////
//Cabecera: void listarVehiculos(char *, usuario *, int *, vehiculo **, int *, viajes **, int *, pasos *, int * )
//Precondición: La estructura vehiculo, viajes, el entero nVehiculos y nViajes deben estar inicializados
//Postcondición: Lista los vehiculos del archivo txt

void listarVehiculo(char *id, usuario *vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes **vViajes, int *nViajes, pasos *vPasos, int *nPasos)
{
	setlocale( LC_ALL, "spanish"); //Para ajustar al idioma español
	int i, j;
    char matricula[8];
    system("cls"); //Limpia la pantalla
	puts("-LISTA DE VEHÍCULOS-");
	puts("MATRÍCULA-USUARIO-PLAZAS-DESCRIPCIÓN");	
	for(i=0;i<(*nVehiculos);i++)	//Con este bucle nos mostrara toda la informacion de cada vehículo
	{							
	 printf("%s-%s-%i-%s\n",(*vVehiculos)[i].Id_mat,(*vVehiculos)[i].Id_usuario, (*vVehiculos)[i].Num_plazas, (*vVehiculos)[i].Desc_veh);
	}
    fflush(stdin);
    puts("Elija un vehículo en concreto (por su matrícula) para listar todos los viajes realizados con ese vehículo"); 
    fgets(matricula, 8, stdin); //Usamos fgets para asegurarnos que no escribe carácteres de más
    fflush(stdin); //Liberamos el buffer
    for(j=0;j<(*nViajes);j++)
	{
        if(strcmp(matricula,(*vViajes)[j].Id_mat)==0) //compara la matricula añadida con la del ficheror para ver si existe y muestra los elementos de la matricula introducida
		{
            printf("%s-%s-%s-%s-%s-%i-%s-%i-%s\n",(*vViajes)[j].Id_viaje,(*vViajes)[j].Id_mat,(*vViajes)[j].F_inic,(*vViajes)[j].H_inic,(*vViajes)[j].H_fin,(*vViajes)[j].Plazas_libres,(*vViajes)[j].viaje, (*vViajes)[j].importe, (*vViajes)[j].Estado);
    	}
    }
    system("pause"); //No va a la siguiente operación hasta que pulses una letra
    fflush(stdin);
    vehiculos_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Vuelve al menu vehículos
}
// Su llamada es eliminarVehiculo(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
///////////////////////////////////////////////////////////////////// ELIMINAR USUARIOS /////////////////////////////////////////////////////////////////////////
//Cabecera: void eliminarVehiculo(char *, usuario *, int *, vehiculo **, int *, viajes *, int *, pasos *, int *)
//Precondición: La estructura Vehiculo y el entero nVehiculos deben estar inicializados
//Postcondición: Elimina vehiculos al archivo txt
void eliminarVehiculo(char *id, usuario *vUsuarios, int *nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes *vViajes, int *nViajes, pasos *vPasos, int *nPasos)
{
	setlocale( LC_ALL, "spanish"); //Para ajustar al idioma español
    char matricula[8];
    int i,j;
    char res =' ';
    char res2 = ' ';
    system("cls"); //Limpia la pantalla
    puts("MATRÍCULA-USUARIO-PLAZAS-DESCRIPCIÓN");	
	for(i=0;i<(*nVehiculos);i++)	//Con este bucle nos mostrara toda la informacion de cada vehículo
	{							
	 printf("%s-%s-%i-%s\n",(*vVehiculos)[i].Id_mat,(*vVehiculos)[i].Id_usuario, (*vVehiculos)[i].Num_plazas, (*vVehiculos)[i].Desc_veh);
	}
    do
	{
    puts("Escriba la matrícula del vehículo que desea eliminar");
    fflush(stdin);
    fgets(matricula,8,stdin); //Escribe la matricula que quiere eliminar
    fflush(stdin); //Liberamos el buffer
    for(i=0;i<(*nVehiculos);i++)
	{
        if(strcmp(matricula, (*vVehiculos)[i].Id_mat)==0)
		{
            printf("¿Desea eliminar este vehículo? %s-%s\n",(*vVehiculos)[i].Id_mat,(*vVehiculos)[i].Id_usuario);
            scanf("%c",&res2);
            fflush(stdin);
            if(res2 == 's' || res2 == 'S') //Si responde "S" o "s" entra en el bucle
			{ 
                for(j=i;j+1<(*nVehiculos);j++)	//este bucle recorre desde la posición del elemento a eliminar hasta la ultima linea en blanco del fichero
				{ 
                    strcpy((*vVehiculos)[j].Id_mat, (*vVehiculos)[j+1].Id_mat); //copia el valor de la linea siguiente en la linea actual
                    strcpy((*vVehiculos)[j].Id_usuario, (*vVehiculos)[j+1].Id_usuario);
                    (*vVehiculos)[j].Num_plazas = (*vVehiculos)[j+1].Num_plazas;
                    strcpy((*vVehiculos)[j].Desc_veh, (*vVehiculos)[j+1].Desc_veh);
				}
                (*nVehiculos)--; //Se elimina una fila del total de vehículos
                *vVehiculos=realloc((vehiculo *)(*vVehiculos),(*nVehiculos)*sizeof(vehiculo)); //se reajusta el valor del vector
            }
			else	//Si responde no u otra cosa se cancela la eliminación
			{ 
				puts("Eliminación del usuario cancelada");
				system("pause"); //No va a la siguiente operación hasta que pulses una letra
   				fflush(stdin);
    			vehiculos_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //vuelve al menu vehículos
			}

        }
    }
    puts("¿Desea eliminar otro vehículo?"); //Se le da la opción al usuario de volver a eliminar otro vehículo. Ó si lo ha seleccionado mal de escribir otro.
    scanf("%c", &res);
    fflush(stdin);
    }while(res == 's'|| res == 'S');// Si responde "S" o "s" vuelve a repetirse el bucle
    system("pause"); //No va a la siguiente operación hasta que pulses una letra
    fflush(stdin);
    vehiculos_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Una vez acabada la función vuelve al menu vehículos
}

// Su llamada es modificarVehiculo(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)	
///////////////////////////////////////////////////////////////////// ELIMINAR USUARIOS /////////////////////////////////////////////////////////////////////////
//Cabecera: void modificarVehiculo(char *, usuario *, int , vehiculo **, int *, viajes *, int , pasos *, int )
//PrecondiciÃ³n: La estructura Vehiculo y el entero nVehiculos deben estar inicializados
//PostcondiciÃ³n: modifica vehiculos al archivo txt
void modificarVehiculo(char *id, usuario *vUsuarios, int nUsuarios, vehiculo **vVehiculos, int *nVehiculos, viajes *vViajes, int nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish"); //Para poder escribir y leer en español
	char matricula[8];
	int i,aux=0;
	int op;
	char res = ' ', res2 = ' ';
	fflush(stdin); 
	system("cls"); //Limpia la pantalla
	for(i=0;i<(*nVehiculos);i++)	//Con este bucle nos mostrara toda la informacion de cada vehículo
	{						
	 printf("%s-%s-%i-%s\n",(*vVehiculos)[i].Id_mat,(*vVehiculos)[i].Id_usuario, (*vVehiculos)[i].Num_plazas, (*vVehiculos)[i].Desc_veh);
	}
	puts("Introduce la matrícula del vehículo que desea modificar");
	fgets(matricula,8,stdin); //Introduce una matricula para comparar
	fflush(stdin); //Liberamos el buffer
	for(i=0;i<*nVehiculos;i++)
	{
    	if(strcmp(matricula,(*vVehiculos)[i].Id_mat)==0) //Si se cumple que la matricula escrita está en el fichero entra en el if
		{
        	aux=1; //aux pasa a ser 1 para confirmar que la matricula seleccionada existe
        	do
			{
        		puts("¿Qué desea modificar?\n1-Matrícula\n2-Número de plazas\n3-Descripción del vehículo\n"); //Eliges que elemento de la estructura deseas modificar
        		scanf("%i",&op);
        		fflush(stdin);
        		switch (op)
        		{
        			case 1: puts("Escriba la nueva matrícula del vehículo");
            				fgets((*vVehiculos)[i].Id_mat,8,stdin);
            				fflush(stdin);
            				break;
        			case 2: puts("Escriba el nuevo número de plazas");
            				scanf("%d",&(*vVehiculos)[i].Num_plazas);
            				fflush(stdin);
            				break;
        			case 3: puts("Escriba la nueva descripción del coche");
            				gets((*vVehiculos)[i].Desc_veh);
            				fflush(stdin);
            				break;
        			default:puts("Opción incorrecta");
            				break;
        		}
        		puts("Quiere seguir modificando este vehículo?");
        		scanf("%c",&res);
        		fflush(stdin);
    		}while(res =='s' || res =='S'); //Si responde "S" o "s" se repite el bucle
    		system("pause"); //No va a la siguiente operación hasta que pulses una letra
    		fflush(stdin);
    		vehiculos_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Vuelve al menu vehículos
    	}  
    }
    if(aux==0) //Si la matricula que ha escrito no existe aux no cambia a 1 y entra en este if
	{
        puts("La matrícula seleccionada no existe\n¿Quiere seleccionar otra?");
        scanf("%c",&res2);
        fflush(stdin);
        if(res2 == 's' || res2 == 'S') //Si responde "S" o "s" vuelve al principio de la función para poder seleccionar otra matricula
        {
        	modificarVehiculo(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
		}
		else // Si responde no u otra cosa vuelve al menu vehículos
		{
			vehiculos_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
		}		   
    }
}

// Su llamada es listarViaje(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
////////////////////////////////////////////////////////////// LISTAR VIAJES /////////////////////////////////////////////////////////////////////
//Cabecera: void listarViajes(char *, usuario *, int , vehiculo *, int , viajes **, int *, pasos *, int )
//Precondición: La estructura Viajes y el entero n deben estar inicializados
//Postcondición: Lista todos los viajes del archivo txt
void listarViaje(char *id, usuario *vUsuarios, int nUsuarios, vehiculo *vVehiculos, int nVehiculos, viajes **vViajes, int *nViajes, pasos *vPasos, int nPasos)
{
	setlocale(LC_ALL, "spanish"); //Para ajustar el idioma al español
    setlocale(LC_ALL, "es_ES");
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252); // Para mayor facilidad hemos eliminado los euros del fichero txt pero lo imprimimos por pantalla
	int p,i;
	system("cls"); 		//Limpia la pantalla
    puts("-LISTAR VIAJES-");
	if((*nViajes) == 0)	//La estructura if muestra si el fichero esta vacío ya que no hay nada para buscar
	{														
        printf("No hay viajes.\n");
    }
	else
	{
        for(i=0;i<(*nViajes);i++)	//El bucle for busca en la linea en la que se encuentra el id que has seleccionado
		{											
			printf("%s-%s-%s-%s-%s-%i-%s-%.2f%c-%s\n", (*vViajes)[i].Id_viaje, (*vViajes)[i].Id_mat, (*vViajes)[i].F_inic, (*vViajes)[i].H_inic, (*vViajes)[i].H_fin, (*vViajes)[i].Plazas_libres, (*vViajes)[i].viaje, (*vViajes)[i].importe, 128, (*vViajes)[i].Estado );				//Muestra la matricula del alumno que has buscado 
		}
    }
    system("pause"); //No va a la siguiente operación hasta que pulses una letra
    fflush(stdin);
    viajes_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Vuelve al menú viajes
}


// Su llamada es modificarViaje(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
////////////////////////////////////////////////////////////// MODIFICAR VIAJES /////////////////////////////////////////////////////////////////////
//Cabecera: void modificarViaje(char *, usuario *, int , vehiculo *, int , viajes **, int *, pasos *, int )
//Precondición: La estructura Viajes y el entero n deben estar inicializados
//Postcondición: Modifica viajes en el archivo txt 
void modificarViaje(char *id, usuario *vUsuarios, int nUsuarios, vehiculo *vVehiculos, int nVehiculos, viajes **vViajes, int *nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish");		//Para ajustar el idioma al español
	char id_nuevo[4];								//Creamos una variable cadena para comparar con el id del fichero
	int i,e,opc,p,r;
	int aux = 0;
	char s,res;
	system("cls");		//Limpia la pantalla
	for(i=0;i<(*nViajes);i++)	//El bucle for busca en la linea en la que se encuentra el id que has seleccionado
	{												
		printf("%s-%s-%s-%s-%s-%i-%s-%.2f%c-%s\n", (*vViajes)[i].Id_viaje, (*vViajes)[i].Id_mat, (*vViajes)[i].F_inic, (*vViajes)[i].H_inic, (*vViajes)[i].H_fin, (*vViajes)[i].Plazas_libres, (*vViajes)[i].viaje, (*vViajes)[i].importe, 128, (*vViajes)[i].Estado );				//Muestra la matricula del alumno que has buscado 
	}
	puts("-MODIFICAR VIAJE-");
	puts("Introduzca el id que desea modificar:");
	scanf("%s",&id_nuevo);
	fflush(stdin);
	for(i=0;i<(*nViajes);i++)	//Recorremos todo el fichero
	{							
		if(strcmp(id_nuevo,(*vViajes)[i].Id_viaje)==0)	//Comparamos el id que hemos introducido con el del fichero 
		{	
			aux = 1;					//El valor de aux pasa a ser 1 para evitar que entre en el condicional de abajo y asi confirmar que la id introducida es correcta
			printf("El viaje seleccionado es: %s-%s \nDesea modificarlo?\nEscribe S si asi lo desea\n",(*vViajes)[i].Id_viaje,(*vViajes)[i].Id_mat);
			fflush(stdin);								//Liberamos el buffer
			scanf("%s",&s);
			if(s=='S' || s=='s')	//Si elegimos modificar el viaje se nos abrirá un menÃº para elegir quÃ© parte del viaje queremos cambiar
			{						
				system("cls");							//Limpia la pantalla
				puts("- OPCIONES -");
				puts("1. Modificar el id del viaje");
				puts("2. Modificar la matrícula del viaje");
				puts("3. Modificar la fecha");
				puts("4. Modificar la hora de inicio: ");
				puts("5. Modificar la hora de llegada:");
				puts("6. Modificar las plazas libres:");
				puts("7. Modificar el viaje:");
				puts("8. Modificar el importe:");
				puts("9. Modificar el estado del viaje:");
				scanf("%i",&opc);						
				switch(opc)
				{
					case 1: puts("Escribe el nuevo id del viaje:");				
					scanf("%s",&(*vViajes)[i].Id_viaje);
					break;
						
					case 2: puts("Escribe la nueva matrícula:");
					fflush(stdin);
					gets((*vViajes)[i].Id_mat);	//Elegimos gets para escribir cadenas más largas
					break;
						
					case 3: puts("Escribe la nueva fecha:");
					fflush(stdin);
					gets((*vViajes)[i].F_inic);	//Elegimos gets para escribir cadenas más largas
					break;
								
					case 4: puts("Escribe la nueva hora de inicio:");
					fflush(stdin);
					gets((*vViajes)[i].H_inic);	//Elegimos gets para escribir cadenas más largas
					break;					
						
					case 5: puts("Escribe la nueva hora de fin:");
					fflush(stdin);
					gets((*vViajes)[i].H_fin);	//Elegimos gets para escribir cadenas más largas
					break;
						
					case 6: puts("Escribe las nuevas plazas libres:");
					scanf("%i",&(*vViajes)[i].Plazas_libres);
					break;
						
					case 7: system("cls");
					puts("Escribe el tipo de viaje (Ida/Vuelta):");
					puts("0.- Ida");
					puts("1.- Vuelta");
					fflush(stdin);
        			scanf("%d",&p);
					switch(p)
					{
        				case 0:
        				strcpy((*vViajes)[i].viaje,"ida");	
        				break;
        				
						case 1:
        				strcpy((*vViajes)[i].viaje,"vuelta");		
        				break;
        				default: puts("ERROR"); break;
        			} break;
						
					case 8: puts("Escribe el nuevo importe:");
					scanf("%f",&(*vViajes)[i].importe);
					break;
						
					case 9: system("cls");				//Limpia la pantalla
					puts("Escribe el estado del viaje (Abierto/Cerrado/Iniciado/Finalizado/Anulado):");
					puts("0.- Abierto");
					puts("1.- Cerrado");
					puts("2.- Iniciado");
					puts("3.- Finalizado");
					puts("4.- Anulado");
					fflush(stdin);
        			scanf("%d",&r);
					switch(r)
					{
        				case 0: strcpy((*vViajes)[i].Estado,"abierto");	break;
        				case 1: strcpy((*vViajes)[i].Estado,"cerrado");	break;
        				case 2: strcpy((*vViajes)[i].Estado,"iniciado"); break;
        				case 3: strcpy((*vViajes)[i].Estado,"finalizado"); break;
        				case 4: strcpy((*vViajes)[i].Estado,"anulado");	break;
        				default: puts("ERROR"); break;
        			} break;
						
					default:puts("Opcion incorrecta"); 
					system("pause");		//No va a la siguiente operación hasta que pulses una letra
    				viajes_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
					break;
				}
				puts("Modificación realizada"); //Una vez realizada la modificación vuelves al menú viajes
    			system("pause");
    			fflush(stdin);
    			viajes_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
			}
			else	//Si eliges no modificar viajes se cancela la operación
			{ 
				puts("Se ha cancelado la operación");
				system("pause");		//No va a la siguiente operación hasta que pulses una letra
    			fflush(stdin);
    			viajes_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos); //Vuelve al menú viajes
    		}
		}
	}
	if (aux == 0)	//Si el usuario ha escrito mal la id aux no cambia de valor por lo que entraría en este condicional
	{ 
		puts("La ID seleccionada no existe\n¿Quiere seleccionar otra?");
        scanf("%c",&res);
        fflush(stdin);
        if(res == 's' || res == 'S') //Si responde "S" o "s" vuelve al principio de la función
        {
        	modificarViaje(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
		}
		else		//Si responde no u otra cosa vuelve al menú viajes
		{
			viajes_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
		}
	}
}

// Su llamada es eliminarViaje(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)
////////////////////////////////////////////////////////////// ELIMINAR VIAJES /////////////////////////////////////////////////////////////////////
//Cabecera: void eliminarViajes(char *, usuario *, int , vehiculo *, int , viajes **, int *, pasos *, int )
//Precondición: La estructura Viajes y el entero n deben estar inicializados
//Postcondición: Elimina viajes al archivo txt

void eliminarViaje(char *id, usuario *vUsuarios, int nUsuarios, vehiculo *vVehiculos, int nVehiculos, viajes **vViajes, int *nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish");				//Para ajustar el idioma al español
	char id_nuevo[4];												//Variable con la que vamos a buscar el id
	int i,e,aux=0;
	char s,res;
	system("cls");								//Limpia la pantalla
	for(i=0;i<(*nViajes);i++)	//El bucle for busca en la linea en la que se encuentra el id que has seleccionado
	{											
		printf("%s-%s-%s-%s-%s-%i-%s-%.2f%c-%s\n", (*vViajes)[i].Id_viaje, (*vViajes)[i].Id_mat, (*vViajes)[i].F_inic, (*vViajes)[i].H_inic, (*vViajes)[i].H_fin, (*vViajes)[i].Plazas_libres, (*vViajes)[i].viaje, (*vViajes)[i].importe, 128, (*vViajes)[i].Estado );				//Muestra la matricula del alumno que has buscado 

    }
	puts("-ELIMINAR VIAJE-");
	puts("Introduzca el id que desea eliminar:"); 										
	scanf("%s",&id_nuevo);									//Escribimos el id que estamos buscando dentro del fichero
	for(i=0;i<(*nViajes);i++)	//Hacemos un bucle que busque el id anterior en el fichero
	{							
		if(strcmp(id_nuevo,(*vViajes)[i].Id_viaje)==0)	//Comparamos las cadenas (id) para encontrarlo
		{			
			aux = 1;
			printf("El viaje seleccionado es: %s-%s \nDesea eliminarlo? Escribe S si asi lo deseas\n",(*vViajes)[i].Id_viaje,(*vViajes)[i].Id_mat);
			fflush(stdin);
			scanf("%c",&s);
			fflush(stdin);
			if(s=='S' || s=='s')//En este bucle copiamos el contenido de la fila siguiente a la que 
			{					//vamos a borrar consiguiendo el numero total de viajes					
																						
				for(i=0;i+1<(*nViajes);i++)
				{
                strcpy((*vViajes)[i].Id_viaje,(*vViajes)[i+1].Id_viaje);	//Elimina la cadena Id_mat
                strcpy((*vViajes)[i].Id_mat,(*vViajes)[i+1].Id_mat);		//Elimina la cadena Id_viaje
                strcpy((*vViajes)[i].F_inic,(*vViajes)[i+1].F_inic);
                strcpy((*vViajes)[i].H_inic,(*vViajes)[i+1].H_inic);
                strcpy((*vViajes)[i].H_fin,(*vViajes)[i+1].H_fin);
                (*vViajes)[i].Plazas_libres == (*vViajes)[i+1].Plazas_libres;
                strcpy((*vViajes)[i].viaje,(*vViajes)[i+1].viaje);
                (*vViajes)[i].importe == (*vViajes)[i+1].importe;
                strcpy((*vViajes)[i].Estado,(*vViajes)[i+1].Estado);
        		}
        	(*nViajes)--;																	//Disminuye las lineas de nViajes
        	*vViajes=realloc((viajes *)(*vViajes),(*nViajes)*sizeof(viajes));	//Disminuye el vector vViajes
        	puts("Viaje eliminado con éxito.");
        	system("pause");
    		fflush(stdin);
    		viajes_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
    		}
			else
			{
				puts("Eliminación del usuario cancelada");		//Si el usuario decide no eliminar ningún viaje por lo que vuelve al menú viajes
    			system("pause");		//No va a la siguiente operación hasta que pulses una letra
    			fflush(stdin);			//Libera el buffer
    			viajes_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
			}
		}	
	}
	if (aux == 0)	//Si el usuario ha escrito mal la id aux no cambia de valor por lo que entraría en este condicional
	{	
		puts("La ID seleccionada no existe\n¿Quiere seleccionar otra?");
        scanf("%c",&res);
        fflush(stdin);
        if(res == 's' || res == 'S')	//Si responde "S" o "s" vuelve al principio de la función
        {
        	eliminarViaje(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
		}
        else			//Si responde no u otra cosa vuelve al menú viajes
        {
        	viajes_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);
		}
	}
}

// Su llamada es anadirViaje(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos)	
////////////////////////////////////////////////////////////// AÑADIR VIAJES /////////////////////////////////////////////////////////////////////
//Cabecera: void anadirViajes(char *, usuario *, int , vehiculo *, int , viajes **, int *, pasos *, int )
//Precondición: La estructura Viajes y el entero n deben estar inicializados
//Postcondición: Añade viajes al archivo txt

void anadirViaje(char *id, usuario *vUsuarios, int nUsuarios, vehiculo *vVehiculos, int nVehiculos, viajes **vViajes, int *nViajes, pasos *vPasos, int nPasos)
{
	setlocale( LC_ALL, "spanish");			//Para ajustar el idioma al español
	int r,p, cadena, suma = 0;
	int n = 1;
	char str[7];
	FILE *f;
	system("cls");						//Limpia la pantalla
	puts("-ANADIR VIAJE-");
	fflush(stdin);
	*vViajes=realloc((viajes *)(*vViajes),((*nViajes)+1)*sizeof(viajes));		//Aumentamos la dimensión del vector para ampliar el espacio
	strcpy(str, (*vViajes)[*nViajes-1].Id_viaje);			//Sirve para hacer que la id del viaje se ponga de forma automática y ordenada, sin
    cadena = atoi(str);										//necesidad que el usuario tenga que escribirla y evitar que haya mas de una id igual
    cadena += 1;
    sprintf((*vViajes)[*nViajes].Id_viaje, "%06d", cadena);
	puts("Escribe la nueva matricula:");
	gets((*vViajes)[*nViajes].Id_mat);
	fflush(stdin);
	puts("Escribe la nueva fecha:");
	gets((*vViajes)[*nViajes].F_inic);				//Elegimos gets para escribir cadenas más largas
	fflush(stdin);
	puts("Escribe la nueva hora de inicio:");
	gets((*vViajes)[*nViajes].H_inic);					//Elegimos gets para escribir cadenas más largas
	fflush(stdin);
	puts("Escribe la nueva hora de fin:");
	gets((*vViajes)[*nViajes].H_fin);				//Elegimos gets para escribir cadenas más largas
	fflush(stdin);
	puts("Escribe las nuevas plazas libres:");
	scanf("%i",&(*vViajes)[*nViajes].Plazas_libres);
	fflush(stdin);
	system("cls");													//Para mayor facilidad, hemos decidido hacer un menu para evitar que el usuario escriba la cadena
	puts("Escribe el tipo de viaje (Ida/Vuelta):");
	puts("0.- Ida");
	puts("1.- Vuelta");
	fflush(stdin);
    scanf("%d",&p);
	switch(p)
	{
    	case 0: strcpy((*vViajes)[*nViajes].viaje,"ida"); break;
        case 1: strcpy((*vViajes)[*nViajes].viaje,"vuelta"); break;
        default: puts("ERROR"); break;
    }
	puts("Escribe el nuevo importe:");
	scanf("%f",&(*vViajes)[*nViajes].importe);
	fflush(stdin);
	system("cls");						//Limpia la pantalla	
	puts("Escribe el estado del viaje:");
	puts("0.- Abierto");
	puts("1.- Cerrado");
	puts("2.- Iniciado");
	puts("3.- Finalizado");
	puts("4.- Anulado");
	fflush(stdin);
    scanf("%d",&r);
	switch(r)
	{
        case 0: strcpy((*vViajes)[*nViajes].Estado,"abierto"); break;
        case 1: strcpy((*vViajes)[*nViajes].Estado,"cerrado"); break;
        case 2: strcpy((*vViajes)[*nViajes].Estado,"iniciado");	break;
        case 3: strcpy((*vViajes)[*nViajes].Estado,"finalizado"); break;
        case 4: strcpy((*vViajes)[*nViajes].Estado,"anulado"); break;
        default: puts("ERROR"); break;
    }
    (*nViajes)++;																		//Añade una linea al fichero
	puts("\nViaje anadido con éxito.");
	system("pause");									 //No va a la siguiente operación hasta que pulses una letra
    fflush(stdin);
    viajes_administrador(id,vUsuarios,nUsuarios,vVehiculos,nVehiculos,vViajes,nViajes,vPasos,nPasos);	//Vuelve al menú viajes
}
