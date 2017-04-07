/*
 * fichero.c
 *
 *  Created on: 29 de mar. de 2017
 *      Author: usuario
 */
// Codigo ,Nombre de la playa, coord GPS, localidad, país, provincia, nombre del mar, tipo de arena, tiempo, radiación solar, bandera, oleaje, periodo, temperatura
//Codigo ,Nombre de la playa, coord GPS, localidad, país, provincia, nombre del mar, tipo de arena, tiempo, radiación solar, bandera, oleaje, periodo, temperatura
#include "fichero.h"

void leerPlaya(FILE * f,Playa ** array,int cantAtr,int fila,char *** atr)//array de punteros a playas
{
	printf("entro leer playa");
	fflush(stdout);
	char *str=(char *)malloc(sizeof(char)*300);

	int i=0;
	printf("entro en el while");
	fflush(stdout);
	//si no lo hago asi en la segunda vuelta me da erroor
	//while((str=fgets(str,300,f))!=NULL){
	while(i<fila){

		clearIfNeeded(str,300);
		atr[i]=(char**)malloc(sizeof(char*)*cantAtr);
		str=fgets(str,300,f);

		printf("%s imprimo filas\n",str);//hata aqi bien
		fflush(stdout);
		leerFilaPlaya(str,array[i],cantAtr,atr[i]);

		i++;
		printf("\n%i",i);
		fflush(stdout);
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
	return c+1;
}

void separarFila(char * fila,int cantAtr,char ** atributos){
	printf("entro separarFila");
	fflush(stdout);
	//atributos=(char**)malloc(sizeof(char*)*cantAtr);//da error en la segunda vuelta
	printf("entro separarFila1\n");
	printf("%s\n",fila);
	fflush(stdout);

		int p=0;
			int j;
			int num=0;
			for(j=0;j<cantAtr;j++){
				int c=0;
				int z=fila[p];
				atributos[j]=(char *)malloc(sizeof(char)*20);
				//clearIfNeeded(nombre,20);
				printf("imprimo");
				fflush(stdout);
				while(z!=',' && num<7){
					*(*(atributos+j)+c)=fila[p];
					c++;
					p++;
					z=fila[p];
					printf("%c ",fila[p]);
					fflush(stdout);



				}
				num++;
				p++;
				//printf("nombre %s",atributos[j]);
				//fflush(stdout);



			}
			free(fila);

}
void liberarAtributos(char *** atributos,int cantAtr,int fila)
{
	int i;
	for(i=0;i<fila;i++){

		int j;
		for(j=0;j<cantAtr;j++){
			free(atributos[i][j]);
		}
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
	clearIfNeeded(x,4);
	clearIfNeeded(y,4);
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


	sscanf(x,"%i",&(c.x));
	sscanf(y,"%i",&(c.y));

	return c;
}
void leerFilaPlaya(char * fila,Playa * playa,int cantAtr,char ** atributos)
{
	printf("entro leer fila playa");
	fflush(stdout);
	separarFila(fila,cantAtr,atributos);
	printf("sigo leer fila playa");
	fflush(stdout);
	// Codigo ,Nombre de la playa, coord GPS, localidad, país, provincia, nombre del mar, tipo de arena.
	//En el fichero actividad se guardaran: Código de la playa, nombre de la actividad, tipo de actividad.

	sscanf(atributos[0],"%i",&(playa->codigo));
	printf("%i\n",playa->codigo);
	fflush(stdout);
	printf("%s",atributos[1]);
	fflush(stdout);
	//sscanf(atributos[1],"%s",(playa->nombrePlaya));
	playa->nombrePlaya=atributos[1];
	printf("%s\n",(playa->nombrePlaya));
	fflush(stdout);
	playa->loc=atributos[3];
	//sscanf(atributos[3],"%s",(playa->loc));
	printf("%s\n",(playa->loc));
	fflush(stdout);
	playa->pais=atributos[4];
	//sscanf(atributos[4],"%s",(playa->pais));
	printf("%s\n",(playa->pais));
	fflush(stdout);
	playa->provincia=atributos[5];
	//sscanf(atributos[5],"%s",(playa->provincia));
	printf("%s\n",(playa->provincia));
	fflush(stdout);
	playa->mar=atributos[6];
	//sscanf(atributos[6],"%s",(playa->mar));
	printf("%s\n",(playa->mar));

	fflush(stdout);
	//sscanf(atributos[7],"%s",(playa->arena));
	playa->arena=atributos[7];
	printf("%s\n",(playa->arena));

	Coordenada  coor=ConvertirCoordenada(atributos[2]);
	printf("%s",atributos[2]);
	fflush(stdout);
	(playa->coor).x=coor.x;
	(playa->coor).y=coor.y;
	printf("%ix",(playa->coor).x);
	fflush(stdout);
	printf("%iy",(playa->coor).y);
	fflush(stdout);




}
void clearIfNeeded(char *str, int max_line)
{
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}
