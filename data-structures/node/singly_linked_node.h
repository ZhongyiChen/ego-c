#ifndef __NODE_SINGLYLINKEDNODE_H
#define __NODE_SINGLYLINKEDNODE_H

#include "../../zyc-libs/null.h"

/**
 * The structure of normal Singly LinkedNode
 */
typedef struct Node {
  int data;
  struct Node* next;
} LinkedNode;

/**
 * The structure of root Singly LinkedNode
 */
typedef struct Root {
  int length;
  struct LinkedNode* head;
  struct LinkedNode* tail;
} LinkedRoot;

#endif