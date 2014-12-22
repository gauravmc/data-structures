#include "minunit.h"
#include "list_algorithms.h"
#include "assert.h"

List *prepare_list(char *words[], int len) {
  List *list = List_create();
  for(int i = 0; i < len; i++) {
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
  // list that needs sorting
  char *words[] = {"gaurav", "chande", "12345", "abcd", "abcd", "wxyz", "4444"};
  List *list = prepare_list(words, 7);
  List_modified_bubble_sort(list);
  mu_assert(is_sorted(list), "List was not alphabetically sorted.");

  char *words2[] = {"6", "5", "3", "1", "8", "7", "2", "4"};
  list = prepare_list(words2, 8);
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
  // list that needs sorting
  char *words[] = {"gaurav", "chande", "12345", "abcd", "abcd", "wxyz", "4444"};
  List *list = prepare_list(words, 7);
  list = List_merge_sort(list);
  mu_assert(is_sorted(list), "List was not alphabetically sorted.");

  char *words2[] = {"6", "5", "3", "1", "8", "7", "2", "4"};
  list = prepare_list(words2, 8);
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
