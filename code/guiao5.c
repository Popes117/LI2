#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>

void fold(STACK *s, Container x, Container y){
    STACK *min = ministack();
    push(min,y.a->stack[1]);
    push(min,y.a->stack[2]);
    int i = 3;
    while (i <= y.a->sp)
    {
        char *helper = strdup(x.str);
        parser(min,helper);
        push(min,y.a->stack[i]);
        i++;
        free(helper);
    }
    Container z = min->stack[1];
    free(y.a->stack);
    free(y.a);
    push(s,z);
}
