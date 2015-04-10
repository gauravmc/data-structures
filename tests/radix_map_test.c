#include "minunit.h"
#include "radix_map.h"

char *test_create() {
  RadixMap *map = RadixMap_create();
  mu_assert(map != NULL, "Failed to create RadixMap");

  return NULL;
}

char *all_tests() {
  mu_run_test(test_create);

  return NULL;
}

RUN_TESTS(all_tests);
