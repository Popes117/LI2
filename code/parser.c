#include "parser.h"
#include "operators.h"
#include <stdlib.h>
#include <ctype.h>
#include "type_changes.h"
#include <stdio.h>
#include <string.h>

#define _REST_ return rest;

#define _POPONE_   \
    Container x = pop(s); 

#define _POPTWO_          \
    Container x = pop(s); \
    Container y = pop(s); 

#define _POPTHREE         \
    Container x = pop(s); \
    Container y = pop(s); \
    Container z = pop(s); 

char *alloccStr(){
    return malloc(12000*sizeof(char));
}

char *readString(char *rest, char *str)
{
    size_t i = 0;
    for (size_t n = 0; rest[0] != '"'; i++, n++)
    {
        str[i] = rest[0];
        rest++;
    }
    str[i] = '\0';
    return rest + 1;
}

char *parseString(STACK *s, char *token, char *rest)
{
    ++token;
    Container z;
    z.label = 4;
    z.str = malloc(15000*sizeof(char));
    if (token[0]!= '\0' &&token[strlen(token)-1] == '"')
    {
        size_t i = 0;
        for (; token[i] != '"'; i++)
        {
            z.str[i] = token[i];
        }
        z.str[i] = '\0';
        push(s, z);
    }
    else
    {
        rest = readString(rest, z.str);
        token = strcat(token, " ");
        z.str = strcat(token, z.str);
        push(s, z);
    }
    return rest;
}

char *parse_block(STACK *s, char *rest)
{
    Container z;
    z.label = 6;
    z.str = malloc(120 * sizeof(char));
    size_t i = 1;
    z.str[0] = ' ';
    for (; rest[0] != '}'; i++)
    {
        z.str[i] = rest[0];
        rest++;
    }
    z.str[i] = '\0';
    rest++;
    push(s,z);
    return rest;
}

char *handle6(STACK *s, char *token, char *rest, Container *vars)
{
    Container container;
    switch (hash_function(token))
    {
    case 76:
        nextLine(s);
        _REST_
    case 84:
        readFile(s);
        _REST_
    case 91:
        rest = parse_block(s,rest);
        _REST_
    case 92:
        ou_bit(s);
        _REST_
    case 94:
        not_bit(s,vars);
        _REST_
    default:
        container.label = 3;
        container.type.car = *token;
        push(s, container);
        _REST_
    }
}

char *handle3(STACK *s, char *token, char *rest, Container *vars)
{
    switch (hash_function(token))
    {
    case 35:
        strtoke2(s);
        _REST_
    case 59:
        rest = parseArray(s,rest,vars);
        _REST_
    case 60:
        switch2(s);
        _REST_
    case 62:
        xor_bit(s);
        _REST_
    case 63:
        duplica(s);
        _REST_
    case 69:
        if(token[1]=='<') eMenor(s);
        if(token[1]=='>') eMaior(s);
        if(token[1]=='&') eAnd(s);
        if(token[1]=='|') eOr(s);
        _REST_
    case 67:
        ConvChar(s);
        _REST_
    case 70:
        ConvFloat(s);
        _REST_
    case 73:
        ConvInt(s);
        _REST_
    default:
        rest = handle6(s,token,rest,vars);
        _REST_
}
}
char *handle4(STACK *s, char *token, char *rest, Container *vars)
{
    int x;
    switch (hash_function(token))
    {
        case 30:
            maior(s);
            _REST_
        case 29:
            igual(s);
            _REST_
        case 31:
            ifelse(s);
            _REST_
        case 32:
            roda3(s);
            _REST_
        case 33:
            x = token[0];
            push(s, vars[x - 65]);
            _REST_
        case 34:
            strtoke(s);
            _REST_
        default:
            rest = handle3(s,token,rest,vars);
            _REST_
    }
}

char *handle2(STACK *s, char *token, char *rest, Container *vars)
{
    switch (hash_function(token))
    {
        case 11:
            add(s);
            _REST_
        case 12:
            tamanho(s,vars);
            _REST_
        case 13:
            sub(s);
            _REST_
        case 15:
            division(s);
            _REST_
        case 26:
            coloca(s, vars, token);
            _REST_
        case 27:
            pop(s);
            _REST_
        case 28:
            menor(s);
            _REST_
        default:
            rest = handle4(s,token,rest,vars);
            _REST_
    }
}

char *handle5(STACK *s, char *token, char *rest, Container *vars)
{
    switch (hash_function(token))
    {
    case 6:
        e_bit(s);
        _REST_
    case 8:
        sub1(s);
        _REST_
    case 9:
        add1(s);
        _REST_
    case 10:
        mult(s,vars);
        _REST_
    default:
        rest = handle2(s,token,rest,vars);
        _REST_
    }
}

char *handle(STACK *s, char *token, char *rest, Container *vars)
{
    switch (hash_function(token))
    {
    case 0:
        if (isFloat(token))
        {
            double x;
            sscanf(token, "%lf", &x);
            Container container;
            container.label = 1;
            container.type.numD = x;
            push(s, container);
        }
        else
        {
            long x;
            sscanf(token, "%li", &x);
            Container container;
            container.label = 2;
            container.type.numI = x;
            push(s, container);
        } 
        _REST_
    case 1:
        nots(s);
        _REST_
    case 2:
        rest = parseString(s, token, rest);
        _REST_
    case 3:
        expo(s);
        _REST_
    case 4:
        copy(s,vars);
        _REST_
    case 5:
        mod(s,vars);
        _REST_
    default:
        rest = handle5(s,token,rest,vars);
        _REST_
    } 
    /* if (strcmp(token, "-") == 0)
        sub(s);
    else if (strcmp(token, "+") == 0)
        add(s);
    else if (strcmp(token, "*") == 0)
        mult(s,vars);
    else if (strcmp(token, "/") == 0)
        division(s);
    else if (strcmp(token, "(") == 0)
        sub1(s);
    else if (strcmp(token, ")") == 0)
        add1(s);
    else if (strcmp(token, "%") == 0)
        mod(s,vars);
    else if (strcmp(token, "#") == 0)
        expo(s);
    else if (strcmp(token, "&") == 0)
        e_bit(s);
    else if (strcmp(token, "|") == 0)
        ou_bit(s);
    else if (strcmp(token, "^") == 0)
        xor_bit(s);
    else if (strcmp(token, "~") == 0)
        not_bit(s,vars);
    else if (strcmp(token, "_") == 0)
        {
           Container z = duplica(s);
            push(s,z);
        }
    else if (strcmp(token, ";") == 0)
        pop(s);
    else if (strcmp(token, "\\") == 0)
        switch2(s);
    else if (strcmp(token, "@") == 0)
        roda3(s);
    else if (strcmp(token, "$") == 0)
        copy(s,vars);
    else if (strcmp(token, "l") == 0)
        nextLine(s);
    else if (strcmp(token, "w") == 0)
        truthy(s,vars);
    else if (strcmp(token, "t") == 0)
        readFile(s);
    else if (strcmp(token, "f") == 0)
        ConvFloat(s);
    else if (strcmp(token, "i") == 0)
        ConvInt(s);
    else if (strcmp(token, "c") == 0)
        ConvChar(s);
    else if (strcmp(token, "?") == 0)
        ifelse(s);
    else if (strcmp(token, "=") == 0)
        igual(s);
    else if (strcmp(token, "<") == 0)
        menor(s);
    else if (strcmp(token, ">") == 0)
        maior(s);
    else if (strcmp(token, "e&") == 0)
        eAnd(s);
    else if (strcmp(token, "e|") == 0)
        eOr(s);
    else if (strcmp(token, "e>") == 0)
        eMaior(s);
    else if (strcmp(token, "e<") == 0)
        eMenor(s);
    else if (strcmp(token, "S/") == 0)
        strtoke(s);
    else if (strcmp(token, "N/") == 0)
        strtoke2(s);
    else if (strcmp(token, "{") == 0)
        rest = parse_block(s,rest);
    else if (token[0] == '!')
        nots(s);
    else if (token[0] >= 65 && token[0] < 91)
    {
        int x = token[0];
        push(s, vars[x - 65]);
    }
     else if (token[0] == ':')
        coloca(s, vars, token); 
    else if (token[0] == '\"')
        rest = parseString(s, token, rest);
    else if (strcmp(token, "[") == 0)
        rest = parseArray(s, rest, vars);
    else if (token[0] == ',')
        tamanho(s,vars);
    else
    {
        Container container;
        container.label = 3;
        container.type.car = *token;
        push(s, container);
    }
    return rest; */
}


char *parseArray(STACK *s, char *rest, Container *vars)
{
    char *token;
    STACK *arr = new_stack();
    while (strcmp((token = strtok_r(rest, " \n", &rest)), "]") != 0)
    {
        rest = handle(arr, token, rest, vars);
    }
    Container z;
    z.label = 5;
    z.a = arr;
    push(s, z);
    return rest;
}

void parser(STACK *s, char *rest, Container *vars)
{
    
    char *token;
    while ((token = strtok_r(rest, " \n", &rest)) != NULL)
    {
        rest = handle(s, token, rest, vars);
    }
}


int isFloat(char *token)
{
    for (size_t i = 0; token[i] != '\0'; i++)
    {
        if (token[i] == '.')
            return 1;
    }
    return 0;
}