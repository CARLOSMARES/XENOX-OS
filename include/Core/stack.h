/*
    Autor: Carlos Ignacio Olano Mares
    2020-2021
    Libreria que facilita el uso de pila LIFO en C
*/
#ifndef _STACK_H
#define _STACK_H

    #define NULL 0
    struct element{
    int x;
    int y;
    };

    struct stack {
    struct element *elements;
    int count;
    int top;
    };

    int crete(struct stack *, int);
    int isEmpty(struct stack);
    int isFull(struct stack);
    int push(struct stack*, struct element);
    int pop(struct stack*, struct element *);

#endif