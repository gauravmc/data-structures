#include <double_linked_list.h>
#include <stdlib.h>
#include <assert.h>
#include <lib/debug.h>

Node *Node_create(void *value) {
  Node *node = malloc(sizeof(Node));
  node->prev = node->next = NULL;
  node->value = value;

  return node;
}

void List_push(void *self, void *value) {
  List *list = self;
  Node *node = Node_create(value);

  if(list->count == 0) {
    list->first = node;
  } else {
    node->prev = list->last;
    list->last->next = node;
  }
  list->last = node;
  list->count++;
}

void List_shift(void *self, void *value) {
  List *list = self;
  Node *node = Node_create(value);

  if(list->count == 0) {
    list->last = node;
  } else {
    node->next = list->first;
    list->first->prev = node;
  }
  list->first = node;
  list->count++;
}

void *List_remove(List *list, Node *node) {
  check(list->count > 0 && list->first && list->last, "List is empty.");

  Node *current = list->first;
  do {
    if (current == node) {
      if(node->prev) node->prev->next = node->next;
      if(node->next) node->next->prev = node->prev;
      break;
    }
    current = current->next;
  } while(current);

  if(list->count > 1) {
    if(list->first == node) {
      list->first = node->next;
    } else if(list->last == node) {
      list->last = node->prev;
    }
  } else {
    list->first = list->last = NULL;
  }

  void *value = node->value;
  free(node);
  list->count--;
  return value;
error:
  return NULL;
}

void *List_pop(void *self) {
  List *list = self;
  return List_remove(list, list->last);
}

void *List_unshift(void *self) {
  List *list = self;
  return List_remove(list, list->first);
}

void List_clear(void *self) {
  List *list = self;
  Node *current = list->first;
  do {
    free(current);
    list->count--;
    current = current->next;
  } while(current);
}

List *List_create() {
  List *list = malloc(sizeof(List));
  list->first = list->last = NULL;
  list->count = 0;
  list->push = List_push;
  list->pop = List_pop;
  list->shift = List_shift;
  list->unshift = List_unshift;
  list->clear = List_clear;

  return list;
}
