#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include <math.h>
#include "stack.h"

int sub(STACK *s, char token[])
{
    if (strcmp(token, "-") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,x-y);
        return 1;
    }
    return 0;
}

int add(STACK *s, char token[]){
    if (strcmp(token, "+") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,x+y);
        return 1;
    }
    return 0;
}

int mult(STACK *s, char token[])
{
    if (strcmp(token, "*") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,(x*y));
        return 1;
    }
    return 0;
}

int division(STACK *s, char token[])
{
    if (strcmp(token, "/") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,x/y);
        return 1;
    }
    return 0;
}

int add1(STACK *s, char token[])
{
    if (strcmp(token, ")") == 0)
    {
        int x = pop(s);
        push(s,x+1);
        return 1;
    }
    return 0;
}

int sub1(STACK *s, char token[])
{if (strcmp(token, "(") == 0)
    {
        int x = pop(s);
        push(s,x-1);
        return 1;
    }
    return 0;
}

int mod(STACK *s, char token[])
{if (strcmp(token, "%") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,x%y);
        return 1;
    }
    return 0;
}

int expo(STACK *s, char token[])
{if (strcmp(token, "#") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,pow(x,y));
        return 1;
    }
    return 0;
}

int e_bit(STACK *s, char token[]);

int ou_bit(STACK *s, char token[]);

int xou_bit(STACK *s, char token[]);

int not_bit(STACK *s, char token[]);

int value(STACK *s, char token[]){
    int val;
    sscanf(token,"%d",&val);
        push(s,val);
        return 1;
}

void handle(STACK *s, char token[]){
    add(s,token) || sub(s,token) || mult(s,token) || division(s,token) || mod(s,token) || add1(s,token) || sub1(s,token) || expo(s,token) || value(s,token); 
}
