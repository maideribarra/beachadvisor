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
	char ** tiempo;
	int cant;
	char * tiempoRepetido;

}ListaTiempo;

typedef struct{
	int * radiacionSolar;
	int cant;
	float media;
}ListaRadiacionSolar;
typedef struct{
	char ** bandera;
	int cant;
	char * banderaRepetida;
}ListaBandera;
typedef struct{
	int * oleaje;
	int cant;
	float media;
}ListaOleaje;
typedef struct{
	int * periodo;
	int cant;
	float media;
}ListaPeriodo;
typedef struct{
	int * temperaturaMar;
	int cant;
	float media;
}ListaTemperaturaMar;
typedef struct{
	int disponibilidad;
	int  codigo;
	char * nombrePlaya;
	Coordenada  coor;
	char * loc;
	char * pais;
	char * provincia;
	char * mar;
	char * arena;
	ListaTiempo tiempo;
	ListaRadiacionSolar radiacionSolar;
	ListaBandera bandera;
	ListaOleaje oleaje;
	ListaPeriodo periodo;
	ListaTemperaturaMar temperaturaMar;
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
	int codigo;
	char * transporte;
	char * horario;

}Acceso;

typedef struct{
	Actividad act;
	Playa ** playas;
	int size;
}GrupoActividad;
typedef struct{
	Acceso ac;
	Playa ** playas;
	int size;
}GrupoAcceso;
typedef struct{//Playas en las que predromine este tiempo
	char * tiempo;
	Playa ** playas;
	int size;
}GrupoTiempo;
typedef struct{//Playas en las que predomine esta bandera
	char * Bandera;
	Playa ** playas;
	int size;
}GrupoBandera;

typedef struct{//Playas en las que la media de radiacion solar sea
	int max;
	int min;
	Playa ** playas;
	int size;
}GrupoRadiacion;
typedef struct{//playas en las que la media de temperatura este
	int max;
	int min;
	Playa ** playas;
	int size;
}GrupoTempMar;
typedef struct{
	float max;
	float min;
	Playa ** playas;
	int size;
}GrupoOleaje;
typedef struct{
	float max;
	float min;
	Playa ** playas;
	int size;
}GrupoPeriodoOleaje;
typedef struct{
	char * arena;
	Playa ** playas;
	int size;
}GrupoArena;


void leerPlaya(FILE * f,Playa ** array,int cantAtr,int fila,char *** atr,int * a);
int contarFilas(FILE * f);
void separarFila(char * fila,int cantAtr,char ** atributos);
void liberarAtributos(char *** atributos,int cantAtr,int fila);
void leerFilaPlaya(char * fila,Playa * playa,int cantAtr,char ** atributos,int * a);
Coordenada  ConvertirCoordenada(char * str);
void clearIfNeeded(char *str, int max_line);
int * tamayoo(char * fila,int cantAtr);
void pasarFicheroAarray(char *** array,FILE * f,int CantAtr,int sizef);
Playa * buscarPlaya(Playa ** pl,int size,int codigo);
void inicializarPlayas(Playa ** pl,int sizepl,int numMax);
void liberarPlayas(Playa ** pl,int sizepl);
void meterDatosPlaya(Playa ** pl,char ***array,int CantAtr,int sizef,int sizepl,FILE * f);

void leerAcceso(FILE * f,Acceso ** array,int cantAtr,int fila,char *** atr,int * a);
void leerFilaAcceso(char * fila,Acceso * acceso,int cantAtr,char ** atributos,int * a);
void inicializarAcceso(Acceso ** acceso,int sizeac,int numMax);
void liberarAcceso(Acceso ** acceso,int sizeac);
Acceso * buscarAcceso(Acceso ** acceso,int size,int codigo);
void meterDatosAcceso(Acceso ** acceso,char ***array,int CantAtr,int sizef,int sizeac,FILE * f);
void mostrarAcceso(FILE * access, Acceso *ac);
void copiarString(char cadena[], int x, Acceso * ac, FILE * access);

void leerActividad(FILE * fa, Actividad ** arraya, int atract, int filaa, char *** atra, int * b);
void leerFilaActividad(char * filaa, Actividad * actividad, int atract, char ** atributosA, int * b);
Actividad * buscarActividad(Actividad ** ac,int size,int codigoA, char * nombre);


#endif /* FICHERO_H_ */
