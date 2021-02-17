/*
* timer.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include <timer.h>
#include <es.h>
#include <stdio.h>
#include <isr.h>
unsigned int tick = 0;
unsigned long wait_ticks = 0;
static void timer_callback(registros *regs)
{
    tick++;
    wait_ticks++;

}
void timer_wait(int ticks)
{
    wait_ticks = 0;
    while(wait_ticks <= ticks);
}
void init_timer(unsigned int frequency)
{
    //Registramos el timer en la IRQ0
    register_interrupt_handler(IRQ0, &timer_callback);
    //programamos la Frecuencia
    unsigned int divisor = 1193180 / frequency;
    outb(0x43, 0x36);
    unsigned char l = (unsigned char)(divisor & 0xFF);
    unsigned char h = (unsigned char)( (divisor>>8) & 0xFF );

    // Enviamos la Nueva Frecuencia
    outb(0x40, l);
    outb(0x40, h);
}