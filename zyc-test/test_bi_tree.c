#include "../data-structures/tree/bi_tree.h"

int main() {
  int arr[] = {1, 2, 3, 4, -1, -1, 5, -1, -1, 6, -1, -1, 7, 8, -1, -1, 9, -1, -1};
  int len = sizeof(arr) / sizeof(int);
  BiNode* T = createBiTreeByArray(arr, len);
  preOrderPrint(T);
  return 0;
}