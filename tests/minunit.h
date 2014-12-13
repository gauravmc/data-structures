#undef NDEBUG
#ifndef _minunit_h
#define _minunit_h

#include <stdio.h>
#include <lib/debug.h>
#include <stdlib.h>

#define log_failure(M, ...) fprintf(stderr, "[FAILED] (%s:%d) %s\n", __FILE__, __LINE__, M, ##__VA_ARGS__)

char *message = NULL;
int tests_run;

#define mu_assert(test, message) if (!(test)) { log_failure(message); return message; }
#define mu_assert_equal(exp, act) {\
  if (!(exp == act)) {\
    message = "Expected did not match actual value";\
    log_failure(message);\
    return message;\
  }\
}
#define mu_run_test(test) \
    message = test(); tests_run++; if (message) return message;

#define RUN_TESTS(name) int main() {\
  char *result = name();\
  if (result == 0) {\
    printf("ALL TESTS PASSED\n");\
  }\
  printf("Tests run: %d\n", tests_run);\
  exit(result != 0);\
}

#endif
