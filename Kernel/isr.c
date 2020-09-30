/*
* isr.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include <isr.h>
#include <es.h>
#include <stdio.h>
#include <syscalls.h>
registros_isr interrupt_handlers[256];
void register_interrupt_handler(unsigned char n, registros_isr handler)
{
    interrupt_handlers[n] = handler;
}
void isr_handler(registros regs)
{
   unsigned char int_no = regs.int_no & 0xFF;
    if (interrupt_handlers[regs.int_no] != 0)
    {
        registros_isr handler = interrupt_handlers[regs.int_no];
        handler(&regs);
    }
    else
    {
        printf("unhandled interrupcion: %d\n",regs.int_no);
        for(;;); //detenemos el kernel
        reboot();
    }
}
void irq_handler(registros regs)
{
    if (regs.int_no >= 40)
    {
        outb(0xA0, 0x20);
    }
    outb(0x20, 0x20);
    if (interrupt_handlers[regs.int_no] != 0)
    {
        registros_isr handler = interrupt_handlers[regs.int_no];
        handler(&regs);
    }
}