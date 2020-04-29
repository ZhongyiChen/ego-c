#ifndef __QUEUE_INFINITEQUEUE_H
#define __QUEUE_INFINITEQUEUE_H

#include "../linked-list/doubly_linked_list.h"

typedef LinkedRoot QueueConstructor;

int sizeOfQueue(QueueConstructor* queue);

int isEmptyQueue(QueueConstructor* queue);

int enqueue(QueueConstructor* queue, int data);

int dequeue(QueueConstructor* queue);

QueueConstructor* createInfiniteQueue();

void destoryQueue(QueueConstructor* queue);

void printQueue(QueueConstructor* queue);

#endif