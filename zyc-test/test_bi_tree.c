#include <stdio.h>
#include "../data-structures/tree/bi_tree.h"
#include "../zyc-libs/utils.h"

int main() {
  int arr[] = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, -1};
  int len = sizeof(arr) / sizeof(int);

  printf("Input array: ");
  logarr(arr, len);

  BiNode* T = createBiTreeByArray(arr, len);

  printf("Print the tree in pre-order: ");
  preOrderPrint(T);
  printf("\n");

  printf("Print the tree in in-order: ");
  inOrderPrint(T);
  printf("\n");

  printf("Print the tree in post-order: ");
  postOrderPrint(T);
  printf("\n");

  return 0;
}