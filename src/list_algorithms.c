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
  int swapped;

  do {
    swapped = 0;

    EACH_NODE(list) {
      if (_node != NULL && _node->next != NULL) {
        if (strcmp(_node->value, _node->next->value) > 0) {
          swap(_node, _node->next, list);
          swapped = 1;
        }
      }
    }
  } while(swapped);
}
