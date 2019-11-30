/*
* fs.h
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#ifndef _FS_H
#define _FS_H
/*
* Listado de directorios del sistema
*/
#define unsigned char system[] = "/sys";
#define unsigned char user[] = "/user";
#define unsigned char lib[]= "/lib";
#define unsigned char include[] = "/include";
#define unsigned char tools[] = "/tools";
#define unsigned char app[] = sys + "/apps";
#define unsigned char temp[] ="/temp";
#define unsigned char cache[] = "/cache";
#define unsigned char document[] = user + "/document";
#define unsigned char driver[] = system + "/drivers";
/*
* Permisos para archivos y carpetas
*/
#define unsigned char wre[] = "wre";
#define unsigned char wr[] ="wr-";
#define unsigned char r[] = "-r-";
#define unsigned char none[] = "---";
/*
* Propiedades de los directorios
*/
typedef struct directory
{
unsigned char ubication[100];
unsigned char permision[5];
unsigned char time;
unsigned char date;
unsigned int directorylength;
}directory;
/*
* Propiedades de los archivos
*/
typedef struct file
{
unsigned char ubication[100];
unsigned char name[100];
unsigned char permision[5]; 
unsigned char extension[10];
unsigned short time;
unsigned short date;
unsigned int filelengt;
}file;
#endif