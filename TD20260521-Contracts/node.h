#pragma once
#include "element.h"

typedef struct node {
    element      payload;
    struct node *next;
    struct node *prev;
} node;

/* Allocates a new node on the heap.
 * Sets *n to the new node, or NULL on failure.
 * Returns 0 on success, -1 on malloc failure. */
int create_node(element e, node **n);

/* Frees a single node (does NOT touch neighbours). */
void free_node(node *n);
