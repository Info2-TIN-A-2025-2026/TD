#include "table_list_fixed_size.h"
#include <string.h>

list list_init(void)
{
    list l;
    l.count = 0;
    return l;
}

bool list_is_empty(const list l)
{
    return l.count == 0;
}

bool list_is_full(const list l)
{
    return l.count == LIST_SIZE;
}

int list_insert_elem(list *l, const size_t pos, const element e)
{
    // INFO: return 0 if OK, else <0

    // check if list not full
    if (list_is_full(*l))
    {
        printf("Error, list is full");
        return -1;
    }

    // check if pos coherent
    if (pos > l->count)
    {
        printf("Error, pos %zu incorrect\n", pos);
        return -2;
    }

    // move of cells (backward)
    // for (size_t i = l->count; i > pos; i--)
    // {
    //    memcpy(l->t + i, l->t + i - 1, sizeof(element));
    // }
    memmove(l->t +pos+1,l->t + pos, sizeof(element)*(l->count-pos));
    // copy e at pos
    memcpy(l->t + pos, &e, sizeof(element));

    // update count
    l->count++;
    return 0;
}

int list_remove_elem(list *l, const size_t pos)
{
    // INFO: return 0 if OK, else <0

    // check if list not full
    if (list_is_empty(*l))
    {
        printf("Error, list is empty");
        return -1;
    }

    // check if pos coherent
    if (pos >= l->count)
    {
        printf("Error, pos %zu incorrect\n", pos);
        return -2;
    }

    // move of cells (forward)
    //for (size_t i = pos; i<l->count-1; i++)
    //{
    //    memcpy(l->t + i , l->t + i +1, sizeof(element));
    //}
    memmove(l->t +pos,l->t + pos+1, sizeof(element)*(l->count-pos-1));
    // update count
    l->count--;
    return 0;
}

int list_get_elem(list l, const size_t pos, const element *e) {
    // INFO: return 0 if OK, else <0

    // check if list not full
    if (list_is_empty(l))
    {
        printf("Error, list is empty");
        return -1;
    }

    // check if pos coherent
    if (pos >= l.count)
    {
        printf("Error, pos %zu incorrect\n", pos);
        return -2;
    }
    memcpy((void*)e , l.t + pos, sizeof(element));
    return 0;
}