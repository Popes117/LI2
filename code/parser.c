#include "parser.h"
#include "operadores.h"
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
                sscanf(token,"%lu",&x);
                Container container;
                container.label = 2;
                container.type.numI = x;
                push(s,container);
            }
        }
        /*
            Coloca Aqui todas as funções, Ou seja, encadear else if para cada um dos símbolos(aka "+", "-", etc. e chamar as respetivas funções aqui.)
            Também temos de corrigir os parametros q vamos dar na função do guião 1
            Value e Handle não serão mais necessárias porque isso fará parte deste parser
        */
        if (strcmp(token, "-") == 0) sub(STACK *s);
        else if (strcmp(token, "+") == 0) add(STACK *s);
        else if (strcmp(token, "*") == 0) mult(STACK *s);
        else if (strcmp(token, "/") == 0) division(STACK *s);
        else if (strcmp(token, ")") == 0) add1(STACK *s);
        else if (strcmp(token, "(") == 0) sub1(STACK *s);
        else if (strcmp(token, "%") == 0) mod(STACK *s);
        else if (strcmp(token, "#") == 0) expo(STACK *s);
        else if (strcmp(token, "&") == 0) e_bit(STACK *s);
        else if (strcmp(token, "|") == 0) ou_bit(STACK *s);
        else if (strcmp(token, "^") == 0) xor_bit(STACK *s);
        else if (strcmp(token, "~") == 0) not_bit(STACK *s);
        
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
