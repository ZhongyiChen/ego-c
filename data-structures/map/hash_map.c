/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * 
 */

#include <malloc.h>
#include "../../zyc-libs/null.h"
#include "../../zyc-libs/utils.h"
#include "hash_map.h"

#define INIT_SIZE 11
#define WARN_RATE 2.0     // The storage rate should be warned

int putToBucket(HashMap* map, int bucket_index, char* key, int val);

/**
 * Get a prime which is bigger almost twice than the source one.
 * @param sPrime {int} The source prime
 * @return {int} The destination prime
 */
int getAlmostDoublePrime(int sPrime) {
  int dPrime = sPrime * 2 - 1;
  for (; dPrime > sPrime; dPrime -= 2) {
    if (isprime(dPrime)) return dPrime;
  }
  // Impossible reach here
}

/**
 * ELF hash algorithm.
 * @param key {char*} The input string
 * @param mod {unsigned int} The size of bucket
 * @return {unsigned int} The hash index it get
 */
unsigned int ELFhash(char *key, unsigned int mod) {
  unsigned long h = 0;
  while (*key) {
    h = (h << 4) + *key++;
    unsigned long g = h & 0xF0000000L;
    if (g)
      h ^= g >> 24;
    h &= ~g;
  }
  return h % mod;
}

/**
 * The necessary operations after rehashing.
 * @param map {HashMap*} The map
 */
void rehashDone(HashMap* map) {
  free(map->bucket[0]);
  map->bucket[0] = map->bucket[1];
  map->total[0] = map->total[1];
  map->used[0] = map->used[1];
  map->bucket[1] = NULL;
  map->total[1] = getAlmostDoublePrime(map->total[0]);
  map->used[1] = 0;
}

/**
 * Judge the backup bucket is used or not.
 * @param map {HashMap*} The map
 * @return {int} 0 means not be used; 1 means be used
 */
int isBackupUsed(HashMap* map) {
  return (NULL != map->bucket[1] || 
    WARN_RATE < (double)map->used[0] / map->total[0]);
}

/**
 * Move the key/val from current bucket to backup bucket.
 * @param map {HashMap*} The map
 */
void rehash(HashMap* map) {
  int i = 0;
  int count = 0;
  int cur_total = map->total[0];
  HashItem** cur_bucket = map->bucket[0];
  if (!map->bucket[1]) {
    map->bucket[1] = (HashItem**)calloc(map->total[1], sizeof(HashItem*));
  }
  HashItem* item = NULL;
  HashItem* item_next = NULL;
  while (count < 10) {
    if (0 == map->used[0]) break;
    if (i >= cur_total) break;
    item = cur_bucket[i];
    if (!item) {
      i++;
      continue;
    }
    while (item) {
      item_next = item->next;
      putToBucket(map, 1, item->key, item->val);
      free(item);
      map->used[0] -= 1;
      item = item_next;
    }
    cur_bucket[i] = NULL;
    i++;
    count++;
  }
  if (0 == map->used[0]) rehashDone(map);
}

/**
 * Put the pair of key/val to the indicated bucket.
 * @param map {HashMap*} The map
 * @param bucket_index {int} The index of bucket
 * @param key {char*} The key
 * @param val {int} The value
 * @return {int} 0 means failure; 1 means success
 */
int putToBucket(HashMap* map, int bucket_index, char* key, int val) {
  unsigned int mod = map->total[bucket_index];
  int item_index = ELFhash(key, mod);
  HashItem** bucket = map->bucket[bucket_index];
  HashItem* item = bucket[item_index];
  while (item) {
    if (cmpstr(item->key, key)) {
      item->val = val;
      return 1;
    }
    item = item->next;
  }
  HashItem* hi = (HashItem*)malloc(sizeof(HashItem) + sizeof(char) * sizeof(key));
  if (!hi) return 0;
  cpystr(hi->key, key);
  hi->val = val;
  hi->next = bucket[item_index];
  bucket[item_index] = hi;
  map->used[bucket_index] += 1;
  return 1;
}

/**
 * Put a pair of key/val onto map.
 * @param map {HashMap*} The map
 * @param key {char*} The key
 * @param val {int} The value
 * @return {int} 0 means failure; 1 means success
 */
int putToMap(HashMap* map, char* key, int val) {
  int index = 0;
  if (isBackupUsed(map)) {
    rehash(map);  // Move some items from current bucket to backup bucket
    index = (NULL == map->bucket[1]) ? 0 : 1;
  }
  return putToBucket(map, index, key, val);
}

/**
 * Get the hash item by the key.
 * @param map {HashMap*} The map
 * @param bucket_index {int} The index of bucket
 * @param key {char*} The key
 * @return {HashItem*} The pointer of the hash item
 */
HashItem* getFromBucket(HashMap* map, int bucket_index, char* key) {
  if (0 == map->used[bucket_index]) return NULL;
  unsigned int mod = map->total[bucket_index];
  int item_index = ELFhash(key, mod);
  HashItem** bucket = map->bucket[bucket_index];
  HashItem* item = bucket[item_index];
  while (item) {
    if (cmpstr(item->key, key)) return item; 
    item = item->next;
  }
  return item;
}

/**
 * Get val from map by key.
 * @param map {HashMap*} The map
 * @param key {char*} The key
 * @return {int} The value you need
 */
int getFromMap(HashMap* map, char* key) {
  HashItem* hi;
  if (isBackupUsed(map)) {
    rehash(map);  // Move some items from current bucket to backup bucket
    if (NULL != map->bucket[1]) {
      hi = getFromBucket(map, 1, key);
      if (hi) return hi->val;
    }
  }
  hi = getFromBucket(map, 0, key);
  if (hi) return hi->val;
  printf("Error: The key '%s' could not be found.\n", key);
  return -9999;
}

/**
 * Remove the hash item by the key.
 * @param map {HashMap*} The map
 * @param bucket_index {int} The index of bucket
 * @param key {char*} The key
 * @return {int} The removed val
 */
int removeFromBucket(HashMap* map, int bucket_index, char* key) {
  int val = -9999;
  if (0 == map->used[bucket_index]) return val;
  unsigned int mod = map->total[bucket_index];
  int item_index = ELFhash(key, mod);
  HashItem** bucket = map->bucket[bucket_index];
  HashItem* item_prev = NULL;
  HashItem* item = bucket[item_index];
  while (item) {
    if (cmpstr(item->key, key)) {
      val = item->val;
      if (item_prev) {
        item_prev->next = item->next;
      } else {
        bucket[item_index] = item->next;
      }
      free(item);
      return val; 
    }
    item_prev = item;
    item = item->next;
  }
  return val;
}

/**
 * Remove val from map by key.
 * @param map {HashMap*} The map
 * @param key {char*} The key
 * @return {int} The value you remove
 */
int removeFromMap(HashMap* map, char* key) {
  int val;
  if (isBackupUsed(map)) {
    rehash(map);  // Move some items from current bucket to backup bucket
    if (NULL != map->bucket[1]) {
      val = removeFromBucket(map, 1, key);
      if (-9999 != val) return val;
    }
  }
  val = removeFromBucket(map, 0, key);
  if (-9999 != val) return val;
  printf("Error: The key '%s' is inexistent, nothing could be removed.\n", key);
  return val;
}

/**
 * Create a hash map.
 * @return {HashMap*} the hash map
 */
HashMap* createHashMap() {
  HashMap* hm = (HashMap*)malloc(sizeof(HashMap));
  
  hm->total[0] = INIT_SIZE;
  hm->used[0] = 0;
  hm->bucket[0] = (HashItem**)calloc(INIT_SIZE, sizeof(HashItem*));
  
  hm->total[1] = getAlmostDoublePrime(INIT_SIZE);
  hm->used[1] = 0;
  hm->bucket[1] = NULL;

  return hm;
}

/**
 * Destory the bucket.
 * @param map {HashMap*} The map
 * @param bucket_index {int} The index of bucket
 */
void destroyBucket(HashMap* map, int bucket_index) {
  HashItem** bucket = map->bucket[bucket_index];
  if (!bucket) return;
  HashItem* item = NULL;
  HashItem* item_next = NULL;
  int total = map->total[bucket_index];
  int i = 0;
  for (i = 0; i < total; i++) {
    item = bucket[i];
    while (item) {
      item_next = item->next;
      free(item);
      item = item_next;
    }
  }
  free(bucket);
  bucket = NULL;
}

/**
 * Destory the hash map.
 * @param map {HashMap*} The map
 */
void destoryMap(HashMap* map) {
  destroyBucket(map, 0);
  destroyBucket(map, 1);
  free(map);
  map = NULL;
}

/**
 * Print the bucket.
 * @param map {HashMap*} The map
 * @param bucket_index {int} The index of bucket
 */
void printBucket(HashMap* map, int bucket_index) {
  printf("bucket[%d]:\n", bucket_index);
  HashItem** bucket = map->bucket[bucket_index];
  HashItem* item = NULL;
  int total = map->total[bucket_index];
  printf("total: %d\n", total);
  int used = map->used[bucket_index];
  printf("used: %d\n", used);
  if (used == 0) return;
  int i = 0;
  for (; i < total; i++) {
    item = bucket[i];
    if (!item) {
      printf("[]\n");
      continue;
    }
    while (item) {
      printf("[%s: %d] ", item->key, item->val);
      item = item->next;
    }
    printf("\n");
  }
}

/**
 * Print the hash map.
 * @param map {HashMap*} The map
 * @return {HashMap*} the hash map
 */
void printMap(HashMap* map) {
  printBucket(map, 0);
  printf("\n");
  printBucket(map, 1);
}