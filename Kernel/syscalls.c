/*
* syscalls.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include "syscalls.h"
void shutdown()
{
}
void reboot()
{
    asm{
        mov ax, 0
        int 19h		// Reboot the system
    }
}