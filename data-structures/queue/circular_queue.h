#ifndef __QUEUE_CIRCULARQUEUE_H
#define __QUEUE_CIRCULARQUEUE_H

typedef struct {
  int* pool;
  int total_size;         // Total size of the pool
  int head;               // The head of the pool
  int tail;               // The tail of the pool
} QueueConstructor;

int sizeOfQueue(QueueConstructor* queue);

int isFullQueue(QueueConstructor* queue);

int isEmptyQueue(QueueConstructor* queue);

int enqueue(QueueConstructor* queue, int data);

int dequeue(QueueConstructor* queue);

QueueConstructor* createCircularQueue(int total_size);

void destoryQueue(QueueConstructor* queue);

void printQueue(QueueConstructor* queue);

#endif