#include "stack.h" 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

STACK * new_stack() {
        STACK *s = malloc(sizeof(STACK));
        s->stack = malloc(BUFSIZ*sizeof(Container));
        //s->size = 40;
        return s;
}

/* STACK* reallocSTACK(STACK *s){

        STACK *ns = realloc(s,sizeof(STACK));
        ns->size *= 2;
        ns->stack = realloc(s->stack,(s->size)*sizeof(Container));
        return ns;
} */

void prepush(STACK *s, Container container){
        //if(s->size == s->sp) s = reallocSTACK(s);
        s->sp++;
        for (int i = s->sp; i > 1; i--)
        {
                s->stack[i] = s->stack[i-1];
        }
        s->stack[1] = container;
}

void push(STACK *s, Container container){
        //if(s->size == s->sp) s = reallocSTACK(s);
        s->sp++;
        s->stack[s->sp] = container;
}

Container pop(STACK *s){
        Container r = s->stack[s->sp];
        s->sp--;
        return r;
}

void printer(STACK *s){
    for (int i = 1; i <= s->sp; i++)
        {
            Container z = s->stack[i];
            if (z.label == 3)
            {
                printf("%c",z.type.car);
            }
            else if(z.label == 2){
                printf("%li",z.type.numI);
            } 
            else if (z.label == 1){
                printf("%g",z.type.numD);
            }
            else if (z.label == 4){
                printf("%s",z.str);
            } 
            else{
                printer(z.a);
                free(z.a->stack);
                free(z.a);
            }
    }
} 