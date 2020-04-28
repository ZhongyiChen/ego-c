#ifndef __STACK_FINITESTACK_H
#define __STACK_FINITESTACK_H

typedef struct {
  int* pool;
  int total_size;         // Total size of the pool
  int cursor;             // The top of the pool
} StackConstructor;

int sizeOfStack(StackConstructor* stack);

int isFullStack(StackConstructor* stack);

int isEmptyStack(StackConstructor* stack);

int pushToStack(StackConstructor* stack, int data);

int popFromStack(StackConstructor* stack);

StackConstructor* createFiniteStack(int total_size);

void destoryStack(StackConstructor* stack);

void printStack(StackConstructor* stack);

#endif