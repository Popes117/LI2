#include "stack.h" 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "macro.h"

/**
 * @file Ficheiro responsável pela definição da Stack.
 */


STACK * new_stack() {
        STACK *s = malloc(sizeof(STACK));
        s->stack = malloc(100001*sizeof(Container));
        return s;
}

STACK * ministack() {
        STACK *s = malloc(sizeof(STACK));
        s->stack = malloc(50*sizeof(Container));
        return s;
}

void prepush(STACK *s, Container container){
        s->sp++;
        for (int i = s->sp; i > 1; i--)
        {
                s->stack[i] = s->stack[i-1];
        }
        s->stack[1] = container;
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

void printer(STACK *s){
    for (int i = 1; i <= s->sp; i++)
        {
            Container z = s->stack[i];
            if (_Zlabel_ == 3)
            {
                printf("%c",_Zcar_);
            }
            else if(_Zlabel_ == 2){
                printf("%li",_ZnumI_);
            } 
            else if (_Zlabel_ == 1){
                printf("%g",_ZnumD_);
            }
            else if (_Zlabel_ == 4){
                printf("%s",_Zstr_);
            } 
            else if (_Zlabel_ == 6 ){
                printf("{%s}",_Zstr_);
            } 
            else{
                printer(z.a);
            }
    }
} 