#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operators.h"
#include "stack.h"
#include <math.h>
#include "parser.h"
#include "type_changes.h"
#include "macro.h"

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

void tamanho2(STACK *s, Container z){
    z.label = 2;
    int x = strlen(z.str);
    while (z.str[x]!='\0')
    {
        x++;
    }
    
    z.type.numI = x;
    push(s,z);
}

void compare(STACK *s, Container x, Container y, Container *vars){
    STACK *min = new_stack();
    if (_Xlabel_ == 6)
    {   
        for (int i = 1; i <= y.a->sp;i++)
        {
            push(min,y.a->stack[i]);
            char *helper = strdup(x.str);
            parser(min,helper,vars);
            free(helper);
        }
        int i = 1;
        int n = 1;
        while (i <= min->sp)
        {
            if (min->stack[i].type.numI == 1 || min->stack[i].type.numD == 1)
            {
                    y.a->stack[n] = y.a->stack[i];
                    n++;
            }
            i++;
        }
        y.a->sp = n-1;
    }
    free(min->stack);
    free(min);
    push(s,y);
}

void tamanho(STACK *s, Container *vars) {
    Container x = pop(s);
    Container y;
    y.label = 2;
    if(_Xlabel_ == 6)
    {
        compare(s,x,pop(s),vars);
    }
    if(_Xlabel_ == 2){
        Container z;
        z.label = 5;
        z.a = new_stack();
        for(int i = 0; i < x.type.numI; i++){
            y.type.numI = i;
            push(z.a,y);
        }
        push(s,z);
    }
    else if(_Xlabel_ == 5){
        STACK *aux = x.a;
        Container z;
        z.label = 2;
        z.type.numI = aux->sp;
        push(s,z);
    }
    else
     {   
        int n = strlen(x.str);
        y.type.numI = n;
        push(s,y);
    }
}

void arrcat(STACK *s, Container z) {
    if (z.label != 5)
    {
        push(s,z);
    }
    else {
        for (int i = 1; i <= z.a->sp; i++)
        {  
            push(s,z.a->stack[i]);
           /* if(z.a->stack[i].label == 4) free(z.a->stack[i].str); */
        }
    }
}

void strtoke(STACK *s)
{
    Container y = pop(s);
    Container z;
    z.label = 5;
    z.a = new_stack();
    char *token = alloca(BUFSIZ);
    while ((token = strtok_r(y.str," \n",&y.str))!= NULL)
    {
        Container aux;
        aux.label = 4;
        aux.str = token;
        push(z.a,aux);
    }
    push(s,z);
}

void strtoke2(STACK *s)
{
    Container y = pop(s);
    Container z;
    z.label = 5;
    z.a = new_stack();
    char *token = alloca(BUFSIZ);
    while ((token = strtok_r(y.str,"\n",&y.str))!= NULL)
    {
        Container aux;
        aux.label = 4;
        aux.str = token;
        push(z.a,aux);
    }
    push(s,z);
}


