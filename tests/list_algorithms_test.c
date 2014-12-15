#include "minunit.h"
#include "list_algorithms.h"

char *test_something() {
  mu_assert_equal(1, 1);

  return NULL;
}

char *all_tests() {
  mu_run_test(test_something);

  return NULL;
}

RUN_TESTS(all_tests);
