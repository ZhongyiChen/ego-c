/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * This piece of code can produce an finite stack with SinglyLinkedList.
 * Yes! You can push as many data as you want to the list, so long as
 * the memory is still enough.
 */

#include <malloc.h>
#include "../../zyc-libs/null.h"
#include "../linked-list/singly_linked_list.h"
#include "infinite_stack.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

/**
 * Get the current size of a stack.
 * @param stack {StackConstructor*} The stack
 * @return {int} the size
 */
int sizeOfStack(StackConstructor* stack) {
  return stack->length;
}

/**
 * Judge the stack is empty or not.
 * @param stack {StackConstructor*} The stack
 * @return {int} 0 means not empty, 1 means empty
 */
int isEmptyStack(StackConstructor* stack) {
  return (0 == stack->length);
}

/**
 * Store a value into the stack.
 * @param stack {StackConstructor*} The stack
 * @return {int} 0 means failure, 1 means success
 */
int pushStack(StackConstructor* stack, int data) {
  return pushToList((LinkedRoot*)stack, data);
}

/**
 * Fetch a value from the stack.
 * @param stack {StackConstructor*} The stack
 * @return {int} The fetched value
 */
int popStack(StackConstructor* stack) {
  if (isEmptyStack(stack)) {
    printf("Error: You cannot pop a value from an empty stack!\n");
    return -9999;
  }
  return popFromList((LinkedRoot*)stack);
}

/**
 * Create a new stack with total size.
 * @param total_size {int} The total size of the new stack
 * @return {StackConstructor*} The new stack
 */
StackConstructor* createInfiniteStack() {
  return (StackConstructor*)createSinglyLinkedList();
}

/**
 * Destory the stack.
 * @param stack {StackConstructor*} The stack
 */
void destoryStack(StackConstructor* stack) {
  destroyList((LinkedRoot*)stack);
}

/**
 * Print the content of the stack.
 * @param stack {StackConstructor*} The stack
 */
void printStack(StackConstructor* stack) {
  printList((LinkedRoot*)stack);
}