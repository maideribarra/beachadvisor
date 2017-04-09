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
		printf("leo %i fila",i);
		fflush(stdout);
		char *str=(char *)malloc(sizeof(char)*300);
		clearIfNeeded(str,300);
		atr[i]=(char**)malloc(sizeof(char*)*cantAtr);
		str=fgets(str,300,f);

		leerFilaPlaya(str,array[i],cantAtr,atr[i],a);

		i++;

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
int * tamayoo(char * fila,int cantAtr){
	int * a=(int *)malloc(sizeof(int)*cantAtr);
	int t=0;
	int i=-1;
	int j=0;

	char c=fila[0];

	while(t<cantAtr){
		i++;
		if(c==','){
			a[t]=i;

			t++;
			i=-1;
		}

		j++;
		c=fila[j];




	}
	return a;
}

void separarFila(char * fila,int cantAtr,char ** atributos){


		int * a=tamayoo(fila,cantAtr);

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



				//printf("%i %s",j,*(atributos+j));
				//fflush(stdout);


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

				fflush(stdout);
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
	printf(" ");
	//printf("%i",(playa->codigo));
				//fflush(stdout);

	playa->nombrePlaya=atributos[1];
	//printf("%s",playa->nombrePlaya);
			//fflush(stdout);

	playa->loc=atributos[3];
	//printf("%s",playa->loc);
				//fflush(stdout);


	playa->pais=atributos[4];
	//printf("%s",playa->pais);
					//fflush(stdout);

	playa->provincia=atributos[5];
	//printf("%s",playa->provincia);
						//fflush(stdout);


	playa->mar=atributos[6];
	//printf("%s",playa->mar);
							//fflush(stdout);

	playa->arena=atributos[7];
	//printf("%s",playa->arena);
								//fflush(stdout);

	Coordenada  coor=ConvertirCoordenada(atributos[2]);

	(playa->coor).x=coor.x;
	(playa->coor).y=coor.y;
	printf("he leido la fila");
		fflush(stdout);




}
void clearIfNeeded(char *str, int max_line)
{
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}
//tiempo, radiación solar, bandera, oleaje, periodo, temperatura.
void pasarFicheroAarray(char *** array,FILE * f,int CantAtr,int sizef)
{
	int i=0;

	while(i<sizef){
		char *string=(char *)malloc(sizeof(char)*300);
		clearIfNeeded(string,300);
		string=fgets(string,300,f);
		//printf("i while pasararray %i",i);
		//fflush(stdout);
		array[i]=(char**)malloc(sizeof(char*)*CantAtr);
		separarFila(string,CantAtr,array[i]);
		i++;
	}

}
Playa * buscarPlaya(Playa ** pl,int size,int codigo)
{
	int i;
	for(i=0;i<size;i++){
		if((pl[i]->codigo)==codigo)
		{
			return pl[i];
		}
	}return NULL;
}
void inicializarPlayas(Playa ** pl,int sizepl,int numMax)
{
	int j;
	for(j=0;j<sizepl;j++){
		pl[j]->bandera.bandera=(char **)malloc(sizeof(char*)*numMax);
		pl[j]->oleaje.oleaje=(int **)malloc(sizeof(int *)*numMax);
		pl[j]->periodo.periodo=(int **)malloc(sizeof(int*)*numMax);
		pl[j]->radiacionSolar.radiacionSolar=(int **)malloc(sizeof(int *)*numMax);
		pl[j]->temperaturaMar.temperaturaMar=(int **)malloc(sizeof(int *)*numMax);
		pl[j]->tiempo.tiempo=(char **)malloc(sizeof(char *)*numMax);
		((pl[j]->bandera).cant)=0;
		((pl[j]->oleaje).cant)=0;
		((pl[j]->periodo).cant)=0;
		((pl[j]->radiacionSolar).cant)=0;
		((pl[j]->temperaturaMar).cant)=0;
		((pl[j]->tiempo).cant)=0;
	}
}
void liberarPlayas(Playa ** pl,int sizepl)
{
	int j;
		for(j=0;j<sizepl;j++){
			free(pl[j]->bandera.bandera);
			free(pl[j]->oleaje.oleaje);
			free(pl[j]->periodo.periodo);
			free(pl[j]->radiacionSolar.radiacionSolar);
			free(pl[j]->temperaturaMar.temperaturaMar);
			free(pl[j]->tiempo.tiempo);
		}
}
void meterDatosPlaya(Playa ** pl,char ***array,int CantAtr,int sizef,int sizepl,FILE * f)
{
	inicializarPlayas(pl,sizepl,10);

	pasarFicheroAarray(array,f,CantAtr,sizef);
	int i;
	for(i=0;i<sizef;i++){
		int codigo;
		sscanf(*(*(array+i)),"%i",&codigo);
		printf(" ");
		Playa * p=buscarPlaya(pl,sizepl,codigo);

		int j;
		for(j=0;j<CantAtr;j++){

			if(j==1){
				int h=((p->bandera).cant);

				*(((p->bandera).bandera)+h)=*(*(array+i)+j);

			}if(j==2){
				int h=((p->oleaje).cant);
				int ole;
				sscanf(*(*(array+i)+j),"%i",&ole);
				*(((p->oleaje).oleaje)+h)=ole;

			}if(j==3){
				int h=((p->periodo).cant);
				int per;
				sscanf(*(*(array+i)+j),"%i",&per);
				*(((p->periodo).periodo)+h)=per;
			}if(j==4){
				int h=((p->radiacionSolar).cant);
				int rad;
				sscanf(*(*(array+i)+j),"%i",&rad);
				*(((p->radiacionSolar).radiacionSolar)+h)=rad;
			}if(j==5){
				int h=((p->temperaturaMar).cant);
				int tem;
				sscanf(*(*(array+i)+j),"%i",&tem);
				*(((p->temperaturaMar).temperaturaMar)+h)=tem;
			}if(j==6){
				int h=((p->tiempo).cant);

				*(((p->tiempo).tiempo)+h)=*(*(array+i)+j);
			}else{

			}
		}

		((p->bandera).cant)++;
		((p->oleaje).cant)++;
		((p->periodo).cant)++;
		((p->radiacionSolar).cant)++;
		((p->temperaturaMar).cant)++;
		((p->tiempo).cant)++;
	}
}

void leerAcceso(FILE * f, Acceso ** array,int cantAtr,int fila,char *** atr,int * a)
{
	int i=0;

		while(i<fila){
			char *str=(char *)malloc(sizeof(char)*300);
			clearIfNeeded(str,300);
			atr[i]=(char**)malloc(sizeof(char*)*cantAtr);
			str=fgets(str,300,f);

			leerFilaAcceso(str,array[i],cantAtr,atr[i],a);

			i++;

	}
}
void leerFilaAcceso(char * fila, Acceso * playa,int cantAtr,char ** atributos,int * a)
{

	separarFila(fila,cantAtr,atributos);
	printf("he separado la fila");
	fflush(stdout);


	sscanf(atributos[0],"%i",&(playa->codigo));
	printf("%i",(playa->codigo));
				fflush(stdout);

	playa->transporte=atributos[1];
	printf("%s",playa->transporte);
			fflush(stdout);

	playa->horario=atributos[3];
	printf("%s",playa->horario);
				fflush(stdout);

	printf("he leido la fila");//debug
		fflush(stdout);

}
void inicializarAcceso(Acceso ** acceso,int sizeac,int numMax)
{
	int j;
		for(j=0;j<sizeac;j++){
			acceso[j]->codigo=(int **)malloc(sizeof(int*)*numMax);
			acceso[j]->transporte=(char **)malloc(sizeof(char *)*numMax);
			acceso[j]->horario=(char **)malloc(sizeof(char*)*numMax);
		}
	}
void liberarAcceso(Acceso ** acceso,int sizeac)
{
	int j;
		for(j=0;j<sizeac;j++){
			free(acceso[j]->codigo);
			free(acceso[j]->transporte);
			free(acceso[j]->horario);
		}
	}
Acceso * buscarAcceso(Acceso ** acceso,int size,int codigo)
{
	int i;
		for(i=0;i<size;i++){
			if((acceso[i]->codigo)==codigo)
			{
				return acceso[i];
			}
		}return NULL;
	}

//No se como acceder al array y al fichero a la vez para modificar los datos dentro de ellos
void meterDatosAcceso(Acceso ** acceso,char ***array,int CantAtr,int sizef,int sizeac,FILE * f)
{

	}
