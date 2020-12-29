/*
* boot.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#ifndef XENOXOS
//#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif
#include <stdio.h>
#include "shell.h"
#include <keyboard.h>
#include <timer.h>
#include <time.h>

long startup_time = 0;
extern long kernel_mktime(struct tm * tm);
#define CMOS_READ(addr) ({ \
outb_p(0x80|addr,0x70); \
inb_p(0x71); \
})

#define BCD_TO_BIN(val) ((val)=((val)&15) + ((val)>>4)*10)

static void time_init(void)
{
	struct tm time;

	do {
		time.tm_sec = CMOS_READ(0);
		time.tm_min = CMOS_READ(2);
		time.tm_hour = CMOS_READ(4);
		time.tm_mday = CMOS_READ(7);
		time.tm_mon = CMOS_READ(8)-1;
		time.tm_year = CMOS_READ(9);
	} while (time.tm_sec != CMOS_READ(0));
	BCD_TO_BIN(time.tm_sec);
	BCD_TO_BIN(time.tm_min);
	BCD_TO_BIN(time.tm_hour);
	BCD_TO_BIN(time.tm_mday);
	BCD_TO_BIN(time.tm_mon);
	BCD_TO_BIN(time.tm_year);
	startup_time = kernel_mktime(&time);
}

k_x_main()
{
    cls();
    k_xy_printf("**************************\n",30,30,0x00);
    k_xy_printf("*        XENOX-OS        *\n",31,30,0x00);
    k_xy_printf("**************************\n",32,30,0x00);
    time_init();
    init_timer(100);
    timer_whait(30000);
    init_keyboard();
    timer_whait(30000);
    shell();
}