/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * Sort an array with the way of bubble sort.
 */

#include "../../zyc-libs/utils.h"

/**
 * Sorting interface
 * @param arr {int*} The initial address of the array
 * @param len {int} The length of the array
 */
void bubbleSort(int* arr, int len) {
  int i = 0;
  int j = 0;
  for (; i < len; i++) {
    for (j = i; j < len; j++) {
      if (arr[j] < arr[i]) swap(arr + i, arr + j);
    }
  }
}