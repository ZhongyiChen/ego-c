/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * This piece of code can produce an finite stack via the size you indicate.
 * Once the stack was produced, its size could not be changed anymore.
 * The interfaces are including:
 *            pushStack() -------------------- Store a value
 *            popStack() --------------------- Fetch a value
 *            sizeOfStack() -------------------- Get the current size
 *            isEmptyStack() ----------------- Judge the stack is empty or not
 *            isFullStack() ------------------ Judge the stack is full or not
 *            createFiniteStack() ------- Create a stack
 *            destoryFiniteStack() ------ Destory the stack
 *            printStack() -------------- Print the content of the stack
 */

#include <malloc.h>
#include "../../zyc-libs/null.h"
#include "finite_stack.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

/**
 * Get the current size of a stack.
 * @param stack {FiniteStack*} The stack
 * @return {int} the size
 */
int sizeOfStack(FiniteStack* stack) {
  return stack->cursor + 1;
}

/**
 * Judge the stack is full or not.
 * @param stack {FiniteStack*} The stack
 * @return {int} 0 means not full, 1 means full
 */
int isFullStack(FiniteStack* stack) {
  return (sizeOfStack(stack) == stack->total_size);
}

/**
 * Judge the stack is empty or not.
 * @param stack {FiniteStack*} The stack
 * @return {int} 0 means not empty, 1 means empty
 */
int isEmptyStack(FiniteStack* stack) {
  return (-1 == stack->cursor);
}

/**
 * Store a value into the stack.
 * @param stack {FiniteStack*} The stack
 * @return {int} 0 means failure, 1 means success
 */
int pushStack(FiniteStack* stack, int data) {
  if (isFullStack(stack)) {
    printf("Error: Push failed! The stack was already full!\n");
    return 0;
  }
  stack->pool[++stack->cursor] = data;
  return 1;
}

/**
 * Fetch a value from the stack.
 * @param stack {FiniteStack*} The stack
 * @return {int} The fetched value
 */
int popStack(FiniteStack* stack) {
  if (isEmptyStack(stack)) {
    printf("Error: You cannot pop a value from an empty stack!\n");
    return -9999;
  }
  return stack->pool[stack->cursor--];
}

/**
 * Create a new stack with total size.
 * @param total_size {int} The total size of the new stack
 * @return {FiniteStack*} The new stack
 */
FiniteStack* createFiniteStack(int total_size) {
  if (total_size <= 0) {
    printf("Error: The initial size must bigger than zero!\n");
    return NULL;
  }
  FiniteStack* stack = (FiniteStack*)malloc(sizeof(FiniteStack));
  stack->pool = (int*)malloc(sizeof(int) * total_size);
  stack->total_size = total_size;
  stack->cursor = -1;
  return stack;
}

/**
 * Destory the stack.
 * @param stack {FiniteStack*} The stack
 */
void destoryFiniteStack(FiniteStack* stack) {
  free(stack->pool);
  free(stack);
}

/**
 * Print the content of the stack.
 * @param stack {FiniteStack*} The stack
 */
void printStack(FiniteStack* stack) {
  if (isEmptyStack(stack)) {
    return;
  }
  int len = sizeOfStack(stack);
  int i = 0;
  for (; i < len; i++) {
    printf("%d ", stack->pool[i]);
  }
  printf("\n");
}