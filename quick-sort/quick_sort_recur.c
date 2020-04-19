// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

/**
 * 打印数组
 * @param {int*} arr 数组起始地址
 * @param {int} len 数组的长度
 */
void print_arr(int* arr, int len) {
  int i = 0;
  for (; i < len; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
}

/**
 * 两数互换
 * @param {int*} a 数一
 * @param {int*} b 数二
 */
void swap(int* a, int* b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

/**
 * 快速排序
 * @param {int*} arr 数组起始地址
 * @param {int} l 左边的下标
 * @param {int} r 右边的下标
 */
void quick_sort(int* arr, int l, int r) {
  int tmp = arr[l];     // 基准项
  int i = l + 1;
  int j = r;
  for (; i <= j;) {
    while (i < j && arr[j] >= tmp) j--;
    while (i < j && arr[i] <= tmp) i++;
    if (i == j) {
      if (arr[i] < tmp) swap(arr + l, arr + i);
      else (i = j = l);
      break;
    }
    if (arr[i] > tmp && arr[j] < tmp) {
      swap(arr + i, arr + j);
    }
  }
  if (l < j - 1) quick_sort(arr, l, j - 1);
  if (j + 1 < r) quick_sort(arr, j + 1, r);
}

/**
 * 排序
 * @param {int*} arr 数组起始地址
 * @param {int} len 数组的长度
 */
void sort(int* arr, int len) {
  quick_sort(arr, 0, len - 1);
}

int main() {
  int arr[] = {5, 6, 3, 2, 9, 4, 7, 9, 1, 8, 3};
  int len = sizeof(arr) / sizeof(int);
  print_arr(arr, len);
  sort(arr, len);
  print_arr(arr, len);
}