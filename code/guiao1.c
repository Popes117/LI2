#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>


int sub(STACK *s) {
    int x = pop(s);
    int y = pop(s);
    push(s,y-x);
}

int add(STACK *s) {
    int x = pop(s);
    int y = pop(s);
    push(s,x+y);
}

int mult(STACK *s) {
    int x = pop(s);
    int y = pop(s);
    push(s,(y*x));
}

int division(STACK *s) {
    int x = pop(s);
    int y = pop(s);
    push(s,y/x);
}

int add1(STACK *s) {
    int x = pop(s);
    push(s,x+1);
}

int sub1(STACK *s) {
    int x = pop(s);
    push(s,x-1);
}

int mod(STACK *s) {
    int x = pop(s);
    int y = pop(s);
    push(s,y%x);
}

int expo(STACK *s) {
    int x = pop(s);
    int y = pop(s);
    push(s,pow(y,x));
}

int e_bit(STACK *s) {
    int x = pop(s);
    int y = pop(s);
    push(s,y&x);
}

int ou_bit(STACK *s) {
    int x = pop(s);
    int y = pop(s);
    push(s,y|x);
}

int xor_bit(STACK *s) {
    int x = pop(s);
    int y = pop(s);
    push(s,y^x);
}

int not_bit(STACK *s) {
    int x = pop(s);
    push(s,~x);
}




