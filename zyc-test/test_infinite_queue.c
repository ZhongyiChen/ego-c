#include "../data-structures/queue/infinite_queue.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

int main() {
  QueueConstructor* queue = createInfiniteQueue(5);

  printf("Is queue empty? ");
  if (isEmptyQueue(queue)) {
    printf("Yes!\n");
  } else {
    printf("No!\n");
  }

  printf("Enqueue 5: ");
  enqueue(queue, 5);
  printQueue(queue);

  printf("Enqueue 6: ");
  enqueue(queue, 6);
  printQueue(queue);

  printf("Enqueue 7: ");
  enqueue(queue, 7);
  printQueue(queue);

  printf("The length of queue: %d\n", sizeOfQueue(queue));

  printf("Enqueue 8: ");
  enqueue(queue, 8);
  printQueue(queue);

  printf("Enqueue 9: ");
  enqueue(queue, 9);
  printQueue(queue);

  printf("Is queue empty? ");
  if (isEmptyQueue(queue)) {
    printf("Yes!\n");
  } else {
    printf("No!\n");
  }

  printf("Enqueue 4: ");
  enqueue(queue, 4);
  printQueue(queue);

  printf("After dequeue: ");
  int deData = dequeue(queue);
  printQueue(queue);
  printf("The data dequeued: %d\n", deData);

  printf("Dequeue again: ");
  deData = dequeue(queue);
  printQueue(queue);
  printf("The data dequeued: %d\n", deData);

  printf("Dequeue more: ");
  deData = dequeue(queue);
  printQueue(queue);
  printf("The data dequeued: %d\n", deData);

  printf("Enqueue 3: ");
  enqueue(queue, 3);
  printQueue(queue);

  printf("Enqueue 2: ");
  enqueue(queue, 2);
  printQueue(queue);

  printf("The length of queue: %d\n", sizeOfQueue(queue));

  printf("Is queue empty? ");
  if (isEmptyQueue(queue)) {
    printf("Yes!\n");
  } else {
    printf("No!\n");
  }

  printf("After dequeue: ");
  deData = dequeue(queue);
  printQueue(queue);
  printf("The data dequeued: %d\n", deData);

  printf("After dequeue: ");
  deData = dequeue(queue);
  printQueue(queue);
  printf("The data dequeued: %d\n", deData);

  printf("After dequeue: ");
  deData = dequeue(queue);
  printQueue(queue);
  printf("The data dequeued: %d\n", deData);

  printf("After dequeue: ");
  deData = dequeue(queue);
  printQueue(queue);
  printf("The data dequeued: %d\n", deData);

  printf("After dequeue: ");
  deData = dequeue(queue);
  printQueue(queue);
  printf("The data dequeued: %d\n", deData);

  printf("The length of queue: %d\n", sizeOfQueue(queue));

  printf("After dequeue: ");
  deData = dequeue(queue);
  printQueue(queue);
  printf("The data dequeued: %d\n", deData);

  destoryQueue(queue);

  return 0;
}