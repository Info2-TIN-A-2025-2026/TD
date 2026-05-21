#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "element.h"
#include "node.h"

typedef struct {
    node  *first;
    node  *last;
    size_t count;
} chained_list;

/* ---- lifecycle ---- */
chained_list list_init(void);
void         list_free(chained_list *l);

/* ---- queries ---- */
bool list_is_empty(chained_list l);
int  list_get_elem(chained_list l, size_t pos, element *e);

/* ---- mutations ---- */
int list_insert_elem(chained_list *l, size_t pos, element e);
int list_remove_elem(chained_list *l, size_t pos);

/* ---- display ---- */
void list_display(chained_list l);

/* ---- persistence ---- */
int list_save(chained_list l,  const char *filename);
int list_load(chained_list *l, const char *filename);
