#include <stdio.h>
#include "fifo.h"

int main(int argc, const char *argv[])
{
    fifo l;
    l = fifo_init();

    element e;

    e=1.;
    fifo_enqueue(&l, e);
    e=2.;
    fifo_enqueue(&l, e);
    e=3.;
    fifo_enqueue(&l, e);

    fifo_dequeue(&l, &e);
    display_element(e);
    fifo_dequeue(&l, &e);
    display_element(e);
    fifo_dequeue(&l, &e);
    display_element(e);

    fifo_free(&l);
}