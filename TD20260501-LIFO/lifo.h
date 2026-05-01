#pragma once

#include "element.h"
#include "table_list_dyn_size.h"

typedef list lifo;

lifo lifo_init(void);
int lifo_push(lifo *l, const element e);
int lifo_pop(lifo* l, element *e);
void lifo_free(lifo* l);


