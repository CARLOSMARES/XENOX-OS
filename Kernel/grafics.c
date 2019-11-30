/*
* grafics.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include <graphics.h>
static unsigned long origin=SCREEN_START;
static unsigned long scr_end=SCREEN_START+LINES*COLUMNS*2;
static unsigned long pos;
static unsigned long x,y;
static unsigned long top=0,bottom=LINES;
static unsigned long lines=LINES,columns=COLUMNS;
void modo_video(unsigned char modo)
{
asm
{
MOV AH,0
MOV AL,MODO //0X13
INT 10H
}
}
void pixel(unsigned int COR_Y, unsigned int COR_X, unsigned char COLOR)
{
asm
{
MOV AX,0A000H
MOV ES,AX
MOV AL,COLOR
MOV BX,COR_X
MOV DX,COR_Y
XCHG DH,DL
MOV DI,DX
SHR DI,1
SHR DI,1
ADD DI,DX
ADD DI,BX
MOV ES:[DI],AL
}
}
unsigned char lee_pixel(unsigned int COR_X, unsigned char COR_Y)
{
unsigned char COLOR;
asm{
MOV AX,0A000H
MOV ES,AX
MOV BX,COR_X
MOV DX,COR_Y
XCHG DH,DL
MOV DI,DX
SHR DI,1
SHR DI,1
ADD DI,DX
ADD DI,BX
MOV COLOR,ES:[DI]
}
return (COLOR);
}
void color_rgb(unsigned char COLOR,unsigned char R, unsigned char G, unsigbed char B)
{
asm{
MOV AL,COLOR
MOV DX,3C8H
OUT DX,AL
INC DX
MOV AL,R
OUT DX,AL
MOV AL,B
OUT DX,AL
}
}
static inline void gotoxy(unsigned int new_x,unsigned int new_y)
{
	if (new_x>=columns || new_y>=lines)
		return;
	x=new_x;
	y=new_y;
	pos=origin+((y*columns+x)<<1);
}