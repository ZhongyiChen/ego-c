/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * 
 */

#include <malloc.h>
#include "../../zyc-libs/null.h"
#include "doubly_linked_list.h"

// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wincompatible-pointer-types"

/**
 * Create a new node to the list.
 * @param next {LinkedNode*} Indicate the prev node
 * @param next {LinkedNode*} Indicate the next node
 * @param data {int} The data needed to be stored
 */
LinkedNode* createNode(LinkedNode* prev, LinkedNode* next, int data) {
  LinkedNode* node = (LinkedNode*)malloc(sizeof(LinkedNode));
  node->data = data;
  node->prev = prev;
  node->next = next;
  return node;
}


/**
 * Remove a node from the list.
 * @param list {LinkedRoot*} The list owned the node
 * @param node {LinkedNode*} The node needed to be removed
 */
void removeNode(LinkedRoot* list, LinkedNode* node) {
  if (NULL == node) {
    return;
  }
  if (list->head == list->tail) {
    list->head = list->tail = NULL;
  } else if (node == (LinkedNode*)list->head) {
    node->next->prev = NULL;
    list->head = node->next;
  } else if (node == (LinkedNode*)list->tail) {
    node->prev->next = NULL;
    list->tail = node->prev;
  } else {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
  free(node);
  list->length--;
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
  removeNode(list, node);

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
  LinkedNode* node = list->tail;
  int data = node->data;
  removeNode(list, node);

  return data;
}

/**
 * Append a new node to the end of the list.
 * @param list {LinkedRoot*} The list
 * @param data {int} The data should be stored
 */
void appendToList(LinkedRoot* list, int data) {
  LinkedNode* pre_tail = list->tail;
  LinkedNode* new_node = createNode(pre_tail, NULL, data);
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
 * @param list {LinkedRoot*} The list
 * @param data {int} The data should be stored
 */
void prependToList(LinkedRoot* list, int data) {
  LinkedNode* pre_head = list->head;
  LinkedNode* new_node = createNode(NULL, pre_head, data);
  list->head = new_node;
  if (NULL == pre_head) {
    list->tail = list->head;
  } else {
    pre_head->prev = list->head;
  }
  list->length++;
}

/**
 * Create a new doublyLinkedList.
 * The head store no data.
 */
LinkedRoot* createDoublyLinkedList() {
  LinkedRoot* list = (LinkedRoot*)malloc(sizeof(LinkedRoot));
  list->length = 0;
  list->head = NULL;
  list->tail = NULL;
  return list;
}

/**
 * Destroy the doublyLinkedList.
 * @param list {LinkedRoot*} The list
 */
void createDoublyLinkedList(LinkedRoot* list) {
  LinkedNode* node = list->head;
  LinkedNode* next;
  while (NULL != node) {
    next = node->next;
    free(node);
    node = next;
  }
  free(list);
}

#pragma GCC diagnostic pop