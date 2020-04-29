/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * 
 */

#include <malloc.h>
#include "../../zyc-libs/null.h"
#include "infinite_queue.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

/**
 * Get the current size of a queue.
 * @param queue {QueueConstructor*} The queue
 * @return {int} the size
 */
int sizeOfQueue(QueueConstructor* queue) {
  return queue->length;
}

/**
 * Judge the queue is empty or not.
 * @param queue {QueueConstructor*} The queue
 * @return {int} 0 means not empty, 1 means empty
 */
int isEmptyQueue(QueueConstructor* queue) {
  return (0 == queue->length);
}

/**
 * Enqueue a value into the queue.
 * @param queue {QueueConstructor*} The queue
 * @param data {int} The data needed to be stored
 * @return {int} 0 means failure, 1 means success
 */
int enqueue(QueueConstructor* queue, int data){
  return pushToList((LinkedRoot*)queue, data);
}

/**
 * Dequeue a value from the queue.
 * @param queue {QueueConstructor*} The queue
 * @return {int} The fetched value
 */
int dequeue(QueueConstructor* queue){
  if (isEmptyQueue(queue)) {
    printf("Error: You cannot dequeue a value from an empty queue!\n");
    return -9999;
  }
  return shiftFromList((LinkedRoot*)queue);
}

/**
 * Create a new infinite queue.
 * @return {QueueConstructor*} The new queue
 */
QueueConstructor* createInfiniteQueue(){
  return (QueueConstructor*)createDoublyLinkedList();
}

/**
 * Destory the queue.
 * @param queue {QueueConstructor*} The queue
 */
void destoryQueue(QueueConstructor* queue){
  destroyList((LinkedRoot*)queue);
}

/**
 * Print the content of the queue.
 * @param queue {QueueConstructor*} The queue
 */
void printQueue(QueueConstructor* queue){
  if (isEmptyQueue(queue)) {
    printf("\n");
    return;
  }
  printList((LinkedRoot*)queue);
}