#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
    ListNode *first;
};

struct list_node
{
    int info;
    ListNode *next;
};

LinkedList *ll_create()
{
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->first = NULL;
    return l;
}

int ll_is_empty(LinkedList *l)
{
    return l->first == NULL;
}

void ll_insert(LinkedList *l, int v)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->info = v;
    node->next = l->first;
    l->first = node;
}

{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->info = v;
    node->next = NULL;

    if (l->first == NULL) {
        l->first = node;
    } else {
        ListNode *p = l->first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = node;
    }
}

int ll_size(LinkedList *l)
{
    int cnt = 0;
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        cnt++;
    }
    return cnt;
}

int ll_is_in(LinkedList *l, int v)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        if (p->info == v)
            return 1;
        p = p->next;
    }
    return 0;
}

int ll_remove(LinkedList *l, int v)
{
    ListNode *p = l->first;
    ListNode *prev = NULL;

    while (p != NULL)
    {
        if (p->info == v)
        {
            if (prev == NULL)
                l->first = p->next;
            else
                prev->next = p->next;

            free(p);
            return 1;
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }

    return 0;
}

void ll_remove_all(LinkedList *l, int v)
{
    while (ll_remove(l, v))
        ;
}

void ll_free(LinkedList *l)
{
    ListNode *p = l->first;
    while (p != NULL)
    {
        ListNode *t = p->next;
        free(p);
        p = t;
    }
    free(l);
}

void ll_print(LinkedList *l)
{
    for (ListNode *p = l->first; p != NULL; p = p->next)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}

LinkedList *ll_concatenate(LinkedList *l1, LinkedList *l2)
{
    LinkedList *new_list = ll_create();

    ListNode *p = l1->first;
    while (p != NULL) {
        ll_append(new_list, p->info);
        p = p->next;
    }

    p = l2->first;
    while (p != NULL) {
        ll_append(new_list, p->info);
        p = p->next;
    }

    return new_list;
}