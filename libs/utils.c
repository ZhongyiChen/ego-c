// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

#include "utils.h"

/**
 * Print array
 * @param {int*} arr The initial address of the array
 * @param {int} len The length of the array
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
 * @param {int*} a First variable
 * @param {int*} b Second variable
 */
void swap(int* a, int* b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}