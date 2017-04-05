/*
 * fichero.h
 *
 *  Created on: 29 de mar. de 2017
 *      Author: usuario
 */

#ifndef FICHERO_H_
#define FICHERO_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char  codigo;
	char * nombrePlaya;
	char  coor;
	char * loc;
	char * pais;
	char * provincia;
	char * mar;
	char * arena;
	char * tiempo;
	char * radiacionSolar;
	char * bandera;
	char * oleaje;
	char * periodo;
	char temperatura;
}Playa;
void leerPlaya(FILE * f,Playa * array,int cantAtr);
int NoAcaba(char * str);
void leerFila(char * fila,Playa * array,int cantAtr);



#endif /* FICHERO_H_ */
