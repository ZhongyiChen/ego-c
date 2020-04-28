#include "../data-structures/linked-list/singly_linked_list.h"
// #include <stdio.h>
extern int printf (const char *__restrict __format, ...);

int main() {
  LinkedRoot* list = createSinglyLinkedList();

  printf("Append 3 to list: \n");
  appendToList(list, 3);
  printList(list);
  printf("\n");

  printf("Append 4 to list: \n");
  appendToList(list, 4);
  printList(list);
  printf("\n");
  
  printf("Append 5 to list: \n");
  appendToList(list, 5);
  printList(list);
  printf("\n");
  
  printf("Prepend 2 to list: \n");
  prependToList(list, 2);
  printList(list);
  printf("\n");
  
  printf("Prepend 1 to list: \n");
  prependToList(list, 1);
  printList(list);
  printf("\n");
  
  printf("Remove node locates at index 2 of list: \n");
  removeNodeByIndex(list, 2);
  printList(list);
  printf("\n");
  
  printf("Insert 9 to index 2 of list: \n");
  insertNodeByIndex(list, 2, 9);
  printList(list);
  printf("\n");
  
  printf("Update node locates at index 2 of list with 7: \n");
  updateNodeByIndex(list, 2, 7);
  printList(list);
  printf("\n");
  
  return 0;
}