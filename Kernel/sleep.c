/*
* shell.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include <timer.h>
void sleep(int ms) /*aprox*/
{
   timer_wait(ms);
}