#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "element.h"

#define LIST_SIZE 10

typedef struct {

    element t[LIST_SIZE];
    size_t count;
} list;


 // prototypes
list list_init(void);
bool list_is_empty(const list l);
bool list_is_full(const list l);
int list_insert_elem(list *l, const size_t pos, const element e);
int list_remove_elem(list *l, const size_t pos);
int list_get_elem(list l, const size_t pos, const element *e);
