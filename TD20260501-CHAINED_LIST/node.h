#pragma once

#include "element.h"

typedef struct node {

    struct node *next;
    struct node *prev;
    element payload;

} node;


int create_node(const element e, node **n);