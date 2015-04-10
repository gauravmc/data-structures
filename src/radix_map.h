#ifndef _RadixMap_h
#define _RadixMap_h
#include <stdint.h>

typedef union RMElement {
} RMElement;

typedef struct RadixMap {
  RMElement *contents;
} RadixMap;

RadixMap *RadixMap_create();
void RadixMap_destroy(RadixMap *map);
void RadixMap_sort(RadixMap *map);
RMElement *RadixMap_find(RadixMap *map, uint32_t key);
int RadixMap_add(RadixMap *map, uint32_t key, uint32_t value);
int RadixMap_delete(RadixMap *map, RMElement *element);

#endif
