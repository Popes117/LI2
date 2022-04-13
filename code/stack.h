#define MAX 1000

typedef struct {
        int stack[MAX];
        int sp;
} STACK;

STACK *new_stack();

void push(STACK *s, int elem);

int pop(STACK *s);