#ifndef __TREE_BITREE_H
#define __TREE_BITREE_H

#include "../node/bi_node.h"

BiNode* createBiTreeByArray(int* arr, int len);
void preOrderPrint(BiNode* tree);

#endif