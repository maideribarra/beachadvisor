/*
 * busqueda.c
 *
 *  Created on: 31 de mar. de 2017
 *      Author: usuario
 */
#include "fichero.h"
void imprimirArray(Playa ** arr,int tam)
{
	int i;
	for(i=0;i<tam;i++){
		printf("Nombre playa: %s\nCodigo playa: %i\nLocalizacion playa: %s\nProvincia playa: %s\nPais playa: %s\nCoordenada: (%i,%i)\n",arr[i]->nombrePlaya,arr[i]->codigo,arr[i]->loc,arr[i]->provincia,arr[i]->pais,arr[i]->coor.x,arr[i]->coor.y);
		printf("---------------------------------------------------------\n");
		fflush(stdout);
	}
}
int estaEn(int *op,int size,int num)
{
	int numero=1;
	int i;
	for(i=0;i<size;i++){
		if(num==op[i]){
			return numero;
		}
	}numero=0;
	return numero;
}

