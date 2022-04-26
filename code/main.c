#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "parser.h"

int main(){
    STACK *s = (STACK *) malloc(sizeof(STACK));
    parser(s);
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
        else{
            printf("%g",z.type.numD);
        }
    }
printf("\n");
}


