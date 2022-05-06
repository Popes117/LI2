#include "stack.h" 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

STACK * new_stack() {
        STACK *s = malloc(sizeof(STACK));
        s->stack = malloc(40*sizeof(Container));
        s->size = 40;
        return s;
}

STACK* reallocSTACK(STACK *s){
        STACK *ns = realloc(s,sizeof(STACK));
        ns->stack = realloc(s->stack, (s->size*2)*sizeof(Container));
        ns->size *= 2;
        return ns;
}

void push(STACK *s, Container container){
        if(s->size == s->sp) s = reallocSTACK(s);
        s->sp++;
        s->stack[s->sp] = container;
}

Container pop(STACK *s){
        Container r = s->stack[s->sp];
        s->sp--;
        return r;
}