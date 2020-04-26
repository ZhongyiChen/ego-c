#ifndef __LINKEDLIST_SINGLYLINKEDLIST_H
#define __LINKEDLIST_SINGLYLINKEDLIST_H

#include "../node/singly_linked_node.h"
#include "../../zyc-libs/null.h"

void removeNodeByIndex(LinkedRoot* list, int index);

void removeNodesByData(LinkedRoot* list, int data);

void updateNodeByIndex(LinkedRoot* list, int index, int data);

int getIndexOfData(LinkedRoot* list, int data);

void insertNodeByIndex(LinkedRoot* list, int index, int data);

void appendNode(LinkedRoot* list, int data);

void prependNode(LinkedRoot* list, int data);

LinkedRoot* createSinglyLinkedList();

void printNodes(LinkedRoot* list);

#endif