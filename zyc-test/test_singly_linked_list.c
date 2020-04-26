#include "../data-structures/linked-list/singly_linked_list.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

int main() {
  LinkedRoot* list = createSinglyLinkedList();
  printf("Append 3 to list: \n");
  appendNode(list, 3);
  printNodes(list);
  printf("\n");
  printf("Append 4 to list: \n");
  appendNode(list, 4);
  printNodes(list);
  printf("\n");
  printf("Append 5 to list: \n");
  appendNode(list, 5);
  printNodes(list);
  printf("\n");
  printf("Prepend 2 to list: \n");
  prependNode(list, 2);
  printNodes(list);
  printf("\n");
  printf("Prepend 1 to list: \n");
  prependNode(list, 1);
  printNodes(list);
  printf("\n");
  printf("Remove node locates at index 2 of list: \n");
  removeNodeByIndex(list, 2);
  printNodes(list);
  printf("\n");
  printf("Insert 9 to index 2 of list: \n");
  insertNodeByIndex(list, 2, 9);
  printNodes(list);
  printf("\n");
  printf("Update node locates at index 2 of list with 7: \n");
  updateNodeByIndex(list, 2, 7);
  printNodes(list);
  printf("\n");
  return 0;
}