#include "radix_map.h"
#include <stdlib.h>

RadixMap *RadixMap_create() {
  RadixMap *map = malloc(sizeof(RadixMap));

  return map;
}
