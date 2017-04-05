/*
 * busqueda.c
 *
 *  Created on: 31 de mar. de 2017
 *      Author: usuario
 */
#include "fichero.h"
void imprimirArray(Playa * arr,int tam)
{
	int i;
	for(i=0;i<tam;i++){
		printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",arr[i].arena,arr[i].bandera,arr[i].codigo,arr[i].coor,arr[i].loc,arr[i].mar,arr[i].nombrePlaya,arr[i].oleaje,arr[i].pais,arr[i].periodo,arr[i].provincia,arr[i].radiacionSolar,arr[i].temperatura,arr[i].tiempo);
	}

}

