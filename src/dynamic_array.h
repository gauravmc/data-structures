#ifndef _DArray_h
#define _DArray_h
#include <stdlib.h>

typedef struct DArray {
  int max;
  size_t element_size;
  void **contents;
} DArray;

DArray *DArray_create(size_t element_size, int max);

#endif
