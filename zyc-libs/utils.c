#include <stdio.h>
#include "utils.h"

/**
 * Print array
 * @param arr {int*} The initial address of the array
 * @param len {int} The length of the array
 */
void logarr(int* arr, int len) {
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

/**
 * Copy the source string to destination.
 * @param d {char*} The pointer to destination
 * @param s {char*} The pointer to source
 */
void cpystr(char* d, char* s) {
  while (0 != (*d++ = *s++));
}

/**
 * Judge the both keys are equal or not.
 * @param d {char*} The destination
 * @param s {char*} The source
 * @return {int} 0 means not equal; 1 means equal
 */
int cmpstr(char* d, char* s) {
  int i = 0;
  for (; *(s + i) || *(d + i); i++) {
    if (!*(s + i)) return 0;
    if (!*(d + i)) return 0;
    if (*(s + i) != *(d + i)) return 0;
  }
  return 1;
}

/**
 * Judge a number is prime or not.
 * @param val {int} The number
 * @return {int} 0 means it is not; 1 means it is
 */
int isprime(int val) {
  if (2 == val) return 1;
  if (1 >= val || 0 == val % 2) return 0;
  for (int i = 3; (i * i) <= val; i += 2) {
    if (0 == val % i) return 0;
  }
  return 1;
}
