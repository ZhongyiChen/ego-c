#ifndef __STACK_FINITESTACK_H
#define __STACK_FINITESTACK_H

typedef struct {
  int* bucket;
  int total_size;         // Total size of the bucket
  int cursor;             // The top of the bucket
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