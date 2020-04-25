/**
 * @author       chenzhongyi <http://chenzhongyi.net/>
 * @copyright    2020 Zhongyi Chen.
 * 
 */

#include <malloc.h>
#include "../node/singly_linked_node.h"
#include "../../zyc-libs/null.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

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
 * Append a new node to the end of the list.
 * @param list {LinkedRoot*} The list should be appended to
 * @param data {int} The data should be stored
 */
void appendNode(LinkedRoot* list, int data) {
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
void prependNode(LinkedRoot* list, int data) {
  LinkedNode* new_node = createNode(NULL, data);
  LinkedNode* pre_head = list->head;
  new_node->next = pre_head;
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
 * Print nodes' data from head to tail.
 * @param list {LinkedRoot*} The list should be printed.
 */
void printNodes(LinkedRoot* list) {
  LinkedNode* node = list->head;
  while (NULL != node) {
    printf("%d ", node->data);
  }
  node = node->next;
  printf("\n");
}