/*
* syscalls.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/

//Se manda llamar a la cabecera donde estan declaradas las funciones
#include "sys/syscalls.h"

//Funcion de apagado del sistema
void shutdown()
{
}

//Funcion de Reinicio del sistema
void reboot()
{
    /*
    * Se manda llamar unas instrucciones de ensamblador dentro del archivo de lenguaje C
    * por medio del metodo ASM
    */
    asm{
        // Se mueve el valor de 0 a AX con la instruccion MOV
        mov ax, 0
        // Instruccion para Reiniciar El Systema en Ensamblador
        int 19h		// Reboot the system
    }
}