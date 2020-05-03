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
#define WARN_RATE 2           // The storage rate should be warned

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
  return dPrime * 2;      // Impossible excute this
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

// rehash() {
// }

/**
 * Judge the backup bucket is used or not.
 * @param map {HashMap*} The map
 * @return {int} 0 means not be used; 1 means be used
 */
int isBackupUsed(HashMap* map) {
  return (NULL != map->bucket[1] || 
    WARN_RATE < map->current_used / map->current_total);
}

/**
 * Put the pair of key/val to the indicated bucket.
 * @param bucket {HashItem**} Which bucket
 * @param key {char*} The key
 * @param val {int} The value
 * @param mod {unsigned int} The size of the bucket
 * @return {int} 0 means failure; 1 means success
 */
int putToBucket(HashItem** bucket, char* key, int val, unsigned int mod) {
  int index = ELFhash(key, mod);
  HashItem* hi = (HashItem*)malloc(sizeof(HashItem) + sizeof(char) * sizeof(key));
  if (!hi) return 0;
  cpystr(hi->key, key);
  hi->val = val;
  hi->next = NULL;
  bucket[index] = hi;
  return 1;
}

/**
 * Get the hash item by the key.
 * @param bucket {HashItem**} Which bucket
 * @param key {char*} The key
 * @param mod {unsigned int} The size of the bucket
 * @return {HashItem*} The pointer of the hash item
 */
HashItem* getFromBucket(HashItem** bucket, char* key, unsigned int mod) {
  int index = ELFhash(key, mod);
  return bucket[index];
}

/**
 * Put a pair of key/val onto map.
 * @param map {HashMap*} The map
 * @param key {char*} The key
 * @param val {int} The value
 * @return {int} 0 means failure; 1 means success
 */
int putToMap(HashMap* map, char* key, int val) {
  int isSuccess;
  if (isBackupUsed(map)) {
    isSuccess = putToBucket(map->bucket[1], key, val, map->backup_total);
    if (isSuccess) map->backup_used += 1;
    return isSuccess;
  }
  isSuccess = putToBucket(map->bucket[0], key, val, map->current_total);
  if (isSuccess) map->current_used += 1;
  return isSuccess;
}

int getFromMap(HashMap* map, char* key) {
  HashItem* hi;
  if (isBackupUsed(map)) {
    hi = getFromBucket(map->bucket[0], key, map->current_total);
    if (hi) return hi->val;
  }
  hi = getFromBucket(map->bucket[0], key, map->current_total);
  if (hi) return hi->val;
  printf("Error: The key '%s' could not be found.\n", key);
  return -9999;
}

/**
 * Create a hash map.
 * @return {HashMap*} the hash map
 */
HashMap* createHashMap() {
  HashMap* hm = (HashMap*)malloc(sizeof(HashMap));
  hm->current_total = INIT_SIZE;
  hm->current_used = 0;
  hm->backup_total = getAlmostDoublePrime(INIT_SIZE);
  hm->backup_used = 0;
  hm->bucket[0] = (HashItem**)calloc(INIT_SIZE, sizeof(HashItem*));
  hm->bucket[1] = NULL;
  return hm;
}

// destoryMap() {
// }

// printMap() {
// }