/*
 * menu.c
 *
 *  Created on: 27 de mar. de 2017
 *      Author: usuario
 */
#include<stdlib.h>
#include<stdio.h>
#include "string.h"
void pedirPorTeclado(char * pregunta,int * variable){
	char str[3];
	clearIfNeeded(str,3);
	printf("%s",pregunta);
	fflush(stdout);
	fgets(str,3,stdin);
	printf("%i string\n",str[0]);
	printf("%i string\n",str[1]);
	printf("%i string\n",str[2]);
	sscanf(str,"%i",variable);
}
void clearIfNeeded(char *str, int max_line)
{
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}
