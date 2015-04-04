#include "minunit.h"
#include "dynamic_array.h"

char *test_dynamic_array_create() {
  DArray *array = DArray_create(sizeof(int), 100);
  mu_assert(array != NULL, "should be a DArray");
  mu_assert_equal(100, array->max);
  mu_assert_equal(sizeof(int), array->element_size);
  mu_assert(array->contents != NULL, "array contents should not be NULL");

  return NULL;
}

char *all_tests() {
  mu_run_test(test_dynamic_array_create);

  return NULL;
}

RUN_TESTS(all_tests);
