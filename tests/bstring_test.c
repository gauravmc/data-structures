#include "minunit.h"
#include "lib/debug.h"
#include "lib/bstrlib.h"

char *test_different_functions() {
  // create + length
  bstring string1 = bfromcstr("string");
  mu_assert_equal(6, blength(string1));

  // bassign, biseq
  bstring string2 = bfromcstr("foo");
  bassign(string2, string1);
  mu_assert(strcmp(bdata(string1), bdata(string2)) == 0, "both strings should be equal");
  mu_assert(biseq(string1, string2) == 1, "both strings should be equal");

  // bconcat
  bstring string2 = bfromcstr("foo");
  string1 = bfromcstr("Hello");
  string2 = bfromcstr(", World!");
  bconcat(string1, string2);
  mu_assert(strcmp("Hello, World!", bdata(string1)) == 0, "returned string not as expected");

  // bsplit
  string1 = bfromcstr("foo, bar, baz");
  struct bstrList *words;
  words = bsplit(string1, ',');
  mu_assert(strcmp("foo", bdata(words->entry[0])) == 0, "returned string not as expected");

  return NULL;
}

char *all_tests() {
  mu_run_test(test_different_functions);

  return NULL;
}

RUN_TESTS(all_tests);
