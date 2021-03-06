/*
 * fichero.c
 *
 *  Created on: 29 de mar. de 2017
 *      Author: usuario
 */

#include "fichero.h"

void leerPlaya(FILE * f,Playa ** array,int cantAtr,int fila,char *** atr,int * a)//lee el fichero playas y mete los datos en el array de playas
{



	int i=0;

	while(i<fila){
		//printf("leo %i fila",i);
		//fflush(stdout);
		char *str=(char *)malloc(sizeof(char)*300);
		clearIfNeeded(str,300);
		atr[i]=(char**)malloc(sizeof(char*)*cantAtr);
		str=fgets(str,300,f);

		leerFilaPlaya(str,array[i],cantAtr,atr[i],a);

		i++;

	}



}

int contarFilas(FILE * f)//cuenta cuantas filas tiene el fichero
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
int * tamayoo(char * fila,int cantAtr){//devuelve una array de enteros con el tama�o de cada palabra del fichero separado por comas.
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

void separarFila(char * fila,int cantAtr,char ** atributos){//guarda los datos de una fila del fichero en un array de string,cada campo separado por comas en un indice del array


		int * a=tamayoo(fila,cantAtr);

		int p=0;
			int j;

			for(j=0;j<cantAtr;j++){
				int num=0;
				int c=0;
				char z;
				z=fila[p];
				int tam=a[j];
				//printf("%i",tam);
				//fflush(stdout);

				atributos[j]=(char *)malloc(sizeof(char)*tam+1);
				//clearIfNeeded(atributos[j],tam);



				while(z!=',' && num<tam){


					*(*(atributos+j)+c)=fila[p];


					c++;
					p++;
					z=fila[p];
					//printf("%c",*(*(atributos+j)+c));
					//fflush(stdout);
					//printf("p %i c %i j %i",p,c,j);
					//fflush(stdout);
					num++;





				}
				*(*(atributos+j)+c)='\0';
				p++;



				//printf("%i %s",j,*(atributos+j));
				//fflush(stdout);


			}

			free(a);
			free(fila);

}
void liberarAtributos(char *** atributos,int cantAtr,int fila)//libera el array atributos que contiene los campos del fichero, en cada indice del array se guardan los campos de una linea del fichero
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
Coordenada  ConvertirCoordenada(char * str)//convierte el string que corresponde a la coordenada del fichero en un punto.
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
void leerFilaPlaya(char * fila,Playa * playa,int cantAtr,char ** atributos,int * a)//guarda los campos de una fila del fichero en la playa (el array esta compuesto de punteros a las playas).
{

	separarFila(fila,cantAtr,atributos);
	//printf("he separado la fila");
	//fflush(stdout);


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
	//printf("he leido la fila");
		//fflush(stdout);




}
void clearIfNeeded(char *str, int max_line)
{
	// Limpia los caracteres de m�s introducidos
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}

void pasarFicheroAarray(char *** array,FILE * f,int CantAtr,int sizef)//pasa los campos del fichero a un array de 3 dimensiones.
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
Playa * buscarPlaya(Playa ** pl,int size,int codigo)//busca la playa con ese codigo
{
	int i;
	for(i=0;i<size;i++){
		if((pl[i]->codigo)==codigo)
		{
			return pl[i];
		}
	}return NULL;
}
void inicializarPlayas(Playa ** pl,int sizepl,int numMax)//inicializa los valores de la estructura playa
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
void liberarPlayas(Playa ** pl,int sizepl)//libera los arrays que hay dentro de las estructuras que estan dentro de cada playa
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
void meterDatosPlaya(Playa ** pl,char ***array,int CantAtr,int sizef,int sizepl,FILE * f)//mete los datos del fichero datos playas en las plays teniendo en cuenta el codigo
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
void leerFilaAcceso(char * fila, Acceso * acceso,int cantAtr,char ** atributos,int * a)
{

	separarFila(fila,cantAtr,atributos);
	printf("he separado la fila");
	fflush(stdout);


	sscanf(atributos[0],"%i",&(acceso->codigo));
	printf("%i",(acceso->codigo));
				fflush(stdout);

	acceso->transporte=atributos[1];
	printf("%s",acceso->transporte);
			fflush(stdout);

	acceso->horario=atributos[3];
	printf("%s",acceso->horario);
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

void mostrarAcceso(FILE * access, Acceso *ac){
	char aux;
	char cadena[50];
	int x,y;

	//Lectura y colocaci�n de lo leido en la estructura
	for(x = 0 ; !feof(access) ; x++)
	{
		aux='0';
		for(y = 0 ; aux != ',' ; y++)
		{
			aux = fgetc(access);
			if(aux != ',')
			{
				cadena[y] = aux;
			}
		}
		copiarString(cadena, x, ac, access);
		fgets(cadena, 50, access);
		ac[x].codigo=atoi(cadena);
		printf("Codigo: %i, Transporte: %c, Horario: %c\n", ac[x].codigo, ac[x].transporte, ac[x].horario);
	}
}
void copiarString(char cadena[], int x, Acceso * ac, FILE * access)
{
	//Contamos cu�ntos caracteres hay dentro de la cadena de caracteres
	int N = strlen(cadena) + 1;
	//reservo memoria
	ac[x].codigo = (char*)malloc(N*sizeof(char));//codigo es int y lo que tenemos es una cadena de char's

	strcpy(ac[x].codigo, access);// El error tiene que ver con los punteros

	}


void leerActividad(FILE * fa, Actividad ** arraya, int atract, int filaa, char *** atra, int * b){

	int n=0;

	while(n<filaa){
		char * stract=(char *)malloc(sizeof(char)*200);
		atra[n]=(char **)malloc(sizeof(char*)*atract);
		stract=fgets(stract, 200, fa);

		leerFilaActividad(stract, arraya[n],atract, atra[n], b);
		n++;

	}
}


void leerFilaActividad(char * filaa, Actividad * actividad, int atract, char ** atributosA, int * b){

	separarFila(filaa, atract, atributosA);

	//printf("he separado la fila");
	//fflush(stdout);

	sscanf(atributosA[0], "%i", &(actividad->nombre));
	//printf("%i", (actividad->nombre));
	//fflush(stdout);

	actividad->tipo=atributosA[1];
	//printf("%s", actividad->tipo);
	//fflush(stdout);

	actividad->nombre=atributosA[2];
	//printf("%s", actividad->nombre);
	//fflush(stdout);

}


Actividad * buscarActividad(Actividad ** ac,int size,int codigoA, char *nombre)
{
	int i;
	for(i=0;i<size;i++){
		if((ac[i]->nombre)==nombre)
		{
			return ac[i];
		}
	}return NULL;
}

