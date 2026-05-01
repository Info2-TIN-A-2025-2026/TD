#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "element.h"

#define GROWING_SIZE 10

typedef struct {

    element *t;
    size_t count; // number of cells used in t
    size_t size;  // total number of cells in t
} list;


// prototypes
list list_init(void);
bool list_is_empty(const list l);
bool list_is_full(const list l);
int list_insert_elem(list *l, const size_t pos, const element e);
int list_remove_elem(list *l, const size_t pos);
int list_get_elem(list l, const size_t pos, const element *e);
void list_free(list *l);