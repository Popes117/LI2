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
            else if (z.label == 1){
                printf("%g",z.type.numD);
            }
            else if (z.label == 4){
                printf("%s",z.str);
                // Em vez do print dar free(z.str);
            }
        }
        printf("\n");
    }
}