#pragma once

#include <stdio.h>
#include "element.h"

typedef struct node {

    struct node *next;
    struct node *prev;
    element payload;

} node;

typedef struct {

    node *first;
    node *last;
    size_t count;

} chained_list;


chained_list list_init();
int list_insert_elem(chained_list *l, const size_t pos, const element e);
