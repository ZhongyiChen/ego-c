/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * 
 */

#include "../../zyc-libs/utils.h"

/**
 * Sorting interface
 * @param arr {int*} The initial address of the array
 * @param len {int} The length of the array
 */
void selectionSort(int* arr, int len) {
  int i = 0;
  int j = 0;
  int tmp = 0;      // Store the index of the smallest item
  for (; i < len; i++) {
    tmp = i;
    for (j = i; j < len; j++) {
      if (arr[j] < arr[tmp]) tmp = j;
    }
    if (tmp != i) swap(arr + i, arr + tmp);
  }
}