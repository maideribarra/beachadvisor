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
		printf("\t Tiempo mas repetido %s ",((*(arr+i))->tiempo).tiempo);
				fflush(stdout);
		printf("Bandera:\n");
		impchar(((*(arr+i))->bandera).bandera,((*(arr+i))->bandera).cant);
		printf("\t Bandera mas repetida en esta playa %s\n",((*(arr+i))->bandera).banderaRepetida);
		fflush(stdout);
		printf("Periodo Oleaje:\n");
		impint(((*(arr+i))->periodo).periodo,((*(arr+i))->periodo).cant);
		printf("\t Periodo oleaje medio %f\n",((*(arr+i))->periodo).media);
		fflush(stdout);
		printf("Oleaje:\n");
		impint(((*(arr+i))->oleaje).oleaje,((*(arr+i))->oleaje).cant);
		printf("\t oleaje medio %f\n",((*(arr+i))->periodo).media);
		fflush(stdout);
		printf("Temperatura del mar:\n");
		impint(((*(arr+i))->temperaturaMar).temperaturaMar,((*(arr+i))->temperaturaMar).cant);
		printf("\t Temperatura media del agua: %f\n",((*(arr+i))->temperaturaMar).media);
		fflush(stdout);
		printf("Radiacion solar:\n");
		impint(((*(arr+i))->radiacionSolar).radiacionSolar,((*(arr+i))->radiacionSolar).cant);
		printf("\t Radiacion media: %f \n",((*(arr+i))->radiacionSolar).media);
		fflush(stdout);
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
int cadenaIgual(char * c1,char *c2)
{
	int i;
	for(i=0;i<3;i++){
		if(c1[i]!=c2[i]){
			return 0;
		}
	}return 1;
}
float mediaaa(int * val,int size)
{
	int c=0;
	int i;
	for(i=0;i<size;i++){
		c=c+val[i];
	}
	float media=(float)c/(float)size;

	return media;
}
char * repetidooo(char ** valores,int size)
{
	int * repeticiones=(int *)malloc(sizeof(int)*size);
	int h;
	for(h=0;h<size;h++){
		repeticiones[h]=0;
	}
	int i;
	for(i=0;i<size;i++){
		int j;
		for(j=i;j<size;j++){
			int g=cadenaIgual(valores[i],valores[j]);
			if(g==1){
				repeticiones[i]++;
				repeticiones[j]++;
			}
		}
	}
	int g;
	int k=repeticiones[0];
	int p=0;
	for(g=1;g<size;g++){
		if(repeticiones[g]>k){
			k=repeticiones[g];
			p=g;
		}
	}
	free(repeticiones);
	return valores[p];
}
void ponerValorRepetido(Playa ** playas,int size)
{
	int i;
	for(i=0;i<size;i++){
		Playa * p=playas[i];
		float temp=mediaaa((p->temperaturaMar).temperaturaMar,(p->temperaturaMar).cant);
		printf("%f",temp);
		fflush(stdout);
		(p->temperaturaMar).media=temp;
		float rad=mediaaa((p->radiacionSolar).radiacionSolar,(p->radiacionSolar).cant);
		(p->radiacionSolar).media=rad;
		float oleaje=mediaaa((p->oleaje).oleaje,(p->oleaje).cant);
		(p->oleaje).media=oleaje;
		float periodo=mediaaa((p->periodo).periodo,(p->periodo).cant);
		(p->periodo).media=periodo;

		char * bandera=repetidooo((p->bandera).bandera,(p->bandera).cant);
		(p->bandera).banderaRepetida=bandera;
		char * tiempo=repetidooo((p->tiempo).tiempo,(p->tiempo).cant);
		(p->tiempo).tiempoRepetido=tiempo;



	}
}




