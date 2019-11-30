/*
* limits.h
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#ifndef _LIMITS_H
#define _LIMITS_H
#define CHAR_BIT        8
#define SCHAR_MIN       ((signed char) 0x80)
#define SCHAR_MAX       127
#define UCHAR_MAX       255
#define CHAR_MIN        0
#define CHAR_MAX        255
#define SHRT_MIN        ((short) 0x8000)
#define SHRT_MAX        32767
#define USHRT_MAX       65535U
#define INT_MIN         ((int) 0x8000)
#define INT_MAX         32767
#define UINT_MAX        65535U
#define LONG_MAX        2147483647L
#define LONG_MIN        ((long) 0x80000000)
#define ULONG_MAX       4294967295UL
/* End of limits.h */
#endif