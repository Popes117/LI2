#include "stack.h" 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

STACK * new_stack() {
        return (STACK *) malloc(sizeof(STACK));
}

void push(STACK *s, int elem){
        s->sp++;
        s->stack[s->sp] = elem;
}

int pop(STACK *s){
        int r = s->stack[s->sp];
        s->sp--;
        return r;
}