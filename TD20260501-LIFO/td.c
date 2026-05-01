#include <stdio.h>
#include "lifo.h"

int main(int argc, const char *argv[])
{
    lifo l;
    l = lifo_init();

    element e;

    e=1.;
    lifo_push(&l, e);
    e=2.;
    lifo_push(&l, e);
    e=3.;
    lifo_push(&l, e);

    lifo_pop(&l, &e);
    display_element(e);
    lifo_pop(&l, &e);
    display_element(e);
    lifo_pop(&l, &e);
    display_element(e);

    lifo_free(&l);
}