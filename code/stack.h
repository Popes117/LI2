#define MAX 1000
#pragma once

typedef struct {
        int label; 
        /* 
           1 - Double
           2 - Long
           3 - Char
        */
        union HoldType {
                long numI;
                double numD;
                char car;
        } type;
} Container;

typedef struct {
        Container stack[MAX];
        int sp;
} STACK;

STACK *new_stack();

void push(STACK *s, Container container);

Container pop(STACK *s);