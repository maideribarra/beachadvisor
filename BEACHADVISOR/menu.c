/*
 * menu.c
 *
 *  Created on: 27 de mar. de 2017
 *      Author: usuario
 */
#include<stdlib.h>
#include<stdio.h>
#include "string.h"
void pedirPorTeclado(char * pregunta,int * variable){//si mete una letra peta
	char str[5];
	clearIfNeeded(str,5);
	printf("%s",pregunta);
	fflush(stdout);
	fgets(str,5,stdin);
	printf("%i string\n",str[0]);
	printf("%i string\n",str[1]);
	printf("%i string\n",str[2]);
	sscanf(str,"%i",variable);
	printf("%i variable\n",*variable);
	int i;
	for(i=0;i<5;i++){
		if(str[i]==115){//para la s
			*variable=115;
		}if(str[i]==97){
			*variable=97;
		}
	}
}
void clearIfNeeded(char *str, int max_line)
{
	// Limpia los caracteres de más introducidos
	if ((strlen(str) == max_line-1) && (str[max_line-2] != '\n'))
		while (getchar() != '\n');
}

void imprimirOpciones(int * array,int size)
{
	printf("Has elegido las siguientes prioridades de busqueda:\n");
	int i;
	for(i=0;i<(size-1);i++){
		printf("%i,",array[i]);
	}printf("%i\n",array[size-1]);
}
void menuTemperatura(int *c,int * opciones,int * p)
{
	int i=*c;
	char * menu3="5. Entre (10-16 ºC)\n6. Entre (17-20 ºC)\n7. Entre (20-25 ºC)\n";
	pedirPorTeclado(menu3,opciones+i);
	printf("%i",opciones[i]);
	if(opciones[i]=='a'){
		menuDatosMar(p,c,opciones);
	}else{
		*c=*c+1;
	}

}
void menuOleaje(int *c,int * opciones,int * p)
{
	int i=*c;
	char * menu3="8. Entre (0-1 metros)\n9. Entre (1-2 metros)\n10. (> 2 metros)\n";
	pedirPorTeclado(menu3,opciones+i);
	if(opciones[i]=='a'){
		menuDatosMar(p,c,opciones);
	}else{
		*c=*c+1;
	}
}
void menuPeriodoOleaje(int *c,int * opciones,int * p)
{
	int i=*c;
	char * menu3="11. Entre (0-9 segundos)\n12. Entre (10 - 15 segundos)\n13. Entre (> 16 segundos)\n";
	pedirPorTeclado(menu3,opciones+i);
	if(opciones[i]=='a'){
		menuDatosMar(p,c,opciones);
	}else{
		*c=*c+1;
	}
}
void menuBandera(int *c,int * opciones,int * p)
{
	int i=*c;
	char * menu3="17.Rojo\n18.Amarillo\n19.Verde\n";
	pedirPorTeclado(menu3,opciones+i);
	if(opciones[i]=='a'){
		menuDatosMar(p,c,opciones);
	}else{
		*c=*c+1;
	}
}
void menuArena(int *c,int * opciones,int * p)
{
	int i=*c;
	char * menu3="20.Arena natural\n21.Arena artificial\n22.Piedras";
	pedirPorTeclado(menu3,opciones+i);
	if(opciones[i]=='a'){
		menuCriterios(opciones,c,p);
	}else{
		*c=*c+1;
	}
}
void menuAtmosfericos(int *c,int * opciones,int * p)
{
	int i=*c;
	char * menu3="23.Tiempo soleado\n24.Tiempo nublado\n25.Lluvia\n26.Poca radiación solar.\n";
	pedirPorTeclado(menu3,opciones+i);
	if(opciones[i]=='a'){
		menuCriterios(opciones,c,p);
	}else{
		*c=*c+1;
	}
}
void menuAcceso(int *c,int * opciones,int * p)
{
	int i=*c;
	char * menu3="27.Metro\n28.Tren\n29.Bus\n30.Coche";
	pedirPorTeclado(menu3,opciones+i);
	if(opciones[i]=='a'){
		menuCriterios(opciones,c,p);
	}else{
		*c=*c+1;
	}
}
void menuAcctividad(int *c,int * opciones,int * p)
{
	int i=*c;
	char * menu3="-1.Surf\n-2.Padelsurf\n-3.Interés geológico.\n-4.Piragüismo\n";
	pedirPorTeclado(menu3,opciones+i);
	if(opciones[i]=='a'){
		menuCriterios(opciones,c,p);
	}else{
		*c=*c+1;
	}
}
void menuCriterios(int * opciones,int * c,int * p)
{
	char * menu2="Seleccione el siguiente criterio de ordenación de la búsqueda \n-1.Actividad\n-2.Datos del mar\n-3.Arena\n-4.Atmosféricos\n-5.Modo de acceso\nCuando acabe de elegir las prioridades pulse 's'\nComo maximo puede elegir 5 prioridades";
	pedirPorTeclado(menu2,p+1);
	printf("%i\n ",p[1]);
			if(p[1]==1){
				menuAcctividad(c,opciones,p);


			}if(p[1]==2){
				int num2=0;
				menuDatosMar(p,c,opciones);

			}if(p[1]==3){
				menuArena(c,opciones,p);

			}if(p[1]==4){
				menuAtmosfericos(c,opciones,p);

			}if(p[1]==5){
				menuAcceso(c,opciones,p);

			}if(p[1]=='a'){

				menuPrincipal(c,opciones,p);

			}if((p[1]<1 || p[1]>5) && p[1]!='s' && p[1]!='a'){
				//printf("%i",num1);
				printf("El numero marcado no esta disponible en el menu.Seleccione otro de nuevo");
			}

}
void menuDatosMar(int *p,int *c,int *opciones)
{
	char * menu3="-1.Temperatura del Mar\n-2.Oleaje\n-3.Periodo de Oleaje\n-4.Bandera\n";
				pedirPorTeclado(menu3,p+2);
				if(p[2]==1){
					menuTemperatura(c,opciones,p);

				}if(p[2]==2){
					menuOleaje(c, opciones,p);

				}if(p[2]==3){
					menuPeriodoOleaje(c,opciones,p);

				}if(p[2]==4){
					menuBandera(c,opciones,p);
				}if(p[2]=='a'){
					menuCriterios(opciones,c,p);

				}
}
void menuPrincipal(int *c,int *opciones,int *p)
{
	p[0]=0;
	while(p[0]!=4){
	char * menu1="¿Qué deeesea, buscar datos del dia de hoy o tendencias y pronósticos?\n(Si quiere buscar datos de hoy pulse 1, si desea buscar tendencias y pronósticos pulse 2\n, si quiere dejar algún comentario de una playa pulse 3, si desea salir pulse 4).";
		pedirPorTeclado(menu1,&p[0]);
		//printf("%i ",p[0]);
		if(p[0]==1){
			p[1]=0;
			do{
				menuCriterios(opciones,c,p);
			}while(p[1]!='s' || c>5);
			//printf("voy a imprimir opciones");
			imprimirOpciones(opciones,c);
		}

		if(p[0]==2){

		}if(p[0]==3){


		}if(p[0]<1 || p[0]>3){
			printf("El numero marcado no esta disponible en el menu.Seleccione otro de nuevo");
		}
	}
}
