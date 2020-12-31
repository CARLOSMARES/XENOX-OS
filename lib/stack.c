#include <core/stack.h>
#include <stdlib.h>

int create(struct pila *p, int nro_elementos){

   if( nro_elementos < 0) { return 0; }
   
   struct element arreglo_elementos[nro_elementos];
   p->elementos = &arreglo_elementos;
   p->tope = nro_elementos - 1;
   p->contador = 0;
   return 1;
}

int push(struct stack *p, struct element elem){
   if (p == NULL ) {return -1;}
   if (isFull(*p) == 1) { return -2; }
   p->elements[p->count] = elem;
   p->count++;
   return 1;
}

int pop(struct stack *p, struct element *e){
   if (p == NULL) { return -1; }
   if (isEmpty(*p)) { return -2; }
   struct element resp = (*p).elements[(*p).count - 1 ];
   p->count--;
   e->x = resp.x;
   e->y = resp.y;
   return 1;
}

int isEmpty(struct stack p){
   if(p.count == 0) {return 1;}
   return 0;
}

int isFull(struct stack p){
   if(p.count > p.top) {return 1;}
   return 0;
}

int count (struct stack p){
   return p.count;
}