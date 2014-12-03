#ifndef _List_h
#define _List_h

typedef struct Node {
  struct Node *next;
  struct Node *prev;
  void *value;
} Node;

typedef struct {
  int count;
  Node *first;
  Node *last;

  void (*push)(void *self, void *value);
  void *(*pop)(void *self);
} List;

void List_push(void *self, void *value);
void *List_pop(void *self);
List *List_create();

#endif
