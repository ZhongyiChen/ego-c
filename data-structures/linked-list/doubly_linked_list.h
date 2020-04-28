#ifndef __LINKEDLIST_DOUBLYLINKEDLIST_H
#define __LINKEDLIST_DOUBLYLINKEDLIST_H

#include "../../zyc-libs/null.h"

/**
 * The structure of normal Doubly LinkedNode
 */
typedef struct Node {
  int data;
  struct Node* prev;
  struct Node* next;
} LinkedNode;

/**
 * The structure of root Doubly LinkedNode
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

int unshiftToList(LinkedRoot* list, int data);

int shiftFromList(LinkedRoot* list);

int pushToList(LinkedRoot* list, int data);

int popFromList(LinkedRoot* list);

void appendToList(LinkedRoot* list, int data);

void prependToList(LinkedRoot* list, int data);

LinkedRoot* createDoublyLinkedList();

void destroyList(LinkedRoot* list);

void printList(LinkedRoot* list);

#endif