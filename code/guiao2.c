#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>
#include "parser.h"
#include "macro.h"

void duplica(STACK *s)
{
    Container x = pop(s);
    push(s,x);
    push(s,x);
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

   Container x = pop(s);
   Container y = pop(s);
   Container z = pop(s);
   push(s,y); 
   push(s,x); 
   push(s,z);

}

void copy_help(STACK *min,Container x, Container y, Container *vars){
    for (int i = 1; i <= y.a->sp;i++)
        {
            push(min,y.a->stack[i]);
            char *helper = strdup(x.str);
            parser(min,helper,vars);
            free(helper);
        }
}

void copy(STACK *s, Container *vars){

    Container x = pop(s);
    if (_Xlabel_ == 6)
    {
        Container y = pop(s);
        STACK *min = new_stack();
        if (_Xlabel_ == 6)
        {
            copy_help(min,x,y,vars);
            int i = 1;
            while (i <= min->sp)
            {
                for (int j = 1; j <= min->sp - i; j++){
                   if (min->stack[j].type.numI > min->stack[j+1].type.numI){
                        Container z = min->stack[j];
                        min->stack[j] = min->stack[j+1];
                        min->stack[j+1] = z;
                        z = y.a->stack[j];
                        y.a->stack[j] = y.a->stack[j+1];
                        y.a->stack[j+1] = z;
                    }
            }
                i++;   
            }
        }
        push(s,y);
    }
    else 
    {
        Container y = s->stack[s->sp - x.type.numI];
        push(s,y);
    }
}

void nextLine(STACK *s){
    char linha[BUFSIZ];
    if (fgets(linha,BUFSIZ,stdin) != NULL)
    {
        Container z;
        z.label = 4;
        z.str = linha;
        push(s,z);
    }
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