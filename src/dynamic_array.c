#include "dynamic_array.h"

DArray *DArray_create(size_t element_size, int max) {
  DArray *array = malloc(sizeof(DArray));
  array->element_size = element_size;
  array->max = max;
  array->contents = calloc(max, sizeof(void *));

  return array;
}
