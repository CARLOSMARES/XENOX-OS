struct element{
   int x;
   int y;
};

struct stack {
   struct element *elements;
   int count;
   int top;
};

int crete(struct pila *, int);
int isEmpty(struct pila);
int isFull(struct pila);
int push(struct pila*, struct elemento);
int pop(struct pila*, struct elemento *);