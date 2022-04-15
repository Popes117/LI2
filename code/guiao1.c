#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>

int handle(STACK *s, char *token){
    return add(s,token) || sub(s,token) || mult(s,token) || division(s,token) || mod(s,token) || add1(s,token) || sub1(s,token) || expo(s,token) || e_bit(s,token) || ou_bit(s,token) || xor_bit(s,token) || not_bit(s,token) || value(s,token);
    }

int sub(STACK *s, char *token)
{
    if (strcmp(token, "-") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,y-x);
        return 1;
    }
    return 0;
}

int add(STACK *s, char *token){
    if (strcmp(token, "+") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,x+y);
        return 1;
    }
    return 0;
}

int mult(STACK *s, char *token)
{
    if (strcmp(token, "*") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,(y*x));
        return 1;
    }
    return 0;
}

int division(STACK *s, char *token)
{
    if (strcmp(token, "/") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,y/x);
        return 1;
    }
    return 0;
}

int add1(STACK *s, char *token)
{
    if (strcmp(token, ")") == 0)
    {
        int x = pop(s);
        push(s,x+1);
        return 1;
    }
    return 0;
}

int sub1(STACK *s, char *token)
{if (strcmp(token, "(") == 0)
    {
        int x = pop(s);
        push(s,x-1);
        return 1;
    }
    return 0;
}

int mod(STACK *s, char *token)
{if (strcmp(token, "%") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,y%x);
        return 1;
    }
    return 0;
}

int expo(STACK *s, char *token)
{if (strcmp(token, "#") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,pow(y,x));
        return 1;
    }
    return 0;
}

int e_bit(STACK *s, char *token)
{
    if (strcmp(token, "&") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,y&x);
        return 1;
    }
    return 0;
}

int ou_bit(STACK *s, char *token)
{
    if (strcmp(token, "|") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,y|x);
        return 1;
    }
    return 0;
}

int xor_bit(STACK *s, char *token)
{
    if (strcmp(token, "^") == 0)
    {
        int x = pop(s);
        int y = pop(s);
        push(s,y^x);
        return 1;
    }
    return 0;
}

int not_bit(STACK *s, char *token)
{
    if (strcmp(token, "~") == 0)
    {
        int x = pop(s);
        push(s,~x);
        return 1;
    }
    return 0;
}

int value(STACK *s, char *token){
    int val;
    sscanf(token,"%d",&val);
        push(s,val);
        return 1;
}



