/*
 * main.c
 *
 *  Created on: 27 de mar. de 2017
 *      Author: usuario
 */
#include<stdlib.h>
#include<stdio.h>
#include"menu.h"
void main(void){
	int * posicionMenu=(int*)malloc(sizeof(int)*4);
	int *opciones=(int *)malloc(sizeof(int)*5);
	int i=0;
	int *c;
	c=&i;
	*c=0;
	int num=0;
	printf("\t\tBEACH ADVISOR\n\n");
	printf("°°°°°°°°°°°°|\ \n°°°°°°°°°°°°|_\ \n°°°°°°°°°°°°|__\ \n°°°°°°°°°°°°|___\ \n°°°°°°°°°°°°|____\°°°°°°\n°°°°°°°°°°°°|_____\°°°°°°\n°°°°°°°°°°°°|______\°°°°°°\n°°°°°°______|_______________\n~~~~\____________________/~~~~\n,.-~*´¨¯¨`*•~-.¸,.-~*´¨¯¨`*•~-.¸,.-~*´¨¯¨`*•~-.¸,.-~*´¨¯¨`*•~-.¸,.-~*\n´¨¯¨`*•~-.¸,.-~*´¨¯¨`*•~-.¸,.-~*´¨¯¨`*•~-.¸,.-~*´ `*•~-.¸,.-~*´`*•~-.¸,.-~*´•~-.¸,.-~*´¨¯¨`*•)\n\n\n\n");

	menuPrincipal(c,opciones,posicionMenu);

	free(opciones);
	free(posicionMenu);
	free(c);

}

