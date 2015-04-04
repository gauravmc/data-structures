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

char *test_expand_contract() {
  DArray *darray = DArray_create(sizeof(int), 100);
  int *el = DArray_new(darray);
  *el = 50;
  DArray_set(darray, 99, el);

  int old_max = darray->max;
  DArray_expand(darray);
  mu_assert_equal(old_max + (int)darray->expand_rate, darray->max);

  int *val = DArray_get(darray, 99);
  mu_assert_equal(50, *val);

  DArray_contract(darray);
  mu_assert((unsigned int)darray->max == darray->expand_rate + 1, "Should stay at the expand_rate at least.");

  DArray_contract(darray);
  mu_assert((unsigned int)darray->max == darray->expand_rate + 1, "Should stay at the expand_rate at least.");

  val = DArray_get(darray, 99);
  mu_assert_equal(50, *val);

  return NULL;
}

char *test_push() {
  DArray *darray = DArray_create(sizeof(int), 100);
  int *el = DArray_new(darray);
  *el = 50;
  DArray_push(darray, el);
  DArray_push(darray, el);
  DArray_push(darray, el);

  int *val = DArray_get(darray, 0);
  mu_assert_equal(50, *val);
  val = DArray_get(darray, 1);
  mu_assert_equal(50, *val);
  val = DArray_get(darray, 2);
  mu_assert_equal(50, *val);

  mu_assert_equal(100, darray->max);
  DArray_set(darray, 99, el);
  DArray_push(darray, el);
  DArray_push(darray, el);
  DArray_push(darray, el);

  mu_assert_equal(300, darray->max);
  val = DArray_get(darray, 101);
  mu_assert_equal(50, *val);

  return NULL;
}

char *test_pop() {
  DArray *darray = DArray_create(sizeof(int), 100);
  int *el = DArray_new(darray);
  *el = 50;
  DArray_push(darray, el);
  el = DArray_new(darray);
  *el = 60;
  DArray_push(darray, el);
  el = DArray_new(darray);
  *el = 70;
  DArray_push(darray, el);

  int *val = DArray_pop(darray);
  mu_assert_equal(2, darray->end);
  mu_assert_equal(70, *val);
  val = DArray_pop(darray);
  mu_assert_equal(60, *val);
  val = DArray_pop(darray);
  mu_assert_equal(50, *val);

  return NULL;
}

char *all_tests() {
  mu_run_test(test_dynamic_array_create);
  mu_run_test(test_get_set_remove);
  mu_run_test(test_clear_destroy);
  mu_run_test(test_expand_contract);
  mu_run_test(test_push);
  mu_run_test(test_pop);

  return NULL;
}

RUN_TESTS(all_tests);
