#ifndef __MAP_HASHMAP_H
#define __MAP_HASHMAP_H

typedef struct Item {
  struct Item* next;
  int val;
  char key[];
} HashItem;

/**
 * index 0 means current bucket
 * index 1 means backup bucket
 */
typedef struct Map {
  int total[2];
  int used[2];
  HashItem** bucket[2];
} HashMap;

HashMap* createHashMap();

int putToMap(HashMap* map, char* key, int val);

int getFromMap(HashMap* map, char* key);

void printMap(HashMap* map);

void destoryMap(HashMap* map);

#endif