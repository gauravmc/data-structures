#include <double_linked_list.h>
#include <stdlib.h>
#include <lib/debug.h>

void List_push(void *self, void *value) {
  List *list = self;
  Node *node = Node_create();
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

void *List_pop(void *self) {
  List *list = self;

  if(list->count > 0) {
    Node *old_last = list->last;

    if(list->count > 1) {
      list->last = old_last->prev;
    } else {
      list->first = list->last = NULL;
    }

    void *value = old_last->value;
    free(old_last);
    list->count--;

    return value;
  } else {
    return NULL;
  }
}

List *List_create() {
  List *list = malloc(sizeof(List));
  list->first = list->last = NULL;
  list->count = 0;
  list->push = List_push;
  list->pop = List_pop;

  return list;
}

Node *Node_create() {
  Node *node = malloc(sizeof(Node));
  node->prev = node->next = NULL;

  return node;
}
