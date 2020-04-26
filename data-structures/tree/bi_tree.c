/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * 
 * You can create a bitree through this codes fragment. For example,
 * you can pass an array to createBiTreeByArray. First things first,
 * minus value means the stop on growing. Other values mean nodes on
 * the tree. Such as:
 * 
 *            [1, 2, 3, -1, -1, -1, 4, -1, -1]
 * 
 * Then, you would get a tree like fellowing sample:
 * 
 *                           1
 *                         /   \
 *                        2     4
 *                      /  \   /  \ 
 *                     3   -1 -1  -1
 *                   /  \
 *                  -1  -1
 * On that bitree, "-1" means NULL, namely nothing at all. What you 
 * should do is to ignore them.
 */

#include <malloc.h>
#include "bi_tree.h"
#include "../../zyc-libs/null.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

/**
 * Add a node to BiTree.
 * @param parent {BiNode*} The parent of current node
 * @param l_child {BiNode*} The left child of current node
 * @param r_child {BiNode*} The right child of current node
 * @param data {int} The data of child node
 */
BiNode* addNode(BiNode* parent, BiNode* l_child, BiNode* r_child, int data) {
  if (data < 0) return NULL;
  BiNode* node = (BiNode*)malloc(sizeof(BiNode));
  node->data = data;
  node->l_child = l_child;
  node->r_child = r_child;
  node->parent = parent;
  return node;
}

/**
 * Remove a node from BiTree.
 */
BiNode* removeNode(BiNode* node) {
  if (node->parent) {
    if (node == node->parent->l_child) {
      node->parent->l_child = NULL;
    } else {
      node->parent->r_child = NULL;
    }
  }
  if (node->l_child) removeNode(node->l_child);
  if (node->r_child) removeNode(node->r_child);
  free(node);

  return node;
}

/**
 * Trimming the useless temporary child nodes
 * @param tree {BiNode*} The root address of a tree
 */
void trimTmpNodes(BiNode* tree, BiNode* l_tmp, BiNode* r_tmp) {
  if (!tree) return;
  if (tree->r_child != NULL && tree->r_child != r_tmp) {
    trimTmpNodes(tree->r_child, l_tmp, r_tmp);
    return;
  }
  tree->r_child = NULL;
  if (NULL == tree->l_child) return;
  if (tree->l_child == l_tmp) {
    tree->l_child = NULL;
    return;
  }
  trimTmpNodes(tree->l_child, l_tmp, r_tmp);
}

/**
 * Create a BiTree through an integer array in a depth-first way.
 * @param arr {int*} The initial address of the array
 * @param len {int} The length of the array
 */
BiNode* createBiTreeByArray(int* arr, int len) {
  BiNode* l_tmp = addNode(NULL, NULL, NULL, 0); // Temporary left child node
  BiNode* r_tmp = addNode(NULL, NULL, NULL, 0); // Temporary right child node
  BiNode* tree;             // Root node
  BiNode* last;             // Last node
  BiNode* curr;             // Current node
  if (arr[0] < 0) {
    return NULL;
  }
  tree = addNode(NULL, l_tmp, r_tmp, arr[0]);

  last = tree;
  curr = last->l_child;

  int i = 1;
  int is_l_child;

  for (; i < len; i++) {
    is_l_child = (curr == last->l_child);
    BiNode* T = addNode(last, l_tmp, r_tmp, arr[i]);
    if (is_l_child) {
      last->l_child = T;
    } else {
      last->r_child = T;
    }

    if (i == len - 1) break;  // No item below
    if (is_l_child) {
      if (NULL == last->l_child) {
                              // Last node still be it
        curr = last->r_child;
      } else {
        last = last->l_child;
        curr = last->l_child;
      }
      continue;
    }
    if (NULL != last->r_child) {
      last = last->r_child;
      curr = last->l_child;
      continue;
    }
    do {
      last = last->parent;  // Tracing back via the parent of last node
    } while (r_tmp != last->r_child); // Until finding a new right child
    curr = last->r_child;
  }

  trimTmpNodes(tree, l_tmp, r_tmp); // Trim the temporary nodes from the tree
  removeNode(l_tmp);                // Remove the temorary nodes
  removeNode(r_tmp);

  return tree;
}

/**
 * Print all nodes in pre-order.
 * @param tree {BiNode*} The root address of a tree
 */
void preOrderPrint(BiNode* tree) {
  if (NULL == tree) {
    return;
  }
  printf("%d ", tree->data);
  preOrderPrint(tree->l_child);
  preOrderPrint(tree->r_child);
}

/**
 * Print all nodes in in-order.
 * @param tree {BiNode*} The root address of a tree
 */
void inOrderPrint(BiNode* tree) {
  if (NULL == tree) {
    return;
  }
  inOrderPrint(tree->l_child);
  printf("%d ", tree->data);
  inOrderPrint(tree->r_child);
}

/**
 * Print all nodes in post-order.
 * @param tree {BiNode*} The root address of a tree
 */
void postOrderPrint(BiNode* tree) {
  if (NULL == tree) {
    return;
  }
  postOrderPrint(tree->l_child);
  postOrderPrint(tree->r_child);
  printf("%d ", tree->data);
}