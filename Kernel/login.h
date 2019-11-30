/*
* login.h
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#ifndef LOGGIN_H
#define LOGGIN_H
typedef struct user
{
unsigned char name[20];
unsigned char password[20];
unsigned int time;
unsigned int date;
unsigned char permision[5];
unsigned int access;
}
void login(user.name, user.password);
void logout();
#endif