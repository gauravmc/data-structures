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
  int count = 0;

  EACH_NODE(list) { count++; }
  if(count != list->count) return 0;

  EACH_NODE(list) {
    if (_node != NULL && _node->next != NULL) {
      if (strcmp(_node->value, _node->next->value) > 0) {
        return 0;
      }
    }
  }

  return 1;
}

char *test_modified_bubble_sort() {
  List *list = prepared_list();

  // list that needs sorting
  List_modified_bubble_sort(list);
  mu_assert(is_sorted(list), "List was not alphabetically sorted.");

  // already sorted list
  List_modified_bubble_sort(list);
  mu_assert(is_sorted(list), "List was not alphabetically sorted.");

  // empty list
  list = List_create();
  List_modified_bubble_sort(list);
  mu_assert(is_sorted(list), "List was not alphabetically sorted.");

  return NULL;
}

char *test_merge_sort() {
  List *list = prepared_list();

  // list that needs sorting
  list = List_merge_sort(list);
  mu_assert(is_sorted(list), "List was not alphabetically sorted.");

  // already sorted list
  list = List_merge_sort(list);
  mu_assert(is_sorted(list), "List was not alphabetically sorted.");

  // empty list
  list = List_create();
  list = List_merge_sort(list);
  mu_assert(is_sorted(list), "List was not alphabetically sorted.");

  return NULL;
}

char *all_tests() {
  mu_run_test(test_modified_bubble_sort);
  mu_run_test(test_merge_sort);

  return NULL;
}

RUN_TESTS(all_tests);
