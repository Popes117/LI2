#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>

void sub(STACK *s)
{
    
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    
    if (y.label == 3 || x.label == 3)
    {
        z.label = 3;
        z.type.car = toChar(y).type.car-toChar(x).type.car;
    }
    else if (y.label == 1 || x.label == 1)
    {
        z.label = 1;
        z.type.numD = toDouble(y).type.numD-toDouble(x).type.numD;
    }
    else{
        z.label = x.label;
        z.type.numI = y.type.numI-x.type.numI;
    }
    push(s,z);
}

void add(STACK *s){
    
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (y.label == 3 || x.label == 3)
    {
        z.label = 3;
        z.type.car = toChar(x).type.car+toChar(y).type.car;
    }
    else if (y.label == 1 || x.label == 1)
    {
        z.label = 1;
        z.type.numD = toDouble(x).type.numD+toDouble(y).type.numD;
    }
    else
    {
        z.label = x.label;
        z.type.numI = x.type.numI+y.type.numI;
    }
    push(s,z);
}

void mult(STACK *s)
{
    
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (y.label == 1 || x.label == 1)
    {
        z.label = 1;
        z.type.numD = toDouble(x).type.numD*toDouble(y).type.numD;
    }
    else
    {
        z.label = x.label;
        z.type.numI = x.type.numI*y.type.numI;
    }
    push(s,z);
}

void division(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    if (y.label == x.label && x.label == 2)
    {
        z.label = x.label;
        z.type.numI = x.type.numI/y.type.numI;
    }
    else
    {
        z.label = 1;
        z.type.numD = toDouble(y).type.numD/toDouble(x).type.numD;
    }
    push(s,z);
}

void add1(STACK *s)
{
    Container y = pop(s);
    if(y.label == 1)y.type.numD++;
    if(y.label == 2)y.type.numI++;
    else y.type.car++;
    push(s,y);
}

void sub1(STACK *s)
{
    Container y = pop(s);
    if(y.label == 1)y.type.numD--;
    if(y.label == 2)y.type.numI--;
    else y.type.car--;
    push(s,y);
}

void mod(STACK *s)
{
    Container x = pop(s);
    Container y = pop(s);
    Container z;
    z.label = 2;
    z.type.numI= toInt(y).type.numI%toInt(x).type.numI;
    push(s,z);
}
/*
void expo(STACK *s)
{

    push(s,pow(y,x));
}

void e_bit(STACK *s)
{
    
    push(s,y&x);
}

void ou_bit(STACK *s)
{
    
    push(s,y|x);
}

void xor_bit(STACK *s)
{
    
    push(s,y^x);
}

void not_bit(STACK *s)
{
    
    void x = pop(s);
    push(s,~x);
}
*/








