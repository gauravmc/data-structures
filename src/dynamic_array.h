#ifndef _DArray_h
#define _DArray_h
#include <stdlib.h>
#include "lib/debug.h"

typedef struct DArray {
  int end;
  int max;
  size_t element_size;
  void **contents;
} DArray;

DArray *DArray_create(size_t element_size, int max);
void DArray_clear(DArray *array);
void DArray_destroy(DArray *array);

static inline void DArray_set(DArray *array, int index, void *el) {
  check(index < array->max, "DArray attempt to set past max");
  if(index > array->end) array->end = index;
  array->contents[index] = el;
error:
  return;
}

static inline void *DArray_get(DArray *array, int index) {
  check(index < array->max, "DArray attempt to get past max");
  return array->contents[index];
error:
  return NULL;
}

static inline void *DArray_remove(DArray *array, int index) {
  check(index < array->max, "DArray attempt to remove past max");
  void *el = array->contents[index];
  array->contents[index] = NULL;
  return el;
error:
  return NULL;
}

static inline void *DArray_new(DArray *array) {
  check(array->element_size > 0, "0 size dynamic array");
  return malloc(array->element_size);
error:
  return NULL;
}

#endif
