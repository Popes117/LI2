#include <stdlib.h> 
#include <ctype.h>
#include "stack.h"
#pragma once

char* alloccStr();

char* parseArray(STACK *s, char *rest,Container *vars);

void parser(STACK *s, char *line);

int isFloat(char *token);