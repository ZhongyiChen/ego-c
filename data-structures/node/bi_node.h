#ifndef __NODE_BINODE_H
#define __NODE_BINODE_H

#include "../../zyc-libs/null.h"

/**
 * The structure of BiNode
 */
typedef struct Node {
  int data;
  struct Node* l_child;
  struct Node* r_child;
  struct Node* parent;
} BiNode;

#endif