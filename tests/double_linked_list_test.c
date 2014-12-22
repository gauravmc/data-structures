#include "minunit.h"
#include <double_linked_list.h>

List *prepared_list() {
  List *list = List_create();
  list->push(list, "foo");
  list->push(list, "bar");
  list->push(list, "baz");
  return list;
}

char *test_create() {
  List *list = List_create();
  mu_assert(list != NULL, "list should not be NULL");
  mu_assert_equal(NULL, list->first);
  mu_assert_equal(NULL, list->last);
  mu_assert_equal(0, list->count);
  return NULL;
}

char *test_list_push_value_to_blank_list() {
  List *list = List_create();
  char *value = "foobar";

  list->push(list, value);

  mu_assert_equal(value, list->last->value);
  mu_assert_equal(value, list->first->value);
  mu_assert_equal(NULL, list->last->next);
  mu_assert_equal(NULL, list->last->prev);
  mu_assert_equal(1, list->count);

  return NULL;
}

char *test_push_multiple_values() {
  List *list = List_create();

  list->push(list, "foo");
  list->push(list, "bar");
  list->push(list, "baz");

  mu_assert_equal("baz", list->last->value);
  mu_assert_equal("foo", list->first->value);
  mu_assert_equal("bar", list->last->prev->value);
  mu_assert_equal(3, list->count);

  return NULL;
}

char *test_pop() {
  List *list = prepared_list();

  void *value = list->pop(list);
  mu_assert_equal("baz", value);
  mu_assert_equal("bar", list->last->value);
  mu_assert_equal(2, list->count);

  value = list->pop(list);
  mu_assert_equal("bar", value);
  mu_assert_equal("foo", list->last->value);
  mu_assert_equal("foo", list->first->value);
  mu_assert_equal(1, list->count);

  value = list->pop(list);
  mu_assert_equal("foo", value);
  mu_assert_equal(NULL, list->last);
  mu_assert_equal(NULL, list->first);
  mu_assert_equal(0, list->count);

  return NULL;
}

char *test_list_shift_value_to_blank_list() {
  List *list = List_create();
  char *value = "foobar";

  list->shift(list, value);

  mu_assert_equal(value, list->last->value);
  mu_assert_equal(value, list->first->value);
  mu_assert_equal(NULL, list->last->next);
  mu_assert_equal(NULL, list->last->prev);
  mu_assert_equal(1, list->count);

  return NULL;
}

char *test_shift_multiple_values() {
  List *list = List_create();

  list->shift(list, "foo");
  list->shift(list, "bar");
  list->shift(list, "baz");

  mu_assert_equal("foo", list->last->value);
  mu_assert_equal("baz", list->first->value);
  mu_assert_equal("bar", list->last->prev->value);
  mu_assert_equal(3, list->count);

  return NULL;
}

char *test_unshift() {
  List *list = prepared_list();

  void *value = list->unshift(list);
  mu_assert_equal("foo", value);
  mu_assert_equal("bar", list->first->value);
  mu_assert_equal(2, list->count);

  value = list->unshift(list);
  mu_assert_equal("bar", value);
  mu_assert_equal("baz", list->last->value);
  mu_assert_equal("baz", list->first->value);
  mu_assert_equal(1, list->count);

  value = list->unshift(list);
  mu_assert_equal("baz", value);
  mu_assert_equal(NULL, list->last);
  mu_assert_equal(NULL, list->first);
  mu_assert_equal(0, list->count);

  return NULL;
}

char *test_empty_list() {
  List *list = prepared_list();

  list->empty(list);
  mu_assert_equal(0, list->count);

  return NULL;
}

char *test_destroy_list() {
  List *list = prepared_list();
  List_destroy(list);

  return NULL;
}

char *test_each_node_macro() {
  char *words[] = {"gaurav", "chande", "12345", "abcd", "abcd", "wxyz", "4444"};
  List *list = List_create();
  for(int i=0; i < 7; i++) {
    list->push(list, words[i]);
  }

  int index = 0;
  EACH_NODE(list) {
    mu_assert_equal(words[index], _node->value);
    index++;
  }

  return NULL;
}

char *all_tests() {
  mu_run_test(test_create);
  mu_run_test(test_list_push_value_to_blank_list);
  mu_run_test(test_push_multiple_values);
  mu_run_test(test_pop);
  mu_run_test(test_list_shift_value_to_blank_list);
  mu_run_test(test_shift_multiple_values);
  mu_run_test(test_unshift);
  mu_run_test(test_empty_list);
  mu_run_test(test_each_node_macro);
  mu_run_test(test_destroy_list);

  return NULL;
}

RUN_TESTS(all_tests);
