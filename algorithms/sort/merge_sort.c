/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * 
 */

#include <malloc.h>
#include "../../zyc-libs/utils.h"

int* createDynamicArray(int len) {
  return calloc(len, sizeof(int));
}

void freeDynamicArray(int* arr) {
  free(arr);
}

/**
 * Copy a slide of an array into another array.
 * @param dst {int*} The destination array
 * @param src {int*} The source array
 * @param dst_index {int} The starting index of destination array
 * @param src_index {int} The starting index of source array
 * @param len {int} The length of the slide whick need to be copied
 */
void cpyArr(int* dst, int* src, int dst_index, int src_index, int len) {
  int i = len - 1;
  for (; i >= 0; i--) {
    *(dst + dst_index + i) = *(src + src_index + i);
  }
}

/**
 * @param dst {int*} The destination array
 * @param src {int*} The source array
 * @param l {int} The leftmost index
 * @param m {int} The middle index
 * @param r {int} The rightmost index
 */
void mergeArr(int* dst, int* src, int l, int m, int r) {
  int cursor = l;
  int i = l;
  int j = m;

  while (i < m || j <= r) {
    if (i >= m) {
      dst[cursor++] = src[j++];
      continue;
    }
    if (j > r) {
      dst[cursor++] = src[i++];
      continue;
    }
    if (src[i] < src[j]) {
      dst[cursor++] = src[i++];
      continue;
    }
    dst[cursor++] = src[j++];
  
  }

}

/**
 * Merge sort.
 * @param arr {int*} The initial address of the array
 * @param len {int} The length of the array
 */

void mergeSort(int* arr, int len) {
  int* dup = createDynamicArray(len);
  int* src = arr;
  int* dst = dup;
  int* tmp;

  int slide_side = 1, l, r, m;

  while (1) {
    for (l = 0; l < len; l += (slide_side * 2)) {
      m = l + slide_side;
      r = l + slide_side * 2 - 1;
      r = r < len ? r : (len - 1);
      mergeArr(dst, src, l, m, r);
    }
    slide_side *= 2;
    if (slide_side > len) break;
    tmp = dst;
    dst = src;
    src = tmp;
  }

  if (arr != dst) cpyArr(arr, dst, 0, 0, len);

  freeDynamicArray(dup);
}