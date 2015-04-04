#include "minunit.h"
#include "dynamic_array.h"

char *test_dynamic_array_create() {
  DArray *darray = DArray_create(sizeof(int), 100);
  mu_assert(darray != NULL, "should be a DArray");
  mu_assert_equal(100, darray->max);
  mu_assert_equal(sizeof(int), darray->element_size);
  mu_assert(darray->contents != NULL, "darray contents should not be NULL");

  return NULL;
}

char *test_get_set_remove() {
  DArray *darray = DArray_create(sizeof(int), 100);
  int *el = DArray_new(darray);
  *el = 50;
  DArray_set(darray, 1, el);

  int *val = DArray_get(darray, 1);
  mu_assert_equal(50, *val);

  int *val2 = DArray_remove(darray, 1);
  mu_assert_equal(50, *val2);
  mu_assert_equal(NULL, darray->contents[1]);
}

char *test_clear_destroy() {
  DArray *darray = DArray_create(sizeof(int), 100);
  int *el = DArray_new(darray);
  *el = 50;
  DArray_set(darray, 1, el);

  DArray_clear(darray);
  DArray_destroy(darray);

  return NULL;
}

char *all_tests() {
  mu_run_test(test_dynamic_array_create);
  mu_run_test(test_get_set_remove);
  mu_run_test(test_clear_destroy);

  return NULL;
}

RUN_TESTS(all_tests);
