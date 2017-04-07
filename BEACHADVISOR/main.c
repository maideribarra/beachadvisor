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
	imprimirArray(playas,num);

	fclose(h);
	//imprimirArray(playas,1);
	free(opciones);
	free(posicionMenu);
	for(j=0;j<num;j++){
			free(playas[j]);
		}
	free(playas);
	liberarAtributos(atr,8,num);


}

