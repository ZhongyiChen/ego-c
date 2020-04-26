#include "../algorithms/quick-sort/quick_sort_recur.h"
#include "../zyc-libs/utils.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

int main() {
  int arr[] = {5, 6, 3, 2, 9, 4, 7, 9, 1, 8, 3};
  int len = sizeof(arr) / sizeof(int);

  printf("Input array: ");
  print_arr(arr, len);

  quick_sort(arr, len);

  printf("Output array: ");
  print_arr(arr, len);

  return 0;
}