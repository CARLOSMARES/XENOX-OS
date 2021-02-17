#include "queue.h"
#include <malloc.h>

void add(pNodo *first, pNodo *last, int v)
{
    pNodo new;
    new = (pNodo)malloc(sizeof(tipoNodo));
    new->value = v;
    new->next = NULL;
    if(*last)
        (*last)->next = new;
    *last = new;
    if(!*first)
        *first = new;
}

int read(pNodo *first, pNodo *last)
{
    pNodo nodo;
    int v;
    nodo = *first;
    if(!nodo)
        return 0;
    *first = nodo->next;
    v = nodo->value;
    free(nodo);
    if(!first)
        *last = NULL;
    return v;
}
