/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * 
 */

#include <malloc.h>
#include "../../zyc-libs/null.h"
#include "circular_queue.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

/**
 * Get the current size of a queue.
 * @param queue {QueueConstructor*} The queue
 * @return {int} the size
 */
int sizeOfQueue(QueueConstructor* queue) {
  if (-1 == queue->head) {
    return 0;
  }
  if (queue->tail == queue->head) {
    return 1;
  }
  int d_value = queue->tail - queue->head + 1;
  if (queue->tail > queue->head) {
    return d_value;
  }
  return (queue->total_size + d_value);
}

/**
 * Judge the queue is full or not.
 * @param queue {QueueConstructor*} The queue
 * @return {int} 0 means not full, 1 means full
 */
int isFullQueue(QueueConstructor* queue) {
  return (sizeOfQueue(queue) == queue->total_size);
}

/**
 * Judge the queue is empty or not.
 * @param queue {QueueConstructor*} The queue
 * @return {int} 0 means not empty, 1 means empty
 */
int isEmptyQueue(QueueConstructor* queue) {
  return (-1 == queue->head);
}

/**
 * Enqueue a value into the queue.
 * @param queue {QueueConstructor*} The queue
 * @param data {int} The data needed to be stored
 * @return {int} 0 means failure, 1 means success
 */
int enqueue(QueueConstructor* queue, int data) {
  if (isFullQueue(queue)) {
    printf("Error: Enqueue failed! The queue was already full!\n");
    return 0;
  }
  if (isEmptyQueue(queue)) {
    queue->tail = queue->head = 0;
  } else {
    queue->tail = (queue->tail + 1) % queue->total_size;
  }
  queue->pool[queue->tail] = data;
  return 1;
}

/**
 * Dequeue a value from the queue.
 * @param queue {QueueConstructor*} The queue
 * @return {int} The fetched value
 */
int dequeue(QueueConstructor* queue) {
  if (isEmptyQueue(queue)) {
    printf("Error: You cannot dequeue a value from an empty queue!\n");
    return -9999;
  }
  int data = queue->pool[queue->head];
  if (queue->tail == queue->head) {
    queue->tail = queue->head = -1;
  } else {
    queue->head = (queue->head + 1) % queue->total_size;
  }
  return data;
}

/**
 * Create a new queue with total size.
 * @param total_size {int} The total size of the new queue
 * @return {QueueConstructor*} The new queue
 */
QueueConstructor* createCircularQueue(int total_size) {
  if (total_size <= 0) {
    printf("Error: The initial size must bigger than zero!\n");
    return NULL;
  }
  QueueConstructor* queue = (QueueConstructor*)malloc(sizeof(QueueConstructor));
  queue->pool = (int*)malloc(sizeof(int) * total_size);
  queue->total_size = total_size;
  queue->head = -1;
  queue->tail = -1;
  return queue;
}

/**
 * Destory the queue.
 * @param queue {QueueConstructor*} The queue
 */
void destoryQueue(QueueConstructor* queue) {
  free(queue->pool);
  free(queue);
}

/**
 * Print the content of the queue.
 * @param queue {QueueConstructor*} The queue
 */
void printQueue(QueueConstructor* queue) {
  if (isEmptyQueue(queue)) {
    printf("\n");
    return;
  }
  int cursor = queue->head;
  for (; cursor != queue->tail;) {
    printf("%d ", queue->pool[cursor]);
    cursor = (cursor + 1) % queue->total_size;
  }
  printf("%d\n", queue->pool[cursor]);
}