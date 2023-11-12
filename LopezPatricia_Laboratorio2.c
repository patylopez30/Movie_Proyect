#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

//ESTRUCTURAS
struct fecha{
	int dia;
	int mes;
	int anio;
};

struct actores{
	char nombre [25];
	char apellido[25];
	char nacionalidad [20];
	struct fecha fechaNacimiento;
};

struct peliculas{
	char clave_pelicula[30];
	char titulo[30];
	char pais[20];
	int anio_estreno; 
	char duracion[20];
	char genero[20];
	int numero_actores;
	struct actores infoActores[6];
};

struct peliculas catalogo[12];


//DECLARACI�N DE FUNCIONES
void agregarNuevo( struct peliculas catalogo [], int contador);
void imprimirPeliculas (struct peliculas catalogo [], int contador);
void imprimirActores(struct peliculas catalogo [], int contador);




main(){
	setlocale(LC_CTYPE, "Spanish");

	char resp;
	int opcion;
	int contador=0;
	
	
	do{
		printf("\n\t\t\t*** MEN� ***");
		printf("\t\n1. A�adir nueva pelicula");
		printf("\t\n2. A�adir nuevo actor a una pel�cula");
		printf("\t\n3. Mostrar cat�logo de pel�culas");
		printf("\t\n4. Mostrar todos los actores");
		printf("\t\n5. Salir ");
		printf("\t\n\n Digite la operaci�n que desea realizar: ");
		scanf("%d", &opcion);
	
	
		switch(opcion){
			case 1:
			    fflush(stdin);
				printf("\nIntroduce la clave de la pel�cula: ");
				gets(catalogo[contador].clave_pelicula);
				fflush(stdin);
				printf("Introduce el T�tulo de la pel�cula: ");
				gets(catalogo[contador].titulo);
				fflush(stdin);
				printf("Introduce el Pa�s: ");
				gets(catalogo[contador].pais);
				fflush(stdin);
				printf("Introduce el a�o de estreno: ");
				scanf("%d", &catalogo[contador].anio_estreno);
				fflush(stdin);
				printf("Introduce la duraci�n de la pel�cula: ");
				gets(catalogo[contador].duracion);
				fflush(stdin);
				printf("Introduce el g�nero: ");
				gets(catalogo[contador].genero);
				fflush(stdin);
				printf("Introduce el n�mero de actores: ");
				scanf("%d", &catalogo[contador].numero_actores);
				fflush(stdin);
				
				
				printf("\nACTORES:");
				int i=0;
				for(i=0; i<catalogo[contador].numero_actores;i++){
					fflush(stdin);
					printf("\n\nIntroduce el nombre:");
					gets(catalogo[contador].infoActores[i].nombre);
					fflush(stdin);
					
					printf("Introduce el apellido: ");
					gets(catalogo[contador].infoActores[i].apellido);
					fflush(stdin);
					
					printf("Introduce la nacionalidad: ");
					gets(catalogo[contador].infoActores[i].nacionalidad);
					fflush(stdin);
					
					printf("Introduce la fecha de nacimiento ");
					printf("\nDia: ");
					scanf("%d", &catalogo[contador].infoActores[i].fechaNacimiento.dia);
					fflush(stdin);
					printf("Mes: ");
					scanf("%d", &catalogo[contador].infoActores[i].fechaNacimiento.mes);
					fflush(stdin);
					printf("Anio: ");
					scanf("%d", &catalogo[contador].infoActores[i].fechaNacimiento.anio);
					fflush(stdin);
				}
				
				contador ++;	
			break;
			
			
			case 2:
				agregarNuevo(catalogo, contador);
				
			break;
			
		
			case 3: 
				imprimirPeliculas (catalogo, contador);
			break;
			
			case 4: 
				imprimirActores(catalogo, contador);
			break;
			
			case 5:
				exit(1);
			break;
			
			default:
				printf("La opci�n es incorrecta");	
		}
	
		printf("\n\n�Desea seleccionar otra opci�n? ('S' para si, 'N' para no): \n");
		scanf("%s",&resp);
	
	}while(resp!='N'&& resp !='n');
}



//DEFINICI�N DE FUNCIONES

void agregarNuevo( struct peliculas catalogo [], int contador){
	char clave[6];
	char clave_pelicula [30];
	int i=0, num=0, extra=0, total=0;
	bool bandera= false;
	printf("\nInserte la clave de la pel�cula que desea buscar: ");
	fflush(stdin);
	gets(clave);
	
	while(bandera==false && num<contador){
		if(strcmp(catalogo[num].clave_pelicula,clave)==0){
			bandera=true;
			printf("\n\nPEL�CULA ENCONTRADA EN LA BASE DE DATOS");
			printf("\n\nIngrese a cantidad adicional de actores/actrices que desea agregar:");
			scanf("%d",&extra);
			
			total= catalogo[num].numero_actores + extra;
			int j=0, maximo=5;
			if (total < maximo){
				
				int j;
				for(j=catalogo[num].numero_actores; j < total ; j++){
					fflush(stdin);
					printf("\n\nIntroduce el nombre:");
					gets(catalogo[num].infoActores[j].nombre);
					fflush(stdin);
					
					printf("Introduce el apellido: ");
					gets(catalogo[num].infoActores[j].apellido);
					fflush(stdin);
					
					printf("Introduce la nacionalidad: ");
					gets(catalogo[num].infoActores[j].nacionalidad);
					fflush(stdin);
					
					printf("Introduce la fecha de nacimiento ");
					printf("\nDia: ");
					scanf("%d", &catalogo[num].infoActores[j].fechaNacimiento.dia);
					fflush(stdin);
					printf("Mes: ");
					scanf("%d", &catalogo[num].infoActores[j].fechaNacimiento.mes);
					fflush(stdin);
					printf("Anio: ");
					scanf("%d", &catalogo[num].infoActores[j].fechaNacimiento.anio);
					fflush(stdin);
				}
				catalogo[num].numero_actores++;
			}else{
				printf("\nERROR: S�lo puedes ingresar un m�ximo de 5 actores");
			}
		}
		num++;
	}
	if(bandera==false){
		printf("ERROR: La pel�cula no se encuentra registrada ");
	}
}


void imprimirPeliculas (struct peliculas catalogo [], int contador){
	printf("\n\n");
	printf("\t\t\t CAT�LOGO DE PEL�CULAS\n");
	int i=0;
	for(i=0;i<contador;i++){
		printf("\n\nClave de la Pel�cula: %s", catalogo[i].clave_pelicula);
		printf("\nT�tulo de la Pel�cula: %s", catalogo[i].titulo);
		printf("\nPa�s: %s", catalogo[i].pais);
		printf("\nA�o de estreno: %d", catalogo[i].anio_estreno);
		printf("\nDuraci�n: %s", catalogo[i].duracion);
		printf("\nG�nero: %s", catalogo[i].genero);
		printf("\nN�mero de actores: %d", catalogo[i].numero_actores);
		
		int j=0;
		printf("\nACTORES:");
		for(j=0; j<catalogo[i].numero_actores;j++){
		printf("\n%s %s", catalogo[i].infoActores[j].nombre, catalogo[i].infoActores[j].apellido);
		}
	}
}


void imprimirActores(struct peliculas catalogo [], int contador){
	printf("\n\n");
	printf("\t\t\t DATOS ACTORES Y ACTRICES");
	int i=0;
	for(i=0; i<contador; i++){
		int j=0;
		for(j=0; j<catalogo[i].numero_actores;j++){
		printf("\n\n %s %s", catalogo[i].infoActores[j].nombre, catalogo[i].infoActores[j].apellido);
		printf("\nNacionalidad: %s", catalogo[i].infoActores[j].nacionalidad);
		printf("\nFecha de Nacimiento: %d del %d de %d", catalogo[i].infoActores[j].fechaNacimiento.dia, catalogo[i].infoActores[j].fechaNacimiento.mes, catalogo[i].infoActores[j].fechaNacimiento.anio);
		}
	}	
}
	
	





