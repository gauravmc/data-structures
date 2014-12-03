#ifndef _List_h
#define _List_h

typedef struct ListNode {
  struct ListNode *next;
  struct ListNode *prev;
  void *value;
} ListNode;

typedef struct {
  int count;
  ListNode *first;
  ListNode *last;

  void (*push)(void *self, void *value);
  void *(*pop)(void *self);
} List;

void List_push(void *self, void *value);
void *List_pop(void *self);
List *List_create();

#endif
