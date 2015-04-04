#include "dynamic_array.h"

DArray *DArray_create(size_t element_size, int max) {
  check(max > 0, "initial max must be > 0");

  DArray *array = malloc(sizeof(DArray));
  array->element_size = element_size;
  array->max = max;
  array->contents = calloc(max, sizeof(void *));
  array->end = 0;

  return array;
error:
  return NULL;
}

void DArray_clear(DArray *array) {
  for(int i=0; i<=array->max; i++) {
    if(array->contents[i] != NULL) {
      free(array->contents[i]);
    }
  }
}

void DArray_destroy(DArray *array) {
  free(array->contents);
  free(array);
}
