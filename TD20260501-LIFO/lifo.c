#include "lifo.h"

lifo lifo_init(void)
{
    return list_init();
}
int lifo_push(lifo *l, const element e)
{
   return list_insert_elem(l, l->count, e);
}
int lifo_pop(lifo *l, element *e)
{
    int ret=0;
    ret=list_get_elem(*l, l->count-1, e);
    if(0==ret) { // if (!ret)
        return list_remove_elem(l, l->count-1);
    }
    return ret;
}
void lifo_free(lifo *l)
{
    list_free(l);
}
