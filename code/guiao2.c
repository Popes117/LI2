#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>
#include "parser.h"

void duplica(STACK *s)
{
        Container x = pop(s);

        push(s,x);
        push(s,x);
       
       
}

void popes(STACK *s)
{
    {
        pop(s);
        Container y = pop(s);
        Container z = pop(s);

        push(s,z);
        push(s,y);
    }

}

void switch2(STACK *s)
{
        Container x = pop(s);
        Container y = pop(s);
         
        push(s,x);
        push(s,y);

}


void roda3(STACK *s)
{
    {
        Container x = pop(s);
        Container y = pop(s);
        Container z = pop(s);

        push(s,y); 
        push(s,x); 
        push(s,z);
    }
}

void copy(STACK *s){

    int x = pop(s).type.numI;
    Container y = s->stack[s->sp - x];
    push(s,y);

}

void nextLine(STACK *s, char *line){
    parser(s,line);
}

void ConvChar(STACK *s)
{
   Container x = pop(s);
   push(s,toChar(x)); 
}
void ConvInt(STACK *s)
{
   Container x = pop(s);
   push(s,toInt(x)); 
}
void ConvFloat(STACK *s)
{
   Container x = pop(s);
   push(s,toDouble(x)); 
}