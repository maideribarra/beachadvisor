/*
 * fichero.c
 *
 *  Created on: 29 de mar. de 2017
 *      Author: usuario
 */

#include "fichero.h"

void leerPlaya(FILE * f,Playa ** array,int cantAtr,int fila,char *** atr,int * a)//array de punteros a playas
{



	int i=0;

	while(i<fila){
		char *str=(char *)malloc(sizeof(char)*300);
		printf("FILA %i",i);
			fflush(stdout);

		clearIfNeeded(str,300);
		atr[i]=(char**)malloc(sizeof(char*)*cantAtr);
		str=fgets(str,300,f);

		leerFilaPlaya(str,array[i],cantAtr,atr[i],a);

		i++;
		printf("%i",i);
		fflush(stdout);

	}



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
int * tamayoo(char * fila){
	int * a=(int *)malloc(sizeof(int)*8);
	int t=0;
	int i=-1;
	int j=0;
	char c=fila[0];
	while(t<8){
		i++;
		if(c==','){
			a[t]=i;
			printf("%i",a[t]);
			fflush(stdout);
			t++;
			i=-1;
		}

		j++;
		c=fila[j];



	}
	return a;
}

void separarFila(char * fila,int cantAtr,char ** atributos){


		int * a=tamayoo(fila);

		int p=0;
			int j;

			for(j=0;j<cantAtr;j++){
				int num=0;
				int c=0;
				char z;
				z=fila[p];
				int tam=a[j];

				atributos[j]=(char *)malloc(sizeof(char)*tam);




				while(z!=',' && num<tam){


					*(*(atributos+j)+c)=fila[p];


					c++;
					p++;
					z=fila[p];
					//printf("%c",z);
					//fflush(stdout);
					//printf("p %i c %i j %i",p,c,j);
					//fflush(stdout);
					num++;





				}

				p++;



				printf("%i %s",j,*(atributos+j));
				fflush(stdout);


			}

			free(a);
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

	Coordenada  c;

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




	}


	sscanf(x,"%i",&(c.x));
	sscanf(y,"%i",&(c.y));

	return c;
}
void leerFilaPlaya(char * fila,Playa * playa,int cantAtr,char ** atributos,int * a)
{

	separarFila(fila,cantAtr,atributos);
	printf("he separado la fila");
	fflush(stdout);


	sscanf(atributos[0],"%i",&(playa->codigo));

	playa->nombrePlaya=atributos[1];

	playa->loc=atributos[3];
	printf("%s",playa->loc);
			fflush(stdout);

	playa->pais=atributos[4];

	playa->provincia=atributos[5];

	playa->mar=atributos[6];

	playa->arena=atributos[7];

	Coordenada  coor=ConvertirCoordenada(atributos[2]);

	(playa->coor).x=coor.x;
	(playa->coor).y=coor.y;
	printf("%i",(playa->coor).x);
		fflush(stdout);
		printf("%i",(playa->coor).y);
				fflush(stdout);





}
void clearIfNeeded(char *str, int max_line)
{
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}
