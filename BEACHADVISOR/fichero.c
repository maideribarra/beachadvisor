/*
 * fichero.c
 *
 *  Created on: 29 de mar. de 2017
 *      Author: usuario
 */
// Codigo ,Nombre de la playa, coord GPS, localidad, país, provincia, nombre del mar, tipo de arena, tiempo, radiación solar, bandera, oleaje, periodo, temperatura
//Codigo ,Nombre de la playa, coord GPS, localidad, país, provincia, nombre del mar, tipo de arena, tiempo, radiación solar, bandera, oleaje, periodo, temperatura
#include "fichero.h"

void leerPlaya(FILE * f,Playa * array,int cantAtr)
{
	printf("entro");
	fflush(stdout);
	char *str;
	str=(char *)malloc(sizeof(char)*300);
	while((str=fgets(str,300,f))!=NULL){
		//leerFila(str,array,cantAtr);
		printf("%s\n",str);
		fflush(stdout);





	}
	free(str);


}
int NoAcaba(char * str)
{
	int i;
	char * acabar="ACABO";
	for(i=0;i<5;i++){
		if(str[i]!=acabar[i]){
			return 0;
		}
	}
	return 1;

}
void leerFila(char * fila,Playa * array,int cantAtr)
{

	int i;
	int p;
	for(i=0;i<strlen(fila);i++){
		int j;
		for(j=0;j<cantAtr;j++){
			int c=0;
			int z=0;
			char * nombre=(char *)malloc(sizeof(char)*20);
			while(c!=44){
				*(nombre+c)=fila[p];
				c++;
				p++;

			}
			p++;
			if(j==0){
				array[j].arena=nombre;
			}if(j==1){
				array[j].bandera=nombre;
			}if(j==2){
				array[j].codigo=nombre;
			}if(j==3){
				array[j].coor=nombre;
			}if(j==4){
				array[j].loc=nombre;
			}if(j==5){
				array[j].mar=nombre;
			}if(j==6){
				array[j].nombrePlaya=nombre;
			}if(j==7){
				array[j].oleaje=nombre;
			}if(j==8){
				array[j].pais=nombre;
			}if(j==9){
				array[j].periodo=nombre;
			}if(j==10){
				array[j].provincia=nombre;
			}if(j==11){
				array[j].radiacionSolar=nombre;
			}if(j==12){
				array[j].temperatura=nombre;
			}if(j==13){
				array[j].tiempo=nombre;
			}
			j++;
		}
		i++;
	}

}
