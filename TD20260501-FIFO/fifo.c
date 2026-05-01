#include "fifo.h"

fifo fifo_init(void)
{
    return list_init();
}
int fifo_enqueue(fifo *l, const element e)
{
   return list_insert_elem(l, 0, e);
}
int fifo_dequeue(fifo *l, element *e)
{
    int ret=0;
    ret=list_get_elem(*l, l->count-1, e);
    if(0==ret) { // if (!ret)
        return list_remove_elem(l, l->count-1);
    }
    return ret;
}
void fifo_free(fifo *l)
{
    list_free(l);
}
