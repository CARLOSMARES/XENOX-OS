/*
* stdarg.h
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#ifndef _STDARG_H_
#define	_STDARG_H_
typedef char *va_list;
#define	__va_promote(type) \
	(((sizeof(type) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))
#define	va_start(ap, last) \
	(ap = ((char *)&(last) + __va_promote(last)))
#define	va_arg(ap, type) \
	((type *)(ap += sizeof(type)))[-1]
#define	va_end(ap)
#endif