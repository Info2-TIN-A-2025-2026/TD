#include "table_list_dyn_size.h"
#include <stdlib.h>
#include <string.h>

list list_init(void)
{
    list l;
    l.count = 0;
    l.size = 0;
    return l;
}

bool list_is_empty(const list l)
{
    return l.count == 0;
}

bool list_is_full(const list l)
{
    return l.count == l.size;
}

int list_insert_elem(list *l, const size_t pos, const element e)
{
    // INFO: return 0 if OK, else <0

    // check if list not full
    if (list_is_full(*l))
    {
        element *tmp = NULL;
        tmp = (element *)realloc(l->t, sizeof(element) * (l->size + GROWING_SIZE));
        // merci de terminer pour la prochaine fois
    }

    // check if pos coherent
    if (pos > l->count)
    {
        printf("Error, pos %zu incorrect\n", pos);
        return -2;
    }
    // move of cells (backward)
    memmove(l->t + pos + 1, l->t + pos, sizeof(element) * (l->count - pos));
    //  copy e at pos
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
    memmove(l->t + pos, l->t + pos + 1, sizeof(element) * (l->count - pos - 1));
    // update count
    l->count--;
    return 0;
}

int list_get_elem(list l, const size_t pos, const element *e)
{
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
    memcpy((void *)e, l.t + pos, sizeof(element));
    return 0;
}