#include "minunit.h"
#include "list_algorithms.h"
#include "assert.h"

List *prepared_list() {
  char *words[] = {"gaurav", "chande", "12345", "abcd", "abcd", "wxyz", "4444"};
  List *list = List_create();
  for(int i = 0; i < 7; i++) {
    list->push(list, words[i]);
  }
  return list;
}

int is_sorted(List *list) {
  Node *cur = NULL;
  Node *next = NULL;

  EACH_NODE(list) {
    cur = _node;
    next = _node->next;
    if (cur != NULL && next != NULL) {
      if (strcmp(cur->value, next->value) > 0) {
        return 0;
      }
    }
  }

  return 1;
}

char *test_modified_bubble_sort() {
  List *list = prepared_list();
  List_modified_bubble_sort(list);
  mu_assert(is_sorted(list), "List was not sorted as alphabetically.");

  return NULL;
}

char *all_tests() {
  mu_run_test(test_modified_bubble_sort);

  return NULL;
}

RUN_TESTS(all_tests);
