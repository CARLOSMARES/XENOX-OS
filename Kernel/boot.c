/*
* boot.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#ifndef XENOXOS
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
#include <stdio.h>
#include "shell.h"
#include <keyboard.h>
#include <timer.h>
k_x_main()
{
cls();
k_xy_printf("**************************\n",30,30,0x00);
k_xy_printf("*        XENOX-OS        *\n"31,30,0x00);
k_xy_printf("**************************\n"32,30,0x00);
init_timer(100);
timer_whait(30000);
init_keyboard();
timer_whait(30000);
shell();
}