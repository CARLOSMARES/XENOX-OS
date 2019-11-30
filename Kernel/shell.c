/*
* shell.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include <shell.h>
#include <stdio.h>
#include <timer.h>
#include "syscalls.h"
#include <sys/system.h>
void shell()
{
cls();
while(true)
{
char command[50];
printf("root@XENOXOS-> ");
scanf("%s", command);
switch(command)
{
case "help":
help();
case "/?":
help();
case "version":
version();
case "ver":
version();
case "cls":
cls();
case "clear":
cls();
case "shutdown":
shutdown();
case "reshell":
reshell();
default:
printf("No command found");
}
}
}
void reshell()
{
cls();
     k_xy_printf("Reiniciando Su Equipo Por Favor Espere",10,10,0x00);
     timer_wait(20000);
     reshell();
}
void shutdown();
{
cls():
     k_xy_printf("Apagando Su Equipo Por Favor Espere",10,10,0x00);
     timer_wait(20000);
}
void help()
{
printf("Commands:\n");
printf("help or /?: Help\n");
printf("cls or clear: Clear Screen\n");
printf("version or ver: Version for Opersting System");
printf("shutdown: Shutdown PC\n");
printf("reshell: Reshell PC\n");
}
void version()
{
printf("XENOX-OS\n");
printf("Version 0.1\n");
printf("FASE: ALPHA 1\n");
printf("CODE NAME: SEPHIROT");
}