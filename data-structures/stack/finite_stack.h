#ifndef __STACK_FINITESTACK_H
#define __STACK_FINITESTACK_H

typedef struct {
  int* pool;
  int total_size;         // Total size of the pool
  int cursor;             // The top of the pool
} FiniteStack;

int sizeOfStack(FiniteStack* stack);

int isFullStack(FiniteStack* stack);

int isEmptyStack(FiniteStack* stack);

int pushStack(FiniteStack* stack, int data);

int popStack(FiniteStack* stack);

FiniteStack* createFiniteStack(int total_size);

void destoryFiniteStack(FiniteStack* stack);

void printStack(FiniteStack* stack);

#endif