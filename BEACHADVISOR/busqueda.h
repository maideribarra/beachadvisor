/*
 * busqueda.h
 *
 *  Created on: 31 de mar. de 2017
 *      Author: usuario
 */

#include "fichero.h"
#ifndef BUSQUEDA_H_
#define BUSQUEDA_H_
void imprimirArray(Playa ** arr,int tam);
int estaEn(int *op,int size,int num);
void impchar(char ** ch,int size);
void impint(int * entero,int size);
void ponerValorRepetido(Playa ** playas,int size);
float mediaaa(int * val,int size);
char * repetidooo(char ** valores,int size);
int cadenaIgual(char * c1,char *c2);

#endif /* BUSQUEDA_H_ */
