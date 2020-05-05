#include <stdio.h>
#include "../algorithms/search/bi_search.h"
#include "../zyc-libs/utils.h"

int main() {
  int arr[] = {1, 3, 4, 5, 7, 8, 9, 11, 15, 21};
  int len = sizeof(arr) / sizeof(int);

  printf("Input array: ");
  logarr(arr, len);

  printf("The index of data 1 is: %d\n", biSearch(arr, len, 1));

  printf("The index of data 8 is: %d\n", biSearch(arr, len, 8));

  printf("The index of data 13 is: %d\n", biSearch(arr, len, 13));

  return 0;
}