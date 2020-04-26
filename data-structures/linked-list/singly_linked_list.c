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
 * Remove a node from the list.
 * @param list {LinkedRoot*} The list owned the node
 * @param node {LinkedNode*} The node needed to be removed
 * @param pre_node {LinkedNode*} One node before the node
 */
LinkedNode* removeNode(LinkedRoot* list, LinkedNode* node, LinkedNode* pre_node) {
  if (NULL == node) {
    return;
  }
  if (list->head == list->tail) {
    list->head = list->tail = NULL;
  } else if (node == list->head) {
    list->head = node->next;
  } else {
    if (NULL != pre_node) {
      pre_node->next = node->next;
    } else {
      pre_node = list->head;
      while (pre_node->next != node)
        pre_node = pre_node->next;
      pre_node->next = node->next;
    }
    if (list->tail == node) list->tail = pre_node;
  }
  free(node);
  list->length--;
  return node;
}

/**
 * Remove a node which meets the index you indicate.
 * @param list {LinkedRoot*} The list owned the removed node
 * @param index {int} The index that node located at
 */
void removeNodeByIndex(LinkedRoot* list, int index) {
  if (index + 1 > list->length) {
    printf("Error: no such index! Nothing could be removed.\n");
    return;
  }
  LinkedNode* pre_node = NULL;
  LinkedNode* node = list->head;      // The default node
  int i = 0;
  for (; i < index; i++) {
    pre_node = node;
    node = node->next;
  }
  removeNode(list, node, pre_node);
}

/**
 * Remove the nodes which equal to the indicated data.
 * @param list {LinkedRoot*} The list owned the removed node
 * @param data {int} The value
 */
void removeNodesByData(LinkedRoot* list, int data) {
  LinkedNode* pre_node = NULL;
  LinkedNode* node = list->head;      // The default node
  int i = 0;
  for (; i < list->length; i++) {
    if (NULL != node) return;
    if (data == node->data) removeNode(list, node, pre_node);
    pre_node = node;
    node = node->next;
  }
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
 * @param data {int} The value
 * @param index {int} The index that node should locate at
 */
void insertNodeByIndex(LinkedRoot* list, int data, int index) {
  if (0 == index) {
    prependNode(list, data);
    return;
  }
  if (list->length == index) {
    appendNode(list, data);
    return;
  }
  if (index > list->length) {
    printf("Error: \
      The length of current list is %d, \
      index shouldn't larger than that. \
    ");
    return;
  }
  LinkedNode* pre_node = list->head;
  int i = 0;
  for (; i < index; i++) {
    pre_node = pre_node->next;
  }
  LinkedNode* new_node = createNode(pre_node->next, data);
  pre_node->next = new_node;
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