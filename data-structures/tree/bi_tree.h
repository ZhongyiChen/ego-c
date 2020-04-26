#ifndef __TREE_BITREE_H
#define __TREE_BITREE_H

/**
 * The structure of BiNode
 */
typedef struct Node {
  int data;
  struct Node* l_child;
  struct Node* r_child;
  struct Node* parent;
} BiNode;

BiNode* createBiTreeByArray(int* arr, int len);

void preOrderPrint(BiNode* tree);

void inOrderPrint(BiNode* tree);

void postOrderPrint(BiNode* tree);

#endif