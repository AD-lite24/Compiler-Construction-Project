#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#include "linked_list_parser.h"


struct Stack{
    LL_ELE list;
};

typedef struct Stack Stack;
Stack* createStack();
void push(Stack* stack,Elements element);
Elements top(Stack* stack);
void pop(Stack* stack);
bool isEmpty(Stack* stack);

#endif