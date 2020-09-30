/*
* es.h
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#ifndef _ES_H
#define _ES_H
/*definimos las funciones de entrada y salida por lo puertos*/
#define outb(port,value) \
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));\
#define inb(port) ({\
	unsigned char _v; \
	__asm__ __volatile__ ("inb %%dx,%%al":"=a" (_v):"d" (port)); \
	_v; \
	})
static __inline__ void outportb(unsigned short port, unsigned char val)
{
    __asm__ __volatile__ ("outb %%al, %%dx" : : "d" (port), "a" (val));
}
static __inline__ void idle()
{
	__asm__("hlt");
}
#endif