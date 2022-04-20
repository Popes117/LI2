#include <stdlib.h> 
#include <ctype.h>
#include "stack.h"
#pragma once

void parser(char *line, STACK *s);

int isFloat(char *token);