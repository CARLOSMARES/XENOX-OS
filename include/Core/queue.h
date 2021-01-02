/*
    Autor: Carlos Ignacio Olano Mares
    2020-2021
    Libreria que facilita el uso de colas en C
*/
#ifndef _QUEUE_H
#define _QUEUE_H

    typedef struct node{
        int value;
        struct node *next;
    }tipoNodo;

    typedef tipoNodo *pNodo;

    void add(pNodo *first, pNodo *last);

    int read(pNodo *first, pNodo *last);

#endif