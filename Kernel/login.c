/*
* login.c
* AUTOR: CARLOS IGNACIO OLANO MARES
* Copyrigth 2018 Carlos Ignacio Olano Mares <alumno_carlosignacio@hotmail.com>
*/
#include <stdio.h>
#include "login.h"
unsigned char user[20];
unsigned char padsword[20];
void login(user.name,user.password)
{
/*
* Comparamos si nombre de usuario y
* contraseña no estan vacios
*/
if(user.name <> " " && user.password <> " ")
{
/*
* Comparamos el nombre de usuario y
* password son correctos
*/
if user.name == user && user.pasword == password)
{
/*
* Si son correctos retornamos correcto
* que equivale a 1
*/
user.acces = 1;
}
}
else
{
/*
* Si son correctos retornamos correcto
* que equivale a 0
*/
user.acces = 0;
}
return user.acces;
}
void logout()
{
}