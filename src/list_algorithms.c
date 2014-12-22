#include "list_algorithms.h"
#include "stdio.h"
#include "lib/debug.h"

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

List *merge(List *left, List *right) {
  List *result = List_create();

  while(left->count > 0 || right->count > 0) {
    if(left->count > 0 && right->count > 0) {
      if(strcmp(left->first->value, right->first->value) <= 0) {
        result->push(result, left->unshift(left));
      } else {
        result->push(result, right->unshift(right));
      }
    } else if(left->count > 0) {
      result->push(result, left->unshift(left));
    } else if(right->count > 0) {
      result->push(result, right->unshift(right));
    }
  }

  return result;
}

List *List_merge_sort(List *list) {
  if(list->count <= 1) return list;

  List *left = List_create();
  List *right = List_create();
  int mid = list->count/2;

  int index = 0;
  EACH_NODE(list) {
    if(index == mid) break;
    left->push(left, _node->value);
    index++;
  }

  index = 0;
  EACH_NODE(list) {
    if(index >= mid) right->push(right, _node->value);
    index++;
  }

  left = List_merge_sort(left);
  right = List_merge_sort(right);
  return merge(left, right);
}
