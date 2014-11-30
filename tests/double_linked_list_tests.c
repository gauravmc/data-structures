#include "minunit.h"

char *test_something() {
  mu_assert(5 == 5, "should be true");
  return NULL;
}

char *all_tests() {
  mu_run_test(test_something);

  return NULL;
}

RUN_TESTS(all_tests);
