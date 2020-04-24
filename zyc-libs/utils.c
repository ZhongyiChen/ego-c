// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

#include "utils.h"

/**
 * Print array
 * @param arr {int*} The initial address of the array
 * @param len {int} The length of the array
 */
void print_arr(int* arr, int len) {
  int i = 0;
  for (; i < len; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
}

/**
 * Switch two variables
 * @param a {int*} First variable
 * @param b {int*} Second variable
 */
void swap(int* a, int* b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}