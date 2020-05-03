#include <stdio.h>
#include "../data-structures/map/hash_map.h"

int main() {
  HashMap* hm = createHashMap();

  printf("Put [hello: 5] to hm.\n");
  putToMap(hm, "hello", 5);
  int val = getFromMap(hm, "hello");

  printf("The value of 'hello' in hm: %d\n\n", getFromMap(hm, "hello"));
  printf("The value of 'world' in hm: %d\n\n", getFromMap(hm, "world"));

  putToMap(hm, "name1", 1);
  putToMap(hm, "name2", 3);
  putToMap(hm, "name3", 5);
  putToMap(hm, "name4", 7);
  putToMap(hm, "name5", 9);

  printf("\n");
  printMap(hm);
  printf("\n");

  putToMap(hm, "name6", 11);
  putToMap(hm, "name7", 13);
  putToMap(hm, "name8", 15);
  putToMap(hm, "name9", 17);
  putToMap(hm, "name10", 19);
  putToMap(hm, "name11", 21);
  putToMap(hm, "name12", 23);
  putToMap(hm, "name13", 25);
  putToMap(hm, "name14", 27);
  putToMap(hm, "name15", 29);

  printf("\n");
  printMap(hm);
  printf("\n");

  putToMap(hm, "name16", 31);
  putToMap(hm, "name17", 33);
  putToMap(hm, "name18", 35);
  putToMap(hm, "name19", 37);
  putToMap(hm, "name20", 39);
  putToMap(hm, "name21", 41);
  putToMap(hm, "name22", 43);
  putToMap(hm, "name23", 45);
  putToMap(hm, "name24", 47);
  putToMap(hm, "name25", 49);

  printf("\n");
  printMap(hm);
  printf("\n");

  putToMap(hm, "name11", 97);
  putToMap(hm, "name25", 51);

  printf("\n");
  printMap(hm);
  printf("\n");

  destoryMap(hm);

  return 0;
}