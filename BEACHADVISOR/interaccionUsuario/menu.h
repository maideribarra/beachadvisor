/*
 * menu.h
 *
 *  Created on: 27 de mar. de 2017
 *      Author: usuario
 */

#ifndef MENU_H_
#define MENU_H_
void pedirPorTeclado(char * pregunta,int * variable);

void imprimirOpciones(int * array,int size);
void menuTemperatura(int *c,int * opciones);
void menuOleaje(int *c,int * opciones);
void menuPeriodoOleaje(int *c,int * opciones);
void menuBandera(int *c,int * opciones);
void menuArena(int *c,int * opciones);
void menuAtmosfericos(int *c,int * opciones);
void menuAcceso(int *c,int * opciones);
void menuAcctividad(int *c,int * opciones);
void menuCriterios(int * opciones,int * c,int * p);
void menuDatosMar(int *p,int *c,int *opciones);
void menuPrincipal(int *c,int *opciones,int *p);
#endif /* MENU_H_ */
