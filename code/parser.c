#include "parser.h"
#include "operators.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


void parser(char *line, STACK *s){
    char *rest = line;
    char *token;
    while ((token = strtok_r(rest," \n",&rest) )!= NULL)
    {
        if (isdigit(*token))
        {
            if(isFloat(token)){
                double x;
                sscanf(token,"%lf",&x);
                Container container;
                container.label = 1;
                container.type.numD = x;
                push(s,container);
            }
            else{
                long x;
                sscanf(token,"%li",&x);
                Container container;
                container.label = 2;
                container.type.numI = x;
                push(s,container);
            }
        }
        else if (strcmp(token, "-") == 0) sub(s);
        else if (strcmp(token, "+") == 0) add(s);
        else if (strcmp(token, "*") == 0) mult(s);
        else if (strcmp(token, "/") == 0) division(s);
        else if (strcmp(token, ")") == 0) add1(s);
        else if (strcmp(token, "(") == 0) sub1(s);
        else if (strcmp(token, "%") == 0) mod(s);
       /*  else if (strcmp(token, "#") == 0) expo(s);
        else if (strcmp(token, "&") == 0) e_bit(s);
        else if (strcmp(token, "|") == 0) ou_bit(s);
        else if (strcmp(token, "^") == 0) xor_bit(s);
        else if (strcmp(token, "~") == 0) not_bit(s);*/
        else if (strcmp(token, "_") == 0) duplica(s);
        else if (strcmp(token, ";") == 0) popes(s);
        else if (strcmp(token, "\\") == 0) switch2(s);
        else if (strcmp(token, "@") == 0) roda3(s);
        else if (strcmp(token, "$") == 0) copy(s);
        else{
           Container container;
           container.label = 3;
           container.type.car = *token;
           push(s,container);
       }
    }
}

int isFloat(char *token){
    for (size_t i = 0; token[i] != '\0'; i++)
    {
        if (token[i] == '.') return 1;
    }
    return 0;
}