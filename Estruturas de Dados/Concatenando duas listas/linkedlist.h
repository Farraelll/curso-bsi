#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct list LinkedList;
typedef struct list_node ListNode;

LinkedList *ll_create();

void ll_insert(LinkedList *l, int v);

void ll_insert_sorted(LinkedList *l, int v);

void ll_append(LinkedList *l, int v);

int ll_remove(LinkedList *l, int v);

void ll_remove_all(LinkedList *l, int v);

int ll_size(LinkedList *l);

int ll_is_in(LinkedList *l, int v);

int ll_is_empty(LinkedList *l);

int ll_is_sorted(LinkedList *l);

LinkedList *ll_reversed(LinkedList *l);

LinkedList *ll_concatenate(LinkedList *l1, LinkedList *l2);

void ll_free(LinkedList *l);

void ll_print(LinkedList *l);

#endif