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

char *test_get_set_remove() {
  DArray *array = DArray_create(sizeof(int), 100);
  int *el = DArray_new(array);
  *el = 50;
  DArray_set(array, 1, el);

  int *val = DArray_get(array, 1);
  mu_assert_equal(50, *val);

  int *val2 = DArray_remove(array, 1);
  mu_assert_equal(50, *val2);
  mu_assert_equal(NULL, array->contents[1]);
}

char *test_clear_destroy() {
  DArray *array = DArray_create(sizeof(int), 100);
  int *el = DArray_new(array);
  *el = 50;
  DArray_set(array, 1, el);

  DArray_clear(array);
  DArray_destroy(array);

  return NULL;
}

char *all_tests() {
  mu_run_test(test_dynamic_array_create);
  mu_run_test(test_get_set_remove);
  mu_run_test(test_clear_destroy);

  return NULL;
}

RUN_TESTS(all_tests);
