#include <double_linked_list.h>
#include <stdlib.h>

List *List_create() {
  return malloc(sizeof(List));
}
