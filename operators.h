#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int handle(STACK *s, char *token);

int sub(STACK *s, char *token);

int add(STACK *s, char *token);

int mult(STACK *s, char *token);

int division(STACK *s, char *token);

int add1(STACK *s, char *token);

int sub1(STACK *s, char *token);

int mod(STACK *s, char *token);

int expo(STACK *s, char *token);

int e_bit(STACK *s, char *token);

int ou_bit(STACK *s, char *token);

int xou_bit(STACK *s, char *token);

int not_bit(STACK *s, char *token);

int value(STACK *s, char *token);