#ifndef _DArray_h
#define _DArray_h
#include <stdlib.h>
#include "lib/debug.h"

typedef struct DArray {
  int end;
  int max;
  size_t element_size;
  size_t expand_rate;
  void **contents;
} DArray;

DArray *DArray_create(size_t element_size, int max);
void DArray_clear(DArray *darray);
void DArray_destroy(DArray *darray);
void DArray_expand(DArray *darray);
void DArray_contract(DArray *darray);
void DArray_push(DArray *darray, void *el);
void *DArray_pop(DArray *darray);

static inline void DArray_set(DArray *darray, int index, void *el) {
  check(index < darray->max, "DArray attempt to set past max");
  if(index > darray->end) darray->end = index;
  darray->contents[index] = el;
error:
  return;
}

static inline void *DArray_get(DArray *darray, int index) {
  check(index < darray->max, "DArray attempt to get past max");
  return darray->contents[index];
error:
  return NULL;
}

static inline void *DArray_remove(DArray *darray, int index) {
  check(index < darray->max, "DArray attempt to remove past max");
  void *el = darray->contents[index];
  darray->contents[index] = NULL;
  return el;
error:
  return NULL;
}

static inline void *DArray_new(DArray *darray) {
  check(darray->element_size > 0, "0 size dynamic darray");
  return malloc(darray->element_size);
error:
  return NULL;
}

#endif
