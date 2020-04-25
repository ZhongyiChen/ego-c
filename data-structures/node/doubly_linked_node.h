#ifndef __NODE_DOUBLYLINKNODE_H
#define __NODE_DOUBLYLINKNODE_H

#include "../../zyc-libs/null.h"

/**
 * The structure of normal Doubly LinkNode
 */
typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} LinkedNode;

/**
 * The structure of root Doubly LinkNode
 */
typedef struct Root {
  int length;
  struct LinkedNode* head;
  struct LinkedNode* tail;
} LinkedRoot;

#endif