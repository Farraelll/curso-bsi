//Oitavo exercício desenvolvido pelo professor;
//O objetivo é concatenar duas listas linkadas.

#include "linkedlist.h"
#include <stdio.h>

int main(void)
{
    LinkedList *l;

    printf("Create a list with 10 elements\n");
    l = ll_create();
    for (int i = 0; i < 10; i++)
        ll_insert(l, i);
    ll_print(l);
    printf("------------\n\n");

    printf("Removing the first zero\n");
    ll_remove(l, 0);
    ll_print(l);
    printf("There are %d elements in the list.\n", ll_size(l));
    printf("------------\n\n");

    printf("Adding ones and removing ones\n");
    for (int i = 0; i < 5; i++)
        ll_insert(l, 1);
    ll_print(l);
    ll_remove_all(l, 1);
    ll_print(l);
    printf("------------\n\n");

    printf("Checking whether 4 and 10 are in the list\n");
    int values[5] = {-1, 0, 4, 5, 10};
    for (int i = 0; i < 5; i++)
        if (ll_is_in(l, values[i]))
            printf("%d is in the list.\n", values[i]);
        else
            printf("%d is NOT in the list.\n", values[i]);

    ll_free(l);

    return 0;
}