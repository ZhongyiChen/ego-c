#include <stdio.h>
#include "../algorithms/sort/heap_sort.h"
#include "../zyc-libs/utils.h"

int main() {
  int arr[] = {1, 5, 6, 3, 2, 9, 4, 7, 9, 1, 8, 3, 11, 1, 9, 23};
  int len = sizeof(arr) / sizeof(int);

  printf("Input array: ");
  logarr(arr, len);

  heapSort(arr, len);

  printf("Output array: ");
  logarr(arr, len);

  return 0;
}