#include <stdio.h>
#include "../data-structures/map/hash_map.h"

int main() {
  HashMap* hm = createHashMap();
  char* name = "hello";
  putToMap(hm, name, 5);
  int val = getFromMap(hm, name);
  printf("The value: %d\n", val);
  val = getFromMap(hm, "world");
  return 0;
}