#include "stack.h" 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

STACK * new_stack() {
        return (STACK *) malloc(sizeof(STACK));
}

void push(STACK *s, Container container){
        s->sp++;
        s->stack[s->sp] = container;        
}

Container pop(STACK *s){
        Container r = s->stack[s->sp];
        s->sp--;
        return r;
}
