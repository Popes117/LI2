#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "parser.h"
#include "type_changes.h"

int main(){
    STACK *s = new_stack();
    char line[15000];
    if (fgets(line,15000,stdin) != NULL)
    {
        Container vars[26];
        fill(vars);
        parser(s,line,vars);
        printer(s);
        printf("\n");
        free(s->stack);
        free(s);
    }
}
