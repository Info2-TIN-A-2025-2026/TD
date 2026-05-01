#pragma once

#include "element.h"
#include "table_list_dyn_size.h"

typedef list fifo;

fifo fifo_init(void);
int fifo_enqueue(fifo *l, const element e);
int fifo_dequeue(fifo* l, element *e);
void fifo_free(fifo* l);


