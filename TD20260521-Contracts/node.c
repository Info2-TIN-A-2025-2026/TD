#include <stdlib.h>
#include <string.h>
#include "node.h"

int create_node(element e, node **n) {
    *n = (node *)malloc(sizeof(node));
    if (*n == NULL) {
        return -1;
    }
    memcpy(&((*n)->payload), &e, sizeof(element));
    (*n)->next = NULL;
    (*n)->prev = NULL;
    return 0;
}

void free_node(node *n) {
    if (n)
        free(n);
}
