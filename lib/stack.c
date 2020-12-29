#include <stack.h>
#include <malloc.h>
int create(struct pila *p, int nro_elementos){

   if( nro_elementos < 0) { return 0; }
   
   struct elemento arreglo_elementos[nro_elementos];
   p->elementos = &arreglo_elementos;
   p->tope = nro_elementos - 1;
   p->contador = 0;
   return 1;
}

int push(struct pila *p, struct elemento elem){
   if (p == NULL ) {return -1;}
   if (isFull(*p) == 1) { return -2; }
   p->elementos[p->contador] = elem;
   p->contador++;
   return 1;
}

int pop(struct pila *p, struct elemento *e){
   if (p == NULL) { return -1; }
   if (isEmpty(*p)) { return -2; }
   struct elemento resp = (*p).elementos[(*p).contador - 1 ];
   p->contador--;
   e->x = resp.x;
   e->y = resp.y;
   return 1;
}

int isEmpty(struct pila p){
   if(p.contador == 0) {return 1;}
   return 0;
}

int isFull(struct pila p){
   if(p.contador > p.tope) {return 1;}
   return 0;
}

int count (struct pila p){
   return p.contador;
}