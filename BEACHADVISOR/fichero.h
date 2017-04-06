/*
 * fichero.h
 *
 *  Created on: 29 de mar. de 2017
 *      Author: usuario
 */

#ifndef FICHERO_H_
#define FICHERO_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int x;
	int y;

}Coordenada;
typedef struct{
	int  codigo;
	char * nombrePlaya;
	Coordenada  coor;
	char * loc;
	char * pais;
	char * provincia;
	char * mar;
	char * arena;
	char ** tiempo;
	int ** radiacionSolar;
	char ** bandera;
	int ** oleaje;
	int ** periodo;
	int ** temperaturaMar;
}Playa;
typedef struct{
	int dia;
	int mes;
	int anyo;

}fecha;

typedef struct{
	char * nombre;
	char * tipo;
}Actividad;
typedef struct{
	char * transporte;
	char * horario;

}Acceso;

typedef struct{
	Actividad act;
	Playa * playas;


}GrupoActividad;
typedef struct{
	Acceso ac;
	Playa * playas;

}GrupoAcceso;
typedef struct{//Playas en las que predromine este tiempo
	char * tiempo;
	Playa * playas;

}GrupTiempo;
typedef struct{//Playas en las que predomine esta bandera
	char * Bandera;
	Playa * playas;
}GrupoBandera;

typedef struct{//Playas en las que la media de radiacion solar sea
	int max;
	int min;
	Playa * playas;
}GrupoRadiacion;
typedef struct{//playas en las que la media de temperatura este
	int max;
	int min;
	Playa * playas;

}GrupoTempMar;
typedef struct{
	float max;
	float min;
	Playa * playas;

}GrupoOleaje;
typedef struct{
	float max;
	float min;
	Playa * playas;
}GrupoPeriodoOleaje;
typedef struct{
	float max;
	float min;
	Playa * playas;
}GrupoArena;

void leerPlaya(FILE * f,Playa ** array,int cantAtr,int fila);
int contarFilas(FILE * f);
char ** separarFila(char * fila,int cantAtr);
void liberarAtributos(char ** atributos,int cantAtr);
void leerFilaPlaya(char * fila,Playa * playa,int cantAtr);
Coordenada  ConvertirCoordenada(char * str);
void liberarAtributos(char ** atributos,int cantAtr);

#endif /* FICHERO_H_ */
