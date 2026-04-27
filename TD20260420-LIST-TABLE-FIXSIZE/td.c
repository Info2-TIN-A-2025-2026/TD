#include <stdio.h>
#include "table_list_fixed_size.h"

int main(int argc, const char *argv[])
{
    list l;
    l = list_init();

    element e = 3.;
    list_insert_elem(&l, 0, e);
    e = 2.;
    list_insert_elem(&l, 0, e);
    e = 4.;
    list_insert_elem(&l, 2, e);
    e = 1;
    list_insert_elem(&l, 0, e);
    e = 5;
    list_insert_elem(&l, 4, e);
    e = 6;
    list_insert_elem(&l, 6, e);

    printf("l.count=%lu\n", l.count);
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        printf("%lu ", i);
        display_element(l.t[i]);
    }

    printf("---\n");
    list_remove_elem(&l,3);
    printf("l.count=%lu\n", l.count);
    for (size_t i = 0; i < LIST_SIZE; i++)
    {
        printf("%lu ", i);
        display_element(l.t[i]);
    }
    printf("---\n");
    list_get_elem(l, 2, &e);
    display_element(e);
    return 0;
}