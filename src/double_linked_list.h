#ifndef _List_h
#define _List_h

typedef struct {
  struct ListNode *next;
  struct ListNode *prev;
  void *value;
} ListNode;

typedef struct {
  int count;
  ListNode *first;
  ListNode *last;

  void (*push)(void *self, void *value);
} List;

void List_push();
List *List_create();

#endif
