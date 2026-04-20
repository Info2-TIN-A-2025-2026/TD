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
list init(void);
bool is_empty(const list l);
bool is_full(const list l);
int insert(list *l, const size_t pos, const element e);
