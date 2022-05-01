#define MAX 1000
#pragma once


typedef union HoldType {
                long numI;
                double numD;
                char car;
        } Type;

typedef struct stack STACK;
typedef struct Container{
        int label; 
        /* 
           1 - Double
           2 - Long
           3 - Char
           4 - String
           5 - Array
        */
       union{
                char *str;
                STACK *a;
                Type type;
       };
} Container;

struct stack {
        int size;
        Container *stack;
        int sp;
};


STACK* new_stack();

STACK* reallocSTACK(STACK *s);

void push(STACK *s, Container container);

Container pop(STACK *s);