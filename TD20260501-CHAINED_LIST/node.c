#include "node.h"
#include <stdlib.h>
#include <string.h>

int create_node(const element e, node **n) {

    *n = (node*)malloc(sizeof(node));
    if(NULL==*n) {
        return 1;
    }
    memcpy(&((*n)->payload), &e, sizeof(element));
    (*n)->next = NULL;
    (*n)->prev = NULL;
    return 0;
}