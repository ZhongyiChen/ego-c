/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * 
 */

#include <malloc.h>
#include "../../zyc-libs/null.h"
#include "singly_linked_list.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

/**
 * Create a new node to the list.
 * @param next {LinkedNode*} Indicate the next node
 * @param data {int} The data needed to be stored
 */
LinkedNode* createNode(LinkedNode* next, int data) {
  LinkedNode* node = (LinkedNode*)malloc(sizeof(LinkedNode));
  node->data = data;
  node->next = next;
  return node;
}

/**
 * Remove a node from the list.
 * @param list {LinkedRoot*} The list owned the node
 * @param node {LinkedNode*} The node needed to be removed
 * @param prev_node {LinkedNode*} One node before the node
 */
void removeNode(LinkedRoot* list, LinkedNode* node, LinkedNode* prev_node) {
  if (NULL == node) {
    return;
  }
  if (list->head == list->tail) {
    list->head = list->tail = NULL;
  } else if (node == (LinkedNode*)list->head) {
    list->head = node->next;
  } else {
    if (NULL != prev_node) {
      prev_node->next = node->next;
    } else {
      prev_node = list->head;
      while (prev_node->next != node)
        prev_node = prev_node->next;
      prev_node->next = node->next;
    }
    if ((LinkedNode*)list->tail == node) list->tail = prev_node;
  }
  free(node);
  list->length--;
}

/**
 * Remove a node which meets the index you indicate.
 * @param list {LinkedRoot*} The list owned the removed node
 * @param index {int} The index that node located at
 */
void removeNodeByIndex(LinkedRoot* list, int index) {
  if (index < 0 || index + 1 > list->length) {
    printf("Error: no such index! Nothing could be removed.\n");
    return;
  }
  LinkedNode* prev_node = NULL;
  LinkedNode* node = list->head;      // The default node
  int i = 0;
  for (; i < index; i++) {
    prev_node = node;
    node = node->next;
  }
  removeNode(list, node, prev_node);
}

/**
 * Remove the nodes which equal to the indicated data.
 * @param list {LinkedRoot*} The list owned the removed node
 * @param data {int} The value
 */
void removeNodesByData(LinkedRoot* list, int data) {
  LinkedNode* prev_node = NULL;
  LinkedNode* node = list->head;      // The default node
  int i = 0;
  for (; i < list->length; i++) {
    if (NULL != node) return;
    if (data == node->data) removeNode(list, node, prev_node);
    prev_node = node;
    node = node->next;
  }
}

/**
 * Update the node with new data.
 * @param list {LinkedRoot*} The list
 * @param index {int} The index that node locate at
 * @param data {int} The new value
 */
void updateNodeByIndex(LinkedRoot* list, int index, int data) {
  if (index < 0 || index + 1 > list->length) {
    printf("Error: no such index! Nothing could be updated.\n");
    return;
  }
  LinkedNode* node = list->head;      // The default node
  int i = 0;
  for (; i < index; i++) {
    node = node->next;
  }
  node->data = data;
}

/**
 * Get the index of the node which first own the indicated data
 * @param list {LinkedRoot*} The list
 * @param data {int} The value
 */
int getIndexOfData(LinkedRoot* list, int data) {
  LinkedNode* node = list->head;      // The default node
  int i = 0;
  while (node && data != node->data) {
    node = node->next;
    i++;
  }
  if (NULL == node) {
    return -1;
  }
  return i;
}

/**
 * Insert a node at the indicated index.
 * @param list {LinkedRoot*} The list
 * @param index {int} The index that node should locate at
 * @param data {int} The value
 */
void insertNodeByIndex(LinkedRoot* list, int index, int data) {
  if (0 == index) {
    prependToList(list, data);
    return;
  }
  if (list->length == index) {
    appendToList(list, data);
    return;
  }
  if (index < 0 || index > list->length) {
    printf("Error: \
      The length of current list is %d, \
      index shouldn locate at [0, %d]. \
    ", list->length, list->length);
    return;
  }
  LinkedNode* prev_node = list->head;
  int i = 0;
  for (; i < index - 1; i++) {
    prev_node = prev_node->next;
  }
  LinkedNode* new_node = createNode(prev_node->next, data);
  prev_node->next = new_node;
  list->length++;
}

/**
 * Unshift a new node to the end of the list.
 * @param list {LinkedRoot*} The list
 * @param data {int} The data should be stored
 */
int unshiftToList(LinkedRoot* list, int data) {
  prependToList(list, data);
}

/**
 * Shift a node from the end of the list.
 * @param list {LinkedRoot*} The list
 */
int shiftFromList(LinkedRoot* list) {
  if (NULL == list->head) {
    printf("Error: list is empty! Nothing could be shifted!\n");
    return -9999;
  }
  LinkedNode* node = list->head;
  int data = node->data;
  removeNode(list, node, NULL);

  return data;
}

/**
 * Push a new node to the end of the list.
 * @param list {LinkedRoot*} The list
 * @param data {int} The data should be stored
 */
int pushToList(LinkedRoot* list, int data) {
  appendToList(list, data);
}

/**
 * Pop a node from the end of the list.
 * @param list {LinkedRoot*} The list
 */
int popFromList(LinkedRoot* list) {
  if (NULL == list->tail) {
    printf("Error: list is empty! Nothing could be poped!\n");
    return -9999;
  }
  LinkedNode* prev_node = NULL;
  LinkedNode* node = list->head;      // The default node
  while (node != (LinkedNode*)list->tail) {
    prev_node = node;
    node = node->next;
  }
  int data = node->data;
  removeNode(list, node, prev_node);

  return data;
}

/**
 * Append a new node to the end of the list.
 * @param list {LinkedRoot*} The list should be appended to
 * @param data {int} The data should be stored
 */
void appendToList(LinkedRoot* list, int data) {
  LinkedNode* new_node = createNode(NULL, data);
  LinkedNode* pre_tail = list->tail;
  list->tail = new_node;
  if (NULL == pre_tail) {
    list->head = list->tail;
  } else {
    pre_tail->next = list->tail;
  }
  list->length++;
}

/**
 * Prepend a new node to the end of the list.
 * @param list {LinkedRoot*} The list should be prepended to
 * @param data {int} The data should be stored
 */
void prependToList(LinkedRoot* list, int data) {
  LinkedNode* pre_head = list->head;
  LinkedNode* new_node = createNode(pre_head, data);
  list->head = new_node;
  if (NULL == pre_head) {
    list->tail = list->head;
  }
  list->length++;
}

/**
 * Create a new SinglyLinkedList.
 * The head store no data.
 */
LinkedRoot* createSinglyLinkedList() {
  LinkedRoot* list = (LinkedRoot*)malloc(sizeof(LinkedRoot));
  list->length = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}

/**
 * Destroy the SinglyLinkedList.
 * @param list {LinkedRoot*} The list
 */
void destroyList(LinkedRoot* list) {
  LinkedNode* node = list->head;
  LinkedNode* next;
  while (NULL != node) {
    next = node->next;
    free(node);
    node = next;
  }
  free(list);
}

/**
 * Print nodes' data from head to tail.
 * @param list {LinkedRoot*} The list should be printed.
 */
void printList(LinkedRoot* list) {
  LinkedNode* node = list->head;
  while (NULL != node) {
    printf("%d ", node->data);
    node = node->next;
  }
}

#pragma GCC diagnostic pop