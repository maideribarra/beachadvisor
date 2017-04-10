/*
 * busqueda.c
 *
 *  Created on: 31 de mar. de 2017
 *      Author: usuario
 */
#include "fichero.h"
void imprimirArray(Playa ** arr,int tam)//imprime los datos de las playas
{
	//printf("entro imprimir array");
	//fflush(stdout);
	int i;
	for(i=0;i<tam;i++){
		printf("Nombre playa: %s\nCodigo playa: %i\nLocalizacion playa: %s\nProvincia playa: %s\nPais playa: %s\nCoordenada: (%i,%i)\n",arr[i]->nombrePlaya,arr[i]->codigo,arr[i]->loc,arr[i]->provincia,arr[i]->pais,arr[i]->coor.x,arr[i]->coor.y);
		printf("Compatibilidad de la playa: %i\n",(*(arr+i))->disponibilidad);
		printf("Tiempo:\n");
		char ** tiem=(arr[i]->tiempo).tiempo;
		int n=((*(arr+i))->tiempo).cant;
		impchar(tiem,n);
		printf("\t Tiempo mas repetido %s \n ",((*(arr+i))->tiempo).tiempoRepetido);
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
		printf("\t oleaje medio %f\n",((*(arr+i))->oleaje).media);
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
int estaEn(int *op,int size,int num)//devuelve 0 si el numero ya esta en el array de opcines(si el usuario ya ha elegido esta opcion)
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
void impchar(char ** ch,int size)//imprime el array de char
{
	//printf("entro imprimir char %i",size);
	//fflush(stdout);
	int i;
	for(i=0;i<(size);i++){
		printf("%s,",ch[i]);
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
}
void impint(int * entero,int size)//imprime el array de int
{
	//printf("entro imprimir int %i",size);
		//fflush(stdout);
	int i;
	for(i=0;i<(size);i++){
		printf("%i,",(entero[i]));
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
}
int cadenaIgual(char * c1,char *c2)//devuelve 1 si las 3 primeras letras de una palabra son iguales y 0 si no lo son.
{
	int i;
	for(i=0;i<3;i++){
		if(c1[i]!=c2[i]){
			return 0;
		}
	}return 1;
}
float mediaaa(int * val,int size)//devuelve la media de un array de enteros
{
	int c=0;
	int i;
	for(i=0;i<size;i++){
		c=c+val[i];
	}
	float media=(float)c/(float)size;

	return media;
}
char * repetidooo(char ** valores,int size)//devuelve el valor mas repetido de un array de char
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
void ponerValorRepetido(Playa ** playas,int size){//mete dentro de las estructuras de playa los valores mas repetidos o la media.{
	int i;
	for(i=0;i<size;i++){
		Playa * p=playas[i];
		float temp=mediaaa((p->temperaturaMar).temperaturaMar,(p->temperaturaMar).cant);
		//printf("%f",temp);
		//fflush(stdout);
		(p->temperaturaMar).media=temp;
		float rad=mediaaa((p->radiacionSolar).radiacionSolar,(p->radiacionSolar).cant);
		(p->radiacionSolar).media=rad;
		float oleaje=mediaaa((p->oleaje).oleaje,(p->oleaje).cant);
		(p->oleaje).media=oleaje;
		float periodo=mediaaa((p->periodo).periodo,(p->periodo).cant);
		(p->periodo).media=periodo;

		char * tiempo=repetidooo((p->tiempo).tiempo,(p->tiempo).cant);
		(p->tiempo).tiempoRepetido=tiempo;
		char * bandera=repetidooo((p->bandera).bandera,(p->bandera).cant);
		(p->bandera).banderaRepetida=bandera;




	}
}

//Las estructuras grupo son un conjunto de playas que cumplen una caracteristica,sirven para despues modificar la compatibilidad de estas playas segun la busqueda del usuario

GrupoTiempo crearGrupoTiempo(char * tiempo,Playa ** array,int size)//crea el grupo tiempo que se compone de un array de string,el string mas repetido y el tamaño del array
{

	int c=0;
	int i;
	for(i=0;i<size;i++){
		int l=cadenaIgual(((array[i])->tiempo).tiempoRepetido,tiempo);
		if(l==1){
			c++;
		}
	}
	Playa ** grupo=(Playa **)malloc(sizeof(Playa*)*c);
	int num=0;
	for(i=0;i<size;i++){
			int l=cadenaIgual(((array[i])->tiempo).tiempoRepetido,tiempo);
			if(l==1){
				grupo[num]=(array[i]);
				num++;
			}
		}
	GrupoTiempo gt;
	gt.tiempo=tiempo;
	gt.playas=grupo;
	gt.size=num;
	return gt;
}

GrupoBandera crearGrupoBandera(char * bandera,Playa ** array,int size)//crea el grupo bandera que se compone de un array de string,el string mas repetido y el tamaño del array
{
	int c=0;
		int i;
		for(i=0;i<size;i++){
			int l=cadenaIgual(((array[i])->bandera).banderaRepetida,bandera);
			if(l==1){
				c++;
			}
		}
		Playa ** grupo=(Playa **)malloc(sizeof(Playa*)*c);
		int num=0;
		for(i=0;i<size;i++){
				int l=cadenaIgual(((array[i])->bandera).banderaRepetida,bandera);
				if(l==1){
					grupo[num]=(array[i]);
					num++;
				}
			}
		GrupoBandera gb;
		gb.Bandera=bandera;
		gb.playas=grupo;
		gb.size=num;
		return gb;

}

GrupoArena crearGrupoArena(char * arena,Playa ** array,int size)//crea el grupo arena que se compone de un array de string,el string mas repetido y el tamaño del array
{
	int c=0;
		int i;
		for(i=0;i<size;i++){
			int l=cadenaIgual(((array[i])->arena),arena);
			if(l==1){
				c++;
			}
		}
		Playa ** grupo=(Playa **)malloc(sizeof(Playa*)*c);
		int num=0;
		for(i=0;i<size;i++){
				int l=cadenaIgual(((array[i])->arena),arena);
				if(l==1){
					grupo[num]=(array[i]);
					num++;
				}
			}
		GrupoArena ga;
		ga.arena=arena;
		ga.playas=grupo;
		ga.size=num;
		return ga;

}

GrupoOleaje crearGrupoOleaje(int min,int max,Playa ** array,int size)//crea el grupo oleaje que se compone de un array, el tamaño del array y la media
{
	int c=0;
			int i;
			for(i=0;i<size;i++){
				if((array[i]->oleaje).media>min && (array[i]->oleaje).media<=max ){
					c++;
				}
			}
			Playa ** grupo=(Playa **)malloc(sizeof(Playa*)*c);
			int num=0;
			for(i=0;i<size;i++){
				if((array[i]->oleaje).media>=min && (array[i]->oleaje).media<=max ){

						grupo[num]=(array[i]);
						num++;

				}
			}
			GrupoOleaje go;
			go.max=max;
			go.min=min;
			go.playas=grupo;
			go.size=num;
			return go;

}

GrupoPeriodoOleaje crearPeriodoOleaje(int min,int max,Playa ** array,int size)//crea el grupo periodo oleaje que se compone de un array, el tamaño del array y la media y el intervalo de valores
{
	int c=0;
	int i;
	for(i=0;i<size;i++){
		if((array[i]->periodo).media>min && (array[i]->periodo).media<=max ){
			c++;
		}
	}
	Playa ** grupo=(Playa **)malloc(sizeof(Playa*)*c);
	int num=0;
	for(i=0;i<size;i++){
		if((array[i]->periodo).media>min && (array[i]->periodo).media<=max ){

			grupo[num]=(array[i]);
			num++;

		}
	}
	GrupoPeriodoOleaje gpo;
	gpo.max=max;
	gpo.min=min;
	gpo.playas=grupo;
	gpo.size=num;
	return gpo;

}

GrupoRadiacion crearRadiacion(int min,int max,Playa ** array,int size)//crea el grupo radiacion que se compone de un array, el tamaño del array y la media y los valores entre los que se encuentran las playas en lo que se refiere a la radiacion
{
	int c=0;
		int i;
		for(i=0;i<size;i++){
			if((array[i]->radiacionSolar).media>min && (array[i]->radiacionSolar).media<=max ){
				c++;
			}
		}
		Playa ** grupo=(Playa **)malloc(sizeof(Playa*)*c);
		int num=0;
		for(i=0;i<size;i++){
			if((array[i]->radiacionSolar).media>min && (array[i]->radiacionSolar).media<=max ){

				grupo[num]=(array[i]);
				num++;

			}
		}
		GrupoRadiacion gr;
		gr.max=max;
		gr.min=min;
		gr.playas=grupo;
		gr.size=num;
		return gr;

}

GrupoTempMar crearTemp(int min,int max,Playa ** array,int size)//crea el grupo temperatura del agua que se compone de un array de playas que tienen una temperatura media denttro del intervalo ,el intervalo y el tamaño del array
{
	int c=0;
			int i;
			for(i=0;i<size;i++){
				if((array[i]->temperaturaMar).media>min && (array[i]->temperaturaMar).media<=max ){
					c++;
				}
			}
			Playa ** grupo=(Playa **)malloc(sizeof(Playa*)*c);
			int num=0;
			for(i=0;i<size;i++){
				if((array[i]->temperaturaMar).media>min && (array[i]->temperaturaMar).media<=max ){

					grupo[num]=(array[i]);
					num++;

				}
			}
			GrupoTempMar gtm;
			gtm.max=max;
			gtm.min=min;
			gtm.playas=grupo;
			gtm.size=num;
			return gtm;
}
void aumentarCompatibilidad(Playa ** playas,int comp,int size)//incrementa la disponibiidad de la playa,el usuario vera las playas ordenadas por este parametro.Incrementa +5 si es la primera prioridad del usuario,+4 si es la segunda prioridad,+3 si es la tercera prioridad,+2 si es la segunda prioridad,+1 si es la quinta prioridad
{
	int i;
	for(i=0;i<size;i++){
		playas[i]->disponibilidad=(playas[i]->disponibilidad)+comp;
		//printf("compatibilidad %i",(playas[i]->disponibilidad)+comp);
		//fflush(stdout);

	}
}
void inicializarCompatibilidad(Playa ** playas,int size)//inicia la disponibilidad de todas las playas a 0
{
	int i;
		for(i=0;i<size;i++){
			playas[i]->disponibilidad=0;
		}
}
void liberarElegidas(Playa *** eleg,int size)//libera el array
{
	int i;
	for(i=0;i<size;i++){
		free(eleg[i]);
	}
	free(eleg);
}

void devolverPlayas(int * opciones,int sizeop,Playa ** playas,int tampl)//aumenta la disponibilidad (compatibilidad) de las plyas respecto a la busqueda del usuario para luego ordenarlas respecto a este parametro.
{
	inicializarCompatibilidad(playas,tampl);
	Playa *** elegidas=(Playa ***)malloc(sizeof(Playa **)*sizeop);

	int i;
	for(i=0;i<sizeop;i++){
		//printf("opcion %i\n",opciones[i]);
		//fflush(stdout);
		if(opciones[i]==5){
			GrupoTempMar tm=crearTemp(10,16,playas,tampl);
			elegidas[i]=tm.playas;
			//printf("%i",tm.size);
			//fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,tm.size);


		}else if(opciones[i]==6){
			GrupoTempMar tm=crearTemp(17,20,playas,tampl);
			elegidas[i]=tm.playas;
			//printf("%i",tm.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,tm.size);

		}else if(opciones[i]==7){
			GrupoTempMar tm=crearTemp(20,25,playas,tampl);
			elegidas[i]=tm.playas;
			//printf("%i",tm.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,tm.size);

		}else if(opciones[i]==8){
			GrupoOleaje o=crearGrupoOleaje(0,1,playas,tampl);
			elegidas[i]=o.playas;
			//printf("%i",o.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,o.size);

		}else if(opciones[i]==9){
			GrupoOleaje o=crearGrupoOleaje(1,2,playas,tampl);
			elegidas[i]=o.playas;
			//printf("%i",o.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,o.size);

		}else if(opciones[i]==10){
			GrupoOleaje o=crearGrupoOleaje(2,3,playas,tampl);
			elegidas[i]=o.playas;
			//printf("%i",o.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,o.size);

		}else if(opciones[i]==11){
			GrupoPeriodoOleaje po=crearPeriodoOleaje(0,9,playas,tampl);
			elegidas[i]=po.playas;
			//printf("%i",po.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,po.size);
		}else if(opciones[i]==12){
			GrupoPeriodoOleaje po=crearPeriodoOleaje(10,15,playas,tampl);
			elegidas[i]=po.playas;
			//printf("%i",po.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,po.size);

		}else if(opciones[i]==13){
			GrupoPeriodoOleaje po=crearPeriodoOleaje(15,100,playas,tampl);
			elegidas[i]=po.playas;
			//printf("%i",po.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,po.size);

		}else if(opciones[i]==17){
			GrupoBandera b=crearGrupoBandera("rojo",playas,tampl);
			elegidas[i]=b.playas;
			//printf("%i",b.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,b.size);

		}else if(opciones[i]==18){
			GrupoBandera b=crearGrupoBandera("amarillo",playas,tampl);
			elegidas[i]=b.playas;
			//printf("%i",b.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,b.size);

		}else if(opciones[i]==19){
			GrupoBandera b=crearGrupoBandera("verde",playas,tampl);
			elegidas[i]=b.playas;
			//printf("%i",b.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,b.size);

		}else if(opciones[i]==20){
			GrupoArena ga=crearGrupoArena("Natural",playas,tampl);
			elegidas[i]=ga.playas;
			//printf("%i",ga.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,ga.size);
		}else if(opciones[i]==21){
			GrupoArena ga=crearGrupoArena("artificial",playas,tampl);
			elegidas[i]=ga.playas;
			//printf("%i",ga.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,ga.size);

		}else if(opciones[i]==22){
			GrupoArena ga=crearGrupoArena("piedras",playas,tampl);
			elegidas[i]=ga.playas;
			//printf("%i",ga.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,ga.size);

		}else if(opciones[i]==23){
			GrupoTiempo t=crearGrupoTiempo("soleado",playas,tampl);
			elegidas[i]=t.playas;
			//printf("%i",t.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,t.size);

		}else if(opciones[i]==24){
			GrupoTiempo t=crearGrupoTiempo("nublado",playas,tampl);
			elegidas[i]=t.playas;
			//printf("%i",t.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,t.size);

		}else if(opciones[i]==25){
			GrupoTiempo t=crearGrupoTiempo("lluvioso",playas,tampl);
			elegidas[i]=t.playas;
			//printf("%i",t.size);
				//		fflush(stdout);
			aumentarCompatibilidad(elegidas[i],5-i,t.size);

		}else{

		}
	}
	liberarElegidas(elegidas,sizeop);

}
void ordenarPlayas(Playa** playas,int size)//metodo burbuja, ordena las playas de mas a menos sugun la compatibilidad con la busqueda del usuario
{
	int i;
	for(i=0;i<size;i++){
		int j;
		for(j=0;j<(size-1);j++){
			if((playas[j]->disponibilidad)<(playas[j+1]->disponibilidad)){
				Playa * p=playas[j];
				playas[j]=playas[j+1];
				playas[j+1]=p;


			}
		}
	}
}





