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
  void (*shift)(void *self, void *value);
  void *(*unshift)(void *self);
  void (*clear)(void *self);
} List;

List *List_create();

#define EACH_NODE(L)\
    for(Node *_node = L->first; _node != NULL; _node = _node->next)

#endif
