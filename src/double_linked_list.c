#include <double_linked_list.h>
#include <stdlib.h>
#include <lib/debug.h>

void List_push(void *self, void *value) {
  List *list = self;
  ListNode *node = malloc(sizeof(ListNode));
  node->value = value;

  if(list->count == 0) {
    list->first = node;
  } else {
    node->prev = list->last;
    list->last->next = node;
  }

  list->last = node;
  list->count++;
}

List *List_create() {
  List *list = malloc(sizeof(List));
  list->count = 0;
  list->push = List_push;
  return list;
}
