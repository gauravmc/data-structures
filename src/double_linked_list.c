#include <double_linked_list.h>
#include <stdlib.h>
#include <lib/debug.h>

void List_push(void *self, void *value) {
  List *list = self;
  ListNode *node = malloc(sizeof(ListNode));
  node->value = value;
  list->last = node;
}

List *List_create() {
  List *list = malloc(sizeof(List));
  list->push = List_push;
  return list;
}
