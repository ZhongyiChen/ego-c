/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * This piece of code can produce an finite stack via the size you indicate.
 * Once the stack was produced, its size could not be changed anymore.
 * The interfaces are including:
 */

#include <stdio.h>
#include <malloc.h>
#include "../../zyc-libs/null.h"
#include "finite_stack.h"

/**
 * Get the current size of a stack.
 * @param stack {StackConstructor*} The stack
 * @return {int} the size
 */
int sizeOfStack(StackConstructor* stack) {
  return stack->cursor + 1;
}

/**
 * Judge the stack is full or not.
 * @param stack {StackConstructor*} The stack
 * @return {int} 0 means not full, 1 means full
 */
int isFullStack(StackConstructor* stack) {
  return (sizeOfStack(stack) == stack->total_size);
}

/**
 * Judge the stack is empty or not.
 * @param stack {StackConstructor*} The stack
 * @return {int} 0 means not empty, 1 means empty
 */
int isEmptyStack(StackConstructor* stack) {
  return (-1 == stack->cursor);
}

/**
 * Store a value into the stack.
 * @param stack {StackConstructor*} The stack
 * @param data {int} The data needed to be stored
 * @return {int} 0 means failure, 1 means success
 */
int pushToStack(StackConstructor* stack, int data) {
  if (isFullStack(stack)) {
    printf("Error: Push failed! The stack was already full!\n");
    return 0;
  }
  stack->bucket[++stack->cursor] = data;
  return 1;
}

/**
 * Fetch a value from the stack.
 * @param stack {StackConstructor*} The stack
 * @return {int} The fetched value
 */
int popFromStack(StackConstructor* stack) {
  if (isEmptyStack(stack)) {
    printf("Error: You cannot pop a value from an empty stack!\n");
    return -9999;
  }
  return stack->bucket[stack->cursor--];
}

/**
 * Create a new stack with total size.
 * @param total_size {int} The total size of the new stack
 * @return {StackConstructor*} The new stack
 */
StackConstructor* createFiniteStack(int total_size) {
  if (total_size <= 0) {
    printf("Error: The initial size must bigger than zero!\n");
    return NULL;
  }
  StackConstructor* stack = (StackConstructor*)malloc(sizeof(StackConstructor));
  stack->bucket = (int*)malloc(sizeof(int) * total_size);
  stack->total_size = total_size;
  stack->cursor = -1;
  return stack;
}

/**
 * Destory the stack.
 * @param stack {StackConstructor*} The stack
 */
void destoryStack(StackConstructor* stack) {
  free(stack->bucket);
  free(stack);
}

/**
 * Print the content of the stack.
 * @param stack {StackConstructor*} The stack
 */
void printStack(StackConstructor* stack) {
  if (isEmptyStack(stack)) {
    return;
  }
  int len = sizeOfStack(stack);
  int i = 0;
  for (; i < len; i++) {
    printf("%d ", stack->bucket[i]);
  }
  printf("\n");
}