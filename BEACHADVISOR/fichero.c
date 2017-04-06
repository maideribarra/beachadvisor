/*
 * fichero.c
 *
 *  Created on: 29 de mar. de 2017
 *      Author: usuario
 */
// Codigo ,Nombre de la playa, coord GPS, localidad, país, provincia, nombre del mar, tipo de arena, tiempo, radiación solar, bandera, oleaje, periodo, temperatura
//Codigo ,Nombre de la playa, coord GPS, localidad, país, provincia, nombre del mar, tipo de arena, tiempo, radiación solar, bandera, oleaje, periodo, temperatura
#include "fichero.h"

void leerPlaya(FILE * f,Playa ** array,int cantAtr,int fila)//array de punteros a playas
{
	printf("entro leer playa");
	fflush(stdout);
	char *str=(char *)malloc(sizeof(char)*300);
	int i=0;
	printf("entro en el while");
	fflush(stdout);
	//while((str=fgets(str,300,f))!=NULL){
	while(i<fila){
		str=fgets(str,300,f);
		printf("%i",i);
		fflush(stdout);
		printf("%s imprimo filas\n",str);
		fflush(stdout);
		leerFilaPlaya(str,array[i],cantAtr);

		i++;
	}
	free(str);


}

int contarFilas(FILE * f)
{
	int c=0;
	int num;
	while((num=getc(f))!=EOF){
		if(num=='\n'){
			c=c+1;
		}

		}
	return c;
}

char ** separarFila(char * fila,int cantAtr){
	printf("entro separarFila");
	fflush(stdout);
	char ** atributos=(char**)malloc(sizeof(char*)*cantAtr);

		int p=0;
			int j;
			for(j=0;j<cantAtr;j++){
				int c=0;
				int z=0;
				char * nombre=(char *)malloc(sizeof(char)*20);
				//clearIfNeeded(nombre,20);

				while(z!=','){
					z=fila[p];
					if(z!=','){
					*(nombre+c)=fila[p];
					c++;
					}


					p++;

				}
				printf("nombre %s",nombre);
				fflush(stdout);
				atributos[j]=nombre;

			}
			free(fila);
			return atributos;
}
void liberarAtributos(char ** atributos,int cantAtr)
{
	int i;
	for(i=0;i<cantAtr;i++){
		int j;
		free(atributos[i]);
	}
	free(atributos);
}
Coordenada  ConvertirCoordenada(char * str)
{
	printf("entro1");
	fflush(stdout);
	Coordenada  c;
	printf("entro3");
	fflush(stdout);

	int i;
	char x[4];
	char y[4];
	for(i=0;i<4;i++){
		x[i]=str[i];

	}
	int j;
	for(j=5;j<9;j++){
		int n;
		n=j-5;
		y[n]=str[j];
		printf("%c %i",y[n],j);
		fflush(stdout);



	}
	printf("%syy",y);
	fflush(stdout);

	sscanf(x,"%i",&(c.x));
	sscanf(y,"%i",&(c.y));

	return c;
}
void leerFilaPlaya(char * fila,Playa * playa,int cantAtr)
{
	printf("entro leer fila playa");
	fflush(stdout);
	char ** atributos=separarFila(fila,cantAtr);
	printf("sigo leer fila playa");
	fflush(stdout);
	// Codigo ,Nombre de la playa, coord GPS, localidad, país, provincia, nombre del mar, tipo de arena.
	//En el fichero actividad se guardaran: Código de la playa, nombre de la actividad, tipo de actividad.

	sscanf(atributos[0],"%i",&(playa->codigo));
	printf("%i\n",playa->codigo);
	fflush(stdout);
	printf("%s",atributos[1]);
	fflush(stdout);
	sscanf(atributos[1],"%s",(playa->nombrePlaya));
	printf("%s\n",(playa->nombrePlaya));
	fflush(stdout);
	sscanf(atributos[3],"%s",(playa->loc));
	printf("%s\n",(playa->loc));
	fflush(stdout);
	sscanf(atributos[4],"%s",(playa->pais));
	printf("%s\n",(playa->pais));
	fflush(stdout);
	sscanf(atributos[5],"%s",(playa->provincia));
	printf("%s\n",(playa->provincia));
	fflush(stdout);
	sscanf(atributos[6],"%s",(playa->mar));
	printf("%s\n",(playa->mar));
	fflush(stdout);
	sscanf(atributos[7],"%s",(playa->arena));
	printf("%s\n",(playa->arena));

	Coordenada  coor=ConvertirCoordenada(atributos[2]);
	printf("%s",atributos[2]);
	fflush(stdout);
	(playa->coor).x=coor.x;
	(playa->coor).y=coor.y;
	printf("%ix",coor.x);
	fflush(stdout);
	printf("%iy",coor.y);
	fflush(stdout);
	printf("%s3",atributos[3]);
	fflush(stdout);


	fflush(stdout);
	liberarAtributos(atributos,cantAtr);

}
