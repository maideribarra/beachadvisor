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
	printf("같같같같같같|\ \n같같같같같같|_\ \n같같같같같같|__\ \n같같같같같같|___\ \n같같같같같같|____\같같같\n같같같같같같|_____\같같같\n같같같같같같|______\같같같\n같같같______|_______________\n~~~~\____________________/~~~~\n,.-~*뇽��`*�~-.�,.-~*뇽��`*�~-.�,.-~*뇽��`*�~-.�,.-~*뇽��`*�~-.�,.-~*\n뇽��`*�~-.�,.-~*뇽��`*�~-.�,.-~*뇽��`*�~-.�,.-~*� `*�~-.�,.-~*�`*�~-.�,.-~*킉~-.�,.-~*뇽��`*�)\n\n\n\n");

	menuPrincipal(c,opciones,posicionMenu);
	printf("\nEmpiezo con el fichero\n");
	fflush(stdout);




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
	leerPlaya(h,playas,8,num,atr);
	printf("he salido");
	fflush(stdout);
	fclose(f);
	//imprimirArray(playas,1);
	free(opciones);
	free(posicionMenu);
	for(j=0;j<num;j++){
			free(playas[j]);
		}
	free(playas);
	liberarAtributos(atr,8,num);


}

