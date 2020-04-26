#include "../data-structures/stack/finite_stack.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

int main() {
  FiniteStack* stack = createFiniteStack(5);

  printf("Is stack empty? ");
  if (isEmptyStack(stack)) {
    printf("Yes!\n");
  } else {
    printf("No!\n");
  }

  printf("Is stack full? ");
  if (isFullStack(stack)) {
    printf("Yes!\n");
  } else {
    printf("No!\n");
  }

  printf("Push 3 to stack: \n");
  pushStack(stack, 3);
  printStack(stack);

  printf("Push 4 to stack: \n");
  pushStack(stack, 4);
  printStack(stack);

  printf("Push 5 to stack: \n");
  pushStack(stack, 5);
  printStack(stack);

  printf("Push 6 to stack: \n");
  pushStack(stack, 6);
  printStack(stack);

  printf("Push 7 to stack: \n");
  pushStack(stack, 7);
  printStack(stack);

  printf("Is stack empty? ");
  if (isEmptyStack(stack)) {
    printf("Yes!\n");
  } else {
    printf("No!\n");
  }

  printf("Is stack full? ");
  if (isFullStack(stack)) {
    printf("Yes!\n");
  } else {
    printf("No!\n");
  }

  printf("Push 8 to stack: \n");
  pushStack(stack, 8);
  printStack(stack);

  printf("Pop from stack: \n");
  popStack(stack);
  printStack(stack);

  printf("Pop to stack: \n");
  popStack(stack);
  printStack(stack);

  printf("The current size of stack: %d\n", sizeOfStack(stack));

  return 0;
}