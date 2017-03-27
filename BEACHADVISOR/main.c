/*
 * main.c
 *
 *  Created on: 27 de mar. de 2017
 *      Author: usuario
 */
#include<stdlib.h>
#include<stdio.h>
#include"menu.h"
void main(void){
	int *opciones=(int *)malloc(sizeof(int)*5);
	int c=0;
	int num=0;

	while(num!=4){
	char str[1];
	char * menu1="¿Qué deeesea, buscar datos del dia de hoy o tendencias y pronósticos?(Si quiere buscar datos de hoy pulse 1, si desea buscar tendencias y pronósticos pulse 2, si quiere dejar algún comentario de una playa pulse 3, si desea salir pulse 4).";
	pedirPorTeclado(menu1,&num);
	printf("%i ",num);
	if(num==1){
		int num1=0;
		do{
		char * menu2="seleccione el orden de prioridad en el resultado de la búsqueda respecto a los parámetros elegidos\n-1.Actividad\n-2.Datos del mar\n-3.Arena\n-4.Atmosféricos\n-5.Modo de acceso\nCuando acabe de elegir las prioridades pulse 's'\n";
		pedirPorTeclado(menu2,&num1);

		printf("%i\n ",num1);
		if(num1==1){
			int num3=0;
			char * menu3="-1.Surf\n-2.Padelsurf\n-3.Interés geológico.\n-4.Piragüismo\n";
			pedirPorTeclado(menu3,opciones+c);
			c=c+1;

		}if(num1==2){
			int num2=0;
			char * menu3="-1.Temperatura del Mar\n-2.Oleaje\n-3.Periodo de Oleaje\n-4.Bandera\n";
			pedirPorTeclado(menu3,&num2);
			if(num2==1){
				char * menu3="5. Entre (10-16 ºC)\n6. Entre (17-20 ºC)\n7. Entre (20-25 ºC)\n";
				pedirPorTeclado(menu3,opciones[c]);
				c=c+1;

			}if(num2==2){
				char * menu3="8. Entre (0-1 metros)\n9. Entre (1-2 metros)\n10. (> 2 metros)\n";
				pedirPorTeclado(menu3,opciones[c]);
				c=c+1;

			}if(num2==3){
				char * menu3="11. Entre (0-9 segundos)\n12. Entre (10 - 15 segundos)\n13. Entre (> 16 segundos)\n";
				pedirPorTeclado(menu3,opciones[c]);
				c=c+1;

			}if(num2==4){
				char * menu3="17.Rojo\n18.Amarillo\n19.Verde\n";
				pedirPorTeclado(menu3,opciones[c]);
				c=c+1;
			}

		}if(num1==3){
			char * menu3="20.Arena natural\n21.Arena artificial\n22.Piedras";
			pedirPorTeclado(menu3,opciones[c]);
			c=c+1;

		}if(num1==4){
			char * menu3="23.Tiempo soleado\n24.Tiempo nublado\n25.Lluvia\n26.Poca radiación solar.\n";
			pedirPorTeclado(menu3,opciones[c]);
			c=c+1;

		}if(num1==5){
			char * menu3="27.Metro\n28.Tren\n29.Bus\n30.Coche";
			pedirPorTeclado(menu3,opciones[c]);
			c=c+1;

		}if(num1<1 || num1>5){
			printf("%i",num1);
			printf("El numero marcado no esta disponible en el menu.Seleccione otro de nuevo");
		}
		}while(num1!='s');
	}
	}

	if(num==2){

	}if(num==3){


	}if(num<1 || num>3){
		printf("2El numero marcado no esta disponible en el menu.Seleccione otro de nuevo");
	}

	free(opciones);

}

