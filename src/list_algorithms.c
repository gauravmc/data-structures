#include "list_algorithms.h"
#include "stdio.h"
#include "string.h"

void swap(Node *cur, Node *next, List *list) {
  next->prev = cur->prev;
  cur->next = next->next;
  next->next = cur;
  cur->prev = next;

  if(next->prev) next->prev->next = next;
  if(cur->next) cur->next->prev = cur;

  if(list->first == cur) list->first = next;
  if(list->last == next) list->last = cur;
}

void List_modified_bubble_sort(List *list) {
  Node *cur = NULL;
  Node *next = NULL;
  int swapped;

  do {
    swapped = 0;

    EACH_NODE(list) {
      cur = _node;
      next = _node->next;
      if (cur != NULL && next != NULL) {
        if (strcmp(cur->value, next->value) > 0) {
          swap(cur, next, list);
          swapped = 1;
        }
      }
    }
  } while(swapped);
}
