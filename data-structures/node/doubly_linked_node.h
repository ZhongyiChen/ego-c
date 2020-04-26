#ifndef __NODE_DOUBLYLINKEDNODE_H
#define __NODE_DOUBLYLINKEDNODE_H

#include "../../zyc-libs/null.h"

/**
 * The structure of normal Doubly LinkedNode
 */
typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} LinkedNode;

/**
 * The structure of root Doubly LinkedNode
 */
typedef struct Root {
  int length;
  struct LinkedNode* head;
  struct LinkedNode* tail;
} LinkedRoot;

#endif