/*
* graphics.h
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
void modo_video(unsigned char modo);
void pixel(unsigned int COR_X, unsigned char COR_Y, unsigned char COLOR);
unsigned char lee_pixel(unsigned int COR_Y, unsigned char COR_Y);
void color_rgb(unsigned char COLOR, unsigned char R, unsigned char G, unsigned char B);
static inline void gotoxy(unsigned int new_x,unsigned int new_y);
