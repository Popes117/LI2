#include "macro.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>

void truthy(STACK *s){
    Container x = pop(s);
    Container y = pop(s);
    STACK *min = ministack();
    while(y.a->stack[y.a->sp] != 0)
    {
        for (int i = 1; i <= y.a->sp;i++)
        {
            push(min,y.a->stack[i]);
            char *helper = strdup(x.str);
            parser(min,helper);
            y.a->stack[i] = min->stack[1];
            pop(min);
            free(helper);
        }
    }
}