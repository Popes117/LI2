#include "operators.h"
#include <string.h>
#include <stdio.h>
#include "stack.h"

int main(){
    STACK *s = (STACK *) malloc(sizeof(STACK));
    char line[BUFSIZ];
    char *token;
    if (fgets(line,BUFSIZ,stdin) != NULL)
    {
        char *rest = line;
        while ((token = strtok_r(rest," \n",&rest) )!= NULL)
        {
           handle(s,token);
        }
        for (int i = 1; i <= s -> sp; i++)
    {
        int z = pop(s);
        printf("%d",z);
    }
    printf("\n");
    }
}