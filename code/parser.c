#include "parser.h"
#include "operators.h"
#include <stdlib.h>
#include <ctype.h>
#include "type_changes.h"
#include <stdio.h>
#include <string.h>
 
char* alloccStr(){
    return malloc (8192*sizeof(char));
} 

char* readString(char *rest, char *str)
{
    size_t i = 0;
    for (size_t n = 0; rest[0] != '"';i++,n++)
    {
        str[i] = rest[0];
        rest++;
    }
    str[i] = '\0';
    return rest + 1;
}

char* parseString(STACK *s, char *token, char *rest){
    ++token;
    Container z;
    z.label = 4;
    z.str = malloc(BUFSIZ*sizeof(char));
    if (token[strlen(token)-1] == '"')
    {
        size_t i = 0;
        for (; token[i] != '"';i++)
        {
            z.str[i] = token[i];
        }
        z.str[i] = '\0';
        push(s,z);
    }
    else
    {
    rest = readString(rest,z.str);
    token = strcat(token," ");
    z.str = strcat(token, z.str);
    push(s,z);
    }
    return rest;
}


char* handle(STACK *s,char *token, char* rest, Container *vars){
    if (isdigit(*token) || (token[0] == '-' && isdigit(token[1])))
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
    else if (strcmp(token, "(") == 0) sub1(s); 
    else if (strcmp(token, ")") == 0) add1(s);
    else if (strcmp(token, "%") == 0) mod(s);
    else if (strcmp(token, "#") == 0) expo(s);
    else if (strcmp(token, "&") == 0) e_bit(s);
    else if (strcmp(token, "|") == 0) ou_bit(s);
    else if (strcmp(token, "^") == 0) xor_bit(s);
    else if (strcmp(token, "~") == 0) not_bit(s);
    else if (strcmp(token, "_") == 0) duplica(s);
    else if (strcmp(token, ";") == 0) popes(s);
    else if (strcmp(token, "\\") == 0) switch2(s);
    else if (strcmp(token, "@") == 0) roda3(s);
    else if (strcmp(token, "$") == 0) copy(s);
    else if (strcmp(token, "l") == 0) nextLine(s);
    else if (strcmp(token, "t") == 0) readFile(s);
    else if (strcmp(token, "f") == 0) ConvFloat(s);
    else if (strcmp(token, "i") == 0) ConvInt(s);
    else if (strcmp(token, "c") == 0) ConvChar(s);
    else if (strcmp(token, "?") == 0) ifelse(s);
    else if (strcmp(token, "=") == 0) igual(s);
    else if (strcmp(token, "<") == 0) menor(s);
    else if (strcmp(token, ">") == 0) maior(s);
    else if (strcmp(token, "e&") == 0) eAnd(s);
    else if (strcmp(token, "e|") == 0) eOr(s);
    else if (strcmp(token, "e>") == 0) eMaior(s);
    else if (strcmp(token, "e<") == 0) eMenor(s);
    else if (strcmp(token, "S/") == 0) strtoke(s);
    else if (strcmp(token, "N/") == 0) strtoke2(s);
    else if (token[0] == '!') nots(s);
    else if (token[0] >= 65 && token[0] <91) 
    {
        int x = token[0];
        push(s,vars[x-65]);
    } 
    else if (token[0] == ':') coloca(s,vars,token);
    else if (token[0] == '\"') rest = parseString(s,token,rest);
    else if (strcmp(token, "[") == 0) rest = parseArray(s,rest,vars);
    else if (token[0] == ',') tamanho(s);
    // else if (strcmp(token, ">")) maioR(s);
    else{
       Container container;
       container.label = 3;
       container.type.car = *token;
       push(s,container);
   }
   return rest;
}

char* parseArray(STACK *s, char *rest,Container *vars){
    char *token;
    STACK *arr = new_stack();
    while(strcmp((token = strtok_r(rest," \n",&rest)),"]")!=0){
        rest = handle(arr,token,rest,vars);
    }
    Container z;
    z.label = 5;
    z.a = arr;
    push(s,z);
    return rest;
}

void parser(STACK *s, char *rest){
    char *token;
    Container vars[26];
    fill(vars);
    while ((token = strtok_r(rest," \n",&rest))!= NULL)
    {
        rest = handle(s,token,rest,vars);   
    }
}

int isFloat(char *token){
    for (size_t i = 0; token[i] != '\0'; i++)
    {
        if (token[i] == '.') return 1;
    }
    return 0;
}