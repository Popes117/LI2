#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "parser.h"

int main(){
    STACK *s = new_stack();
    char line[BUFSIZ];
    if (fgets(line,BUFSIZ,stdin) != NULL)
    {
        parser(s,line);
        printer(s);
        printf("\n");
        free(s->stack);
        free(s);
    }
}
