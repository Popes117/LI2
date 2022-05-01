#include <stdlib.h> 
#include <ctype.h>
#include "stack.h"
#pragma once

void parser(STACK *s, char *line);

int isFloat(char *token);