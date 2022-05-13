#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "parser.h"

int main(){
    STACK *s = new_stack();
    char line[15000];
    if (fgets(line,15000,stdin) != NULL)
    {
        parser(s,line,1);
        printer(s);
        printf("\n");
        free(s->stack);
        free(s);
    }
}
