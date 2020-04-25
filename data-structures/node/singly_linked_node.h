#ifndef __NODE_SINGLYLINKNODE_H
#define __NODE_SINGLYLINKNODE_H

#include "../../zyc-libs/null.h"

/**
 * The structure of normal Singly LinkNode
 */
typedef struct Node {
  int data;
  struct Node* next;
} LinkedNode;

/**
 * The structure of root Singly LinkNode
 */
typedef struct Root {
  int length;
  struct LinkedNode* head;
  struct LinkedNode* tail;
} LinkedRoot;

#endif