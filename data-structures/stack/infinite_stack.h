#ifndef __STACK_INFINITESTACK_H
#define __STACK_INFINITESTACK_H

typedef struct {
  int* pool;
  int cursor;             // The top of the pool
} InfiniteStack;

#endif