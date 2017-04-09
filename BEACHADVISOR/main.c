/*
 * main.c
 *
 *  Created on: 27 de mar. de 2017
 *      Author: usuario
 */
#include<stdlib.h>
#include<stdio.h>
#include"menu.h"
#include "fichero.h"
#include "busqueda.h"

Acceso * ac;
void main(void){
	int * posicionMenu=(int*)malloc(sizeof(int)*4);
	int *opciones=(int *)malloc(sizeof(int)*5);
	int i=0;
	int *c;
	c=&i;
	*c=0;

	printf("\t\tBEACH ADVISOR\n\n");
	printf("°°°°°°°°°°°°|\ \n°°°°°°°°°°°°|_\ \n°°°°°°°°°°°°|__\ \n°°°°°°°°°°°°|___\ \n°°°°°°°°°°°°|____\°°°°°°\n°°°°°°°°°°°°|_____\°°°°°°\n°°°°°°°°°°°°|______\°°°°°°\n°°°°°°______|_______________\n~~~~\____________________/~~~~\n,.-~*´¨¯¨`*•~-.¸,.-~*´¨¯¨`*•~-.¸,.-~*´¨¯¨`*•~-.¸,.-~*´¨¯¨`*•~-.¸,.-~*\n´¨¯¨`*•~-.¸,.-~*´¨¯¨`*•~-.¸,.-~*´¨¯¨`*•~-.¸,.-~*´ `*•~-.¸,.-~*´`*•~-.¸,.-~*´•~-.¸,.-~*´¨¯¨`*•)\n\n\n\n");

	menuPrincipal(c,opciones,posicionMenu);
	FILE *f;
	f=fopen("playa.txt","r");
	int num=contarFilas(f);
	Playa ** playas=(Playa **)malloc(sizeof(Playa *)*num);
	int j;
	for(j=0;j<num;j++){
		playas[j]=(Playa *)malloc(sizeof(Playa));
	}
	fclose(f);
	FILE *h;
	h=fopen("playa.txt","r");
	char *** atr=(char ***)malloc(sizeof(char**)*num);
	printf("leer playa");
	fflush(stdout);
	int * a;
	leerPlaya(h,playas,8,num,atr,a);
	printf("\nempiezo datos playa");

	fclose(h);





	FILE * g=fopen("datosPlaya.txt","r");
	int num2=contarFilas(g);
	char *** datosplaya=(char ***)malloc(sizeof(char**)*num2);
	fclose(g);
	FILE * g2=fopen("datosPlaya.txt","r");
	meterDatosPlaya(playas,datosplaya,7,num2,num,g2);
	printf("salgo");
	fflush(stdout);
	fclose(g2);
	imprimirArray(playas,num);
	//imprimirArray(playas,1);
	free(opciones);
	free(posicionMenu);
	printf("salgo1");
		fflush(stdout);
	liberarPlayas(playas,num);
	printf("salgo2");
		fflush(stdout);
	for(j=0;j<num;j++){
			free(playas[j]);
		}
	printf("salgo3");
		fflush(stdout);
	free(playas);
	printf("salgo4");
		fflush(stdout);
		printf("%i",num);
		fflush(stdout);
		liberarAtributos(datosplaya,7,num2);
			printf("salgo6");
				fflush(stdout);
	liberarAtributos(atr,8,num);
	printf("salgo5");
		fflush(stdout);

		//Lectura del Fichero de modo de acceso

			FILE *access;
			access=fopen("acceso.txt","r");
			if(a==NULL)
			{
				printf("No se ha podido abrir el fichero\n");
				fflush(stdout);
				exit(1);
			}
			int filasAc=contarFilas(access);
				//Una vez tenemos el número de filas del fichero, colocamos el cursor al inicio del fichero
				rewind(access);
				//reservamos memoria para el fichero
				ac=(Acceso*)malloc(filasAc*sizeof(Acceso));
				mostrarAcceso(access, ac);
				liberarAcceso(access, filasAc);//No se cual es el error
}



