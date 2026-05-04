#include <stdio.h>
#include "chained_list.h"

int main(int argc, const char *argv[])
{
    chained_list l;
    l=list_init();
    printf("l.count=%lu\n", l.count);

    element e;
    e=3.;
    list_insert_elem(&l, 0, e);
    printf("l.count=%lu\n", l.count);
    display_element(l.first->payload);
    display_element(l.last->payload);

    e=2.;
    list_insert_elem(&l, 0, e);
    printf("l.count=%lu\n", l.count);
    display_element(l.first->payload);
    display_element(l.last->payload);

    e=1.;
    list_insert_elem(&l, 0, e);
    printf("l.count=%lu\n", l.count);
    display_element(l.first->payload);
    display_element(l.last->payload);
    display_element(l.first->next->payload);
    display_element(l.last->prev->payload);

    e=4.;
    list_insert_elem(&l, 3, e);
    printf("l.count=%lu\n", l.count);
    display_element(l.last->payload);

    e=2.5;
    list_insert_elem(&l, 2, e);
    printf("l.count=%lu\n", l.count);

    display_element(l.first->payload);
    display_element(l.first->next->payload);
    display_element(l.first->next->next->payload);
    display_element(l.first->next->next->next->payload);
    display_element(l.first->next->next->next->next->payload);

    display_element(l.last->prev->prev->payload);

}