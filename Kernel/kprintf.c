/*
* kprintf.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include <stdio.h>
int kprintf(int linia,int columna,char *text,char *color)
{
 char *video=(char*)(0xB8000+((linia*80+columna)*2)); /*direccion de la video segun la linea y la columna*/ 
                                            

 while(*text!=0) //mientras aiga texto                            
{
   *video++ = *text++; //enviamos el texto                      
   *video++ = *color;  //con el color q elegimos                      

}
   return;
}