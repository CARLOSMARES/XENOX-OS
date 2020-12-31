#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct _node{
    int value;
    _node *next;
}tipoNodo;

typedef tipoNodo *pNodo;

void add(pNodo *first, pNodo *last);

int read(pNodo *first, pNodo *last);

#endif