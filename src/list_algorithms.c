#include "list_algorithms.h"
#include "stdio.h"
#include "lib/debug.h"

void swap(Node *cur, Node *next) {
  void *temp = cur->value;
  cur->value = next->value;
  next->value = temp;
}

void List_modified_bubble_sort(List *list) {
  int swapped;

  do {
    swapped = 0;

    EACH_NODE(list) {
      if (_node != NULL && _node->next != NULL) {
        if (strcmp(_node->value, _node->next->value) > 0) {
          swap(_node, _node->next);
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

  List_destroy(left);
  List_destroy(right);
  return result;
}

List *List_merge_sort(List *list) {
  if(list->count <= 1) return list;

  List *left = List_create();
  List *right = List_create();
  int mid = list->count/2;

  EACH_NODE(list) {
    if(mid > 0) {
      right->push(right, _node->value);
    } else {
      left->push(left, _node->value);
    }
    mid--;
  }

  left = List_merge_sort(left);
  right = List_merge_sort(right);
  return merge(left, right);
}
