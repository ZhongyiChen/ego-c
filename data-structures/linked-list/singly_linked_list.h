#ifndef __LINKEDLIST_SINGLYLINKEDLIST_H
#define __LINKEDLIST_SINGLYLINKEDLIST_H

#include "../../zyc-libs/null.h"

/**
 * The structure of normal Singly LinkedNode
 */
typedef struct Node {
  int data;
  struct Node* next;
} LinkedNode;

/**
 * The structure of root Singly LinkedNode
 */
typedef struct Root {
  int length;
  struct LinkedNode* head;
  struct LinkedNode* tail;
} LinkedRoot;

void removeNodeByIndex(LinkedRoot* list, int index);

void removeNodesByData(LinkedRoot* list, int data);

void updateNodeByIndex(LinkedRoot* list, int index, int data);

int getIndexOfData(LinkedRoot* list, int data);

void insertNodeByIndex(LinkedRoot* list, int index, int data);

void appendToList(LinkedRoot* list, int data);

void prependToList(LinkedRoot* list, int data);

LinkedRoot* createSinglyLinkedList();

void printNodes(LinkedRoot* list);

#endif