#include "dynamic_array.h"

DArray *DArray_create(size_t element_size, int max) {
  check(max > 0, "initial max must be > 0");

  DArray *darray = malloc(sizeof(DArray));
  darray->element_size = element_size;
  darray->max = max;
  darray->contents = calloc(max, sizeof(void *));
  darray->end = 0;

  return darray;
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
