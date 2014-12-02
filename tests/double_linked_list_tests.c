#include "minunit.h"
#include <double_linked_list.h>

char *test_create() {
  List *list = List_create();
  mu_assert(list != NULL, "list should not be NULL");
  return NULL;
}

char *test_list_push_value_to_blank_list() {
  List *list = List_create();
  char *value = "foobar";
  list->push(list, value);
  mu_assert(list->last->value == value, "last node's value does not match pushed value");

  return NULL;
}

char *all_tests() {
  mu_run_test(test_create);
  mu_run_test(test_list_push_value_to_blank_list);

  return NULL;
}

RUN_TESTS(all_tests);
