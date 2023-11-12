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


//DECLARACIÓN DE FUNCIONES
void agregarNuevo( struct peliculas catalogo [], int contador);
void imprimirPeliculas (struct peliculas catalogo [], int contador);
void imprimirActores(struct peliculas catalogo [], int contador);




main(){
	setlocale(LC_CTYPE, "Spanish");

	char resp;
	int opcion;
	int contador=0;
	
	
	do{
		printf("\n\t\t\t*** MENÚ ***");
		printf("\t\n1. Añadir nueva pelicula");
		printf("\t\n2. Añadir nuevo actor a una película");
		printf("\t\n3. Mostrar catálogo de películas");
		printf("\t\n4. Mostrar todos los actores");
		printf("\t\n5. Salir ");
		printf("\t\n\n Digite la operación que desea realizar: ");
		scanf("%d", &opcion);
	
	
		switch(opcion){
			case 1:
			    fflush(stdin);
				printf("\nIntroduce la clave de la película: ");
				gets(catalogo[contador].clave_pelicula);
				fflush(stdin);
				printf("Introduce el Título de la película: ");
				gets(catalogo[contador].titulo);
				fflush(stdin);
				printf("Introduce el País: ");
				gets(catalogo[contador].pais);
				fflush(stdin);
				printf("Introduce el año de estreno: ");
				scanf("%d", &catalogo[contador].anio_estreno);
				fflush(stdin);
				printf("Introduce la duración de la película: ");
				gets(catalogo[contador].duracion);
				fflush(stdin);
				printf("Introduce el género: ");
				gets(catalogo[contador].genero);
				fflush(stdin);
				printf("Introduce el número de actores: ");
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
				printf("La opción es incorrecta");	
		}
	
		printf("\n\n¿Desea seleccionar otra opción? ('S' para si, 'N' para no): \n");
		scanf("%s",&resp);
	
	}while(resp!='N'&& resp !='n');
}



//DEFINICIÓN DE FUNCIONES

void agregarNuevo( struct peliculas catalogo [], int contador){
	char clave[6];
	char clave_pelicula [30];
	int i=0, num=0, extra=0, total=0;
	bool bandera= false;
	printf("\nInserte la clave de la película que desea buscar: ");
	fflush(stdin);
	gets(clave);
	
	while(bandera==false && num<contador){
		if(strcmp(catalogo[num].clave_pelicula,clave)==0){
			bandera=true;
			printf("\n\nPELÍCULA ENCONTRADA EN LA BASE DE DATOS");
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
				printf("\nERROR: Sólo puedes ingresar un máximo de 5 actores");
			}
		}
		num++;
	}
	if(bandera==false){
		printf("ERROR: La película no se encuentra registrada ");
	}
}


void imprimirPeliculas (struct peliculas catalogo [], int contador){
	printf("\n\n");
	printf("\t\t\t CATÁLOGO DE PELÍCULAS\n");
	int i=0;
	for(i=0;i<contador;i++){
		printf("\n\nClave de la Película: %s", catalogo[i].clave_pelicula);
		printf("\nTítulo de la Película: %s", catalogo[i].titulo);
		printf("\nPaís: %s", catalogo[i].pais);
		printf("\nAño de estreno: %d", catalogo[i].anio_estreno);
		printf("\nDuración: %s", catalogo[i].duracion);
		printf("\nGénero: %s", catalogo[i].genero);
		printf("\nNúmero de actores: %d", catalogo[i].numero_actores);
		
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
	
	





