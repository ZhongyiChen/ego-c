#include <malloc.h>
#include "../node/bi_node.h"
#include "../../zyc-libs/null.h"
#include <stdio.h>

/**
 * Add a node to BiTree
 * @param parent {BiNode*} the parent of current node
 * @param l_child {BiNode*} the left child of current node
 * @param r_child {BiNode*} the right child of current node
 * @param data {int} the data of child node
 */
BiNode* addNode(BiNode* parent, BiNode* l_child, BiNode* r_child, int data) {
  if (data < 0) return NULL;
  BiNode* T = (BiNode*)malloc(sizeof(BiNode));
  T->data = data;
  T->l_child = l_child;
  T->r_child = r_child;
  T->parent = parent;
  return T;
}

/**
 * Creating a BiTree through an integer array in a depth-first way
 * @param arr {int*} The initial address of the array
 * @param len {int} The length of the array
 */
BiNode* createBiTreeByArray(int* arr, int len) {
  BiNode* tmp_l_child = addNode(NULL, NULL, NULL, 0);
  BiNode* tmp_r_child = addNode(NULL, NULL, NULL, 0);
  BiNode* tree;             // Root node
  BiNode* last;             // Last node
  BiNode* curr;             // Current node
  if (arr[0] < 0) {
    return NULL;
  }
  tree = addNode(NULL, tmp_l_child, tmp_r_child, arr[0]);
  printf("root %d\n", tree->data);

  last = tree;
  curr = last->l_child;

  int i = 1;

  for (; i < len; i++) {
    if (curr == last->l_child) {
      printf("left %d\n", arr[i]);
      last->l_child = addNode(last, tmp_l_child, tmp_r_child, arr[i]);
      if (NULL == last->l_child) {
                              // Last node still be it
        curr = last->r_child;
      } else {
        last = last->l_child;
        curr = last->l_child;
      }
      continue;
    }
    printf("right %d\n", arr[i]);
    last->r_child = addNode(last, tmp_l_child, tmp_r_child, arr[i]);
    if (NULL == last->r_child) {
      do {
        last = last->parent;  // Tracing back via the parent of last node
      } while (NULL == last->r_child); // Until finding a new right child
      curr = last->r_child;
      continue;
    }
                              // Last node still be it
    curr = last->l_child;
  }

  return tree;
}