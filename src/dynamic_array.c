#include "dynamic_array.h"

DArray *DArray_create(size_t element_size, int max) {
  check(max > 0, "initial max must be > 0");

  DArray *darray = malloc(sizeof(DArray));
  darray->element_size = element_size;
  darray->expand_rate = max * 2;
  darray->max = max;
  darray->contents = calloc(max, sizeof(void *));
  darray->end = 0;

  return darray;
error:
  return NULL;
}

int _DArray_resize(DArray *darray, int new_size) {
  darray->max = new_size;
  check(darray->max > 0, "The newsize must be > 0.");

  void *contents = realloc(darray->contents, new_size * sizeof(void *));
  darray->contents = contents;

  return 1;
error:
  return 0;
}

void DArray_expand(DArray *darray) {
  int old_max = darray->max;
  if(_DArray_resize(darray, old_max + (int)darray->expand_rate)) {
    memset(darray->contents + old_max, 0, darray->expand_rate + 1);
  }
}

void DArray_contract(DArray *darray) {
  int new_size = darray->end < (int)darray->expand_rate ? (int)darray->expand_rate : darray->end;
  _DArray_resize(darray, new_size + 1);
}

void DArray_push(DArray *darray, void *el) {
  darray->contents[darray->end] = el;
  darray->end++;

  if(darray->end >= darray->max) {
    DArray_expand(darray);
  }
}

void *DArray_pop(DArray *darray) {
  check(darray->end > 0, "trying to pop from empty array");
  void *el = DArray_remove(darray, darray->end - 1);
  darray->end--;
  return el;

  if(darray->end < (darray->max - (int)darray->expand_rate)) {
    DArray_contract(darray);
  }
error:
  return NULL;
}

void DArray_clear(DArray *darray) {
  for(int i=0; i<=darray->max; i++) {
    if(darray->contents[i] != NULL) {
      free(darray->contents[i]);
    }
  }
}

void DArray_destroy(DArray *darray) {
  free(darray->contents);
  free(darray);
}
