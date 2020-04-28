#ifndef __STACK_INFINITESTACK_H
#define __STACK_INFINITESTACK_H

#include "../linked-list/singly_linked_list.h"

typedef LinkedRoot StackConstructor;

int sizeOfStack(StackConstructor* stack);

int isEmptyStack(StackConstructor* stack);

int pushToStack(StackConstructor* stack, int data);

int popFromStack(StackConstructor* stack);

StackConstructor* createInfiniteStack();

void destoryStack(StackConstructor* stack);

void printStack(StackConstructor* stack);

#endif