#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>
#include "parser.h"
#include "type_changes.h"

void readFile(STACK *s)
{
    char linha[BUFSIZ];
    Container z;
    z.label = 4;
    z.str = alloccStr();
    z.str[0] = '\0';
    while (fgets(linha,BUFSIZ,stdin) != NULL)
    {
        z.str = strcat(z.str,linha);
    }
    push(s,z);
}

void arrcat(STACK *s, STACK *aux) {
    for (size_t i = 1; i <= aux->sp; i++)
    {  
        push(s,aux->stack[i]);
        if(aux->stack[i].label == 4) free(aux->stack[i].str);
    }
    free(aux->stack);
    free(aux);
}

