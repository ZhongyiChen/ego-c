#ifndef __MAP_HASHMAP_H
#define __MAP_HASHMAP_H

typedef struct Item {
  struct Item* next;
  int val;
  char key[];
} HashItem;

typedef struct Map {
  int current_total;        // Total size of current bucket
  int current_used;         // Used size of current bucket
  int backup_total;         // Total size of backup bucket
  int backup_used;          // Used size of backup bucket
  HashItem** bucket[2];
} HashMap;

HashMap* createHashMap();

putToMap(HashMap* map, char* key, int val);

void cpystr(char* d, char* s);

int cmpstr(char* sKey, char* dKey);

#endif