#include "minunit.h"
#include <double_linked_list.h>

char *test_create() {
  List *list = List_create();
  mu_assert(list != NULL, "list should not be NULL");
  return NULL;
}

char *all_tests() {
  mu_run_test(test_create);

  return NULL;
}

RUN_TESTS(all_tests);
