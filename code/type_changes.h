#include "stack.h"
#include "parser.h"
#pragma once

Container toInt(Container container);

Container toDouble(Container container);

Container toChar(Container container);

void fill(Container *vars);

int comparaCont( Container x, Container y);

int isZero(Container container);