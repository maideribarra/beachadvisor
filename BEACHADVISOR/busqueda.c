/*
 * busqueda.c
 *
 *  Created on: 31 de mar. de 2017
 *      Author: usuario
 */
#include "fichero.h"
void imprimirArray(Playa ** arr,int tam)
{
	printf("entro imprimir array");
	fflush(stdout);
	int i;
	for(i=0;i<tam;i++){
		printf("Nombre playa: %s\nCodigo playa: %i\nLocalizacion playa: %s\nProvincia playa: %s\nPais playa: %s\nCoordenada: (%i,%i)\n",arr[i]->nombrePlaya,arr[i]->codigo,arr[i]->loc,arr[i]->provincia,arr[i]->pais,arr[i]->coor.x,arr[i]->coor.y);
		printf("Tiempo:\n");
		char ** tiem=(arr[i]->tiempo).tiempo;
		int n=((*(arr+i))->tiempo).cant;
		impchar(tiem,n);
		printf("Bandera:\n");
		impchar(((*(arr+i))->bandera).bandera,((*(arr+i))->bandera).cant);
		printf("Periodo Oleaje:\n");
		impint(((*(arr+i))->periodo).periodo,((*(arr+i))->periodo).cant);
		printf("Oleaje:\n");
		impint(((*(arr+i))->oleaje).oleaje,((*(arr+i))->oleaje).cant);
		printf("Temperatura del mar:\n");
		impint(((*(arr+i))->temperaturaMar).temperaturaMar,((*(arr+i))->temperaturaMar).cant);
		printf("Radiacion solar:\n");
		impint(((*(arr+i))->radiacionSolar).radiacionSolar,((*(arr+i))->radiacionSolar).cant);
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
void impchar(char ** ch,int size)
{
	printf("entro imprimir char %i",size);
	fflush(stdout);
	int i;
	for(i=0;i<(size);i++){
		printf("%s,",ch[i]);
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
}
void impint(int * entero,int size)
{
	printf("entro imprimir int %i",size);
		fflush(stdout);
	int i;
	for(i=0;i<(size);i++){
		printf("%i,",(entero[i]));
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
}

