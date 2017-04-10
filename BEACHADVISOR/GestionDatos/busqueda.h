/*
 * busqueda.h
 *
 *  Created on: 31 de mar. de 2017
 *      Author: usuario
 */

#include "fichero.h"
#ifndef BUSQUEDA_H_
#define BUSQUEDA_H_
void imprimirArray(Playa ** arr,int tam);
int estaEn(int *op,int size,int num);
void impchar(char ** ch,int size);
void impint(int * entero,int size);
void ponerValorRepetido(Playa ** playas,int size);
float mediaaa(int * val,int size);
char * repetidooo(char ** valores,int size);
int cadenaIgual(char * c1,char *c2);
void devolverPlayas(int * opciones,int sizeop,Playa ** playas,int tampl);
void liberarElegidas(Playa *** eleg,int size);
void inicializarCompatibilidad(Playa ** playas,int size);
void aumentarCompatibilidad(Playa ** playas,int comp,int size);
GrupoTempMar crearTemp(int min,int max,Playa ** array,int size);
GrupoRadiacion crearRadiacion(int min,int max,Playa ** array,int size);
GrupoPeriodoOleaje crearPeriodoOleaje(int min,int max,Playa ** array,int size);
GrupoOleaje crearGrupoOleaje(int min,int max,Playa ** array,int size);
GrupoArena crearGrupoArena(char * arena,Playa ** array,int size);
GrupoBandera crearGrupoBandera(char * bandera,Playa ** array,int size);
GrupoTiempo crearGrupoTiempo(char * tiempo,Playa ** array,int size);
void ordenarPlayas(Playa** playas,int size);
void escribirarray(Playa ** array,int size,FILE * f);
void leerarray(FILE * f,Playa ** array,int size);
#endif /* BUSQUEDA_H_ */
