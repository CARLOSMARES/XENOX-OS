/*
* atoi.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include <stdio.h>
int atoi(char* palabra)
{
int numero = -1,i;
int y=0;
	for (i = 0; i <= strlen(palabra); i++){
		if(palabra[i] - '0' > 0) {
			numero += 1;
		}
		else{
			break;
		}
	}
	for (i = 0; i <= numero;i++){
		y *= 10;
		y += palabra[i] - '0';
	}
return y;
}