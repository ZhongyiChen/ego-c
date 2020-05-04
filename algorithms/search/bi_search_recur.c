/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * Search the index of data from an array via binary search
 * in recur way.
 */

/**
 * Binary search
 * @param arr {int*} The initial address of the array
 * @param l {int} The leftmost index
 * @param r {int} The rightmost index
 * @param data {int} The data needed to search
 * @return {int} The needed index
 */
static int search(int* arr, int l, int r, int data) {
  if (l > r) return -1;
  int i = (l + r) / 2;
  if (data < arr[i]) return search(arr, l, i - 1, data);
  if (data > arr[i]) return search(arr, i + 1, r, data);
  return i;
}

/**
 * Searching interface
 * @param arr {int*} The initial address of the array
 * @param len {int} The length of the array
 * @param data {int} The data need to be searched
 * @return {int} The needed index
 */
int biSearch(int* arr, int len, int data) {
  return search(arr, 0, len - 1, data);
}